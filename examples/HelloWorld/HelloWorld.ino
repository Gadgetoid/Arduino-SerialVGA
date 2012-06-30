#include <SerialVGA.h>

#define BAUD_RATE 9600

void setup() {
  SerialVGA vga(BAUD_RATE);
  vga.reboot();
  
  int window_id = 0;     // ID of window, from  0 to 8
                         // SerialVGA supports up to 9 windows
  int window_x = 0;      // Position of window from left
  int window_y = 0;      // Position of window from top
  int window_w = 30;     // Width of the window in characters
  int window_h = 30;     // Height of the window in lines of text
                         // 4 lines will be used for borders/titles
  int window_border = 1; // 1 for show border, 0 for hide
  
  // 64 colours available in base 4 RGB, consisting of 3 digits 0-3
  vga.set_color(0,49,"330","001");
  
  vga.make_window(0,window_x,window_y,window_w,window_h,window_border,"Hello World");
  vga.print("Hello World!");
}

void loop() {
}
