#include <rgb_lcd.h>
#include <math.h>
#include <Wire.h>
#include "MMA7660.h"
#include "rgb_lcd.h"
#include "DS1307.h"

//for accel
float x, y, z;
MMA7660 accelmeter;
rgb_lcd lcd;

//for state_switch
bool flag = false;
bool flag2 = false;
int count = 0;
int currentState;

//for temp
const int B = 4275;
const int R0 = 100000;

//for game
bool myMelody = false;
bool clicks = false;
bool stopClicks = true;
bool doingMission = false;
int clickCount = 0;
bool stopClicks2 = true;
int clickCount2 = 0;

//stopwatch
int stopWatchCount;
bool trykFoer;
bool urStop;
float tidNu;
float tidFoer;
float counter;



bool nameFlag;
int randomName;


DS1307 clock;

void setup() 
{
  lcd.begin(16, 2);
  accelmeter.init();
  pinMode(7, INPUT);  //for button
  
  Serial.begin(9600);
  clock.begin();
  
}

void loop() 
{
  currentState = stateSwitch();
  clicks = digitalRead(7);


  //state switching
  if (currentState == 0)  //clock
  {
    lcd.setRGB(0, 255, 0);
    clock.getTime();
    lcd.setCursor(0, 0);
    lcd.print(clock.hour, DEC);
    lcd.print(":");
    lcd.print(clock.minute, DEC);
    lcd.print(":");
    lcd.print(clock.second, DEC);
    lcd.print("  ");
    lcd.setCursor(0, 1);
    lcd.print(clock.dayOfMonth, DEC);
    lcd.print("/");
    lcd.print(clock.month, DEC);
    lcd.print("/");
    lcd.print(clock.year+2000, DEC);
    delay(100);
    lcd.clear();
  }
  if (currentState == 1)  //temperature
  {
    lcd.clear();
    tempu();
  }
  
  if (currentState == 2)  //game
  {
    lcd.clear();
    lcd.setRGB(0, 0, 255);
    monsterSpil();
  }

  if (currentState == 3) //stopwacth
  {
    lcd.clear();
    lcd.setRGB(255, 255, 150);
    StopUr();
    /*
    lcd.setCursor(0, 0);
    stopWatchCount += 1;
    lcd.print(stopWatchCount/40);
    lcd.setCursor(0, 1);
    lcd.print("seconds");
    delay(10);
    if(clicks == true)
    {
      stopWatchCount = 0;
      playMelody();
    }
    */

    
  }
  
  if (currentState == 4)  //random student
  {
    lcd.clear();
    lcd.setRGB(255, 0, 0);
    LuckyKid();
  }

  if(currentState == 5)
  {
    lcd.clear();
    lcd.setRGB(255,255,0);
    Chrismas();
  }

}
