// input.c
//
// Akash Jauhar 
// CSC155: Assignment - push button
// 
// Example program for bcm2835 library
// Reads and prints the state of an input pin
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o input input.c -l bcm2835
// sudo ./input
//
// Or you can test it before installing with:
// gcc -o input -I ../../src ../../src/bcm2835.c input.c
// sudo ./input
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
/*
#include <bcm2835.h>
#include <stdio.h>

//Defining the pins and the button
#define PIN RPI_V2_GPIO_P1_11  //Led #1
#define PIN2 RPI_V2_GPIO_P1_13 //Led #2
// Input on RPi pin GPIO 15
#define PIN3 RPI_GPIO_P1_15  //Button
*/
#include "pushButton.h"

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
//    bcm2835_set_debug(1);

    if (!bcm2835_init())
	return 1;

    // Set RPI pin P1-15 to be an input
    bcm2835_gpio_fsel(PIN3, BCM2835_GPIO_FSEL_INPT);
    //  with a pullup
    bcm2835_gpio_set_pud(PIN3, BCM2835_GPIO_PUD_UP);
    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);
    // Blink
    int counter = 0;
    while (1) {
	// Read some data
	uint8_t value = bcm2835_gpio_lev(PIN3);
	printf("read from pin 15: %d\n", value);
	
	// Funtion to read the button and keep a counter
	int readButtonPress(int pin){
	    for(int i = -1; i<counter; i++){
		if(bcm2835_gpio_lev(PIN3) == 0){ //Part 1 - reading the button output
		    printf("Button Pressed\n"); ////Part 1 - reading the button output
		    counter = counter + 1;
		    bcm2835_delay(100);
		}
	    return counter;
	}
    
    }
		
	// wait a bit
	delay(500);
    
    // Blink function used to light the LEDs depending on the button input
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

//Switch statements to make the LED light depending on how many times the button is pressed
    switch (counter){
	case 1: blink(PIN, 1);
		break;
	case 2: blink(PIN2, 1);
		break;
	case 3: blink(PIN, 1);
		blink(PIN2, 1);
		break;
	}

readButtonPress(PIN3);
}
    bcm2835_close();
    return 0;
}

