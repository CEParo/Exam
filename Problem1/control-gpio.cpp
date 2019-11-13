#include"derek_LED.h"
#include"GPIO.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<unistd.h>
#include<cstdlib>
#include<cstdio>
#include<fcntl.h>
#include<sys/epoll.h>

using namespace exploringBB;
using namespace std;

GPIO *outGPIO, *inGPIO, *inGPIO1;

int main()
{
  GPIO inGPIO(26);
  GPIO inGPIO1(46);
  GPIO outGPIO(49);
  
  inGPIO.setDirection(INPUT);
  inGPIO1.setDirection(INPUT);
  outGPIO.setDirection(OUTPUT);
  outGPIO.streamOpen();

   
     cout << "press Button A to light the external LED or Button B to light onboard LED USR3" << endl;
  cout <<"Button A value: " << inGPIO.getValue()<<endl; 
  cout<<"Button B value: " << inGPIO1.getValue()<<endl;
  cout << "Starting the GPIO_control program" << endl;
  LED leds;
  if (inGPIO1.getValue() == HIGH) 
    leds.turnOff();
  else
   leds.turnOn();
  if (inGPIO.getValue() == HIGH)
    outGPIO.streamWrite(LOW);
  else
    outGPIO.streamWrite(HIGH);
  return 0;
}
