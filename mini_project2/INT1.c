#include "INT1.h"

ISR (INT1_vect){
	MOTOR_toggle();
}

void INT1_init(){
	DDRD&=~(1<<PB3);
	GICR|=(1<<INT1);
	MCUCR|=(1<<ISC11)|(1<<ISC10);
	SREG|=(1<<7);

}



