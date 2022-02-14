/*
 * signlanguagegloves.c
 *
 * Created: 12-Feb-22 7:53:33 PM
 * Author : hanamostafa
 */ 

#include <avr/io.h>
#include "Common/DataType.h"
#include "Common/BitMath.h"
#include "ECU/LCD/LCD.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/DIO/DIO.h"


int main(void)
{
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALLER_8);
	float ADCValue;
	float R1=0;
	float R2=0;
	float R3=0;
	float R4=0;
	float R5=0;
	
    while (1) 
    {
		// we will use 4 channels only in this project so will neglect a finger as it's not used much in this project
		//
		
		R1=ADC_ReadChannel_Block(0)/4.8;	//Read from channel 0
		R2=ADC_ReadChannel_Block(1)/4.8;	//Read from channel 1
		R3=ADC_ReadChannel_Block(2)/4.8;	//Read from channel 2
		R4=ADC_ReadChannel_Block(3)/4.8;	//Read from channel 3
		//R5=ADC_ReadChannel_Block(4)/4.8;
		
		
		//to check the sensor's threshold resistance 
		/*
		LCD_Clear();
		ADCValue = ADC_ReadChannel_Block(2)/4.8;     //214 
		LCD_WriteNumbers(ADCValue);
		*/
		
		float RTh1=214.0;	//Put the threshold resistance 
		float RTh2=214.0;	
		float RTh3=214.0;
		float RTh4=214.0;
		//float RTh5=214.0;
		
		if (R1 > RTh1 && R2 < RTh2 && R3 < RTh3 && R4 > RTh4 ) {
			LCD_Clear();
			LCD_WriteString("Peace!");
			break;
		}
		else if (R1 < RTh1 && R2 < RTh2 && R3 > RTh3 && R4 < RTh4 ) {
			LCD_Clear();
			LCD_WriteString("I love You ");
			break;
		}
		else if (R1 > RTh1 && R2 < RTh2 && R3 > RTh3 && R4 > RTh4 ) {
			LCD_Clear();
			LCD_WriteString("You !");
			break;
		}
		else if (R1 < RTh1 && R2 > RTh2 && R3 > RTh3 && R4 > RTh4 ) {
			LCD_Clear();
			LCD_WriteString("OK");
			break;
		}
		else if (R1 > RTh1 && R2 < RTh2 && R3 > RTh3 && R4 < RTh4 ) {
			LCD_Clear();
			LCD_WriteString("Great !");
			break;
		}

		else if (R1 < RTh1 && R2 < RTh2 && R3 < RTh3 && R4 < RTh4 ) {
			LCD_Clear();
			LCD_WriteString("Stop Please!");
			break;
		}
		else{
			LCD_WriteString("Nothing Done !!");
			break;
		}

    }
}

