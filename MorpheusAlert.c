// Including necessary header files for AVR operations and delay operations
#include<avr/io.h>
#include<util/delay.h>

// Main function
void main()
 {
	 
// initializing internal variables
 int x=0;
 DDRB=0xFF;
 DDRD=0x00;
 PORTB=0x0A;
 OCR1A=250;
 OCR2=250;
 TCCR1A=0xA1;
 TCCR1B=0X09;
 TCCR2=0X69;
  
 // Running an infinite loop
  while(1)
  {
   // Pin 1 and 2 of port D correspond to the connections to Proximity Sensor and Alcohol Sensor respectively
   // Both these sensors have active low output, thus if either one or both of the pins are low, the car is brought to a halt
   if(bit_is_clear(PIND,1) || bit_is_set(PIND,2))           
	{	
		// The car is too close to another vehicle or the driver is drunk
		// Bringing the car to a halt. Port B is connected to the motor drivers controlling the car
        // The alarm and the warning lights are also turned on as the car is brought to a halt 
		OCR1A=0;
		OCR2=0;
		PORTB=0X60;
	}
	
	// The goggles worn by the driver is connected to Pin 3 of Port D 
	// Checking if the person is sleeping
    else if(bit_is_set(PIND,0))
		{
		  
		  //Person is awake
		  x=0;
		  OCR1A=250;
		  OCR2=250;
		  
		  // The seatbelt detecting sensor is connected to Pin 0 of Port D and is active high. 
		  // Checking if the seatbelt is worn only if the person is awake
		  if(bit_is_clear(PIND,3))
		  // Person has not worn the seatbelt
		  // Ringing the warning alarm
		     PORTB=0x2A;						
		  
		  else
		  //Ideal case : no obstacle, no alcohol, seatbelt worn, driver awake
		  // Car moves ahead
		     PORTB=0x0A;									
		}
	else
		{
		// Person is sleeping 
		// Sound the wake up alarm for 5 seconds
		if(x<=10)                                            
			{
			 PORTB|=(1<<PB5);						
			 _delay_ms(500);						
			 x++;
			 
			 //Check if the driver has opened his eyes
			 if(bit_is_set(PIND,0))
				 // Driver has opened his eyes. Break the loop
				 break;
			}
		else
		//Timer exceeds 5 seconds
			{
			 x=0;
	
			// Check if the car is already halted
			 if((OCR1A>0)&&(OCR2>0))
					{
					
					// Car is moving. Bringing the car to a gradual halt
					for(int i=0;i<25;i++)
						{
						_delay_ms(50);
						OCR1A-=10;
						OCR2-=10;
						
						// Warning lights are turned on as the car is brought to a graduyal halt
						PORTB|=(1<<PB6);                
						}
					
					// The warning alarm rings as the car is brought to a halt
					PORTB|=(1<<PB5);
					}
			}
			
		}
   }
} 
