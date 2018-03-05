/*
  Demo for exixe modules
  https://github.com/dekuNukem/exixe
  
  exixe "Getting Started" guide
  https://github.com/dekuNukem/exixe/blob/master/getting_started.md

  Demo 5: Loop digits on two tubes with crossfade animation
*/


#include "exixe.h"

// change those to the cs pins you're using
int cs1 = 10;
int cs2 = 9;
unsigned char count;

exixe my_tube1 = exixe(cs1);
exixe my_tube2 = exixe(cs2);

void setup()
{
  my_tube1.clear();
  my_tube2.clear();
  my_tube1.set_led(127, 0, 127); // purple;
  my_tube2.set_led(127, 127, 0); // yellow;
}

void loop()
{
  count = (count + 1) % 10; // keep count between 0 to 9

  my_tube1.crossfade_init(count, 15, 127, 0);
  my_tube2.crossfade_init(10-count, 15, 127, 0);

  while(1)
  {
    unsigned char result1 = my_tube1.crossfade_run();
    unsigned char result2 = my_tube2.crossfade_run();
    if(result1 == EXIXE_ANIMATION_FINISHED && result2 == EXIXE_ANIMATION_FINISHED)
      break;
  }

  delay(250);
}