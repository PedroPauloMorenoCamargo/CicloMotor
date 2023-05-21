/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include <asf.h>
#include <string.h>
#include "ili9341.h"
#include "lvgl.h"
#include "touch/touch.h"
#include <time.h>
#include <stdlib.h>

static  lv_obj_t * labelBtnStart;
 lv_chart_series_t * ser;
lv_obj_t * labelClock;
lv_obj_t * labelCronometro;
static  lv_obj_t * labelBtnPower;
lv_obj_t * labelDistancia;
lv_obj_t * labelDistanciaDecimal;
lv_obj_t * labelVelMed;
lv_obj_t * labelVelMedDecimal;
lv_obj_t * labelVel;
lv_obj_t * labelVelDecimal;
lv_obj_t * labelacc;
lv_obj_t * labelTempo;
lv_obj_t * labelDiameter;
lv_obj_t * labelMaxBPM;
lv_obj_t * labelAvgBPM;
static lv_obj_t * chart;
volatile int casa_decimal = 0;
volatile int renderizou = 0;
volatile int page = 1;
/************************************************************************/
/* LCD / LVGL                                                           */
/************************************************************************/
volatile int in_config = 0;
#define LV_HOR_RES_MAX          (320)
#define LV_VER_RES_MAX          (240)
LV_FONT_DECLARE(Roboto_25);
LV_FONT_DECLARE(dseg15);
LV_FONT_DECLARE(Roboto_18);
LV_FONT_DECLARE(Roboto_15);
LV_FONT_DECLARE(dseg25);
LV_FONT_DECLARE(dseg20);
LV_FONT_DECLARE(Roboto_12);

volatile int comecou = 0;
SemaphoreHandle_t xMutex;
SemaphoreHandle_t xSemaphoreRel;
SemaphoreHandle_t xSemaphoreCronometro;

volatile int seg_cronometro = 0;
volatile int min_cronometro = 0;
volatile int horas_cronometro = 0;
volatile int temp_wheel_diameter = 0;
volatile int wheel_diameter = 0;

volatile int temp_min_relogio = 0;
volatile int temp_horas_relogio = 0;

volatile int seg_relogio = 50;
volatile int min_relogio = 59;
volatile int horas_relogio = 23;
/*A static or global variable to store the buffers*/
static lv_disp_draw_buf_t disp_buf;

/*Static or global buffer(s). The second buffer is optional*/
static lv_color_t buf_1[LV_HOR_RES_MAX * LV_VER_RES_MAX];
static lv_disp_drv_t disp_drv;          /*A variable to hold the drivers. Must be static or global.*/
static lv_indev_drv_t indev_drv;

/************************************************************************/
/* RTOS                                                                 */
/************************************************************************/

#define TASK_LCD_STACK_SIZE                (1024*6/sizeof(portSTACK_TYPE))
#define TASK_LCD_STACK_PRIORITY            (tskIDLE_PRIORITY)


#define TASK_OUTRO_STACK_SIZE                (1024/sizeof(portSTACK_TYPE))
#define TASK_OUTRO_STACK_PRIORITY            (tskIDLE_PRIORITY)
extern void vApplicationStackOverflowHook(xTaskHandle *pxTask,  signed char *pcTaskName);
extern void vApplicationIdleHook(void);
extern void vApplicationTickHook(void);
extern void vApplicationMallocFailedHook(void);
extern void xPortSysTickHandler(void);

extern void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName) {
	printf("stack overflow %x %s\r\n", pxTask, (portCHAR *)pcTaskName);
	for (;;) {	}
}

extern void vApplicationIdleHook(void) { }

extern void vApplicationTickHook(void) { }

extern void vApplicationMallocFailedHook(void) {
	configASSERT( ( volatile void * ) NULL );
}

void TC_init(Tc * TC, int ID_TC, int TC_CHANNEL, int freq);


void TC1_Handler(void) {
	/**
	* Devemos indicar ao TC que a interrupção foi satisfeita.
	* Isso é realizado pela leitura do status do periférico
	**/
	volatile uint32_t status = tc_get_status(TC0, 1);
	seg_relogio++;
	if(seg_relogio == 60){
		seg_relogio = 0;
		min_relogio++;
	}
	if(min_relogio == 60){
		min_relogio = 0;
		horas_relogio++;
	}
	if (horas_relogio == 24){
		horas_relogio = 0;
	}
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR(xSemaphoreRel,xHigherPriorityTaskWoken);
}

void TC3_Handler(void) {
	/**
	* Devemos indicar ao TC que a interrupção foi satisfeita.
	* Isso é realizado pela leitura do status do periférico
	**/
	volatile uint32_t status = tc_get_status(TC1, 0);
	if(comecou){
		seg_cronometro++;
		if(seg_cronometro == 60){
			seg_cronometro = 0;
			min_cronometro++;
		}
		if(min_cronometro == 60){
			min_cronometro = 0;
			horas_cronometro++;
		}
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xSemaphoreGiveFromISR(xSemaphoreCronometro,xHigherPriorityTaskWoken);
	}
}
/************************************************************************/
/* lvgl                                                                 */
/************************************************************************/

static void settings_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		renderizou = 0;
		page = 2;
		in_config = 1;
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}

static void bpm_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		renderizou = 0;
		page = 3;
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}

static void radio_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		LV_LOG_USER("Clicked");
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}


static void home_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		renderizou = 0;
		page = 1;
		in_config = 0;
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}

