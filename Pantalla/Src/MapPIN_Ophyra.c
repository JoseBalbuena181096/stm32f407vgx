/****************************************************************************************
 * www.intesc.mx
 * Autor: Fernando Q.
 * Este documento realiza el mapeo de los pines de la pantalla TFT conectada a la tarjeta
 * Ophyra.
 * En el proyecto es necesario incluir: MapPIN_Ophyra.h y MapPIN_Ophyra.c y copiar
 * las líneas que acontinuación se muestran en la función principal (main) del proyecto.
 ****************************************************************************************
stOphyraBSP.DELAY_MS           = pfDELAY_MS;
stOphyraBSP.SPI_WRITE          = pfSPI_WRITE;
stOphyraBSP.TFT_CS_GPIO        = pfTFT_CS_GPIO;
stOphyraBSP.TFT_RESET_GPIO     = pfTFT_RESET_GPIO;
stOphyraBSP.TFT_RS_GPIO        = pfTFT_RS_GPIO;
*/
#include "ST7735_Driver.h"
#include "stm32f4xx_hal.h"
#include "MapPIN_Ophyra.h"


/***************************************************************************************
 * Funciones de mapeo de los pines de conexion de la pantalla
 ***************************************************************************************/

ST7735_tenErrCode pfSPI_WRITE (U8* pu8Data, U32 u32Size)
{
	HAL_SPI_Transmit(&hspi1,(uint8_t *)pu8Data, u32Size, 0xFFFFFFFF);

	return ST7735_nenSuccess;
}
ST7735_tenErrCode pfTFT_CS_GPIO(U8 u8State)
{

	if (0 == u8State)
	{
		HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_RESET);
	}
	else if (1 == u8State)
	{
	    HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_SET);
	}
	return ST7735_nenSuccess;
}

ST7735_tenErrCode pfTFT_RS_GPIO(U8 u8State)
{
	if (0 == u8State)
	{
		HAL_GPIO_WritePin(TFT_RS_GPIO_Port, TFT_RS_Pin, GPIO_PIN_RESET);
	}
	else if (1 == u8State)
	{
	    HAL_GPIO_WritePin(TFT_RS_GPIO_Port, TFT_RS_Pin, GPIO_PIN_SET);
	}
	return ST7735_nenSuccess;
}

ST7735_tenErrCode pfTFT_RESET_GPIO(U8 u8state)
{
	if (0 == u8state)
	{
		HAL_GPIO_WritePin(TFT_Reset_GPIO_Port, TFT_Reset_Pin, GPIO_PIN_RESET);
	}
	else if (1 == u8state)
	{
	    HAL_GPIO_WritePin(TFT_Reset_GPIO_Port, TFT_Reset_Pin, GPIO_PIN_SET);
	}
	return ST7735_nenSuccess;
}
ST7735_tenErrCode pfTFT_BACKLIGHT_GPIO(U8 u8state){
	if( 0==u8state ){
		HAL_GPIO_WritePin(TFT_BackLight_GPIO_Port, TFT_BackLight_Pin, GPIO_PIN_RESET);
	}else if( 1== u8state ){
		HAL_GPIO_WritePin(TFT_BackLight_GPIO_Port, TFT_BackLight_Pin, GPIO_PIN_SET);
	}

	return ST7735_nenSuccess;
}

ST7735_tenErrCode pfDELAY_MS(U32 u32Delay)
{
	HAL_Delay(u32Delay);
	return ST7735_nenSuccess;
}
ST7735_tenErrCode TFT_Init(U8 Orientation){
	stOphyraBSP.DELAY_MS           = pfDELAY_MS;
	stOphyraBSP.SPI_WRITE          = pfSPI_WRITE;
	stOphyraBSP.TFT_CS_GPIO        = pfTFT_CS_GPIO;
	stOphyraBSP.TFT_RESET_GPIO     = pfTFT_RESET_GPIO;
	stOphyraBSP.TFT_RS_GPIO        = pfTFT_RS_GPIO;
	ST7735_enRegisterBSP(&stOphyraBSP); //Checa si se realizó la asignacion de patitas correctamente
	ST7735_enInit(Orientation);

	return ST7735_nenSuccess;
}

ST7735_tenErrCode TFT_PrintStr(CHAR *pchString, U32 StrColour, U32 StrBkColour){
	stStrDesc.pchString = pchString;
	stStrDesc.u32StrColour = StrColour;
	stStrDesc.u32StrBkColour = StrBkColour;
	ST7735_enPrintStr(&stStrDesc);

	return ST7735_nenSuccess;
}

ST7735_tenErrCode TFT_GotoXY(U8 XCursor, U8 YCursor){
	stStrDesc.u8XCursor = XCursor;
	stStrDesc.u8Ycursor = YCursor;

	return ST7735_nenSuccess;
}
