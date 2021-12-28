// the numbers of leds pins
//9 (index 0) - most left, 13 (index 4) - most right
int led[5] = {9, 10, 11, 12, 13};

void setup() {
  // initialize the digital pin as an output.
  pinMode(led[0], OUTPUT);   
  pinMode(led[1], OUTPUT); 
  pinMode(led[2], OUTPUT); 
  pinMode(led[3], OUTPUT); 
  pinMode(led[4], OUTPUT); 

  //open the serial port
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 5; i++)
  {
     digitalWrite(led[i], HIGH);
     delay(1000);
     digitalWrite(led[i], LOW);
  }
}
