/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* USER CODE BEGIN 0 */
#include<math.h>
#define MPU6050_AD 0xd0
extern uint8_t DatoRecibido[15];
extern uint8_t DatoEnviado[2];
extern TIM_HandleTypeDef htim1;
extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart2;
double Y=0;
double u;
float Kp=346;
double Ki=0;
float Kd=9;
double Ref=0.011;
int atras=0;
int adelante=0;
float x[3]={0,0,0};
float pedirDatosMPU();
void motores(double U);
extern uint8_t DatoSerial[1];

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart2;

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles Non maskable interrupt.
*/
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN HardFault_IRQn 1 */

  /* USER CODE END HardFault_IRQn 1 */
}

/**
* @brief This function handles Memory management fault.
*/
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN MemoryManagement_IRQn 1 */

  /* USER CODE END MemoryManagement_IRQn 1 */
}

/**
* @brief This function handles Pre-fetch fault, memory access fault.
*/
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN BusFault_IRQn 1 */

  /* USER CODE END BusFault_IRQn 1 */
}

/**
* @brief This function handles Undefined instruction or illegal state.
*/
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN UsageFault_IRQn 1 */

  /* USER CODE END UsageFault_IRQn 1 */
}

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
* @brief This function handles Debug monitor.
*/
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles TIM3 global interrupt.
*/
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */
//
 Y=pedirDatosMPU();
 x[0]=Ref-Y;
 x[2]=x[0]+x[2];
 u=Kp*x[0]+Ki*(x[2])+Kd*(x[0]-x[1]);
 motores(u);
 x[1]=x[0];
 HAL_GPIO_WritePin(Led_Azul_GPIO_Port,Led_Azul_Pin,GPIO_PIN_SET);

  /* USER CODE END TIM3_IRQn 1 */
}

/**
* @brief This function handles USART2 global interrupt.
*/
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */

  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */
HAL_UART_Receive_IT(&huart2,DatoSerial,1);
if(DatoSerial[0]=='a'){
for(int i=0;i<=110000;i++){

	 	 	 __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,600);
	 	 HAL_GPIO_WritePin(GPIOA,IN1_Pin,GPIO_PIN_RESET);	///MANDAR UNO AL PIN IN1 DEL PUENTE H
	 	 HAL_GPIO_WritePin(GPIOA,IN2_Pin,GPIO_PIN_SET);
	 	 __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,600);
	 	 HAL_GPIO_WritePin(GPIOC,IN3_Pin,GPIO_PIN_RESET);	///MANDAR UNO AL PIN IN1 DEL PUENTE H
	 	 HAL_GPIO_WritePin(GPIOC,IN4_Pin,GPIO_PIN_SET);
	 	HAL_GPIO_WritePin(Led_Azul_GPIO_Port,Led_Azul_Pin,GPIO_PIN_RESET);
}




}
else if(DatoSerial[0]=='b'){
	for(int i=0;i<=110000;i++){
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,600);
	 	HAL_GPIO_WritePin(GPIOA,IN1_Pin,GPIO_PIN_SET);	///MANDAR CERO AL PIN IN1 DEL PUENTE H
	 	HAL_GPIO_WritePin(GPIOA,IN2_Pin,GPIO_PIN_RESET);
	    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,600);
	    HAL_GPIO_WritePin(GPIOC,IN3_Pin,GPIO_PIN_SET);	///MANDAR CERO AL PIN IN1 DEL PUENTE H
	 	HAL_GPIO_WritePin(GPIOC,IN4_Pin,GPIO_PIN_RESET);
	 	HAL_GPIO_WritePin(Led_Azul_GPIO_Port,Led_Azul_Pin,GPIO_PIN_RESET);
	}


}

