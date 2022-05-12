#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

#define D1 2
#define D2 3
#define D3 4
#define D4 5
#define D5 6

int d1[5];
int d2[5];
int d3[5];
int d4[5];
int d5[5];
int TOTAL;
int TOT [5];
int Modo=1; // se setea en 1 asi comienza en ese modo

void INICIALIZACION()
{
  TOTAL=0;
  TOT[0]=0;
  TOT[1]=0;
  TOT[2]=0;
  TOT[3]=0;
  TOT[4]=0;
} 

/*LO QUE HACE LECTURA ES LEER CADA PUERTO DE ENTRADA CONECTADO AL PULL DOWN DE CADA UNO DE LOS DEDOS, 
  PARA LUEGO MULTIPLICARLO POR UN NUMERO SEGUN CUAL DEDO SEA BAJADO:
  MEÑIQUE LO MULTIPLICA POR 10000
  ANULAR LO MULTIPLICA POR 1000
  MAYOR LO MULTIPLICA POR 100
  INDICE LO MULTIPLICA POR 10
  GORDO LO MULTIPLICA POR  1 
  ESTE RESULTADO LO GUARDA EN VECTORES*/
void LECTURA(int x)
{
   d5[x]= digitalRead (D5)* 10000; // MEÑIQUE
   d4[x]= digitalRead (D4)* 1000; // ANULAR
   d3[x]= digitalRead (D3)* 100; // MAYOR
   d2[x]= digitalRead (D2)* 10; // INDICE
   d1[x]= digitalRead (D1)* 1; // GORDO
}
void FILTRO()
{
 for (int x=0; x<5; x++)
 { 
  LECTURA(x);
   if(x!=0)
   {
    if(d5[x] == 10000 && d5[x-1] == 10000)
    {
     break;
    }
    if(d4[x] == 1000 && d4[x-1] == 1000)
    {
     break;
    }
    if(d3[x] == 100 && d3[x-1] == 100)
    {
     break;
    }
    if(d2[x] == 10 && d2[x-1] == 10)
    {
     break;
    }
    if(d1[x] == 1 && d1[x-1] == 1)
    {
     break;
    }
   }
   
   TOT[x]= TOT[x]+ d1[x]+d5[x]+d4[x]+d3[x]+d2[x];
   delay(10);
 }
}
 void setup() 
{
  pinMode (D5,INPUT);
  pinMode (D4,INPUT);
  pinMode (D3,INPUT);
  pinMode (D2,INPUT);
  pinMode (D1,INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}
 
void loop() 
{
  INICIALIZACION();
  FILTRO();
 TOTAL=TOT[0]+ TOT[1]+ TOT[2]+ TOT[3]+ TOT[4] ;
if(Modo==1)
{
  switch(TOTAL)
  {
    case 10: Serial.print("B"); mySerial.write("B");break;  
    case 11: Serial.print("C"); mySerial.write('C');break;
    case 100: Serial.print("D"); mySerial.write('D');break;
    case 101: Serial.print("F"); mySerial.write('F');break;
    case 110: Serial.print("G"); mySerial.write('G');break;
    case 111: Serial.print("H"); mySerial.write('H');break;
    case 1110: Serial.print("M2"); mySerial.write('d');Modo=2; break;
    case 1100: Serial.print("M3"); mySerial.write('t'); Modo=3; break;
    //case 1111: Borrar; break;
    case 10001: Serial.print("J"); mySerial.write('J');break;
    case 10011: Serial.print("K"); mySerial.write('K');break;
    case 11001: Serial.print("L"); mySerial.write('L');break;
    case 11010: Serial.print("M"); mySerial.write('M');break;
    case 11011: Serial.print("N"); mySerial.write('N');break;
  
    case 11110: Serial.print("A"); mySerial.write('A');break;
    case 11000: Serial.print("E"); mySerial.write('E');break;
    case 11101: Serial.print("I"); mySerial.write('I');break;
    case 00001: Serial.print("O"); mySerial.write('O');break;
    case 11100: Serial.print("U"); mySerial.write('U');break;
    case 11111: Serial.print("_"); mySerial.write('_');break;
  }
}
if(Modo==2)
 {
    
  switch(TOTAL)
  {
    case 10: Serial.print("P"); mySerial.write('P');break;
    case 11: Serial.print("Q"); mySerial.write('Q');break;
    case 100: Serial.print("R"); mySerial.write('R');break;
    case 101: Serial.print("S"); mySerial.write('S');break;
    case 110: Serial.print("T"); mySerial.write('T');break;
    case 111: Serial.print("V"); mySerial.write('V');break;
    case 1101: Serial.print("M1"); mySerial.write('u');Modo=1; break;
    case 1100: Serial.print("M3"); mySerial.write('t');Modo=3; break;
    //case 01111: Borrar ;break;
    case 10001: Serial.print("W"); mySerial.write('W');break;
    case 10011: Serial.print("X"); mySerial.write('X');break;
    case 11001: Serial.print("Y"); mySerial.write('Y');break;
    case 11010: Serial.print("Z"); mySerial.write('Z');break;
    case 11011: 
  
    case 11110: Serial.print("A"); mySerial.write('A');break;
    case 11000: Serial.print("E"); mySerial.write('E');break;
    case 11101: Serial.print("I"); mySerial.write('I');break;
    case 00001: Serial.print("O"); mySerial.write('O');break;
    case 11100: Serial.print("U"); mySerial.write('U');break;
    case 11111: Serial.print("_"); mySerial.write('_');break;
  }  
 }
if(Modo==3)
{
  switch(TOTAL)
  {
    case 10: Serial.print("1"); mySerial.write('1');break;
    case 11: Serial.print("2"); mySerial.write('2');break;
    case 100: Serial.print("3"); mySerial.write('3');break;
    case 101: Serial.print("4"); mySerial.write('4');break;
    case 110: Serial.print("5"); mySerial.write('5');break;
    case 111: Serial.print("6"); mySerial.write('6');break;
    case 1101: Serial.print("M1"); mySerial.write('u');Modo=1; break;
    case 1110: Serial.print("M2"); mySerial.write('d');Modo=2; break;
    //case 01111: Borrar; break;
    case 10001: Serial.print("7"); mySerial.write('7');break;
    case 10011: Serial.print("8"); mySerial.write('8');break;
    case 11001: Serial.print("9"); mySerial.write('9');break;
    case 11010: Serial.print("0"); mySerial.write('0');break;
    case 11011: Serial.print("?"); mySerial.write('?');break;
  
    case 11110: Serial.print("A"); mySerial.write('A');break;
    case 11000: Serial.print("E"); mySerial.write('E');break;
    case 11101: Serial.print("I"); mySerial.write('I');break;
    case 00001: Serial.print("O"); mySerial.write('O');break;
    case 11100: Serial.print("U"); mySerial.write('U');break;
    case 11111: Serial.print("_"); mySerial.write('_');break;
  }    
}
delay(1000);
}
