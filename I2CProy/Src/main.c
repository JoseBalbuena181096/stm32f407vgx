/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
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
#include "main.h"
#include "stm32f4xx_hal.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include"stdio.h"
#include"string.h"
#include"math.h"
#define MPU6050_AD 0xd0
#define RAD 180.0/3.14//direccion del dispositivo a verificar
//en el datasheet
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

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
  MX_I2C1_Init();
  MX_USART3_UART_Init();
  MX_TIM1_Init();

  /* USER CODE BEGIN 2 */

 uint8_t DatoRecibido[15];//15 registros PARA RECIBIR DATOS
 uint8_t DatoEnviado[2];//Direccion de dispositivo  y el dato
 char bufer[100];
 float AX,AY,AZ,GX,GY,GZ,T;//VARIABLES

 float  Ang[3]={0,0,0};
 float AcANG[2]={0,0};
 float angulos[3]={0,0,0};

 //MPU6050 MANAGER REGITRO PRA
 DatoEnviado[0]=0x6B;//direccion del power managente
 DatoEnviado[1]=0x00;
 HAL_I2C_Master_Transmit(&hi2c1,(uint16_t)MPU6050_AD,DatoEnviado,2,100);

 ///frecuencia de registro

 DatoEnviado[0]=0x19;//dsample rate diviter
 DatoEnviado[1]=0x07; //frecuancia a 1khz

 HAL_I2C_Master_Transmit(&hi2c1,(uint16_t)MPU6050_AD,DatoEnviado,2,100);
 HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
 HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
 HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

	  DatoEnviado[0]=0x3B;//DIRECCION D
	  DatoEnviado[1]=0x00; //YA NO TENGO QUE ENVIAR EL SEGUNNDO DATO

	  HAL_I2C_Master_Transmit(&hi2c1,(uint16_t)MPU6050_AD,&DatoEnviado[0],1,100);
	  //ESCLAVO ENVIA DATOS

	  HAL_I2C_Master_Receive(&hi2c1,(uint16_t)MPU6050_AD,DatoRecibido,14,100);
	  AX=(float)(((int16_t)(DatoRecibido[0]<<8|DatoRecibido[1]))/(float)1638);
	  AY=(float)(((int16_t)(DatoRecibido[2]<<8|DatoRecibido[3]))/(float)1638);
	  AZ=(float)(((int16_t)(DatoRecibido[4]<<8|DatoRecibido[5]))/(float)1638);
	  T=(float)(((int16_t)(DatoRecibido[6]<<8|DatoRecibido[7]))/(float)340+(float)36.53);
	  GX=(float)(((int16_t)(DatoRecibido[8]<<8|DatoRecibido[9]))/(float)131);
	  GY=(float)(((int16_t)(DatoRecibido[10]<<8|DatoRecibido[11]))/(float)131);
	  GZ=(float)(((int16_t)(DatoRecibido[12]<<8|DatoRecibido[13]))/(float)131);

	  AcANG[0]=atan(AX/sqrt(pow(AY,2) + pow(AZ,2)))*RAD;
	  AcANG[1]=atan(AY/sqrt(pow(AX,2) + pow(AZ,2)))*RAD;

	  Ang[0]= 0.9*(Ang[0]+GX*0.01) + 0.1*AcANG[0];
	  Ang[1]= 0.9*(Ang[1]+GY*0.01) + 0.1*AcANG[1];
	  Ang[2]= Ang[2]+GZ*0.01;

	  if(Ang[0]>=0&&Ang[0]<90){
		  angulos[0]=Ang[0]+45+90;
		 __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,angulos[0]);
	  }
	  else if(Ang[0]<0&&Ang[0]>-90){
		  angulos[0]= Ang[0]*(-1)+45;
		  __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,angulos[0]);
	  }
	  if(Ang[1]>=0&&Ang[1]<90){
			  angulos[1]=Ang[1]+45+90;
			 __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,angulos[1]);
		  }
		  else if(Ang[1]<0&&Ang[2]>-90){
			  angulos[1]= Ang[1]*(-1)+45;
			  __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,angulos[1]);
		  }
	  if(Ang[2]>=0&&Ang[2]<90){
			  angulos[2]=Ang[2]+45+90;
			 __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,angulos[2]);
		  }
		  else if(Ang[2]<0&&Ang[2]>-90){
			  angulos[2]= Ang[0]*(-1)+45;
			  __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,angulos[0]);
		  }

	  sprintf(bufer, "Temp=%.2f\n\r,Angulo_X=%.2f\n\r,Angulo_Y=%.2f\n\r,Angulo_Z=%.2f\n\r\n",T,Ang[0],Ang[1],Ang[2]);
	  HAL_UART_Transmit(&huart3,(uint8_t*)bufer,(uint16_t)strlen(bufer),(uint32_t)100);
	  HAL_Delay(10);
  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