static void up_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		if(casa_decimal == 0){
			temp_min_relogio++;
			if (temp_min_relogio > 59){
				temp_min_relogio = 0;
			}
		}
		else if (casa_decimal ==1){
			temp_min_relogio+=10;
			if (temp_min_relogio > 59){
				temp_min_relogio -= 60;
			}
		}
		else if (casa_decimal == 2){
			temp_horas_relogio++;
			if (temp_horas_relogio > 23){
				temp_horas_relogio = 0;
			}
		}
		else if (casa_decimal == 3){
			int x = temp_horas_relogio%10;
			temp_horas_relogio+=10;
			if (temp_horas_relogio > 24){
				temp_horas_relogio =x ;
				
			}
			
		}
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}


static void down_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		if(casa_decimal == 0){
			temp_min_relogio--;
			if (temp_min_relogio < 0){
				temp_min_relogio = 59;
			}
		}
		else if (casa_decimal ==1){
			temp_min_relogio-=10;
			if (temp_min_relogio < 0){
				temp_min_relogio += 60;
			}
		}
		else if (casa_decimal == 2){
			temp_horas_relogio--;
			if (temp_horas_relogio < 0){
				temp_horas_relogio = 23;
			}
		}
		else if (casa_decimal == 3){
			temp_horas_relogio-=10;
			if (temp_horas_relogio < 0){
				temp_horas_relogio += 30;
				if (temp_horas_relogio > 24){
					temp_horas_relogio = 24;
				}
				
			}
			
		}
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}

static void change_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		casa_decimal = (casa_decimal+1)%4;
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}

static void plus_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		temp_wheel_diameter++;
		if (temp_wheel_diameter >999){
			temp_wheel_diameter= 0;
		}
		lv_label_set_text_fmt(labelDiameter, "%03d", temp_wheel_diameter);
	}
	else if(code == LV_EVENT_LONG_PRESSED_REPEAT) {
		temp_wheel_diameter+=20;
		if (temp_wheel_diameter >999){
			temp_wheel_diameter= 0;
		}
		lv_label_set_text_fmt(labelDiameter, "%03d", temp_wheel_diameter);
	}
}
static void minus_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		temp_wheel_diameter--;
		if (temp_wheel_diameter <0){
			temp_wheel_diameter= 999;
		}
		lv_label_set_text_fmt(labelDiameter, "%03d", temp_wheel_diameter);
	}
	else if(code == LV_EVENT_LONG_PRESSED_REPEAT) {
		temp_wheel_diameter-=20;
		if (temp_wheel_diameter <0){
			temp_wheel_diameter= 999;
		}
		lv_label_set_text_fmt(labelDiameter, "%03d", temp_wheel_diameter);
	}
}

static void apply_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		seg_relogio = 0;
		min_relogio = temp_min_relogio;
		horas_relogio = temp_horas_relogio;
		wheel_diameter = temp_wheel_diameter;
		renderizou = 0;
		page = 1;
		in_config = 0;
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}



static void delete_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		lv_label_set_text(labelBtnStart, LV_SYMBOL_PLAY);
		comecou = 0;
		seg_cronometro = 0;
		horas_cronometro = 0;
		min_cronometro = 0;
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xSemaphoreGiveFromISR(xSemaphoreCronometro,xHigherPriorityTaskWoken);
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}

static void save_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		lv_label_set_text(labelBtnStart, LV_SYMBOL_PLAY);
		comecou = 0;
		seg_cronometro = 0;
		horas_cronometro = 0;
		min_cronometro = 0;
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xSemaphoreGiveFromISR(xSemaphoreCronometro,xHigherPriorityTaskWoken);
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}


static void start_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		if (!comecou){
			lv_label_set_text(labelBtnStart, LV_SYMBOL_STOP);
		}
		else{
			lv_label_set_text(labelBtnStart, LV_SYMBOL_PLAY);
		}
		comecou = !comecou;
	}
}

