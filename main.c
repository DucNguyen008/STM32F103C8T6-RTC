/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

TIM_HandleTypeDef htim1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */
RTC_TimeTypeDef sTime = {0};
RTC_DateTypeDef DateToUpdate = {0};
//RTC_TimeTypeDef sTime;
//RTC_DateTypeDef DateToUpdate;

uint8_t Second;
uint8_t Minute;
uint8_t Hour;
uint8_t Datev;
uint8_t Dayv;
uint8_t Monthv;
uint8_t Yearv;



/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//void letter(){
int colon[] =  { 1,1,1,1,1,1,1,1,
		   	   	 1,1,0,1,1,0,1,1,
				 1,1,1,1,1,1,1,1};
int error[] =  {   1,1,1,1,1,1,1,1,
		   	   	   0,1,1,0,0,0,0,0,
				   1,1,1,1,1,1,1,1};

int A[] =  { 1,0,0,0,0,0,1,1,
         1,1,1,1,0,1,0,1,
		 1,1,1,1,0,1,1,0,
		 1,1,1,1,0,1,0,1,
		 1,0,0,0,0,0,1,1};

int B[] =  { 1,0,0,0,0,0,0,0,
         1,0,1,1,0,1,1,0,
		 1,0,1,1,0,1,1,0,
		 1,0,1,1,0,1,1,0,
		 1,1,0,0,1,0,0,1};

int C[] =  { 1,1,0,0,0,0,0,1,
         1,0,1,1,1,1,1,0,
		 1,0,1,1,1,1,1,0,
		 1,0,1,1,1,1,1,0,
		 1,1,0,1,1,1,0,1};

int D[] =  { 1,0,0,0,0,0,0,0,
         1,0,1,1,1,1,1,0,
		 1,0,1,1,1,1,1,0,
		 1,0,1,1,1,1,1,0,
		 1,1,0,0,0,0,0,1};

int E[] =  { 1,0,0,0,0,0,0,0,
         1,0,1,1,0,1,1,0,
		 1,0,1,1,0,1,1,0,
		 1,0,1,1,0,1,1,0,
		 1,0,1,1,0,1,1,0};

int F[] =  { 1,0,0,0,0,0,0,0,
         1,1,1,1,0,1,1,0,
		 1,1,1,1,0,1,1,0,
		 1,1,1,1,0,1,1,0,
		 1,1,1,1,0,1,1,0};

int G[] =  { 1,1,0,0,0,0,0,1,
         1,0,1,1,1,1,1,0,
		 1,0,1,0,0,1,1,0,
		 1,0,1,1,0,1,1,0,
		 1,1,0,0,0,1,0,1};

int H[] =  { 1,0,0,0,0,0,0,0,
         1,1,1,1,0,1,1,1,
		 1,1,1,1,0,1,1,1,
		 1,1,1,1,0,1,1,1,
		 1,0,0,0,0,0,0,0};

int I[] =  { 1,0,1,1,1,1,1,0,
         1,0,1,1,1,1,1,0,
		 1,0,0,0,0,0,0,0,
		 1,0,1,1,1,1,1,0,
		 1,0,1,1,1,1,1,0};

int J[] =  { 1,1,0,0,1,1,1,0,
         1,0,1,1,1,1,1,0,
		 1,0,0,0,0,0,0,0,
		 1,1,1,1,1,1,1,0,
		 1,1,1,1,1,1,1,0};

int K[] =  { 1,0,0,0,0,0,0,0,
         1,1,1,1,0,1,1,1,
		 1,1,1,0,1,0,1,1,
		 1,1,0,1,1,1,0,1,
		 1,0,1,1,1,1,1,0};

int L[] =  { 1,0,0,0,0,0,0,0,
         1,0,1,1,1,1,1,1,
		 1,0,1,1,1,1,1,1,
		 1,0,1,1,1,1,1,1,
		 1,0,1,1,1,1,1,1};

int M[] =  { 1,0,0,0,0,0,0,0,
         1,1,1,1,1,1,0,1,
		 1,1,1,1,1,0,1,1,
		 1,1,1,1,1,1,0,1,
		 1,0,0,0,0,0,0,0};

int N[] =  { 1,0,0,0,0,0,0,0,
         1,1,1,1,1,0,0,1,
		 1,1,1,1,0,1,1,1,
		 1,1,0,0,1,1,1,1,
		 1,0,0,0,0,0,0,0};

int O[] =  { 1,1,0,0,0,0,0,1,
         1,0,1,1,1,1,1,0,
		 1,0,1,1,1,1,1,0,
		 1,0,1,1,1,1,1,0,
		 1,1,0,0,0,0,0,1};

