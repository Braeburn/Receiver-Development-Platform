/**********************************************************************************************
 * Copyright � 2017 Digital Confections LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software and associated documentation files (the "Software"), to deal in the 
 * Software without restriction, including without limitation the rights to use, copy, 
 * modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, subject to the 
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 *
 **********************************************************************************************
 * ds3231.h
 *
 * DS3231: Extremely Accurate I2C-Integrated RTC/TCXO/Crystal 
 * http://datasheets.maximintegrated.com/en/ds/DS3231-DS3231S.pdf
 * The DS3231 is a low-cost, extremely accurate I2C real-time clock (RTC) with an integrated 
 * temperature-compensated crystal oscillator (TCXO) and crystal. The device incorporates a 
 * battery input, and maintains accurate timekeeping when main power to the device is interrupted. 
 * The integration of the crystal resonator enhances the long-term accuracy of the device as well 
 * as reduces the piece-part count in a manufacturing line. The DS3231 is available in commercial 
 * and industrial temperature ranges, and is offered in a 16-pin, 300-mil SO package.
 *
 */ 

#include "defs.h"

#ifndef DS3231_H_
#define DS3231_H_

#ifdef INCLUDE_DS3231_SUPPORT

#define DS3231_BUS_BASE_ADDR				0xD0  /* corresponds to slave address = 0b1101000x */

typedef enum {
	Minutes_Seconds,
	Hours_Minutes_Seconds,
	Day_Month_Year_Hours_Minutes_Seconds,
	Time_Format_Not_Specified
} TimeFormat;

void ds3231_read_time(int32_t* val, char* buffer, TimeFormat format);
void ds3231_set_time(int32_t offset);
void timeValToString(char *str, int32_t timeVal);

#endif // #ifdef INCLUDE_DS3231_SUPPORT

#endif /* DS3231_H_ */