void lv_main(void) {
	static  lv_obj_t * labelBtnSettings;
	static  lv_obj_t * labelBtnDelete;
	static  lv_obj_t * labelBtnSave;
	static  lv_obj_t * labelBtnHome;
	static  lv_obj_t * labelBtnRadio;
	static  lv_obj_t * labelBtnBPM;
	static  lv_obj_t * labelBtnList;
	lv_obj_t * labelLogo;
	lv_obj_t * labelCronometroTexto;
	lv_obj_t * labelVelMedTexto;
	lv_obj_t * labelDistanciaTexto;
	lv_obj_t * labelVelTexto;
	lv_obj_t * labelDistanciaUnidade;
	lv_obj_t * labelVelMedUnidade;
	lv_obj_t * labelVelUnidade;
	
	static lv_style_t style;
	lv_style_init(&style);
	lv_style_set_bg_color(&style, lv_color_black());
	lv_style_set_border_width(&style, 0);
	
	labelLogo = lv_label_create(lv_scr_act());
	lv_obj_align(labelLogo, LV_ALIGN_TOP_MID, 0 , 25);
	lv_obj_set_style_text_font(labelLogo, &Roboto_25, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelLogo, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelLogo, "BIKE.IO");
	
	labelClock = lv_label_create(lv_scr_act());
	lv_obj_align(labelClock, LV_ALIGN_TOP_RIGHT,-5 , 10);
	lv_obj_set_style_text_font(labelClock, &dseg15, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelClock, lv_color_white(), LV_STATE_DEFAULT);
	
	/*Create an array for the points of the line*/
	static lv_point_t line_points[] = { {0, 0}, {239,0} };
	static lv_point_t line_points2[] = { {0, 0}, {0,67} };

	/*Create style*/
	static lv_style_t style_line;
	lv_style_init(&style_line);
	lv_style_set_line_width(&style_line, 1);
	lv_style_set_line_color(&style_line, lv_color_white());
	lv_style_set_line_rounded(&style_line, true);

	/*Create a line and apply the new style*/
	lv_obj_t * line1;
	line1 = lv_line_create(lv_scr_act());
	lv_line_set_points(line1, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line1, &style_line, 0);
	lv_obj_align(line1, LV_ALIGN_TOP_LEFT,0 , 50);
	
	//Label cronometro
	labelCronometroTexto = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelCronometroTexto,line1, LV_ALIGN_OUT_BOTTOM_LEFT,1 , 0);
	lv_obj_set_style_text_font(labelCronometroTexto, &Roboto_18, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelCronometroTexto, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelCronometroTexto, "Cronometro:");
	//Cronometro
	labelCronometro = lv_label_create(lv_scr_act());
	lv_obj_align(labelCronometro,LV_ALIGN_CENTER,0 , -75);
	lv_obj_set_style_text_font(labelCronometro, &dseg25, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelCronometro, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelCronometro, "%02d:%02d:%02d", seg_cronometro, min_cronometro,horas_cronometro);
	//Play
	lv_obj_t * btnStart = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnStart, start_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnStart, LV_ALIGN_CENTER,0, -45);
	lv_obj_add_style(btnStart, &style, 0);
	lv_obj_set_width(btnStart, 35);
	lv_obj_set_height(btnStart, 35);
	
	labelBtnStart = lv_label_create(btnStart);
	lv_label_set_text(labelBtnStart, LV_SYMBOL_PLAY);
	lv_obj_center(labelBtnStart);
	
	//Delete
	lv_obj_t * btnDelete = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnDelete, delete_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnDelete, LV_ALIGN_CENTER,-80, -45);
	lv_obj_add_style(btnDelete, &style, 0);
	lv_obj_set_width(btnDelete, 35);
	lv_obj_set_height(btnDelete, 35);
	
	labelBtnDelete = lv_label_create(btnDelete);
	lv_label_set_text(labelBtnDelete, LV_SYMBOL_TRASH);
	lv_obj_center(labelBtnDelete);
	
	//Save
	lv_obj_t * btnSave = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnSave, delete_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnSave, LV_ALIGN_CENTER,80, -45);
	lv_obj_add_style(btnSave, &style, 0);
	lv_obj_set_width(btnSave, 35);
	lv_obj_set_height(btnSave, 35);
	
	labelBtnSave = lv_label_create(btnSave);
	lv_label_set_text(labelBtnSave, LV_SYMBOL_SAVE);
	lv_obj_center(labelBtnSave);
	
	/*Create a line and apply the new style*/
	lv_obj_t * line2;
	line2 = lv_line_create(lv_scr_act());
	lv_line_set_points(line2, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line2, &style_line, 0);
	lv_obj_align(line2, LV_ALIGN_TOP_LEFT,0 , 132);
	//Label cronometro
	labelDistanciaTexto = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelDistanciaTexto,line2, LV_ALIGN_OUT_BOTTOM_LEFT,1 , 0);
	lv_obj_set_style_text_font(labelDistanciaTexto, &Roboto_18, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelDistanciaTexto, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelDistanciaTexto, "Distancia:");
	//Distancia
	labelDistancia = lv_label_create(lv_scr_act());
	lv_obj_align(labelDistancia,LV_ALIGN_CENTER,-20 , 0);
	lv_obj_set_style_text_font(labelDistancia, &dseg25, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelDistancia, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelDistancia, "%d.",138);
	//Distancia Decimal
	labelDistanciaDecimal = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelDistanciaDecimal,labelDistancia,LV_ALIGN_OUT_RIGHT_MID,2 , 7);
	lv_obj_set_style_text_font(labelDistanciaDecimal, &dseg20, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelDistanciaDecimal, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelDistanciaDecimal, "%d",8);
	//Distancia Unidade
	labelDistanciaUnidade = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelDistanciaUnidade,labelDistanciaDecimal,LV_ALIGN_OUT_RIGHT_MID,8 , 13);
	lv_obj_set_style_text_font(labelDistanciaUnidade, &Roboto_15, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelDistanciaUnidade, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelDistanciaUnidade, "Km");
	/*Create a line and apply the new style*/
	lv_obj_t * line3;
	line3 = lv_line_create(lv_scr_act());
	lv_line_set_points(line3, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line3, &style_line, 0);
	lv_obj_align(line3, LV_ALIGN_CENTER,0 , 25);
	/*Create a line and apply the new style*/
	lv_obj_t * line4;
	line4 = lv_line_create(lv_scr_act());
	lv_line_set_points(line4, line_points2, 2);     /*Set the points*/
	lv_obj_add_style(line4, &style_line, 0);
	lv_obj_align(line4, LV_ALIGN_CENTER,0 , 60);
	//Label Vel Med
	labelVelMedTexto = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelVelMedTexto,line3, LV_ALIGN_OUT_BOTTOM_LEFT,1 , 5);
	lv_obj_set_style_text_font(labelVelMedTexto, &Roboto_18, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelVelMedTexto, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelVelMedTexto, "Vm:");
	//Vel med
	labelVelMed = lv_label_create(lv_scr_act());
	lv_obj_align(labelVelMed,LV_ALIGN_CENTER,-70 , 65);
	lv_obj_set_style_text_font(labelVelMed, &dseg20, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelVelMed, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelVelMed, "%d.",45);
	//Vel Med Decimal
	labelVelMedDecimal = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelVelMedDecimal,labelVelMed,LV_ALIGN_OUT_RIGHT_MID,2 , 10);
	lv_obj_set_style_text_font(labelVelMedDecimal, &dseg15, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelVelMedDecimal, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelVelMedDecimal, "%d",8);
	//
	labelVelMedUnidade = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelVelMedUnidade,labelVelMedDecimal,LV_ALIGN_OUT_RIGHT_MID,4 , 10);
	lv_obj_set_style_text_font(labelVelMedUnidade, &Roboto_12, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelVelMedUnidade, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelVelMedUnidade, "Km/h");
	//Label Vel Med
	labelVelTexto = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelVelTexto,line3, LV_ALIGN_OUT_BOTTOM_MID,32 , 5);
	lv_obj_set_style_text_font(labelVelTexto, &Roboto_18, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelVelTexto, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelVelTexto, "V:");
	//Vel med
	labelVel = lv_label_create(lv_scr_act());
	lv_obj_align(labelVel,LV_ALIGN_CENTER,50 , 65);
	lv_obj_set_style_text_font(labelVel, &dseg20, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelVel, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelVel, "%d.",25);
	//Vel Decimal
	labelVelDecimal = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelVelDecimal,labelVel,LV_ALIGN_OUT_RIGHT_MID,2 , 10);
	lv_obj_set_style_text_font(labelVelDecimal, &dseg15, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelVelDecimal, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelVelDecimal, "%d",8);
	//
	labelVelUnidade = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelVelUnidade,labelVelDecimal,LV_ALIGN_OUT_RIGHT_MID,4 , 10);
	lv_obj_set_style_text_font(labelVelUnidade, &Roboto_12, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelVelUnidade, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelVelUnidade, "Km/h");
	//Label Vel Med
	labelacc = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelacc,line3, LV_ALIGN_OUT_BOTTOM_RIGHT,20 , -2);
	lv_obj_set_style_text_font(labelacc, LV_FONT_DEFAULT, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelacc, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelacc, LV_SYMBOL_PLUS);
	lv_obj_t * line5;
	line5 = lv_line_create(lv_scr_act());
	lv_line_set_points(line5, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line5, &style_line, 0);
	lv_obj_align(line5, LV_ALIGN_CENTER,0 , 93);
	//Delete
	lv_obj_t * btnHome = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnHome, home_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnHome, LV_ALIGN_BOTTOM_LEFT,0, 0);
	lv_obj_add_style(btnHome, &style, 0);
	lv_obj_set_width(btnHome, 60);
	lv_obj_set_height(btnHome, 60);
	
	labelBtnHome = lv_label_create(btnHome);
	lv_label_set_text(labelBtnHome, LV_SYMBOL_HOME);
	lv_obj_center(labelBtnHome);
	
	//Delete
	lv_obj_t * btnRadio = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnRadio, radio_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnRadio, LV_ALIGN_BOTTOM_LEFT,60, 0);
	lv_obj_add_style(btnRadio, &style, 0);
	lv_obj_set_width(btnRadio, 60);
	lv_obj_set_height(btnRadio, 60);
	
	labelBtnRadio = lv_label_create(btnRadio);
	lv_label_set_text(labelBtnRadio, LV_SYMBOL_WARNING);
	lv_obj_center(labelBtnRadio);
	
	//Delete
	lv_obj_t * btnBPM = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnBPM, bpm_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnBPM, LV_ALIGN_BOTTOM_LEFT,120, 0);
	lv_obj_add_style(btnBPM, &style, 0);
	lv_obj_set_width(btnBPM, 60);
	lv_obj_set_height(btnBPM, 60);
	
	labelBtnBPM = lv_label_create(btnBPM);
	lv_label_set_text(labelBtnBPM, LV_SYMBOL_WIFI);
	lv_obj_center(labelBtnBPM);
	
	//Delete
	lv_obj_t * btnSettings = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnSettings, settings_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnSettings ,LV_ALIGN_BOTTOM_LEFT,180, 0);
	lv_obj_add_style(btnSettings, &style, 0);
	lv_obj_set_width(btnSettings, 60);
	lv_obj_set_height(btnSettings, 60);
	
	labelBtnSettings = lv_label_create(btnSettings);
	lv_label_set_text(labelBtnSettings, LV_SYMBOL_SETTINGS);
	lv_obj_center(labelBtnSettings);
}

