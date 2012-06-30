/*
    SerialVGA.h - Library for the HobbyTronics Serial VGA driver board
    Created by Philip Howard, July 2012.
*/
#ifndef SerialVGA_h
#define SerialVGA_h

#include "Arduino.h"

class SerialVGA
{
    public:
        SerialVGA(Stream& serial);
        void set_cursor(int x, int y);
        void set_focus(int w);
        void erase_window(int w);
        void toggle_cursor(int w, int onoff);
        void make_window(int id, int x, int y, int w, int h, int b, char *title);
        void set_baud_rate(int baud);
        void reboot();
        void set_color(int startx, int endx, char *fg, char *bg);

        void print(char *text_str);
        void print_inverse(char *text_str);
        void println(char *text_str);
    private:
        int _baud;
        Stream& _serial;
        void send_command(char* command,char *params);
};

#endif