int P[] =  { 1,0,0,0,0,0,0,0,
         1,1,1,1,0,1,1,0,
		 1,1,1,1,0,1,1,0,
		 1,1,1,1,0,1,1,0,
		 1,1,1,1,1,0,0,1};

int Q[] =  { 1,1,0,0,0,0,0,1,
         1,0,1,1,1,1,1,0,
		 1,0,1,0,1,1,1,0,
		 1,1,0,1,1,1,1,0,
		 1,0,1,0,0,0,0,1};

int R[] =  { 1,0,0,0,0,0,0,0,
         1,1,1,1,0,1,1,0,
		 1,1,1,0,0,1,1,0,
		 1,1,0,1,0,1,1,0,
		 1,0,1,1,1,0,0,1};

int S[] =  { 1,1,0,1,1,0,0,1,
         1,0,1,1,0,1,1,0,
		 1,0,1,1,0,1,1,0,
		 1,0,1,1,0,1,1,0,
		 1,1,0,0,1,1,0,1};

int T[] =  { 1,1,1,1,1,1,1,0,
         1,1,1,1,1,1,1,0,
		 1,0,0,0,0,0,0,0,
		 1,1,1,1,1,1,1,0,
		 1,1,1,1,1,1,1,0};

int U[] =  { 1,1,0,0,0,0,0,0,
         1,0,1,1,1,1,1,1,
		 1,0,1,1,1,1,1,1,
		 1,0,1,1,1,1,1,1,
		 1,1,0,0,0,0,0,0};

int V[] =  { 1,1,1,1,0,0,0,0,
         1,1,0,0,1,1,1,1,
		 1,0,1,1,1,1,1,1,
		 1,1,0,0,1,1,1,1,
		 1,1,1,1,0,0,0,0};

int W[] =  { 1,1,0,0,0,0,0,0,
         1,0,1,1,1,1,1,1,
		 1,1,0,0,0,0,0,1,
		 1,0,1,1,1,1,1,1,
		 1,1,0,0,0,0,0,0};

int X[] =  { 1,0,0,1,1,1,0,0,
         1,1,1,0,1,0,1,1,
		 1,1,1,1,0,1,1,1,
		 1,1,1,0,1,0,1,1,
		 1,0,0,1,1,1,0,0};

int Y[] =  { 1,1,1,1,1,1,0,0,
         1,1,1,1,1,0,1,1,
		 1,0,0,0,0,1,1,1,
		 1,1,1,1,1,0,1,1,
		 1,1,1,1,1,1,0,0};

int Z[] =  { 1,0,0,1,1,1,1,0,
         1,0,1,0,1,1,1,0,
		 1,0,1,1,0,1,1,0,
		 1,0,1,1,1,0,1,0,
		 1,0,1,1,1,1,0,0};

int ONE[] =  { 1,1,1,1,1,1,1,1,
           1,0,1,1,1,1,0,1,
		   1,0,0,0,0,0,0,0,
		   1,0,1,1,1,1,1,1,
		   1,1,1,1,1,1,1,1};

int TWO[] =  { 1,0,1,1,1,1,0,1,
           1,0,0,1,1,1,1,0,
		   1,0,1,0,1,1,1,0,
		   1,0,1,1,0,1,1,0,
		   1,0,1,1,1,0,0,1};

int THREE[] =  { 1,1,0,1,1,1,0,1,
             1,0,1,1,0,1,1,0,
			 1,0,1,1,0,1,1,0,
			 1,0,1,1,0,1,1,0,
			 1,1,0,0,1,0,0,1};

int FOUR[] =  { 1,1,1,0,0,1,1,1,
            1,1,1,0,1,0,1,1,
			1,1,1,0,1,1,0,1,
			1,0,0,0,0,1,1,0,
			1,1,1,0,1,1,1,1};

int FIVE[] =  { 1,1,0,1,1,0,0,0,
            1,0,1,1,0,1,1,0,
			1,0,1,1,0,1,1,0,
			1,0,1,1,0,1,1,0,
			1,1,0,0,1,1,1,0};

int SIX[] =  { 1,1,0,0,0,0,0,1,
           1,0,1,1,0,1,1,0,
		   1,0,1,1,0,1,1,0,
		   1,0,1,1,0,1,1,0,
		   1,1,0,0,1,1,1,0};

int SEVEN[] =  { 1,1,1,1,1,1,1,0,
             1,1,1,1,1,1,1,0,
			 1,0,0,0,0,1,1,0,
			 1,1,1,1,1,0,1,0,
			 1,1,1,1,1,1,0,0};

int EIGHT[] =  { 1,1,0,0,0,0,0,1,
             1,0,1,1,0,1,1,0,
			 1,0,1,1,0,1,1,0,
			 1,0,1,1,0,1,1,0,
			 1,1,0,0,0,0,0,1};

