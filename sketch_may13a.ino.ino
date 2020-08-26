#include <MsTimer2.h>

int r = 0;
int g = 0;
int b = 0;
int velocity = 10;
int mode = 2;
int brightness = 255;
int input=0;
byte left=0;
//int port=0;
//int x=0; для функции переливания(еще не реализовано)
//int t=0; для функции переливания(еще не реализовано)

void setup() {
  Serial.begin(9600);
 //pinMode(2, INPUT_PULLUP);
 //pinMode(3, INPUT_PULLUP);
  digitalWrite(2, HIGH);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  analogWrite(9, r);
  analogWrite(10, g);
  analogWrite(11, b);
  //attachInterrupt(0, button, CHANGE);
  //attachInterrupt(1, switcher, CHANGE);
  MsTimer2::set(20,timerInterupt);
  MsTimer2::start();
}
void  timerInterupt() { //пытаемся выйти из перелива если сменился режим
  if(Serial.available() > 0 && mode == 1)
   left=1;
}

void loop()
{
  ask();
  work();
}
void button() {
  if (brightness < 255) brightness=brightness+50;
  if (brightness >= 255) brightness=5;
}
void switcher() {
  if (mode < 19)
  {
    mode++;
  }
  else mode = 2;
}
void work(){
  switch (mode) //режимы работы
  {
    case 0:
      r = 0;
      g = 0;
      b = 0;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b); 
      break; 
    case 1:
    
   /*
    color(1);
    color(2);
    color(3);
    color(2);
    */
       if (r >= brightness)
        {
          for (r; r != 0; r--)
          {
            if(left==1) break;
            analogWrite(9, r);
            delay(velocity);
          }
        }
       if(r < brightness)
       {
        for (r; r < brightness; r++)
        {
          if(left==1) break;
          analogWrite(9, r);
          delay(velocity);
        }
       }
      
      if (g >= brightness)
        {
          for (g; g != 0; g--)
          {
            if(left==1) break;
            analogWrite(10, g);
            delay(velocity);
          }
        }
       if(g < brightness)
       { 
        for (g; g < brightness ; g++) //разгорается
        {
          if(left==1) break;
          analogWrite(10, g);
          delay(velocity);
        }
       }
      
      if(b >= brightness)
        {
        for (b; b != 0 ; b--)
        {
          if(left==1) break;
          analogWrite(11, b);
          delay(velocity);
        }
        }
      if(b < brightness)
       {
        for (b; b < brightness; b++)
        {
          if(left==1) break;
          analogWrite(11, b);
          delay(velocity);
        }
       }
      left=0;
      break;
     
    case 2:
      r = brightness;
      g = brightness;
      b = brightness;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);  
      break;
    case 19:
      r = brightness;
      g = 0;
      b = 0;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);  
      break;
    case 4:
      r = 0;
      g = brightness;
      b = 0;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;   
    case 5:
      r = 0;
      g = 0;
      b = brightness;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b); 
      break;
    case 6:
      r = 0;
      g = brightness;
      b = brightness;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 7:
      r = brightness;
      g = 0;
      b = brightness;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 8:
      r = brightness;
      g = brightness;
      b = 0;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 9:
      r = brightness/2;
      g = brightness;
      b = brightness/2;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 10:
      r = brightness;
      g = brightness/2;
      b = brightness/2;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 11:
      r = brightness/2;
      g = brightness/2;
      b = brightness;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 12:
      r = brightness/2;
      g = brightness/2;
      b = 0;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 13:
      r = brightness/2;
      g = 0;
      b = brightness;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 14:
      r = 0;
      g = brightness/2;
      b = brightness;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 15:
      r = brightness;
      g = 0;
      b = brightness/2;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 16:
      r = brightness;
      g = brightness/2;
      b = 0;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 17:
      r = brightness;
      g = 0;
      b = brightness/4;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;
    case 18:
      r = brightness;
      g = brightness/8;
      b = brightness/4;
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      break;

      case 3:
     // if (r >= brightness)
        {
          for (r; r != 0; r--)
          {
            if(left==1) break;
            analogWrite(9, r);
            delay(velocity);
          }
        }
     //  if(r < brightness)
       {
        for (r; r < brightness; r++)
        {
          if(left==1) break;
          analogWrite(9, r);
          delay(velocity);
        }
       }
      
    //  if (g >= brightness)
        {
          for (g; g != 0; g--)
          {
            if(left==1) break;
            analogWrite(10, g);
            delay(velocity);
          }
        }
      // if(g < brightness)
       { 
        for (g; g < brightness ; g++) //разгорается
        {
          if(left==1) break;
          analogWrite(10, g);
          delay(velocity);
        }
       }
      
     // if(b >= brightness)
        {
        for (b; b != 0 ; b--)
        {
          if(left==1) break;
          analogWrite(11, b);
          delay(velocity);
        }
        }
      //if(b < brightness)
       {
        for (b; b < brightness; b++)
        {
          if(left==1) break;
          analogWrite(11, b);
          delay(velocity);
        }
       }
      left=0;
      break;
  }
}
void ask(){
  if(Serial.available() > 0)
  {
    input = Serial.parseInt();
    Serial.write(input);
    switch(input)
    {
      case 1:
      switcher();
      break;
      //Serial.print("Смена режима");
      case 2:
      button();
      break;
      //Serial.print("Яркость");
      case 3:
      brightness=255;
      break;
      case 4:
      brightness=5;
      break;
      case 5:
      if(brightness <=200)
        brightness+=50;
        else brightness=255;
      break;
      case 6:
      brightness-=50;
      break;
      case 7:
      velocity+=2;
      break;
      case 8:
      if(velocity>=3)
      velocity-=2;
      break;
      case 78:
      velocity=10;
      break;
      case 9:
      mode=1;
      break;
      case 99:
      mode=0;
      break;
      case 98:
      mode=2;
      break;
      
      default:
      break;
    }
  }
  //else return 0;
}
/*int color(int x){ //функция переливания
  switch(x)
  {
    case 1:
    port=9;
    case 2:
    port=10;
    case 3:
    port=11;
  }
  if (t >= brightness)
        {
        for (t; t != 0; t--)
        {
          analogWrite(port, t);
          delay(velocity);
        }
        }
   
      for (t; t <= brightness; t++)
      {
        analogWrite(port, t);
        delay(velocity);
      }
  return 0;
}*/