static void draw_event_cb(lv_event_t * e)
{
	lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
	if(!lv_obj_draw_part_check_type(dsc, &lv_chart_class, LV_CHART_DRAW_PART_TICK_LABEL)) return;

}

void lv_bpm(void) {
	lv_obj_t * labelAvgBPMTexto;
	lv_obj_t * labelMaxBPMTexto;
	lv_obj_t * labelLogo;
	lv_obj_t * labelMaxBPMUnidade;
	lv_obj_t * labelAvgBPMUnidade;
	static  lv_obj_t * labelBtnHome;
	static  lv_obj_t * labelBtnRadio;
	static  lv_obj_t * labelBtnBPM;
	static  lv_obj_t * labelBtnList;
	static  lv_obj_t * labelBtnSettings;
	static lv_style_t style;
	lv_style_init(&style);
	lv_style_set_bg_color(&style, lv_color_black());
	lv_style_set_border_width(&style, 0);
	
	labelLogo = lv_label_create(lv_scr_act());
	lv_obj_align(labelLogo, LV_ALIGN_TOP_MID, 0 , 25);
	lv_obj_set_style_text_font(labelLogo, &Roboto_25, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelLogo, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelLogo, "BIKE.IO");
	
	
	labelClock = lv_label_create(lv_scr_act());
	lv_obj_align(labelClock, LV_ALIGN_TOP_RIGHT,-5 , 10);
	lv_obj_set_style_text_font(labelClock, &dseg15, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelClock, lv_color_white(), LV_STATE_DEFAULT);
	
	/*Create an array for the points of the line*/
	static lv_point_t line_points[] = { {0, 0}, {239,0} };
	static lv_point_t line_points2[] = { {0, 0}, {0,47} };

	/*Create style*/
	static lv_style_t style_line;
	lv_style_init(&style_line);
	lv_style_set_line_width(&style_line, 1);
	lv_style_set_line_color(&style_line, lv_color_white());
	lv_style_set_line_rounded(&style_line, true);

	/*Create a line and apply the new style*/
	lv_obj_t * line1;
	line1 = lv_line_create(lv_scr_act());
	lv_line_set_points(line1, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line1, &style_line, 0);
	lv_obj_align(line1, LV_ALIGN_TOP_LEFT,0 , 50);
	labelAvgBPMTexto = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelAvgBPMTexto,line1, LV_ALIGN_OUT_BOTTOM_LEFT,5 , 3);
	lv_obj_set_style_text_font(labelAvgBPMTexto, &Roboto_18, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelAvgBPMTexto, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelAvgBPMTexto, "Avg:");
	
	labelMaxBPMTexto = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelMaxBPMTexto,line1, LV_ALIGN_OUT_BOTTOM_MID,40 , 3);
	lv_obj_set_style_text_font(labelMaxBPMTexto, &Roboto_18, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelMaxBPMTexto, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelMaxBPMTexto, "Max:");
	
	//Label cronometro
	labelAvgBPM = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelAvgBPM,line1, LV_ALIGN_OUT_BOTTOM_LEFT, 30, 25);
	lv_obj_set_style_text_font(labelAvgBPM, &dseg20, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelAvgBPM, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelAvgBPM, "150");
	
	//Distancia Unidade
	labelAvgBPMUnidade = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelAvgBPMUnidade,labelAvgBPM,LV_ALIGN_OUT_RIGHT_MID, 4, 13);
	lv_obj_set_style_text_font(labelAvgBPMUnidade, &Roboto_12, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelAvgBPMUnidade, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelAvgBPMUnidade, "BPM");
	
	labelMaxBPM = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelMaxBPM,line1, LV_ALIGN_OUT_BOTTOM_MID, 65, 25);
	lv_obj_set_style_text_font(labelMaxBPM, &dseg20, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelMaxBPM, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelMaxBPM, "150");
	
	labelMaxBPMUnidade = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelMaxBPMUnidade,labelMaxBPM,LV_ALIGN_OUT_RIGHT_MID, 4, 13);
	lv_obj_set_style_text_font(labelMaxBPMUnidade, &Roboto_12, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelMaxBPMUnidade, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelMaxBPMUnidade, "BPM");
	
	lv_obj_t * line4;
	line4 = lv_line_create(lv_scr_act());
	lv_line_set_points(line4, line_points2, 2);     /*Set the points*/
	lv_obj_add_style(line4, &style_line, 0);
	lv_obj_align(line4, LV_ALIGN_CENTER,0 , -83);
	lv_obj_t * line5;
	line5 = lv_line_create(lv_scr_act());
	lv_line_set_points(line5, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line5, &style_line, 0);
	lv_obj_align(line5, LV_ALIGN_CENTER,0 , -60);
	
	 /*Create a chart*/
	 lv_obj_t * chart;
	 chart = lv_chart_create(lv_scr_act());
	 lv_obj_set_size(chart, 175, 140);
	 lv_obj_align(chart, LV_ALIGN_CENTER,30 , 20);
	 lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
	 lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 200);
	 lv_chart_set_point_count(chart, 100);
	 /*Do not display points on the data*/
	 lv_obj_set_style_size(chart, 0, LV_PART_INDICATOR);
	 lv_obj_add_event_cb(chart, draw_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
	 lv_chart_set_axis_tick(chart, LV_CHART_AXIS_PRIMARY_Y,10 , 5, 6, 4, true, 60);
	 lv_chart_set_update_mode(chart,LV_CHART_UPDATE_MODE_CIRCULAR);
	 ser = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
	 lv_chart_refresh(chart);
	 //Delete
	 lv_obj_t * btnHome = lv_btn_create(lv_scr_act());
	 lv_obj_add_event_cb(btnHome, home_handler, LV_EVENT_ALL, NULL);
	 lv_obj_align(btnHome, LV_ALIGN_BOTTOM_LEFT,0, 0);
	 lv_obj_add_style(btnHome, &style, 0);
	 lv_obj_set_width(btnHome, 60);
	 lv_obj_set_height(btnHome, 60);
	 
	 labelBtnHome = lv_label_create(btnHome);
	 lv_label_set_text(labelBtnHome, LV_SYMBOL_HOME);
	 lv_obj_center(labelBtnHome);
	 
	 //Delete
	 lv_obj_t * btnRadio = lv_btn_create(lv_scr_act());
	 lv_obj_add_event_cb(btnRadio, radio_handler, LV_EVENT_ALL, NULL);
	 lv_obj_align(btnRadio, LV_ALIGN_BOTTOM_LEFT,60, 0);
	 lv_obj_add_style(btnRadio, &style, 0);
	 lv_obj_set_width(btnRadio, 60);
	 lv_obj_set_height(btnRadio, 60);
	 
	 labelBtnRadio = lv_label_create(btnRadio);
	 lv_label_set_text(labelBtnRadio, LV_SYMBOL_WARNING);
	 lv_obj_center(labelBtnRadio);
	 
	 //Delete
	 lv_obj_t * btnBPM = lv_btn_create(lv_scr_act());
	 lv_obj_add_event_cb(btnBPM, bpm_handler, LV_EVENT_ALL, NULL);
	 lv_obj_align(btnBPM, LV_ALIGN_BOTTOM_LEFT,120, 0);
	 lv_obj_add_style(btnBPM, &style, 0);
	 lv_obj_set_width(btnBPM, 60);
	 lv_obj_set_height(btnBPM, 60);
	 
	 labelBtnBPM = lv_label_create(btnBPM);
	 lv_label_set_text(labelBtnBPM, LV_SYMBOL_WIFI);
	 lv_obj_center(labelBtnBPM);
	 
	 //Delete
	 lv_obj_t * btnSettings = lv_btn_create(lv_scr_act());
	 lv_obj_add_event_cb(btnSettings, settings_handler, LV_EVENT_ALL, NULL);
	 lv_obj_align(btnSettings ,LV_ALIGN_BOTTOM_LEFT,180, 0);
	 lv_obj_add_style(btnSettings, &style, 0);
	 lv_obj_set_width(btnSettings, 60);
	 lv_obj_set_height(btnSettings, 60);
	 
	 labelBtnSettings = lv_label_create(btnSettings);
	 lv_label_set_text(labelBtnSettings, LV_SYMBOL_SETTINGS);
	 lv_obj_center(labelBtnSettings);

	
}
void lv_config(void) {
	static lv_style_t style_line;
	lv_style_init(&style_line);
	lv_style_set_line_width(&style_line, 1);
	lv_style_set_line_color(&style_line, lv_color_white());
	lv_style_set_line_rounded(&style_line, true);
	lv_obj_t * labelLogo;
	static  lv_obj_t * labelBtnHome;
	static  lv_obj_t * labelBtnUp;
	static  lv_obj_t * labelBtnDown;
	static  lv_obj_t * labelBtnChange;
	static  lv_obj_t * labelBtnPower;
	static  lv_obj_t * labelBtnPlus;
	static  lv_obj_t * labelBtnMinus;
	static  lv_obj_t * labelBtnApply;
	lv_obj_t * labelTempoTexto;
	lv_obj_t * labelDiameterUnidade;
	lv_obj_t * labelDiameterTexto;
	static lv_style_t style;
	static lv_point_t line_points[] = { {0, 0}, {239,0} };
	lv_style_init(&style);
	lv_style_set_bg_color(&style, lv_color_black());
	lv_style_set_border_width(&style, 0);
	//Label Logo
	labelLogo = lv_label_create(lv_scr_act());
	lv_obj_align(labelLogo, LV_ALIGN_TOP_MID, 0 , 25);
	lv_obj_set_style_text_font(labelLogo, &Roboto_25, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelLogo, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelLogo, "Settings");
	//Botão Home
	lv_obj_t * btnHome = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnHome, home_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnHome, LV_ALIGN_TOP_LEFT,0, 0);
	lv_obj_add_style(btnHome, &style, 0);
	lv_obj_set_width(btnHome, 50);
	lv_obj_set_height(btnHome, 50);
	
	labelBtnHome = lv_label_create(btnHome);
	lv_label_set_text(labelBtnHome, LV_SYMBOL_HOME);
	lv_obj_center(labelBtnHome);
	//Linha 1
	lv_obj_t * line1;
	line1 = lv_line_create(lv_scr_act());
	lv_line_set_points(line1, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line1, &style_line, 0);
	lv_obj_align(line1, LV_ALIGN_TOP_LEFT,0 , 50);
	//Label Tempo
	labelTempoTexto = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelTempoTexto,line1, LV_ALIGN_OUT_BOTTOM_LEFT,5, 10);
	lv_obj_set_style_text_font(labelTempoTexto, &Roboto_18, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelTempoTexto, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelTempoTexto, "Time:");

	labelTempo = lv_label_create(lv_scr_act());
	lv_obj_align(labelTempo,LV_ALIGN_CENTER,-5 , -70);
	lv_obj_set_style_text_font(labelTempo, &dseg25, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelTempo, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelTempo, "%02d:%02d", temp_horas_relogio, temp_min_relogio);
	//Up
	lv_obj_t * btnUp = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnUp, up_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnUp, LV_ALIGN_TOP_RIGHT,-40, 55);
	lv_obj_add_style(btnUp, &style, 0);
	lv_obj_set_width(btnUp, 40);
	lv_obj_set_height(btnUp, 40);
	
	labelBtnUp = lv_label_create(btnUp);
	lv_label_set_text(labelBtnUp, LV_SYMBOL_UP);
	lv_obj_center(labelBtnUp);
	
	lv_obj_t * btnDown = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnDown, down_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnDown, LV_ALIGN_TOP_RIGHT,-40, 90);
	lv_obj_add_style(btnDown, &style, 0);
	lv_obj_set_width(btnDown, 40);
	lv_obj_set_height(btnDown, 40);
	
	labelBtnDown = lv_label_create(btnDown);
	lv_label_set_text(labelBtnDown, LV_SYMBOL_DOWN);
	lv_obj_center(labelBtnDown);
	
	lv_obj_t * btnChange = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnChange, change_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnChange, LV_ALIGN_TOP_RIGHT,0, 70);
	lv_obj_add_style(btnChange, &style, 0);
	lv_obj_set_width(btnChange, 40);
	lv_obj_set_height(btnChange, 40);
	
	labelBtnChange = lv_label_create(btnChange);
	lv_label_set_text(labelBtnChange, LV_SYMBOL_REFRESH);
	lv_obj_center(labelBtnChange);
	
	lv_obj_t * line2;
	line2 = lv_line_create(lv_scr_act());
	lv_line_set_points(line2, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line2, &style_line, 0);
	lv_obj_align(line2, LV_ALIGN_TOP_LEFT,0 , 132);
	
	//Label Diametro
	labelDiameterTexto = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelDiameterTexto,line2, LV_ALIGN_OUT_BOTTOM_LEFT,5, 10);
	lv_obj_set_style_text_font(labelDiameterTexto, &Roboto_18, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelDiameterTexto, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelDiameterTexto, "Wheel Diameter:");
	//Label Diametro
	temp_wheel_diameter = wheel_diameter;
	labelDiameter = lv_label_create(lv_scr_act());
	lv_obj_align(labelDiameter,LV_ALIGN_CENTER,-5 , 25);
	lv_obj_set_style_text_font(labelDiameter, &dseg25, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelDiameter, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelDiameter, "%03d", temp_wheel_diameter);
	
	labelDiameterUnidade = lv_label_create(lv_scr_act());
	lv_obj_align_to(labelDiameterUnidade,labelDiameter,LV_ALIGN_OUT_RIGHT_MID,8 , 13);
	lv_obj_set_style_text_font(labelDiameterUnidade, &Roboto_15, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(labelDiameterUnidade, lv_color_white(), LV_STATE_DEFAULT);
	lv_label_set_text_fmt(labelDiameterUnidade, "mm");
	
	lv_obj_t * btnPlus = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnPlus, plus_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnPlus, LV_ALIGN_TOP_RIGHT,-10, 165);
	lv_obj_add_style(btnPlus, &style, 0);
	lv_obj_set_width(btnPlus, 40);
	lv_obj_set_height(btnPlus, 40);
	
	labelBtnPlus = lv_label_create(btnPlus);
	lv_label_set_text(labelBtnPlus, LV_SYMBOL_PLUS);
	lv_obj_center(labelBtnPlus);
	
	lv_obj_t * btnMinus = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnMinus, minus_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnMinus, LV_ALIGN_TOP_LEFT,10, 165);
	lv_obj_add_style(btnMinus, &style, 0);
	lv_obj_set_width(btnMinus, 40);
	lv_obj_set_height(btnMinus, 40);
	
	labelBtnMinus = lv_label_create(btnMinus);
	lv_label_set_text(labelBtnMinus, LV_SYMBOL_MINUS);
	lv_obj_center(labelBtnMinus);
	
	lv_obj_t * line3;
	line3 = lv_line_create(lv_scr_act());
	lv_line_set_points(line3, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line3, &style_line, 0);
	lv_obj_align(line3, LV_ALIGN_TOP_LEFT,0 , 210);
	

	lv_obj_t * btnApply = lv_btn_create(lv_scr_act());
	lv_obj_add_event_cb(btnApply, apply_handler, LV_EVENT_ALL, NULL);
	lv_obj_align(btnApply, LV_ALIGN_CENTER,0, 100);
	lv_obj_add_style(btnApply, &style, 0);
	lv_obj_set_width(btnApply, 90);
	lv_obj_set_height(btnApply, 90);
	
	labelBtnApply = lv_label_create(btnApply);
	lv_label_set_text(labelBtnApply, "Apply");
	lv_obj_center(labelBtnApply);
	
	
	
	
}




