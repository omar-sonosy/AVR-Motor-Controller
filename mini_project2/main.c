#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
#include "adc.h"
#include "lcd.h"
#include "motor.h"
#include "pwm.h"
#include "INT1.h"



int main(void){
	INT1_init();
	SREG|=(1<<7);
	LCD_init();
	ADC_init();
	MOTOR_init();
	uint16 adc_value;
	uint8 duty_cycle;
	char str[]="ADC value= ";
	MOTOR_clockwise();
	while(1){
		adc_value=ADC_readChannel(0);
		duty_cycle= adc_value/4;
		PWM_Timer0_Init(duty_cycle);
		LCD_displayStringRowColumn(0,0,str);
		LCD_intgerToString(adc_value);
		LCD_displayCharacter(' ');
		LCD_displayCharacter(' ');

	}




	return 0;
}
