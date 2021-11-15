int Motor = 8; //set relay to pin 8
int count;
int const trigPin2 = 13; 
int const echoPin2 = 12;
int const trigPin = 6; 
int const echoPin = 5;
int const ledpin = 4;
int Sw2 = 2; // Water sensor
void setup()
{Serial.begin(115200);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT); 
pinMode(ledpin, OUTPUT); 
pinMode(Sw2,INPUT);
pinMode(Motor,OUTPUT);
}
void loop()
{ 
int check = digitalRead(Sw2);
Serial.print("Sw = ");Serial.println(check);
int duration, distance;
int duration2, distance2;
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
digitalWrite(trigPin2, HIGH);
delay(1);
digitalWrite(trigPin2, LOW);


duration = pulseIn(echoPin, HIGH); //กำหนดให้ตรวจสัญญาณ LOW ก่อน ฟังก์ชันนี้จะเริ่มนับเวลาในหน่วยไมโครวินาที และรอจนกว่าจะเจอสัญญาณ HIGH ถึงจะหยุดนับเวลา
distance = (duration/2) / 29.1; //Calculate the distance (in cm) based on the speed of sound.
      Serial.println(distance);

duration2 = pulseIn(echoPin2, HIGH); //กำหนดให้ตรวจสัญญาณ LOW ก่อน ฟังก์ชันนี้จะเริ่มนับเวลาในหน่วยไมโครวินาที และรอจนกว่าจะเจอสัญญาณ HIGH ถึงจะหยุดนับเวลา
distance2 = (duration2/2) / 29.1; //Calculate the distance (in cm) based on the speed of sound.
      Serial.println(distance2);




      
 if(distance <= 8 && distance >= 0){ //distance 1-10
      Serial.println("Found object!");
      digitalWrite(ledpin, HIGH);
      if (distance2 <= 5 && distance2 >= 0){ //Water sensor 
        digitalWrite(Motor,HIGH); // Motor ทำงาน
        Serial.println("Processing");}
      else  {
        digitalWrite(Motor,LOW); //Motor หยุดการทำงาน
        Serial.println("Done");}

           
  }
else{
  Serial.println("No object found!");
  digitalWrite(ledpin, LOW);
  
  digitalWrite(Motor,HIGH);
  count = 0;
  Serial.print("Count = ");
  Serial.println(count);
  }
   
  delay(200);

      
}