/************************************************************************/
/* TASKS                                                                */
/************************************************************************/

static void task_lcd(void *pvParameters) {
	int px, py;
	for (;;)  {
		if(xSemaphoreTake( xMutex, 50 )){
			if (renderizou == 0){
				lv_obj_clean(lv_scr_act());
				if (page == 1){
					lv_main();
				}
				else if (page == 2){
					lv_config();
				}
				else if (page == 3){
					lv_bpm();
				}
				renderizou = 1;
			}
			lv_tick_inc(50);
			lv_task_handler();
			xSemaphoreGive(xMutex);
			vTaskDelay(50);
		}
	}
}

static void task_cronometro(void *pvParameters) {
	TC_init(TC1, ID_TC3, 0, 1);
	tc_start(TC1, 0);

	for (;;)  {
		if (xSemaphoreTake(xSemaphoreCronometro, 50) && xSemaphoreTake(xMutex, 50)) {
			lv_label_set_text_fmt(labelCronometro, "%02d:%02d:%02d", horas_cronometro, min_cronometro,seg_cronometro);
			xSemaphoreGive(xMutex);
		}
	}
}


static void task_relogio(void *pvParameters) {
	TC_init(TC0, ID_TC1, 1, 1);
	tc_start(TC0, 1);
	int flag_pisca_rel = 0;
	int flag_pisca_edit = 0;
	for (;;)  {
		if (xSemaphoreTake(xSemaphoreRel, 50) && xSemaphoreTake(xMutex, 50)) {
			if(in_config == 0){
				if (flag_pisca_rel == 1){
					lv_label_set_text_fmt(labelClock, "%02d:%02d", horas_relogio, min_relogio);
					flag_pisca_rel = 0;
				}
				else {
					lv_label_set_text_fmt(labelClock, "%02d %02d", horas_relogio, min_relogio);
					flag_pisca_rel = 1;
				}
			}
			else{
				if (casa_decimal == 0){
					if (flag_pisca_edit == 1){
						lv_label_set_text_fmt(labelTempo, "%02d:%01d ", temp_horas_relogio, temp_min_relogio/10);
						flag_pisca_edit = 0;
					}
					else {
						lv_label_set_text_fmt(labelTempo, "%02d:%02d", temp_horas_relogio, temp_min_relogio);
						flag_pisca_edit = 1;
					}
				}
				else if (casa_decimal == 1){
					if (flag_pisca_edit == 1){
						lv_label_set_text_fmt(labelTempo, "%02d:    %01d ", temp_horas_relogio, temp_min_relogio%10);
						flag_pisca_edit = 0;
					}
					else {
						lv_label_set_text_fmt(labelTempo, "%02d:%02d", temp_horas_relogio, temp_min_relogio);
						flag_pisca_edit = 1;
					}
				}
				else if (casa_decimal == 2){
					if (flag_pisca_edit == 1){
						lv_label_set_text_fmt(labelTempo, "%01d  :%02d ", temp_horas_relogio/10, temp_min_relogio);
						flag_pisca_edit = 0;
					}
					else {
						lv_label_set_text_fmt(labelTempo, "%02d:%02d", temp_horas_relogio, temp_min_relogio);
						flag_pisca_edit = 1;
					}
				}
				else if (casa_decimal == 3){
					if (flag_pisca_edit == 1){
						lv_label_set_text_fmt(labelTempo, "  %01d:%02d ", temp_horas_relogio%10, temp_min_relogio);
						flag_pisca_edit = 0;
					}
					else {
						lv_label_set_text_fmt(labelTempo, "%02d:%02d", temp_horas_relogio, temp_min_relogio);
						flag_pisca_edit = 1;
					}
				}
			}
			xSemaphoreGive(xMutex);
		}
	}
}

