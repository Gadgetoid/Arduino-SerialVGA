Arduino SerialVGA
=================

Arduino Library for the Hobbytronics Serial VGA adaptor board

Find it here: http://www.hobbytronics.co.uk/serial-vga

Installing
----------

Since Arduino 1.0.0, libraries can be stored in ~/Documents/Arduino/libraries

Simply drop the files in this repository into ~/Documents/Arduino/libraries/SerialVGA

Usage
-----

SerialVGA accepts any Serial capable object derived from a Stream. Just make sure you've initialised it with begin() or otherwise before passing it to SerialVGA.

If you haven't yet changed the baud rate on your Serial VGA driver board then you should initialize the library with:

```c
#include <SerialVGA.h>

void setup()
{
    Serial.begin(9600)
    
    SerialVGA vga(Serial);
    vga.reboot();
}
```

It's not a bad idea to reboot the board to put it back to a known state in your setup() function.

You can also use SoftwareSerial, simply by passing it in place of Serial:

```c
#include <SerialVGA.h>
#include <SoftwareSerial.h>

void setup()
{
    SoftwareSerial SoftSerial(10,11);
    SoftSerial.begin(9600);

    SerialVGA vga(SoftSerial);
    vga.reboot();
}
```
