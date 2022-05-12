#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8
int x=1, a=0, y=6;
TFT TFTscreen = TFT(cs, dc, rst);
char Letras[2], Anterior[2];
void setup() {
  Serial.begin(9600);
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0); //FONDO COLOR NEGRO
  TFTscreen.stroke(255, 0, 0); //TRAZADO COLOR ROJO
  TFTscreen.noFill(); //SIN RELLENO
  TFTscreen.rect(5,3,123,123); //RECTANGULO
  TFTscreen.stroke(0, 0, 255); 
  TFTscreen.noFill(); //SIN RELLENO
  TFTscreen.rect(6,4,121,121); //RECTANGULO
  TFTscreen.stroke(255, 255, 255);
  
  TFTscreen.setTextSize(3);
  TFTscreen.text("T", 95, 30);
  delay(400); 
  TFTscreen.text("A", 59, 30);
  delay(400);
  TFTscreen.text("S", 23, 30);
  delay(400);
  TFTscreen.text("M", 41, 30);
  delay(400);
  TFTscreen.text("R", 77, 30);
  delay(400);  
  TFTscreen.text("GLOVE", 23, 60);
  delay(1000);

  /*BORRADO DEL TITULO*/
  TFTscreen.stroke(0,0,0);
  TFTscreen.text("T", 95, 30);
  TFTscreen.text("A", 59, 30);
  TFTscreen.text("S", 23, 30);
  TFTscreen.text("M", 41, 30);
  TFTscreen.text("R", 77, 30);  
  TFTscreen.text("GLOVE", 23, 60);

  TFTscreen.stroke(255,255,255);
  TFTscreen.setTextSize(2);
  TFTscreen.text("Creadores:", 9, 10); 
  delay(500);
  TFTscreen.setTextSize(1);
  TFTscreen.text("ALBERO Federico", 21, 40); 
  delay(500);   
  TFTscreen.text("BRITO Gonzalo", 25, 55); 
  delay(500);   
  TFTscreen.text("DIPOLITO Agustin", 19, 70); 
  delay(500);   
  TFTscreen.text("MURAKOSHI Leandro", 16, 85); 
  delay(500);   
  TFTscreen.text("ITSB 7D", 45, 110); 
  delay(1000); 

  TFTscreen.stroke(0,0,0);
  TFTscreen.setTextSize(2);
  TFTscreen.text("Creadores:", 9, 10); 
  TFTscreen.setTextSize(1);
  TFTscreen.text("ALBERO Federico", 21, 40);   
  TFTscreen.text("BRITO Gonzalo", 25, 55);  
  TFTscreen.text("DIPOLITO Agustin", 19, 70);   
  TFTscreen.text("MURAKOSHI Leandro", 16, 85);  
  TFTscreen.text("ITSB 7D", 45, 110); 
}

  
void loop() 
{   
  if (Serial.available()>0)//Si el modulo a manda dato, guardarlo en estado.
  {
  Letras[0] = Serial.read();  
  if (Letras[0]=='u')
  { 
    TFTscreen.stroke(255, 0, 0);
    TFTscreen.fill(255, 0, 0);
    TFTscreen.circle(118,118,2);
  }
  else
  {
    if(Letras[0]=='d')
    {
      TFTscreen.stroke(0, 255, 0);
      TFTscreen.fill(0, 255, 0);
      TFTscreen.circle(118,118,2);
    }
    else
    {
      if(Letras[0]=='t')
      {
        TFTscreen.stroke(0, 0, 255);
        TFTscreen.fill(0, 0, 255);
        TFTscreen.circle(118,118,2);
      }
      else
      {
        if(Letras[0]=='*')
        {

        }
        else
        {
          Serial.println(Letras[0]);
          a=a+1;
          if(a==18)
          {
            y=y+10;
            x=1;
          }
          if(a==36)
          {
            y=y+10;
            x=1;
          }
          if(a==54)
          {
            y=y+10;
            x=1;
          }
          if(a==72)
          {
            y=y+10;
            x=1;
          }
          x=x+7;
          TFTscreen.stroke(255, 255, 255);  // set the font color
          TFTscreen.text(Letras, x, y);
          //Esta parte del codigo es para solo 1 caracter o unidad
          Anterior[0]=Letras;
          delay(100);
        }
      }
    }
  }
  }
  // wait for a moment
  //delay(250);
  // erase the text you just wrote
  //TFTscreen.stroke(0, 0, 0);
  //TFTscreen.text(Letras, 10, 30);
}
