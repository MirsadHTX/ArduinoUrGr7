#include "MMA7660.h"


int stateSwitch()
{
  accelmeter.getAcceleration(&x, &y, &z); // Tager memory address som input

  int clicks = digitalRead(7);
    
    if (x >= 1 && flag == false)
    {
      count += 1;
      flag = true;
      playMelody();
    }

    if (x <= -0.8 && flag == false)
    {
      count -=1;
      flag = true;
      playMelody();
    }

    // reset flag
    if (x > -0.5 && x < 0.5)
    {
      flag = false;
    }

        if (count == -1)
    {
      count = 4;
    }
    //max state
    if (count == 5)
    {
      count = 0;
    }

    //away from random student state
    /*if(clicks == 1 && count == 4)
    {
      count -= 1;
    }*/
  
  delay(10);

  return count;

}
