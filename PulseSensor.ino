void serialOutput(){   // Decide How To Output Serial.
 if (serialVisual == true){
     arduinoSerialMonitorVisual('-', Signal);   // goes to function that makes Serial Monitor Visualizer
 } else{
      sendDataToSerial('S', Signal);     // goes to sendDataToSerial function
 }
}


//  Decides How To OutPut BPM and IBI Data
void serialOutputWhenBeatHappens(){
 if (serialVisual == true){            //  Code to Make the Serial Monitor Visualizer Work
    Serial.print("*** Heart-Beat Happened *** ");  //ASCII Art Madness
    Serial.print("BPM: ");
    Serial.print(BPM);
    Serial.print("  ");

    // Put #1 frame on both Display
    show_beat();
    if(BPM > 50 && BPM <= 60) showhr50();
    else if(BPM > 60 && BPM <= 70) showhr60();
    else if(BPM > 70 && BPM <= 80) showhr70();
    else if(BPM > 80 && BPM <= 90) showhr80();
    else if(BPM > 90 && BPM <= 100) showhr90();
    else if(BPM > 100 && BPM <= 110) showhr100();
    else if(BPM > 110 && BPM <= 120) showhr110();
    else if(BPM > 120 && BPM <= 130) showhr120();
    else if(BPM > 130 && BPM <= 140) showhr130();
    else if(BPM > 140 && BPM <= 150) showhr140();
    else if(BPM > 150 && BPM <= 170) showhr150();



 } else{
        sendDataToSerial('B',BPM);   // send heart rate with a 'B' prefix
        sendDataToSerial('Q',IBI);   // send time between beats with a 'Q' prefix

 }
}


//  Sends Data to Pulse Sensor Processing App, Native Mac App, or Third-party Serial Readers.
void sendDataToSerial(char symbol, int data ){
    Serial.print(symbol);

    Serial.println(data);
  }


//  Code to Make the Serial Monitor Visualizer Work
void arduinoSerialMonitorVisual(char symbol, int data ){
  const int sensorMin = 0;      // sensor minimum, discovered through experiment
const int sensorMax = 1024;    // sensor maximum, discovered through experiment

  int sensorReading = data;
  // map the sensor range to a range of 12 options:
  int range = map(sensorReading, sensorMin, sensorMax, 0, 11);
}
