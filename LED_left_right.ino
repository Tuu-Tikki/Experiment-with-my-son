/*
 * Author: MIUZEI
 * IDE V1.6.9
 * Email:support@miuzeipro.com
 */
// the numbers of leds pins
//9 (index 0) - most left, 13 (index 4) - most right
int led[5] = {9, 10, 11, 12, 13};

// the number of the pushbutton pin
const int b_right = 2;     
const int b_left = 4;

// variable for reading the pushbutton status
int b_right_state = LOW;
int b_left_state = LOW;

//current HIGH led index
int current = -1;

//delay time
int pause = 200;
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led[0], OUTPUT);   
  pinMode(led[1], OUTPUT); 
  pinMode(led[2], OUTPUT); 
  pinMode(led[3], OUTPUT); 
  pinMode(led[4], OUTPUT);   

  // initialize the pushbutton pin as an input:
  pinMode(b_right, INPUT);
  pinMode(b_left, INPUT);

  //open the serial port
  Serial.begin(9600);
}

//return the index of the led with HIGH state or -1
int high_led()
{
   int led_index = -1;
   for (int i = 0; i < 5; i++)
   {
      if(digitalRead(led[i]))
      {
         return i;
      }
   }
   return led_index;  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the state of the pushbutton value
  b_right_state = digitalRead(b_right);
  b_left_state = digitalRead(b_left);
  
  // check if the pushbutton "right" is pressed
  if (b_right_state == HIGH)
  {
    Serial.println("b_right is pressed");
    //find the current HIGH led and shift it right
    current = high_led();
    Serial.println(current);
    if (current > -1 && current < 4)
    {
      digitalWrite(led[current], LOW);
      Serial.println("current led is LOW");
      digitalWrite(led[current + 1], HIGH);
      Serial.println("next right led is HIGH");
    }
    else
    {
      digitalWrite(led[4], HIGH);
      Serial.println("most right led is HIGH");
    }  
    //to prevent very fast toggle
    delay(pause);  
  }
  
  // check if the pushbutton "left" is pressed
  if (b_left_state == HIGH)
  {
    Serial.println("b_left is pressed");
    //find the current HIGH led and shift it left
    current = high_led();
    Serial.println(current);
    if (current > 0 && current < 5)
    {
      digitalWrite(led[current], LOW);
      Serial.println("current led is LOW");
      digitalWrite(led[current - 1], HIGH);
      Serial.println("next left led is HIGH");
    }
    else
    {
      digitalWrite(led[0], HIGH);
      Serial.println("most left led is HIGH");
    }  
    //to prevent very fast toggle
    delay(pause); 
  } 
}
