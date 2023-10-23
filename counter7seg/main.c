/*
 * main.c
 *
 *  Created on: 23 Oct 2023
 *      Author: 20128
 */




#include"common_macros.h"
#include"std_types.h"
#include"gpio.h"
#include"util/delay.h"
#include "avr\io.h"  /* To use the IO Ports Registers */

uint8 NUMS[] = {
		0x00,
		0x01,
		0x02,
		0x03,
		0x04,
		0x05,
		0x06,
		0x07,
		0x08,
		0x09,
};
void displayDigit(uint8 digit)
{
	GPIO_writePin(PORTB_ID,PIN0_ID,GET_BIT(digit,0));
	GPIO_writePin(PORTB_ID,PIN1_ID,GET_BIT(digit,1));
	GPIO_writePin(PORTB_ID,PIN2_ID,GET_BIT(digit,2));
	GPIO_writePin(PORTB_ID,PIN4_ID,GET_BIT(digit,3));
	//uint8 mask =((PORTB & 0xF0)|(NUMS[digit] & 0x0F));
	//GPIO_writePort(PORTB_ID, mask);  // Display the digit pattern
}


int main(){


	int i,j,k,l,m;


	GPIO_setupPinDirection( PORTB_ID, PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection( PORTB_ID, PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection( PORTB_ID, PIN2_ID,PIN_OUTPUT);
	GPIO_setupPinDirection( PORTB_ID, PIN4_ID,PIN_OUTPUT);


	GPIO_setupPinDirection( PORTB_ID, PIN5_ID,PIN_OUTPUT);
	GPIO_setupPinDirection( PORTB_ID, PIN6_ID,PIN_OUTPUT);
	GPIO_setupPinDirection( PORTA_ID, PIN2_ID,PIN_OUTPUT);
	GPIO_setupPinDirection( PORTA_ID, PIN3_ID,PIN_OUTPUT);

     // initialize the 7-segment with value 0 by clear the 0,1,2,4 four bits
   /* GPIO_writePin( PORTB_ID,  PIN0_ID, 0);
    GPIO_writePin( PORTB_ID,  PIN1_ID, 0);
    GPIO_writePin( PORTB_ID,  PIN2_ID, 0);
    GPIO_writePin( PORTB_ID,  PIN4_ID, 0);
*/



    while(1){

    	for(i=0; i<= 9 ;i++){
    		for(j=0 ;j<=9 ;j++){
    			for(k=0; k<=9 ; k++){
    				for(l=0 ; l<=9 ;l++){
    					for(m=0;m<=15;m++){


    				     GPIO_writePin(PORTA_ID, PIN2_ID, 0);
    				     GPIO_writePin(PORTB_ID, PIN5_ID, 0);
    					 GPIO_writePin(PORTB_ID, PIN6_ID, 0);
    					 GPIO_writePin(PORTA_ID, PIN3_ID, 1);

    					 displayDigit(l);

    					 _delay_ms(10);

    					 GPIO_writePin(PORTA_ID, PIN3_ID, 0);
    					 GPIO_writePin(PORTB_ID, PIN5_ID, 0);
    					 GPIO_writePin(PORTB_ID, PIN6_ID, 0);
    					 GPIO_writePin(PORTA_ID, PIN2_ID, 1);


    					 displayDigit(k);

    				     _delay_ms(10);


    					 GPIO_writePin(PORTA_ID, PIN3_ID, 0);
    					 GPIO_writePin(PORTA_ID, PIN2_ID, 0);
    					 GPIO_writePin(PORTB_ID, PIN6_ID, 0);
    					 GPIO_writePin(PORTB_ID, PIN5_ID, 1);


    					 displayDigit(j);

    				     _delay_ms(5);



    					 GPIO_writePin(PORTA_ID, PIN3_ID, 0);
    					 GPIO_writePin(PORTA_ID, PIN2_ID, 0);
    					 GPIO_writePin(PORTB_ID, PIN5_ID, 0);
    					 GPIO_writePin(PORTB_ID, PIN6_ID, 1);

    					 displayDigit(i);

    				     _delay_ms(5);
    					}
    				}
    			}
    		}
    	}
    }

	return 0;
}
