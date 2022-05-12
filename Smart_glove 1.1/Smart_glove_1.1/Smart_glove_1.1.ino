#define D6 6
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define S1 7
#define S2 8
int d6[5];
int d2[5];
int d3[5];
int d4[5];
int d5[5];
int c=1500;
int TOTAL;
int TD6, TD5;
int TOT [5];
int Modo=1;
 void setup() 
{
 pinMode (D6,INPUT);
 pinMode (D2,INPUT);
 pinMode (D3,INPUT);
 pinMode (D4,INPUT);
 pinMode (D5,INPUT);
 pinMode (S1,OUTPUT);
 pinMode (S2,OUTPUT);
 pinMode (8,OUTPUT);
 pinMode (10,OUTPUT);
 pinMode (9,OUTPUT);
 digitalWrite (S1,LOW);
 Serial.begin(9600);

}
 
void loop() 
{
  TOTAL=0;
  TOT[0]=0;
  TOT[1]=0;
  TOT[2]=0;
  TOT[3]=0;
  TOT[4]=0;
 for (int x=0; x<5; x++)
 { 
   d6[x]= digitalRead (D6)* 10000;
   d5[x]= digitalRead (D5)* 1000;
   d4[x]= digitalRead (D4)* 100;
   d3[x]= digitalRead (D3)* 10;
   d2[x]= digitalRead (D2)* 1;
   if(x!=0)
   {
    if(d6[x] == 10000 && d6[x-1] == 10000)
    {
     break;
    }
    if(d5[x] == 1000 && d5[x-1] == 1000)
    {
     break;
    }
    if(d4[x] == 100 && d4[x-1] == 100)
    {
     break;
    }
    if(d3[x] == 10 && d3[x-1] == 10)
    {
     break;
    }
        if(d2[x] == 1 && d2[x-1] == 1)
    {
     break;
    }
   }
   
   TOT[x]= TOT[x]+ d6[x]+d5[x]+d4[x]+d3[x]+d2[x];
   delay(10);
 }
 TOTAL=TOT[0]+ TOT[1]+ TOT[2]+ TOT[3]+ TOT[4] ;
if(Modo==1)
{
  switch(TOTAL)
  {
    //case 00010: if(Modo==1){Serial.print("B");}
                //if(Modo==2){Serial.print("P");}   
               // if(Modo==3){Serial.print("1");}      
                //TFTscreen.text(sensorPrintout, 0, 20);
                //break;
    case 11: Serial.print("C");break;
    case 100: Serial.print("D");break;
    case 101: Serial.print("F");break;
    case 110: Serial.print("G");break;
    case 111: Serial.print("H");break;
    case 1110: digitalWrite(9,HIGH);digitalWrite(8,LOW);digitalWrite(7,LOW);Modo=2; break;
    case 1100: digitalWrite(8,HIGH);digitalWrite(9,LOW);digitalWrite(10,LOW); Modo=3; break;
    //case 1111: Borrar; break;
    case 10001: Serial.print("J");break;
    case 10011: Serial.print("K");break;
    case 11001: Serial.print("L");break;
    case 11010: Serial.print("M");break;
    case 11011: Serial.print("N");break;
  
    case 11110: Serial.print("A");break;
    case 11000: Serial.print("E");break;
    case 11101: Serial.print("I");break;
    case 00001: Serial.print("O");break;
    case 11100: Serial.print("U");break;
    case 11111: Serial.print("_");break;
  }
}
if(Modo==2)
 {
    
  switch(TOTAL)
  {
    //case 00010: Serial.print("P");break;
    case 11: Serial.print("P");break;
    case 100: Serial.print("Q");break;
    case 101: Serial.print("R");break;
    case 110: Serial.print("S");break;
    case 111: Serial.print("T");break;
    case 1101: digitalWrite(10,HIGH);digitalWrite(9,LOW);digitalWrite(8,LOW);Modo=1; break;
    case 1100: digitalWrite(8,HIGH);digitalWrite(9,LOW);digitalWrite(10,LOW);Modo=3; break;
    //case 01111: Borrar ;break;
    case 10001: Serial.print("V");break;
    case 10011: Serial.print("W");break;
    case 11001: Serial.print("X");break;
    case 11010: Serial.print("Y");break;
    case 11011: Serial.print("Z");break;
  
    case 11110: Serial.print("A");break;
    case 11000: Serial.print("E");break;
    case 11101: Serial.print("I");break;
    case 00001: Serial.print("O");break;
    case 11100: Serial.print("U");break;
    case 11111: Serial.print("_");break;
  }  
 }
if(Modo==3)
{
  switch(TOTAL)
  {
    //case 00010: Serial.print("1");break;
    case 11: Serial.print("2");break;
    case 100: Serial.print("3");break;
    case 101: Serial.print("4");break;
    case 110: Serial.print("5");break;
    case 111: Serial.print("6");break;
    case 1101: digitalWrite(10,HIGH);digitalWrite(9,LOW);digitalWrite(8,LOW);Modo=1; break;
    case 1110: digitalWrite(9,HIGH);digitalWrite(8,LOW);digitalWrite(10,LOW);Modo=2; break;
    //case 01111: Borrar; break;
    case 10001: Serial.print("7");break;
    case 10011: Serial.print("8");break;
    case 11001: Serial.print("9");break;
    case 11010: Serial.print("0");break;
    case 11011: Serial.print("?");break;
  
    case 11110: Serial.print("A");break;
    case 11000: Serial.print("E");break;
    case 11101: Serial.print("I");break;
    case 00001: Serial.print("O");break;
    case 11100: Serial.print("U");break;
    case 11111: Serial.print("_");break;
  }    
}
  delay (1000);

}
