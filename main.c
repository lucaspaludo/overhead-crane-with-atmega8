#include <avr/io.h>


int main(void)
{
	/*
	
	Entradas: 
	PD2 -> Botão direito
	PD3 -> Botão esquerdo
	PD4 -> Sensor de fim de curso direito
	PD5 -> Sensor de fim de curso esquerdo
	
	*/
	
	//Configurando saídas
	DDRD = (1<<PD0); //Configura o pino PD0 como sáida (motor direito)
	DDRD |= (1<<PD1); //Configura o pino PD1 como saída (motor esquerdo)
	
    while (1) 
    {
		//Liga o motor direito
		if(((PIND&(1<<PD2))!=0) && ((PIND&(1<<PD4))==0)){
			PORTD |= (1<<PD0);
		}
		
		//Desliga o motor direito
		if(((PIND&(1<<PD2))==0) || ((PIND&(1<<PD4))!=0)){
			PORTD &=~(1<<PD0);
		}
		
		//Liga o motor esquerdo
		if(((PIND&(1<<PD3))!=0) && ((PIND&(1<<PD5))==0)){
			PORTD |= (1<<PD1);
		}
		
		//Desliga o motor esquerdo
		if(((PIND&(1<<PD3))==0) || ((PIND&(1<<PD5))!=0)){
			PORTD &=~(1<<PD1);
		}
				
    }
}


