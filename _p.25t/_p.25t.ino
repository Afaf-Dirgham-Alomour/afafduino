// based on the tutorial from Paul McWhorter
// https://youtu.be/WMkN-uHd-Xo?si=FswJonz2gzZ3iN8w
int lightpen=A0;
int lightval;
int greenled=8;
int redled=13;
void setup() {
 pinMode(lightpen,INPUT);
 pinMode(greenled,OUTPUT);
 pinMode(redled,OUTPUT);
 Serial.begin(9600);
 }

void loop() {
  lightval=analogRead(lightpen);
  Serial.println(lightval);
delay(250);
if(lightval>=200){
digitalWrite(8,HIGH);
delay(250);
digitalWrite(13,LOW);
delay(250);
}
else {
  digitalWrite(13,HIGH);
delay(250);
digitalWrite(8,LOW);
delay(250);
}
}