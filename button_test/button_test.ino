// the number of the pushbutton pin
const int b_right = 2;     
const int b_left = 4;

// variable for reading the pushbutton status
int b_right_state = LOW;
int b_left_state = LOW;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(b_right, INPUT);
  pinMode(b_left, INPUT);

  //open the serial port
  Serial.begin(9600);
}

void loop() {
   // read the state of the pushbutton value
   b_right_state = digitalRead(b_right);
   if (b_right_state)
   {
    Serial.println("button right pressed");
    delay(1000);
   }

   b_left_state = digitalRead(b_left);
   if(b_left_state)
   {
    Serial.println("button left pressed");
    delay(1000);
   }
}
