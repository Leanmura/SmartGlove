#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8
int x=1, a=0, y=6, borrar=0;
TFT TFTscreen = TFT(cs, dc, rst);
char Letras[2], Anterior[2];
void setup() 
{
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
/*
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
  delay(1000); */

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
  if (Letras[0]=='a')
  { 
      TFTscreen.text("HOLA ", x, y); 
      x=x+21;
  }
  else
  {
  if (Letras[0]=='b')
  { 
      TFTscreen.text("CHAU ", x, y); 
      x=x+21;
  }
  else
  {
  if (Letras[0]=='e')
  { 
      TFTscreen.text("¿COMO ANDAS? ", x, y+10); 
      x=x+77;
  }
  else
  {
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
        if(Letras[0]=='c')
        {
          TFTscreen.stroke(255, 255, 255);
          TFTscreen.fill(255, 255, 255);
          TFTscreen.circle(118,118,2);
        }
        else
        {
          if(Letras[0]=='*')
          { 
            borrar=borrar+1;
            if(borrar==2)
            {
            x=1;y=6;a=0;// REINICIO LA POSCION DE IMPRESION AL PRINCIPIO 
            TFTscreen.background(0, 0, 0); //FONDO COLOR NEGRO
            TFTscreen.stroke(255, 0, 0); //TRAZADO COLOR ROJO
            TFTscreen.noFill(); //SIN RELLENO
            TFTscreen.rect(5,3,123,123); //RECTANGULO
            TFTscreen.stroke(0, 0, 255); 
            TFTscreen.noFill(); //SIN RELLENO
            TFTscreen.rect(6,4,121,121); //RECTANGULO  
            borrar=1;          
            }
            else
            {
              TFTscreen.stroke(0, 0, 0);  // set the font color
              TFTscreen.text(Anterior, x, y);
              if(a!=0)
              {
                a=a-1;//cuando borramos una letra estamos retrocediendo un espacio 
              }
              x=x-7;                 
          }
        }
        else
        {
          borrar=0; // reinicia el contador de borrar xq si borrar=1 borra una letra, si borrar=2 borra todo en la pantalla
          if(a==17)
          {
            y=y+10;
            x=1;
            a=0;
          }
          x=x+7; // se le suman 7 para que se imprima una letra al lado de la otra
          TFTscreen.stroke(255, 255, 255);  // set the font color
          TFTscreen.text(Letras, x, y);// lee lo que manda el otro guante y lo guarda en un vector
          a=a+1; // cuenta las letras mostradas en pantalla, esto sirve para saber cuando se lleno el renglon
          //Esta parte del codigo es para solo 1 caracter o unidad
          Anterior[0]=Letras[0];

          delay(10);
        }
      }
    }
  }
 }
}
}
}
}
}
