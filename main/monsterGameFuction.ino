#include <Wire.h>
#include "MMA7660.h"
#include "rgb_lcd.h"



void monsterSpil()
{

  //type the output in here for the botton
  clicks = digitalRead(7);


//if sentence that does so click works only once when clicked
if (clicks == true && stopClicks == true && doingMission == false)
{
  clickCount = clickCount + 1;
  playMelody();
  stopClicks = false;
}

if (clicks == false && stopClicks == false && doingMission == false)
{
  stopClicks = true;
}

stopClicks == clicks;
clicks == false;





if (clickCount == 0)
{
  lcd.print("Monster game!");
}

if (clickCount == 1)
{
  lcd.print("Click 50 times");
  lcd.setCursor(0,1);
  lcd.print("to defeat Jeppe");
}

if (clickCount == 2)
{
  lcd.print(clickCount2);
  lcd.print(" Click Click!");
}

if (clicks == true && stopClicks2 == true && clickCount == 2)
{
  doingMission = true;
  clickCount2 = clickCount2 + 1;
  stopClicks2 = false;
}

if (clicks == false && stopClicks2 == false)
{
  stopClicks2 = true;  
}

stopClicks2 == clicks;
clicks == false;

if (clickCount2 > 49 && clickCount == 2)
{
  stopClicks2 = false;
  doingMission = false;
  playMelody();
  clickCount = 3;
  clickCount2 = 0;
  
}

if (clickCount == 3)
{
  lcd.print("good job!");
}

if (clickCount == 4)
{
  lcd.print("Click 100 times");
  lcd.setCursor(0,1);
  lcd.print("To be alpha!");
}

if (clickCount == 5)
{
  lcd.print(clickCount2);
  lcd.print(" BE ALPHA!");
}

if (clicks == true && stopClicks2 == true && clickCount == 5)
{
  doingMission = true;
  clickCount2 = clickCount2 + 1;
  stopClicks2 = false;
}

if (clicks == false && stopClicks2 == false)
{
  stopClicks2 = true;  
}

if (clickCount2 > 99 && clickCount == 5)
{
  stopClicks2 = false;
  doingMission = false;
  playMelody();
  clickCount = 6;
  clickCount2 = 0;
}

if (clickCount == 6)
{
  lcd.print("YOU'RE ALPHA NOW!");
}

if (clickCount == 7)
{
  lcd.print("Click 500 times");
  lcd.setCursor(0,1);
  lcd.print("to defeat Mirsad");
}

if (clickCount == 8)
{
  lcd.print(clickCount2);
  lcd.print(" EASY CLAP!");
}

if (clicks == true && stopClicks2 == true && clickCount == 8)
{
  doingMission = true;
  clickCount2 = clickCount2 + 1;
  stopClicks2 = false;
}

if (clicks == false && stopClicks2 == false)
{
  stopClicks2 = true;  
}

if (clickCount2 > 499 && clickCount == 8)
{
  stopClicks2 = false;
  doingMission = false;
  playMelody();
  clickCount = 9;
  clickCount2 = 0;
}

if (clickCount == 9)
{
  lcd.print("Congratulations");
  lcd.setCursor(0,1);
  lcd.print("You survived");
}

if (clickCount == 10)
{
  clickCount = 0;
}
delay(40);
lcd.clear();

}

void playMelody()
{
  pinMode(3, OUTPUT);
  digitalWrite(3,HIGH);
  delay(50);
  digitalWrite(3,LOW);
 
}