else if(DatoSerial[0]=='d'){
	for(int i=0;i<=110000;i++){
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,600);
	 	HAL_GPIO_WritePin(GPIOA,IN1_Pin,GPIO_PIN_SET);	///MANDAR CERO AL PIN IN1 DEL PUENTE H
	 	HAL_GPIO_WritePin(GPIOA,IN2_Pin,GPIO_PIN_RESET);
	    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,0);
	    HAL_GPIO_WritePin(GPIOC,IN3_Pin,GPIO_PIN_SET);	///MANDAR CERO AL PIN IN1 DEL PUENTE H
	 	HAL_GPIO_WritePin(GPIOC,IN4_Pin,GPIO_PIN_RESET);
	 	HAL_GPIO_WritePin(Led_Azul_GPIO_Port,Led_Azul_Pin,GPIO_PIN_RESET);
	}


}
else if(DatoSerial[0]=='e'){
	for(int i=0;i<=110000;i++){
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,0);
	 	HAL_GPIO_WritePin(GPIOA,IN1_Pin,GPIO_PIN_SET);	///MANDAR CERO AL PIN IN1 DEL PUENTE H
	 	HAL_GPIO_WritePin(GPIOA,IN2_Pin,GPIO_PIN_RESET);
	    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,600);
	    HAL_GPIO_WritePin(GPIOC,IN3_Pin,GPIO_PIN_SET);	///MANDAR CERO AL PIN IN1 DEL PUENTE H
	 	HAL_GPIO_WritePin(GPIOC,IN4_Pin,GPIO_PIN_RESET);
	 	HAL_GPIO_WritePin(Led_Azul_GPIO_Port,Led_Azul_Pin,GPIO_PIN_RESET);
	}


}

  /* USER CODE END USART2_IRQn 1 */
}

/* USER CODE BEGIN 1 */

float pedirDatosMPU(){
	  float AY;
	  DatoEnviado[0]=0x3B;
	  DatoEnviado[1]=0x00;
	  HAL_I2C_Master_Transmit(&hi2c1,(uint16_t)MPU6050_AD,&DatoEnviado[0],1,100);
	  HAL_I2C_Master_Receive(&hi2c1,(uint16_t)MPU6050_AD,DatoRecibido,14,100);
	  AY=(float)(((int16_t)(DatoRecibido[2]<<8|DatoRecibido[3]))/(float)1638);
	  return AY;
}

void motores(double U){
	if (U < -1500){
		U=-1500;
	}
	if (U >1500){
			U=1500;
			}

	atras=0;
	adelante=0;
	if (U>0){
		adelante=U;       // PWM de los motores atras y adelante (las dos ruedas funcionan al tiempo)
		}
	if (U<0){
		atras =fabs(U);
		}
	if (adelante != 0){
	     if (atras == 0 ){
	    	 __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,adelante);
		 	 HAL_GPIO_WritePin(GPIOA,IN1_Pin,GPIO_PIN_RESET);	///MANDAR UNO AL PIN IN1 DEL PUENTE H
		 	 HAL_GPIO_WritePin(GPIOA,IN2_Pin,GPIO_PIN_SET);
		 	 __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,adelante);
		 	 HAL_GPIO_WritePin(GPIOC,IN3_Pin,GPIO_PIN_RESET);	///MANDAR UNO AL PIN IN1 DEL PUENTE H
		 	 HAL_GPIO_WritePin(GPIOC,IN4_Pin,GPIO_PIN_SET);
	     }
	  }

	if (atras != 0){
		if (adelante == 0){
			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,atras);
		 	HAL_GPIO_WritePin(GPIOA,IN1_Pin,GPIO_PIN_SET);	///MANDAR CERO AL PIN IN1 DEL PUENTE H
		 	HAL_GPIO_WritePin(GPIOA,IN2_Pin,GPIO_PIN_RESET);
		    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,atras);
		    HAL_GPIO_WritePin(GPIOC,IN3_Pin,GPIO_PIN_SET);	///MANDAR CERO AL PIN IN1 DEL PUENTE H
		 	HAL_GPIO_WritePin(GPIOC,IN4_Pin,GPIO_PIN_RESET);
				}
			}
}


/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