/************************************************************************/
/* configs                                                              */
/************************************************************************/

static void configure_lcd(void) {
	/**LCD pin configure on SPI*/
	pio_configure_pin(LCD_SPI_MISO_PIO, LCD_SPI_MISO_FLAGS);  //
	pio_configure_pin(LCD_SPI_MOSI_PIO, LCD_SPI_MOSI_FLAGS);
	pio_configure_pin(LCD_SPI_SPCK_PIO, LCD_SPI_SPCK_FLAGS);
	pio_configure_pin(LCD_SPI_NPCS_PIO, LCD_SPI_NPCS_FLAGS);
	pio_configure_pin(LCD_SPI_RESET_PIO, LCD_SPI_RESET_FLAGS);
	pio_configure_pin(LCD_SPI_CDS_PIO, LCD_SPI_CDS_FLAGS);
	
	ili9341_init();
	ili9341_backlight_on();
}

static void configure_console(void) {
	const usart_serial_options_t uart_serial_options = {
		.baudrate = USART_SERIAL_EXAMPLE_BAUDRATE,
		.charlength = USART_SERIAL_CHAR_LENGTH,
		.paritytype = USART_SERIAL_PARITY,
		.stopbits = USART_SERIAL_STOP_BIT,
	};

	/* Configure console UART. */
	stdio_serial_init(CONSOLE_UART, &uart_serial_options);

	/* Specify that stdout should not be buffered. */
	setbuf(stdout, NULL);
}

