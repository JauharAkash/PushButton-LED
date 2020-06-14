//Akash Jauhar
// pushBotton.h 
//header file

#include <bcm2835.h>
#include <stdio.h>

//Defining the pins and the button
#define PIN RPI_V2_GPIO_P1_11  //Led #1
#define PIN2 RPI_V2_GPIO_P1_13 //Led #2
// Input on RPi pin GPIO 15
#define PIN3 RPI_GPIO_P1_15  //Button
// Prototyping
int main(int argc, char **argv);
int readButtonPress(int pin);
void blink(int pin, int counter);


 int counter = 0;
    void blink(int pin, int counter){
	for(int i = 0; i<counter; i++){
	// blinking led light alternatively
        // Turn PIN On
        bcm2835_gpio_write(pin, HIGH);
        // wait a bit
        bcm2835_delay(500);
        // Turn PIN Off
        bcm2835_gpio_write(pin, LOW);
        // wait a bit
        bcm2835_delay(500);

    }
}

	int readButtonPress(int pin){
	    for(int i = -1; i<counter; i++){
		if(bcm2835_gpio_lev(PIN3) == 0){
		    printf("Button Pressed\n");
		    counter = counter + 1;
		    bcm2835_delay(100);
		}
	    return counter;
	}
    
    }
