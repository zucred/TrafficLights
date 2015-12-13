/*******************************************************************************
  System Initialization for Microstick

  Company:
    Microchip Technology Inc.

  File Name:
    system.c

  Summary:
    This file contains configuration bit definitions for use with the Microstick
    Demo.

  Description:
    This file contains configuration bit definitions for use with the Microstick
    Demo.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END
//

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.
 */
#include "system_config.h"
// *****************************************************************************
// *****************************************************************************
// Section: Configuration Bits
// *****************************************************************************
// *****************************************************************************

//FBS
// BWRP Boot Segment Write Protect
#pragma config BWRP            = WRPROTECT_OFF        //Boot Segment may be written             
// BSS Boot Segment Program Flash Code Protection
#pragma config BSS             = NO_FLASH             //No Boot program Flash segment           
// RBS Boot Segment RAM Protection
#pragma config RBS             = NO_RAM               //No Boot RAM                             
//FSS
// SWRP Secure Segment Program Write Protect
#pragma config SWRP            = WRPROTECT_OFF        //Secure segment may be written           
// SSS Secure Segment Program Flash Code Protection
#pragma config SSS             = NO_FLASH             //No Secure Segment                       
// RSS Secure Segment Data RAM Protection
#pragma config RSS             = NO_RAM               //No Secure RAM                           
//FGS
// GWRP General Code Segment Write Protect
#pragma config GWRP            = OFF                  //User program memory is not write-protected
// GSS General Segment Code Protection
#pragma config GSS             = OFF                  //User program memory is not code-protected

//FOSCSEL
// FNOSC Oscillator Mode
#pragma config FNOSC           = FRCPLL               //Internal Fast RC (FRC) w/ PLL           
// IESO Internal External Switch Over Mode
#pragma config IESO            = OFF                  //Start-up device with user-selected oscillator source

//FOSC
// POSCMD Primary Oscillator Source
#pragma config POSCMD          = NONE                 //Primary Oscillator Disabled             
// OSCIOFNC OSC2 Pin Function
#pragma config OSCIOFNC        = ON                   //OSC2 pin has digital I/O function       
// IOL1WAY Peripheral Pin Select Configuration
#pragma config IOL1WAY         = OFF                  //Allow Multiple Re-configurations        
// FCKSM Clock Switching and Monitor
#pragma config FCKSM           = CSDCMD               //Both Clock Switching and Fail-Safe Clock Monitor are disabled

/*******************************************************************************
 End of File
*/
