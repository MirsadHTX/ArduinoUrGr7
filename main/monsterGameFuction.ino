#include <Wire.h>
#include "MMA7660.h"
#include "rgb_lcd.h"



void MonsterSpil()
{

  //type the output in here for the botton
  clicks = digitalRead(7);


//if sentence that does so click works only once when clicked
//These clicks are the ones to switch modes/Screen of the game
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




// Start of the game
if (clickCount == 0)
{
  lcd.print("Monster game!");
}

// Second screen of the game
if (clickCount == 1)
{
  lcd.print("Click 50 times");
  lcd.setCursor(0, 1);
  lcd.print("to defeat Jeppe");
}

// First "fight" in the game where it will count your clicks
if (clickCount == 2)
{
  lcd.print(clickCount2);
  lcd.print(" Click Click!");
}

//Make sure it does not click multiple times 
//DoingMission is a bool that helps tell if we're currently fighting, we can only switch modes when we are not in a fight.
if (clicks == true && stopClicks2 == true && clickCount == 2)
{
  doingMission = true;
  clickCount2 = clickCount2 + 1;
  stopClicks2 = false;
}

//Make sure it does not click multiple times
if (clicks == false && stopClicks2 == false)
{
  stopClicks2 = true;  
}

stopClicks2 == clicks;
clicks == false;

//Once you reached the amount of clicks it will move on to the next move, and reset the click counter back to 0 and DoingMission will be false.
if (clickCount2 > 49 && clickCount == 2)
{
  stopClicks2 = false;
  doingMission = false;
  playMelody();
  clickCount = 3;
  clickCount2 = 0;
  
}

//Fourth screen of the game (Just text)
if (clickCount == 3)
{
  lcd.print("good job!");
}

//Fifth screen of the game (Just text)
if (clickCount == 4)
{
  lcd.print("Click 100 times");
  lcd.setCursor(0,1);
  lcd.print("To be alpha!");
}

//6th screen of the game, it will count your clicks. 
if (clickCount == 5)
{
  lcd.print(clickCount2);
  lcd.print(" BE ALPHA!");
}

//Will start counting every click and doingMission will be true to not interupt with our other if statements
if (clicks == true && stopClicks2 == true && clickCount == 5)
{
  doingMission = true;
  clickCount2 = clickCount2 + 1;
  stopClicks2 = false;
}

// Make sure the clicks only happend once when clicked
if (clicks == false && stopClicks2 == false)
{
  stopClicks2 = true;  
}

// Will stop the fight when you reached the amount of clicks and move to the next mode
//DoingMission will be false and you can continue with the modes
if (clickCount2 > 99 && clickCount == 5)
{
  stopClicks2 = false;
  doingMission = false;
  playMelody();
  clickCount = 6;
  clickCount2 = 0;
}

//7th screen of the game
if (clickCount == 6)
{
  lcd.print("YOU'RE ALPHA NOW!");
}

//8th screen of the game
if (clickCount == 7)
{
  lcd.print("Click 500 times");
  lcd.setCursor(0,1);
  lcd.print("to defeat Mirsad");
}

//9th screen of the game, it will count your clicks once when pressed
if (clickCount == 8)
{
  lcd.print(clickCount2);
  lcd.print(" EASY CLAP!");
}

//If statement that makes it so it will only start counting clicks when we are in the right mode
if (clicks == true && stopClicks2 == true && clickCount == 8)
{
  doingMission = true;
  clickCount2 = clickCount2 + 1;
  stopClicks2 = false;
}

// Make sure clicks only happend once
if (clicks == false && stopClicks2 == false)
{
  stopClicks2 = true;  
}

//End the doing mission and move to the next mode
if (clickCount2 > 499 && clickCount == 8)
{
  stopClicks2 = false;
  doingMission = false;
  playMelody();
  clickCount = 9;
  clickCount2 = 0;
}

//Final screen of the game
if (clickCount == 9)
{
  lcd.print("Congratulations");
  lcd.setCursor(0, 1);
  lcd.print("You survived");
}

//Restarts the game
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
  digitalWrite(3, HIGH);
  delay(50);
  digitalWrite(3, LOW);
 
}
