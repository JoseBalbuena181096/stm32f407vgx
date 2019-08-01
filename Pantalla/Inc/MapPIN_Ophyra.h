/*www.intesc.mx
 * Autro: Fernando Q.
 * Este documento realiza el mapeo de los pines de la pantalla TFT conectada a la tarjeta
 * Ophyra.
 * En el proyecto es necesario incluir: MapPIN_Ophyra.h y MapPIN_Ophyra.c y copiar
 * las líneas que acontinuación se muestran en la función principal (main) del proyecto.
 ****************************************************************************************

:libLibTFT.a
"${workspace_loc:/${ProjName}/Src}"

#include "Intesc_Stdr_Types.h"
#include "ST7735_Driver.h"
#include "MapPIN_Ophyra.h"

stOphyraBSP.DELAY_MS           = pfDELAY_MS;
stOphyraBSP.SPI_WRITE          = pfSPI_WRITE;
stOphyraBSP.TFT_CS_GPIO        = pfTFT_CS_GPIO;
stOphyraBSP.TFT_RESET_GPIO     = pfTFT_RESET_GPIO;
stOphyraBSP.TFT_RS_GPIO        = pfTFT_RS_GPIO;
 * MapPIN_Ophyra.h
 *
 *  Created on: 07/12/2017
 *      Author: Fernando
 */

#ifndef MAPPIN_OPHYRA_H_
#define MAPPIN_OPHYRA_H_
/* Language linkage */
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#include "Intesc_Stdr_Types.h"
#include "stm32f4xx_hal.h"
#define TFT_BackLight 		  pfTFT_BACKLIGHT_GPIO

SPI_HandleTypeDef hspi1;
ST7735_tenErrCode 	pfSPI_WRITE (U8* pu8Data, U32 u32Size);
ST7735_tenErrCode 	pfTFT_CS_GPIO(U8 u8State);
ST7735_tenErrCode 	pfTFT_RS_GPIO(U8 u8State);
ST7735_tenErrCode 	pfTFT_RESET_GPIO(U8 u8state);
ST7735_tenErrCode 	pfTFT_BACKLIGHT_GPIO(U8 u8state);
ST7735_tenErrCode 	pfDELAY_MS(U32 u32Delay);


/******************************************************************************
* \brief  initialization of TFT screen of Ophyra
* \param[in] Orientation: This is a integer. Set display orientation of screen.
* 											 0 = horizontal orientation.
* 											 1 = vertical orientation.
* \return Error code.
* \note   Is necessary register BSP before initializer this module
********************************************************************************/
ST7735_tenErrCode 	TFT_Init(U8 Orientation);

/******************************************************************************
*\brief:  This function print a string into screen.
*\param[in] pchString: This is a pointer to contain a string vector.
*           StrColour: Set colour font; Format: U32 (0x000000)
*         StrBKColour: Set the colour back side of font; Format: U32 (0x000000)
*           		   if parameter is NULL, then back side is transparent.
*\return Error code
******************************************************************************/
ST7735_tenErrCode 	TFT_PrintStr(CHAR *pchString, U32 StrColour, U32 StrBkColour);

/******************************************************************************
 * brief: This function put screen`s cursor in XY coordenates.
 * param[in] XCursor, YCursor:  Those are pointers to indicate position
 * 							   in the screen.
 * return: Error code.
 ******************************************************************************/
ST7735_tenErrCode 	TFT_GotoXY(U8 XCursor, U8 YCursor);
/*
 * Definition of structures objects
 */
ST7735_tstStrDesc 	stStrDesc;
ST7735_tstBSPDriver stOphyraBSP;
#endif /* MAPPIN_OPHYRA_H_ */
