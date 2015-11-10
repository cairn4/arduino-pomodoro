# Arduino Pomodoro Timer

A simple Arduino [pomodoro timer](https://en.wikipedia.org/wiki/Pomodoro_Technique) using an [Adafruit 8x8 backpack matrix display](https://www.adafruit.com/products/870).

## How it works

Each of the 25 minutes is represented by an LED, that form a 5x5 grid. As the timer counts down, the current minute it's on blinks. 

Pressing the button quickly pauses and unpauses the timer. A paused "icon" shows in the bottom right corner of the display when the timer isn't running.

Long pressing the button (for just over a second) resets the timer back to 25 minutes. 

Once the 25 minutes is up, the display flashes and beeps the piezo buzzer.

## Wiring Diagram
![Image Wiring diagram](https://s3.amazonaws.com/cairn4/pomodoro_sketch.jpg)
