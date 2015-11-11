# Arduino Pomodoro Timer

A simple Arduino [pomodoro timer](https://en.wikipedia.org/wiki/Pomodoro_Technique) using an [Adafruit 8x8 backpack matrix display](https://www.adafruit.com/products/870).

## How it works

Each minute is represented by a single LED. The LEDs form a 5x5 grid. As the timer counts down, the current minute's LED blinks. After that minute is up, its LED is turned off.  E.g. 10 LEDs on, then there's 10 minutes left.

Pressing the button quickly pauses and unpauses the timer. A paused "icon" shows in the bottom right corner of the display when the timer isn't running.

Long pressing the button (for just over a second) resets the timer back to 25 minutes. 

Once the 25 minutes is up, the display flashes and the piezo buzzer beeps briefly.

## Materials Used

 * Arduino Uno Rev 3
 * 9v battery or USB cable for power
 * Adafruit Mini 8x8 LED Matrix w/I2C Backpack
 * Breadboard
 * Piezo buzzer
 * Push button
 * 10KΩ resistor
 * Wire

## Additional Libraries Used

 * [Adafruit LED Backpack library](https://github.com/adafruit/Adafruit-LED-Backpack-Library)
 * [Adafruit GFX library](https://github.com/adafruit/Adafruit-GFX-Library)


## Wiring Diagram
![Image Wiring diagram](https://s3.amazonaws.com/cairn4/pomodoro_sketch.jpg)
