/*
    SerialVGA.h - Library for the HobbyTronics Serial VGA driver board
    Created by Philip Howard, July 2012.
*/
#ifndef SerialVGA_h
#define SerialVGA_h

#include "Arduino.h"
#include "Stream.h"

#define CURSOR_ON   1
#define CURSOR_OFF  0


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

        size_t print(const __FlashStringHelper *);
        size_t print(const String &);
        size_t print(const char[]);
        size_t print(char);
        size_t print(unsigned char, int = DEC);
        size_t print(int, int = DEC);
        size_t print(unsigned int, int = DEC);
        size_t print(long, int = DEC);
        size_t print(unsigned long, int = DEC);
        size_t print(double, int = 2);
        size_t print(const Printable&);

        size_t println(const __FlashStringHelper *);
        size_t println(const String &s);
        size_t println(const char[]);
        size_t println(char);
        size_t println(unsigned char, int = DEC);
        size_t println(int, int = DEC);
        size_t println(unsigned int, int = DEC);
        size_t println(long, int = DEC);
        size_t println(unsigned long, int = DEC);
        size_t println(double, int = 2);
        size_t println(const Printable&);
        size_t println(void);

    private:
        int _baud;
        Stream& _serial;
        void send_command(char command,char *params);
};

#endif
