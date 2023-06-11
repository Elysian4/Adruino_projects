#include<SoftwareSerial.h>
SoftwareSerial btSerial(11,10);
int redPin=3;
int greenPin=5;
int bluePin=6;
int r_value;
int g_value;
int b_value;
String colour;
void setup(){
  btSerial.begin(9600);
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(4,LOW);
}
void loop(){
  if(btSerial.available()){
      colour=btSerial.readString();
      
      //indexing: [red,green,blue,saturation]
      int firstCommaIndex=colour.indexOf(',');
      int secondCommaIndex=colour.indexOf(',',firstCommaIndex+1);
      int thirdCommaIndex=colour.indexOf(',',secondCommaIndex+1);
      
      //slicing: substring(start_index,end_index)
      String red=colour.substring(1,firstCommaIndex);
      String green=colour.substring(firstCommaIndex+1,secondCommaIndex);
      String blue=colour.substring(secondCommaIndex+1,thirdCommaIndex);
      
      //typecasting: toInt()
      r_value=red.toInt();
      g_value=green.toInt();
      b_value=blue.toInt();
      
      //analog output part
      analogWrite(redPin,r_value);
      analogWrite(greenPin,g_value);
      analogWrite(bluePin,b_value);   
      Serial.println(r_value);
      Serial.println(g_value);
      Serial.println(b_value);
  }
}
