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

If you haven't yet changed the baud rate on your Serial VGA driver board then you should initialize the library with:

```c
#include <SerialVGA.h>

void setup()
{
    SerialVGA vga(9600);
    vga.reboot();
}
```

It's not a bad idea to reboot the board to put it back to a known state in your setup() function.
