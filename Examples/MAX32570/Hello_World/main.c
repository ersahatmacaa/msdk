/******************************************************************************
 * Copyright (C) 2022 Maxim Integrated Products, Inc., All rights Reserved.
 * 
 * This software is protected by copyright laws of the United States and
 * of foreign countries. This material may also be protected by patent laws
 * and technology transfer regulations of the United States and of foreign
 * countries. This software is furnished under a license agreement and/or a
 * nondisclosure agreement and may only be used or reproduced in accordance
 * with the terms of those agreements. Dissemination of this information to
 * any party or parties not specified in the license agreement and/or
 * nondisclosure agreement is expressly prohibited.
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *
 ******************************************************************************/

/**
 * @file    main.c
 * @brief   Hello World!
 *
 * @details This example uses the UART to print to a terminal and flashes an LED1.
 */

/***** Includes *****/
#include <stdio.h>
#include <stdint.h>

#include <MAX32xxx.h>

#include "bitmap.h"

/***** Definitions *****/

/***** Globals *****/

/***** Functions *****/

// *****************************************************************************
int main(void)
{
    int count = 0;
    printf("\n***********Hello World!***********\n");
    printf("\nLED1 toggles every 500 ms\n");
    
    // initialize display
    MXC_TFT_Init();
    
    // Display image
    MXC_TFT_ShowImage(65, 140, maxim_big_logo_bmp);  // display image on screen
    // Update palette, Use palette from logo_white_bg_white_bmp
    MXC_TFT_SetPalette(logo_white_bg_white_bmp);
    // set up font
    MXC_TFT_SetFont(urw_gothic_13_grey_bg_white);
    
    // Set print area
    area_t print = {10, 20, 300, 85};
    MXC_TFT_ConfigPrintf(&print);
    
    while (1) {
        LED_On(0);
        MXC_Delay(500000);
        LED_Off(0);
        MXC_Delay(500000);
        
        // print on display
        MXC_TFT_Printf("Counter = %d\n", count);
        // print on console
        printf("\nCounter = %d", count++);
    }
}