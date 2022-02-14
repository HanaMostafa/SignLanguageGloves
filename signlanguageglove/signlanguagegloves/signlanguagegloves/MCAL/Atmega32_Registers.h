/*
 * Atmega32_Registers.h
 *
 * Created: 8/7/2021 12:01:47 AM
 *  Author: Bahaa
 */ 


#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

/************************************** General -Registers *******************************************/
#define SFIOR   (*(volatile unsigned char* const)(0x50))


/************************************** DIO-Registers *******************************************/
#define  PINC    (*(volatile unsigned char* const)0x33 )
#define  DDRC    (*(volatile unsigned char* const)0x34 )
#define  PORTC   (*(volatile unsigned char* const)0x35 )

#define  PINB    (*(volatile unsigned char* const)0x36 )
#define  DDRB    (*(volatile unsigned char* const)0x37 )
#define  PORTB   (*(volatile unsigned char* const)0x38 )

#define  PIND    (*(volatile unsigned char* const)0x30 )
#define  DDRD    (*(volatile unsigned char* const)0x31 )
#define  PORTD   (*(volatile unsigned char* const)0x32 )

#define  PINA    (*(volatile unsigned char* const)0x39 )
#define  DDRA    (*(volatile unsigned char* const)0x3A )
#define  PORTA   (*(volatile unsigned char* const)0x3B )

/************************************** INTERRUPT-Registers *******************************************/

#define SREG    (*(volatile unsigned char* const) (0x5F))
#define GICR    (*(volatile unsigned char* const) (0x5B))
#define GIFR    (*(volatile unsigned char* const) (0x5A))
#define MCUCR   (*(volatile unsigned char* const) (0x55))
#define MCUCSR  (*(volatile unsigned char* const) (0x54))

/************************************** ADC -Registers *******************************************/

#define ADMUX 	(*(volatile unsigned char* const)(0x27))
#define ADCSRA 	(*(volatile unsigned char* const)(0x26))
#define ADCH 	(*(volatile unsigned char* const)(0x25))
#define ADCL 	(*(volatile unsigned char* const)(0x24))


#endif /* ATMEGA32_REGISTERS_H_ */
