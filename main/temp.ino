void tempu()  //temperature
{
    lcd.setRGB(255, 30, 255);
    int temp = analogRead(A0);
    float R = 1023.0/temp-1.0;
    R = R0*R;
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
    lcd.print(temperature);
    lcd.print(" Celcius");
    
    delay(100);
    lcd.clear();
}

void LuckyKid() //random student
{
  lcd.setCursor(0, 0);
  /////////////////
  //get random number when button is pressed for random name
  if(clicks == true)
  {
    nameFlag = true;
  }
  if(clicks == false)
  {
    //nameFlag = false;
    randomName = random(0,29);
  }
  ///////Y//////////

  if(clicks == true || nameFlag == true)  //get random name
  {
    if(randomName == 0)
    {
      lcd.print("Jabriil");
    }
    if(randomName == 1)
    {
      lcd.print("Thøger");
    }
    if(randomName == 2)
    {
      lcd.print("Ismail");
    }
    if(randomName == 3)
    {
      lcd.print("Haris");
    }
    if(randomName == 4)
    {
      lcd.print("Taaha");
    }
    if(randomName == 5)
    {
      lcd.print("Mathias");
    }
    if(randomName == 6)
    {
      lcd.print("Emil");
    }
    if(randomName == 7)
    {
      lcd.print("Robert");
    }
    if(randomName == 8)
    {
      lcd.print("Tobias");
    }
    if(randomName == 9)
    {
      lcd.print("Ludvig");
    }
    if(randomName == 10)
    {
      lcd.print("Fahmi");
    }
    if(randomName == 11)
    {
      lcd.print("Jonathan");
    }
    if(randomName == 12)
    {
      lcd.print("Simon");
    }
    if(randomName == 13)
    {
      lcd.print("Jeppe");
    }
    if(randomName == 14)
    {
      lcd.print("William");
    }
    if(randomName == 15)
    {
      lcd.print("Anders");
    }
    if(randomName == 16)
    {
      lcd.print("Rasmus");
    }
    if(randomName == 17)
    {
      lcd.print("Lovro");
    }
    if(randomName == 18)
    {
      lcd.print("Pernille");
    }
    if(randomName == 19)
    {
      lcd.print("Sarah");
    }
    if(randomName == 20)
    {
      lcd.print("Gustav Wett");
    }
    if(randomName == 21)
    {
      lcd.print("Gustav Werk");
    }
    if(randomName == 22)
    {
      lcd.print("Silas");
    }
    if(randomName == 23)
    {
      lcd.print("Freja");
    }
    if(randomName == 24)
    {
      lcd.print("Jacob");
    }
    if(randomName == 25)
    {
      lcd.print("Kasper");
    }
    if(randomName == 26)
    {
      lcd.print("Nelisa");
    }
    if(randomName == 27)
    {
      lcd.print("Mohammed");
    }
    if(randomName == 28)
    {
      lcd.print("Nicolai");
    }
    if(randomName == 29)
    {
      lcd.print("Mie");
    }
  }
  
  lcd.setCursor(0, 1);
  lcd.print("button for name");
  delay(100);
  lcd.clear();
}

void Chrismas() //christmas
{
  lcd.setCursor(0, 0);
  lcd.print(24-clock.dayOfMonth);
  lcd.print(" dage til jul");
  lcd.setCursor(0, 1);
  lcd.print(12-clock.month);
  lcd.print(" maaned t. jul");
}

void StopUr() //stopwatch
{
  
  if (clicks == true && trykFoer ==false)
  {
    if (urStop == false)
    {
       urStop = true;
    }
    else 
    {
      urStop = false;

     tidFoer = tidNu;
     lcd.clear();
    } 
  }
  
  if (urStop==false)
  {
    tidNu = millis();

    counter = tidNu-tidFoer;
  }

  trykFoer = clicks;
  
  lcd.setCursor(0,0);
  lcd.print(counter/1000);
}




void Alarm()
{
    lcd.setCursor(0,0);
    if(alarmState == 0) //hour counter
    {
      if(clicks == true && alarmFlag == false)
      {
        alarmHour = alarmHour + 1;
        alarmFlag = true;
      }
      
      if(clicks == false)
      {
        alarmFlag = false;
      }
  
      lcd.print(alarmHour);
      lcd.print(" hours");
    }
  
  
    if(alarmState == 1) // minute counter
    {
      if(clicks == true && alarmFlag == false)
      {
        alarmMin = alarmMin + 1;
        alarmFlag = true;
      }
      
      if(clicks == false)
      {
        alarmFlag = false;
      }
  
      lcd.print(alarmMin);
      lcd.print(" minutes");
    }
  
  
  
      if (y >= 1 && alarmStateFlag == false)  //increase alarmState
      {
        alarmState = alarmState + 1;
        alarmStateFlag = true;
      }
    
      if (y <= -0.8 && alarmStateFlag == false) //decrease alarmState
      {
        alarmState = alarmState - 1;
        alarmStateFlag = true;
      }
    
    

        // reset alarmStateFlag
        if (y > -0.5 && y < 0.5)
        {
          alarmStateFlag = false;
        }
      
        if (alarmState == -1 && alarmState > 50)
        {
          count = 1;
        }
  
      
      
      if(alarmState > 1)
      {
        clock.getTime();
        alarmState = 999;
        lcd.setCursor(0,0);
        lcd.print("Alarm set");
        lcd.setCursor(0,1);
        lcd.print(alarmHour, DEC);
        lcd.print(":");
        lcd.print(alarmMin, DEC);

        lcd.print("  ");
        lcd.print(clock.hour, DEC);
        lcd.print(":");
        lcd.print(clock.minute, DEC);
        
        if(alarmHour == clock.hour && alarmMin == clock.minute)
        {
          playMelody();
          lcd.print("ALARM");
        }
        
      }
  
  
  
    delay(100);
    lcd.clear();
}


void Schedule() //beep at schedule
{
  
  if(clock.hour == 8 && clock.minute == 15 && clock.second == 1)  //8:15
  {
    playMelody();
  }

  if(clock.hour == 9 && clock.minute == 15 && clock.second == 1)  //9:15
  {
    playMelody();
    delay(1000);
    playMelody();
  }

  if(clock.hour == 9 && clock.minute == 35 && clock.second == 1)  //9:35
  {
    playMelody();
  }

  if(clock.hour == 10 && clock.minute == 35 && clock.second == 1) //10:35
  {
    playMelody();
    delay(1000);
    playMelody();
  }

  if(clock.hour == 10 && clock.minute == 45 && clock.second == 1)  //10:45
  {
    playMelody();
  }

  if(clock.hour == 11 && clock.minute == 45 && clock.second == 1) //11:45
  {
    playMelody();
    delay(1000);
    playMelody();
  }

  if(clock.hour == 12 && clock.minute == 15 && clock.second == 1)  //12:15
  {
    playMelody();
  }

  if(clock.hour == 13 && clock.minute == 15 && clock.second == 1) //13:15
  {
    playMelody();
    delay(1000);
    playMelody();
  }

  if(clock.hour == 13 && clock.minute == 25 && clock.second == 1)  //13:25
  {
    playMelody();
  }

  if(clock.hour == 14 && clock.minute == 25 && clock.second == 1) //14:25
  {
    playMelody();
    delay(1000);
    playMelody();
  }

  if(clock.hour == 14 && clock.minute == 30 && clock.second == 1)  //14:30
  {
    playMelody();
  }

  if(clock.hour == 15 && clock.minute == 30 && clock.second == 1) //15:30
  {
    playMelody();
    delay(1000);
    playMelody();
  }
}