int NINE[] =  { 1,1,1,1,1,0,0,1,
            1,0,1,1,0,1,1,0,
			1,0,1,1,0,1,1,0,
			1,0,1,1,0,1,1,0,
			1,1,0,0,0,0,0,1};
int space[] = { 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1};
//}
void delay_us (uint32_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1,0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);  // wait for the counter to reach the us input in the parameter
}

void PrintLetter5Line(int t[])
{
	int m = 0;
	for(int i = 0; i<5; i++)
	{
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, t[m]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, t[m+1]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, t[m+2]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, t[m+3]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, t[m+4]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, t[m+5]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, t[m+6]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, t[m+7]);

		  m = m + 8;
		  delay_us(100);
	}
}
void PrintLetter3Line(int t[])
{
	int m = 0;
	for(int i = 0; i<3; i++)
	{
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, t[m]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, t[m+1]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, t[m+2]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, t[m+3]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, t[m+4]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, t[m+5]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, t[m+6]);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, t[m+7]);

		  m = m + 8;
		  delay_us(100);
	}
}
//void Display_space(int t[])
//{
//	int m = 0;
//	for(int i = 0; i<5; i++)
//	{
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, t[m]);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, t[m+1]);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, t[m+2]);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, t[m+3]);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, t[m+4]);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, t[m+5]);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, t[m+6]);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, t[m+7]);
//
//		  m = m + 8;
//		  delay_us(156);
//	}
//}

//uint16_t time_per_deg = 21000/360;
// one rotate time = 21 000 us

