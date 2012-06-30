#include <SerialVGA.h>

/*
  serialVGA - Test program for communicating with Hobbytronics serialVGA board
  Creates 5 windows and displays data
  Copyright www.hobbytronics.co.uk 2012
*/

SerialVGA* vga;
unsigned long currentTime;
unsigned long loopTime;
unsigned int  counter=0;
unsigned long number_sum=0;
unsigned long number_avg=0;

void setup() {                
  // initialize  
  Serial.begin(9600);      // Set baud rate for serialVGA board
  
  vga = new SerialVGA(Serial);
  
  vga->reboot();
  
  vga->make_window(0,0,0,100,3,1,""); // Header
  
  vga->print("                        ");
  vga->print("HobbyTronics serialVGA Driver board Demonstration");
 
  vga->make_window(2,0,3,70,32,1,"Raw Data Display");
  vga->make_window(3,70,3,30,32,1,"Calculated Values");
  vga->make_window(4,0,35,100,14,1,"Terminal Input");
  vga->toggle_cursor(4,CURSOR_ON);
  
  vga->make_window(5,0,49,100,1,0,""); // Footer
  vga->print(" Hobbytronics Ltd                     www.hobbytronics.co.uk");
  vga->print("                         serialVGA demo");

  vga->set_color(0,2,"222","101");
  vga->set_color(35,48,"222","001");
  vga->set_color(49,49,"000","111");
  
  currentTime = millis();
  loopTime = currentTime; 
}

void loop() {

  currentTime = millis();
  
  if(currentTime >= (loopTime + 500)){ 
    // send every half second
    loopTime = currentTime;              // Updates loopTime
    
    vga->set_focus(2);                    // Set Window2 as focus
    
    // SerialVGA wraps print//println for...err... aesthetic reasons
    vga->print("This is data - ");     // print data
    vga->println(counter, DEC);
    
    vga->set_focus(3);
    vga->set_cursor(0,0);
    vga->print_inverse("Summary of Data");
    vga->print("\r\n\r\n");
    vga->print("Largest Number - ");
    vga->println(counter, DEC);
    vga->print("SUM of Numbers - ");   // print data    
    vga->println(number_sum, DEC);
    vga->print("AVG of Numbers - ");   // print data    
    vga->println(number_avg, DEC);    
   
    counter++;
    number_sum+=counter;
    number_avg=number_sum/counter;    

  }    
  if (Serial.available() > 0) {
     // Data received into Arduino board, echo'd out to Window 4 (command window)
       int inByte = Serial.read();  
       //vga_command("f,4");               // Set Window4 as focus       
       Serial.write(inByte); 
   } 
   
}