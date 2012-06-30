/*
    SerialVGA.cpp - Library for driving the HobbyTronics SerialVGA driver board.
    Created by Philip Howard, July 2012.
*/
#include "Arduino.h"
#include "SerialVGA.h"

SerialVGA::SerialVGA(int baud)
{
    _baud = baud;
    Serial.begin(baud);
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
    Serial.print(text_str); 
}

void SerialVGA::print(char *text_str)
{
    Serial.print(text_str);
}

void SerialVGA::println(char *text_str)
{
    Serial.println(text_str);
}

void SerialVGA::send_command(char *command,char *params)
{
    Serial.print("^[");
    Serial.print(command);
    if( strlen( params ) > 0 )
    {
        Serial.println(params);
    }
    if( command[0] == 'r' ) delay(2000);                    // 2 second wait for reboot
    if( command[0] == 'w' && _baud == 115200 ) delay(20);    // 20ms delay for window commands
    // Other delays?
    if( command[0] == 'w' && _baud == 9600   ) delay(5);     // Only 5ms needed for 9600 baud

    delay(2); // All commands need a short delay
}


