/*
 * DIO_prog.c

 *
 *  Created on: Aug 17, 2019
 *      Author: Mariam
 */
#include"../std_types.h"
#include"../Bit_calc.h"

#include"DIO_interface.h"
#include"DIO_regs.h"
/*Author*/
/*date:17/8/2019*/
/*Description: dio driver for avr atmega32*/


/*Description:*/
/*inputs:*/
/*outputs*/

void DIO_vidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{
	if((Copy_u8PortId <= PORTD) && (Copy_u8PinId <= PIN7))
	{
		/**/
		if(Copy_u8Direction== OUTPUT)
		{	switch (Copy_u8PortId)
			{
		case PORTA: SetBit(DDRA_Register, Copy_u8PinId);break;
		case PORTB: SetBit(DDRB_Register, Copy_u8PinId);break;
		case PORTC: SetBit(DDRC_Register, Copy_u8PinId);break;
		case PORTD: SetBit(DDRD_Register, Copy_u8PinId);break;
			}
		}
		else if(Copy_u8Direction==INPUT)
		{
			switch (Copy_u8PortId)
						{
					case PORTA: ClrBit(DDRA_Register, Copy_u8PinId);break;
					case PORTB: ClrBit(DDRB_Register, Copy_u8PinId);break;
					case PORTC: ClrBit(DDRC_Register, Copy_u8PinId);break;
					case PORTD: ClrBit(DDRD_Register, Copy_u8PinId);break;
						}
		}

	}
	else
	{/*error*/

	}
}

void DIO_vidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
	if((Copy_u8PortId <= PORTD) && (Copy_u8PinId <= PIN7))
	{

		if(Copy_u8Value == HIGH)
		{
			switch (Copy_u8PortId)

		{
		case PORTA: SetBit(PORTA_Register, Copy_u8PinId);break;
		case PORTB: SetBit(PORTB_Register, Copy_u8PinId);break;
		case PORTC: SetBit(PORTC_Register, Copy_u8PinId);break;
		case PORTD: SetBit(PORTD_Register, Copy_u8PinId);break;
		}
		}
		else if(Copy_u8Value == LOW)
		{
			switch (Copy_u8PortId)
						{
					case PORTA: ClrBit(PORTA_Register, Copy_u8PinId);break;
					case PORTB: ClrBit(PORTB_Register, Copy_u8PinId);break;
					case PORTC: ClrBit(PORTC_Register, Copy_u8PinId);break;
					case PORTD: ClrBit(PORTD_Register, Copy_u8PinId);break;
						}
		}

	}
	else
	{/*error*/

	}
}

u8   DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{  u8 Local_Result;
		/**/
		switch (Copy_u8PortId)
		{
		case PORTA: Local_Result=GetBit(PINA_Register, Copy_u8PinId);break;
		case PORTB: Local_Result=GetBit(PINB_Register, Copy_u8PinId);break;
		case PORTC: Local_Result=GetBit(PINC_Register, Copy_u8PinId);break;
		case PORTD: Local_Result=GetBit(PIND_Register, Copy_u8PinId);break;
		default: Local_Result=0xFF;
		}
return Local_Result;
	}

void DIO_vidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortValue)
{if(Copy_u8PortId <= PORTD)
{
	switch (Copy_u8PortId)
				{
			case PORTA: DDRA_Register= Copy_u8PortValue;break;
			case PORTB: DDRB_Register= Copy_u8PortValue;break;
			case PORTC: DDRC_Register= Copy_u8PortValue;break;
			case PORTD: DDRD_Register= Copy_u8PortValue;break;
				}
	}

	}