int State = 1; // HALL SENSOR SENSED FLAG
int lastState = 1; // HALL SENSOR SENSED FLAG LAST SCAN
//  uint32_t count;
long c=0;
int h1, h2, m1, m2, s1;
int s2 = 18;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
//	HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
//	sTime.Hours = 12;
//	sTime.Minutes = 1;
//	sTime.Seconds = 16;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  HAL_RTC_Init(&hrtc);
  HAL_TIM_Base_Start(&htim1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  	  HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
  	  HAL_RTC_GetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BIN);
	  Hour = sTime.Hours;
      Minute = sTime.Minutes;
	  Second = sTime.Seconds;
	  Datev = DateToUpdate.Date;
	  Dayv = DateToUpdate.WeekDay;
	  Monthv = DateToUpdate.Month;
	  Yearv = DateToUpdate.Year;
	  h1 = Hour/10;
	  h2 = Hour%10;
	  m1 = Minute/10;
	  m2 = Minute%10;
	  s1 = Second/10;
	  s2 = Second%10;

  	  State = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11);
  	  if (State != lastState){
  	    if (State == 0) {
//  	  	    if (Second%2==1) {
//  					PrintLetter3Line(space);
//  					PrintLetter5Line(U);
//  					PrintLetter3Line(space);
//  						PrintLetter5Line(I);
//  						PrintLetter3Line(space);
//  	  					PrintLetter5Line(I);
//  	  					PrintLetter3Line(space);
////  	  	    	}
//  	  	    if (Second%2==0) {
//  					  PrintLetter3Line(space);
//  					PrintLetter5Line(FOUR);
//  					PrintLetter3Line(space);
//  						PrintLetter5Line(FIVE);
//  						PrintLetter3Line(space);
//  	  					PrintLetter5Line(SIX);
//  	  					PrintLetter3Line(space);
//  	  	    	}
  	    	if(h1==0){
  	    		PrintLetter5Line(O);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h1==1){
  	    		PrintLetter5Line(ONE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h1==2){
  	    		PrintLetter5Line(TWO);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h1==3){
  	    		PrintLetter5Line(THREE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h1==4){
  	    		PrintLetter5Line(FOUR);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h1==5){
  	    		PrintLetter5Line(FIVE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h1==6){
  	    		PrintLetter5Line(SIX);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h1==7){
  	    		PrintLetter5Line(SEVEN);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h1==8){
  	    		PrintLetter3Line(space);
  	    		PrintLetter5Line(EIGHT);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h1==9){
  	    		PrintLetter5Line(NINE);
  	    		PrintLetter3Line(space);
  	    	}
  	      //Display first number of Hours



//  	      //Display space
//  	      PrintLetter3Line(space);
//  	      //Display second number of Hours
  	    	if(h2==0){
  	    		PrintLetter5Line(O);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h2==1){
  	    		PrintLetter5Line(ONE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h2==2){
  	    		PrintLetter5Line(TWO);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h2==3){
  	    		PrintLetter5Line(THREE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h2==4){
  	    		PrintLetter5Line(FOUR);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h2==5){
  	    		PrintLetter5Line(FIVE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h2==6){
  	    		PrintLetter3Line(space);
  	    		PrintLetter5Line(SIX);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h2==7){
  	    		PrintLetter5Line(SEVEN);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h2==8){
  	    		PrintLetter3Line(space);
  	    		PrintLetter5Line(EIGHT);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(h2==9){
  	    		PrintLetter5Line(NINE);
  	    		PrintLetter3Line(space);
  	    	}
//  	      //Display colon
  	      PrintLetter3Line(colon);
//  	      //Display first number of Minute
  	    	if(m1==0){
  	    		PrintLetter3Line(space);
  	    		PrintLetter5Line(O);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m1==1){

  	    		PrintLetter5Line(ONE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m1==2){

  	    		PrintLetter5Line(TWO);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m1==3){

  	    		PrintLetter5Line(THREE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m1==4){

  	    		PrintLetter5Line(FOUR);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m1==5){

  	    		PrintLetter5Line(FIVE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m1==6){

  	    		PrintLetter5Line(SIX);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m1==7){

  	    		PrintLetter5Line(SEVEN);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m1==8){

  	    		PrintLetter5Line(EIGHT);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m1==9){

  	    		PrintLetter5Line(NINE);
  	    		PrintLetter3Line(space);
  	    	}
//  	      //Display space
//  	      PrintLetter3Line(space);
//  	      //Display second number of Minute
  	    	if(m2==0){

  	    		PrintLetter5Line(O);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m2==1){

  	    		PrintLetter5Line(ONE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m2==2){

  	    		PrintLetter5Line(TWO);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m2==3){

  	    		PrintLetter5Line(THREE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m2==4){

  	    		PrintLetter5Line(FOUR);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m2==5){

  	    		PrintLetter5Line(FIVE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m2==6){

  	    		PrintLetter5Line(SIX);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m2==7){

  	    		PrintLetter5Line(SEVEN);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m2==8){

  	    		PrintLetter5Line(EIGHT);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(m2==9){

  	    		PrintLetter5Line(NINE);
  	    		PrintLetter3Line(space);
  	    	}
//  	      //Display colon
  	      PrintLetter3Line(colon);
//  	      //Display first number of Seconds
  	    	if(s1==0){
  	    		PrintLetter3Line(space);
  	    		PrintLetter5Line(O);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s1==1){

  	    		PrintLetter5Line(ONE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s1==2){

  	    		PrintLetter5Line(TWO);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s1==3){

  	    		PrintLetter5Line(THREE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s1==4){

  	    		PrintLetter5Line(FOUR);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s1==5){

  	    		PrintLetter5Line(FIVE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s1==6){

  	    		PrintLetter5Line(SIX);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s1==7){

  	    		PrintLetter5Line(SEVEN);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s1==8){

  	    		PrintLetter5Line(EIGHT);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s1==9){

  	    		PrintLetter5Line(NINE);
  	    		PrintLetter3Line(space);
  	    	}
//  	      //Display space
//  	      PrintLetter3Line(space);
//  	      //Display second number of Seconds
  	    	if(s2==0){

  	    		PrintLetter5Line(O);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s2==1){

  	    		PrintLetter5Line(ONE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s2==2){

  	    		PrintLetter5Line(TWO);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s2==3){

  	    		PrintLetter5Line(THREE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s2==4){

  	    		PrintLetter5Line(FOUR);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s2==5){

  	    		PrintLetter5Line(FIVE);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s2==6){

  	    		PrintLetter5Line(SIX);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s2==7){

  	    		PrintLetter5Line(SEVEN);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s2==8){

  	    		PrintLetter5Line(EIGHT);
  	    		PrintLetter3Line(space);
  	    	}
  	    	if(s2==9){

  	    		PrintLetter5Line(NINE);
  	    		PrintLetter3Line(space);
  	    	}
  	    }
//  	    else if(State==1) {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
//                |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, 0);}
  	    lastState = State;
  	  }

  	//count = count + 1;
  	 //if(__HAL_TIM_GET_COUNTER(&htim2) > 2000000) {__HAL_TIM_SET_COUNTER(&htim2,0);}

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef DateToUpdate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
  hrtc.Init.OutPut = RTC_OUTPUTSOURCE_ALARM;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2);
  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 12;
  sTime.Minutes = 1;
  sTime.Seconds = 16;

  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  DateToUpdate.WeekDay = RTC_WEEKDAY_MONDAY;
  DateToUpdate.Month = RTC_MONTH_DECEMBER;
  DateToUpdate.Date = 28;
  DateToUpdate.Year = 20;

  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 72-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 0xffff-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_SET);

  /*Configure GPIO pin : PB11 */
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB14 PB3 PB4 PB5
                           PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hrtc);
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_RTC_AlarmAEventCallback could be implemented in the user file
   */

	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
