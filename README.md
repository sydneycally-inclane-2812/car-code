# car-code
Software used on a remote-controlled car, built for a competition. Written and optimized by me and G.L.

## Usage
This code was developed for the Arduino Uno R3 microcontroller, using the L298N H-Bridge motor controller, HC-05 Bluetooth Module and Servo SG90
Pinout for Arduino is as specified in the code. HC-05's TX connects to Serial RX on Uno.

## Controller
This code uses an Android phone, with the application **Bluetooth RC Car** by **Andi.Co.** to send Bluetooth command characters to the UNO. The documentation for which can be found in the app itself.
The Servo can be controlled by toggling Hazards in the app.

## License

Copyright (c) 2023 

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

- The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

**THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.**