/************************************************************************/
/* port lvgl                                                            */
/************************************************************************/

void my_flush_cb(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p) {
	ili9341_set_top_left_limit(area->x1, area->y1);   ili9341_set_bottom_right_limit(area->x2, area->y2);
	ili9341_copy_pixels_to_screen(color_p,  (area->x2 + 1 - area->x1) * (area->y2 + 1 - area->y1));
	
	/* IMPORTANT!!!
	* Inform the graphics library that you are ready with the flushing*/
	lv_disp_flush_ready(disp_drv);
}

void my_input_read(lv_indev_drv_t * drv, lv_indev_data_t*data) {
	int px, py, pressed;
	
	if (readPoint(&px, &py))
		data->state = LV_INDEV_STATE_PRESSED;
	else
		data->state = LV_INDEV_STATE_RELEASED; 
	
	data->point.x = px;
	data->point.y = py;
}

void configure_lvgl(void) {
	lv_init();
	lv_disp_draw_buf_init(&disp_buf, buf_1, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX);
	
	lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
	disp_drv.draw_buf = &disp_buf;          /*Set an initialized buffer*/
	disp_drv.flush_cb = my_flush_cb;        /*Set a flush callback to draw to the display*/
	disp_drv.hor_res = LV_HOR_RES_MAX;      /*Set the horizontal resolution in pixels*/
	disp_drv.ver_res = LV_VER_RES_MAX;
	disp_drv.sw_rotate = 1;
	disp_drv.rotated = LV_DISP_ROT_90;      /*Set the vertical resolution in pixels*/

	lv_disp_t * disp;
	disp = lv_disp_drv_register(&disp_drv); /*Register the driver and save the created display objects*/
	/* Init input on LVGL */
	lv_indev_drv_init(&indev_drv);
	indev_drv.type = LV_INDEV_TYPE_POINTER;
	indev_drv.read_cb = my_input_read;
	lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);
}
void TC_init(Tc * TC, int ID_TC, int TC_CHANNEL, int freq){
	uint32_t ul_div;
	uint32_t ul_tcclks;
	uint32_t ul_sysclk = sysclk_get_cpu_hz();

	/* Configura o PMC */
	pmc_enable_periph_clk(ID_TC);

	/** Configura o TC para operar em  freq hz e interrupçcão no RC compare */
	tc_find_mck_divisor(freq, ul_sysclk, &ul_div, &ul_tcclks, ul_sysclk);
	
	/** ATIVA PMC PCK6 TIMER_CLOCK1  */
	if(ul_tcclks == 0 )
	pmc_enable_pck(PMC_PCK_6);
	
	tc_init(TC, TC_CHANNEL, ul_tcclks | TC_CMR_CPCTRG);
	tc_write_rc(TC, TC_CHANNEL, (ul_sysclk / ul_div) / freq);

	/* Configura NVIC*/
	NVIC_SetPriority(ID_TC, 4);
	NVIC_EnableIRQ((IRQn_Type) ID_TC);
	tc_enable_interrupt(TC, TC_CHANNEL, TC_IER_CPCS);
}
/************************************************************************/
/* main                                                                 */
/************************************************************************/
int main(void) {
	/* board and sys init */
	board_init();
	sysclk_init();
	configure_console();

	/* LCd, touch and lvgl init*/
	configure_lcd();
	configure_touch();
	configure_lvgl();
	xMutex = xSemaphoreCreateMutex();
	xSemaphoreRel = xSemaphoreCreateBinary();
	xSemaphoreCronometro = xSemaphoreCreateBinary();
	/* Create task to control oled */
	if (xTaskCreate(task_lcd, "LCD", TASK_LCD_STACK_SIZE, NULL, TASK_LCD_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed to create lcd task\r\n");
	}
	if (xTaskCreate(task_cronometro, "LCD", TASK_OUTRO_STACK_SIZE, NULL, TASK_OUTRO_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed to create lcd task\r\n");
	}
	
	if (xTaskCreate(task_relogio, "relogio", TASK_OUTRO_STACK_SIZE, NULL, TASK_OUTRO_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed to create relogio task\r\n");
	}
	/* Start the scheduler. */
	vTaskStartScheduler();

	while(1){ }
}
