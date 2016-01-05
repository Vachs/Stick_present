/*
 * __author__ = "Tomasz
 * __title__  = "Stick"
 */
#include "LedControl.h"
#include "Servo.h" 
//  Variables
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat
int fadePin = 5;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin

int LEFT = 70;
int RIGHT = 145;
int CENTER = (LEFT+RIGHT)/2;
int pos = CENTER;


// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded!
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat".
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// SERVO 
Servo myservo;                      // tworzy obiekt serwo do sterowania wychylaniem się trzpienia z rączki 

// Regards Serial OutPut  -- Set This Up to your needs
static boolean serialVisual = true;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse


LedControl lc = LedControl(12, 11, 10, 2); // Definicja pinów dla wyświetlania

void setup()
{
  pinMode(blinkPin, OUTPUT);        // pin that will blink to your heartbeat!
  pinMode(fadePin, OUTPUT);         // pin that will fade to your heartbeat!
  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS
  // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE,
  // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
  //   analogReference(EXTERNAL);

  // doczepiam servo 
  myservo.attach(9);                // podpięte pod 9 PIN PWN

  lc.shutdown(0, false); // Wake up displays
  lc.shutdown(1, false);
  lc.setIntensity(0, 5); // Set intensity levels
  lc.setIntensity(1, 5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);

  // pokaz wiadomosc powitalna
  //welcome_msg();
}



void loop()
{
  magicGoes();
  //show_heartoff;
}

void ledFadeToBeat() {
  fadeRate -= 15;                         //  set LED fade value
  fadeRate = constrain(fadeRate, 0, 255); //  keep LED fade value from going into negative numbers!
  analogWrite(fadePin, fadeRate);         //  fade LED
}

/*
* funkcja odpowiadająca za działanie całej magii związanej z sercem :v
*/
void magicGoes() {
  serialOutput() ;

  //if (QS == true && BPM <= 160){     // A Heartbeat Was Found
  if (QS == true) {    // A Heartbeat Was Found
    // BPM and IBI have been Determined
    // Quantified Self "QS" true when arduino finds a heartbeat
    digitalWrite(blinkPin, HIGH);    // Blink LED, we got a beat.
    fadeRate = 255;         // Makes the LED Fade Effect Happen
    // Set 'fadeRate' Variable to 255 to fade LED with pulse
    serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.
    QS = false;                      // reset the Quantified Self flag for next time
  }


  ledFadeToBeat();                      // Makes the LED Fade Effect Happen
  delay(20);                             //  take a break
}


void goleft(){
  for(pos = LEFT; pos <= RIGHT; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
}

void goright(){
  for(pos = RIGHT; pos <= LEFT; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
}

/*
 * Przykładowa
 */
void example_direction()
{
  /*
    show(byte_fow);
  delay(500);
  show(byte_upright);
  delay(500);
  show(byte_right);
  delay(500);
   delay(500);
  show(byte_downright);
  delay(500);
  show(byte_downleft);
  delay(500);
   delay(500);
  show(byte_left);
  delay(500);
  show(byte_upleft);
  delay(500);
  */
}
