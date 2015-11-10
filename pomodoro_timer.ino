#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

const int buzzerPin = 9;
const int buttonPin = 3;

int prevButtonState = 1;
int buttonState = 1; 

unsigned long startTime;
unsigned long endTime;
unsigned long timeDiff;
const unsigned long longPress = 1200;

boolean timerRunning = false;
const unsigned long second = 1000;
unsigned long secondTimer = 0;
unsigned long lastSecondTick = 0;

int seconds;
int minutes;

int pixelX = 4;
int pixelY = 4;

boolean finished = false;



void setup() {
	pinMode(buzzerPin, OUTPUT);
	pinMode(buttonPin, INPUT);

	matrix.begin(0x70);
	matrix.setBrightness(0);
	matrix.clear();
	matrix.writeDisplay();

	resetDisplay();
	drawPause();
}



void loop() {
	prevButtonState = buttonState;
	buttonState = digitalRead(buttonPin);

	if(buttonState == LOW && prevButtonState == HIGH) {
		startPress();	
	} else if(buttonState == HIGH && prevButtonState == LOW) {
		released();
	}

	if(timerRunning == true) {
		updateTimer();
	}

	matrix.writeDisplay();
}



void startPress() {
	startTime = millis();
}



/* Quickly press and releasing the button = toggle pauses
	Long press = resets the timer back to 25 min */
void released() {
	endTime = millis();

	if(endTime - startTime > longPress) {
		// long press
		resetTimer();
	} else {
		// normal, short press
		if(finished == false) {
			timerRunning = !timerRunning;
        	drawPause();		
		} else {
			resetTimer();
		}			
	}
}



void updateTimer() {
	secondTimer = millis();
	if(secondTimer - lastSecondTick >= second) {
		lastSecondTick = secondTimer;
		seconds++;

		if(seconds == 60) {
			minutes++;
			seconds = 0;

			pixelX--;
			if(pixelX < 0) {
				pixelY--;
				pixelX = 4;
			}
		}

		updateDisplay();
	}

	if(minutes == 25) {
		timerRunning = false;
		finishedTimer();
	}

}



void updateDisplay() {
	if(seconds % 2 == 0) {
		matrix.drawPixel(pixelX, pixelY, LED_ON);  
	} else {
		matrix.drawPixel(pixelX, pixelY, LED_OFF);  
	}
}



void resetTimer() {
	seconds = 0;
	minutes = 0;
	timerRunning = true;

	resetDisplay();
	drawPause();

	finished = false;
}



/* Fill all the timer pixels back in */
void resetDisplay() {
	matrix.clear();

	for(int x = 0; x < 5; x++) {
		for(int y = 0; y < 5; y++) {
			matrix.drawPixel(x, y, LED_ON);  
		}
	}

	pixelX = 4;
	pixelY = 4;
}



/* Flash the display and buzz a tone when the timer is up */
void finishedTimer() {
	finished = true;

	matrix.clear();

	for(int i = 0; i < 5; i++) {
		matrix.drawRect(0,0, 8,8, LED_ON);
		matrix.writeDisplay();

		tone(buzzerPin, 250, 80);

		delay(120);
		matrix.drawRect(0,0, 8,8, LED_OFF);
		matrix.writeDisplay();

		tone(buzzerPin, 300, 80);
		delay(120);
	}
}



void drawPause() {
	boolean p = !timerRunning;
	matrix.drawLine(7,7, 7, 5, p);
	matrix.drawLine(5, 7, 5, 5, p);
}


