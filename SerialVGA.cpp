/*
    SerialVGA.cpp - Library for driving the HobbyTronics SerialVGA driver board.
    Created by Philip Howard, July 2012.
*/
#include "Arduino.h"
#include "SerialVGA.h"

SerialVGA::SerialVGA(Stream& serial) :
    _serial( serial )
{
    //_baud = baud;
    //_serial = serial;
    //_serial.begin(baud);
}

void SerialVGA::reboot()
{
    char command[] = {'r'};
    char params[] = {};
    send_command(command,params);
}

/*
 makeWindow - Create a new window
 ID = Window ID
 x = x position
 y = y position
 w = window width
 h = window height
 b = window border
*/
void SerialVGA::make_window(int id, int x, int y, int w, int h, int b, char* title)
{
    char command[] = {'w'};
    char params[] = {};
    sprintf(params,",%d,%d,%d,%d,%d,%d,%s",id,x,y,w,h,b,title);
    send_command(command,params);
}

void SerialVGA::erase_window(int w)
{
    char command[] = {'p'};
    char params[] = {};
    sprintf(params,",%d",w);
    send_command(command,params);
}

void SerialVGA::set_focus(int w)
{
    char command[] = {'p'};
    char params[] = {};
    sprintf(params,",%d",w);
    send_command(command,params);
}

void SerialVGA::toggle_cursor(int w, int onoff)
{
    char command[] = {'c'};
    char params[] = {};
    sprintf(params,",%d,%d",w,onoff);
    send_command(command,params);
}

void SerialVGA::set_cursor(int x, int y)
{
    char command[] = {'p'};
    char params[] = {};
    sprintf(params,",%d,%d",x,y);
    send_command(command,params);
}

void SerialVGA::set_color(int startx, int endx, char *fg, char *bg)
{
    char command[] = {'l'};
    char params[] = {};
    sprintf(params,",%d,%d,%s,%s",startx,endx,fg,bg);
    send_command(command,params);
}

void SerialVGA::print_inverse(char *text_str)
{
    // Function to write inverse characters to VGA board
    // Makes bit 7 of each character a 1 
    unsigned int i;
    for(i=0;text_str[i] != '\0';i++) {
        text_str[i]=text_str[i] | 0x80;
    }   
    _serial.print(text_str); 
}


size_t SerialVGA::print(const __FlashStringHelper *ifsh)
{
    _serial.print(ifsh);
}
size_t SerialVGA::print(const String &s)
{
    _serial.print(s);
}

size_t SerialVGA::print(const char str[])
{
    _serial.print(str);
}
size_t SerialVGA::print(char c)
{
    _serial.print(c);
}
size_t SerialVGA::print(unsigned char b, int base)
{
    _serial.print(b,base);
}
size_t SerialVGA::print(int n, int base)
{
    _serial.print(n,base);
}
size_t SerialVGA::print(unsigned int n, int base)
{
    _serial.print((unsigned long) n,base);
}
size_t SerialVGA::print(long n, int base)
{
    _serial.print(n,base);
}
size_t SerialVGA::print(unsigned long n, int base)
{
    _serial.print(n,base);
}
size_t SerialVGA::print(double n, int digits)
{
    _serial.print(n,digits);
}
/*size_t SerialVGA::print(const Printable& x);
{
    _serial.print(x);
}*/

size_t SerialVGA::println(const __FlashStringHelper *ifsh)
{
    _serial.println(ifsh);
}
size_t SerialVGA::println(const String &s)
{
    _serial.println(s);
}
size_t SerialVGA::println(const char c[])
{
    _serial.println(c);
}
size_t SerialVGA::println(char c)
{
    _serial.println(c);
}
size_t SerialVGA::println(unsigned char b, int base)
{
    _serial.println(b,base);
}
size_t SerialVGA::println(int num, int base)
{
    _serial.println(num,base);
}
size_t SerialVGA::println(unsigned int num, int base)
{
    _serial.println(num,base);
}
size_t SerialVGA::println(long num, int base)
{
    _serial.println(num,base);
}
size_t SerialVGA::println(unsigned long num, int base)
{
    _serial.println(num,base);
}
size_t SerialVGA::println(double num, int digits)
{
    _serial.println(num,digits);
}
size_t SerialVGA::println(const Printable& x)
{
    _serial.println(x);
}

/*
void SerialVGA::print(char *text_str)
{
    _serial.print(text_str);
}

void SerialVGA::println(char *text_str)
{
    _serial.println(text_str);
}
*/

void SerialVGA::send_command(char *command,char *params)
{
    _serial.print("^[");
    _serial.print(command);
    if( strlen( params ) > 0 )
    {
        _serial.println(params);
    }
    if( command[0] == 'r' ) delay(2000);                    // 2 second wait for reboot
    if( command[0] == 'w' && _baud == 115200 ) delay(20);    // 20ms delay for window commands
    // Other delays?
    if( command[0] == 'w' && _baud == 9600   ) delay(5);     // Only 5ms needed for 9600 baud

    delay(2); // All commands need a short delay
}


