/*
 * __author__ = "Tomasz
 * __title__  = "Stick"
 */
#include <SoftwareSerial.h>
#include "LedControl.h"
#include "Servo.h"
//  Variables
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat
int statePin = 7;
int fadePin = 5;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin

int LEFT = 70;
int RIGHT = 145;
int CENTER = (LEFT+RIGHT)/2;
int pos = 0;

int wait = 0; // potrzebne do wykrywania połączenia z telefonem

String command = ""; // Stores response of the HC-06 Bluetooth device
// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded!
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat".
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

char inbyte = 0;

// czy debugować
int DEBUG = 1;

// SERVO
Servo myservo;                      // tworzy obiekt serwo do sterowania wychylaniem się trzpienia z rączki
SoftwareSerial mySerial(4, 2); // RX, TX
// Regards Serial OutPut  -- Set This Up to your needs
static boolean serialVisual = true;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse


LedControl lc = LedControl(12, 11, 10, 2); // Definicja pinów dla wyświetlania

void setup()
{
  pinMode(statePin, INPUT);
  pinMode(blinkPin, OUTPUT);        // pin that will blink to your heartbeat!
  pinMode(fadePin, OUTPUT);         // pin that will fade to your heartbeat!
  Serial.begin(36800);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS
  // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE,
  // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
  //   analogReference(EXTERNAL);

  // doczepiam servo
  myservo.attach(9);                // pod    pięte pod 9 PIN PWN
  myservo.write(CENTER);

  lc.shutdown(0, false); // Wake up displays
  lc.shutdown(1, false);
  lc.setIntensity(0, 5); // Set intensity levels
  lc.setIntensity(1, 5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);

  // ustawia Serial i mySerial aby dzialalo jak powinno
  ser();

  // pokaz wiadomosc powitalna
  //welcome_msg(); ta buzka nie jest potrzebna
  if(DEBUG != 1){
    // ekran wczytywania
    welcomeload();
    // animacja szukania telefonu
    phoneanim();
    // animacja startu GPS-u
    gpsanim();
    // wygas ekran, po co się ma marnować prąd
    turnallOFF();

    magicGoes();

    turnallOFF();
    //showhr50;
  }
}



void loop()
{;
  // Read device output if available.
  if (mySerial.available()) {
    while(mySerial.available()) { // While there is more to be read, keep reading.
      command += (char)mySerial.read();
       String help = "";
      // show must go on
      if(command =="10"){
          dollewo();
          myservo.write(70);}
      else if(command == "11"){
          lewo();
          myservo.write(82);}
      else if(command == "12"){
          goralewo();
          myservo.write(94);}
      else if(command == "13"){
          przod();
          myservo.write(106);}
      else if(command == "14"){
          goraprawo();
          myservo.write(118);}
      else if(command == "15"){
          prawo();
          myservo.write(130);
          magicGoes();}
      else if(command == "16"){
          dolprawo();
          myservo.write(145);
        }

    }
    Serial.println(command);
    command = ""; // No repeats
  }

  // Read user input if available.
  if (Serial.available()){
    delay(10); // The delay is necessary to get this working!
    mySerial.write(Serial.read());
  }
}

/* Poprawia to co popsuł producent */
void ser(){
  // Open serial communications:
  Serial.begin(9600);
  Serial.println("Type AT commands!");
  Serial.begin(9600);
  Serial.print("AT+BAUD8");
  Serial.begin(19200);
  Serial.print("AT+BAUD8");
  Serial.begin(38400);
  Serial.print("AT+BAUD8");
  Serial.begin(57600);
  Serial.print("AT+BAUD8");
  Serial.begin(115200);
  Serial.print("AT+BAUD8");
  Serial.begin(230400);
  Serial.print("AT+BAUD8");
  Serial.begin(460800);
  Serial.print("AT+BAUD8");
  Serial.begin(921600);
  Serial.print("AT+BAUD8");
  Serial.begin(1382400);
  Serial.print("AT+BAUD8");
  Serial.begin(115200);
  Serial.print("AT+BAUD8");

  // The HC-06 defaults to 9600 according to the datasheet.
  mySerial.begin(9600);
  mySerial.print("AT+BAUD8");
  mySerial.begin(19200);
  mySerial.print("AT+BAUD8");
  mySerial.begin(38400);
  mySerial.print("AT+BAUD8");
  mySerial.begin(57600);
  mySerial.print("AT+BAUD8");
  mySerial.begin(115200);
  mySerial.print("AT+BAUD8");
  mySerial.begin(230400);
  mySerial.print("AT+BAUD8");
  mySerial.begin(460800);
  mySerial.print("AT+BAUD8");
  mySerial.begin(921600);
  mySerial.print("AT+BAUD8");
  mySerial.begin(1382400);
  mySerial.print("AT+BAUD8");
  mySerial.begin(115200);
  mySerial.print("AT+BAUD8");
}

/* wykrywanie czy moduł jest sparowany z BT */
void telefunken(){
  int button = digitalRead(statePin);
  if(button){
    wait++;
    if(wait == 100){
      phoneanim();
    }
  }else wait = 0;

}

/* przygasa razem z twoim sercem :v */
void ledFadeToBeat() {
  fadeRate -= 15;                         //  set LED fade value
  fadeRate = constrain(fadeRate, 0, 255); //  keep LED fade value from going into negative numbers!
  analogWrite(fadePin, fadeRate);         //  fade LED
}

/*
* funkcja odpowiadająca za działanie całej magii związanej z sercem :v
*/
void magicGoes() {
  for(int i = 0; i <= 100; i++){
    Serial.print(i);
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
}

void demo(){
  myservo.write(60);
  lewo();
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
