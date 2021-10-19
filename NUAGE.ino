/*
  Zoe Caudron

  Made using some code from the Button and StateDetected code examples
  Each player moves the light towards themselves by clicking the button. After a set number of clicks (which they do not know), the program stops on a set LED for 6 seconds.
  The LED colour corresponds to a conversation topic, from light hearted (music, hobbies) to more private topics (what would you like to happen after you pass away). For now the topics are arbitrarily selected but would be randomised ideally.
  The silk paper helps turn the harsh lights into a more comforting soft glow, making the experience reassuring and visually pleasing, which helps opening up to others.
  
*/

//--------------- INITIAL PINS AND VARIABLES -------------------------------------------------

// constants won't change. They're used here to set pin numbers:
// Two buttons control 5 LEDs

const int buttonPin0 = 2;
const int buttonPin1 = 7;
const int ledPin0 = 13;
const int ledPin1 = 12;
const int ledPin2 = 11;
const int ledPin3 = 10;
const int ledPin4 = 9;

//array - not fully sure how to use them so set aside for now
//int leds[numOfL] = {ledPin0, ledPin1, ledPin2, ledPin3, ledPin4};

// variables will change:
int buttonCount = 0;         // between 0 and 4, each button click moves it +1 or -1. Helps select a LED to set on HIGH
int lastButtonStateR = 0;    // For state change detection, stores last button status. One for each button, L and R
int lastButtonStateL = 0;
int buttonStateR = 0;        // For state change detection, stores current button status. One for each button, L and R
int buttonStateL = 0;
int allCount = 0;            // Stores the total number of clicks. Past a certain value, the program pauses and the value is set back to 0 to start a new cycle


//--------------- INITIAL SETUP -------------------------------------------------


void setup() {

  // initialize the LED pins as an output:

  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  // initialize the pushbutton pins as an input:

  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);

  // initialize serial communication - not fully sure what that is yet

  Serial.begin(9600);

}

//--------------- PROGRAM -------------------------------------------------

void loop() {


  // read the state of the pushbuttons values:

  buttonStateR = digitalRead(buttonPin0);
  buttonStateL = digitalRead(buttonPin1);


  // compare the R buttonState to its previous state

  if (buttonStateR != lastButtonStateR) {

    // if the state has changed, increment the counter
    if (buttonStateR == HIGH) {

      // if the current state is HIGH then buttonCount increments and allCount increments:
      buttonCount++;
      allCount++;

      // Delay a little bit to avoid bouncing
      delay(50);
    }
  }
  // save the current state as the last state, for next time through the loop
  lastButtonStateR = buttonStateR;

  // compare the L buttonState to its previous state
  if (buttonStateL != lastButtonStateL) {

    // if the state has changed, increment the counter
    if (buttonStateL == HIGH) {

      // if the current state is HIGH then buttonCount decreases and allCount increments:
      buttonCount--;
      allCount++;

      // Delay a little bit to avoid bouncing
      delay(50);
    }
  }

  // save the current state as the last state, for next time through the loop
  lastButtonStateL = buttonStateL;


  // Making sure the buttonCount values don't go past 4 or under 0 and insures no weird jumps in LEDs
  if (buttonCount > 4 ) {
    buttonCount = 4;
  }
  if (buttonCount < 0) {
    buttonCount = 0;
  }

  // Serial.println(buttonCount);   making sure the buttonCount values are stored and respond properly
  //  int i = buttonCount;



  // LED selection! each has a number linked to its position on the board

  if (i == 0) {
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
  else if (i == 1) {
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
  else if (i == 2) {
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
  else if (i == 3) {
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
  }
  else if (i == 4) {
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
  }


  // After 30 total clicks, the program pauses for 6 seconds, allowing only one LED to be lit up. 6s is an arbitrary value, long enough for players to understand the LEDs won't change again.
  // allCount gets set back to 0 to allow for a new cycle once players are done discussiong the topic.
  if (allCount > 30) {
    delay(6000);
    allCount = 0;

  }

}
