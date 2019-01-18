int soundDetectedPin = 10;
int soundDetectedVal = HIGH; // This is where we record our Sound Measurement
boolean bAlarm = false;

unsigned long lastSoundDetectTime; // Record the time that we measured a sound



const int UNIT = 200;
const int dotT = UNIT;
const int dashT = 3*UNIT;
const int spaceT = 5*UNIT;
int soundAlarmTime = UNIT;

void setup ()
{
  Serial.begin(9600);  
  pinMode (soundDetectedPin, INPUT) ; // input from the Sound Detection Module
}

void getIt(){
  soundDetectedVal = digitalRead (soundDetectedPin) ; // read the sound alarm time
  String cuvant = "";
  if (soundDetectedVal == LOW) // If we hear a sound
  {
    lastSoundDetectTime = millis(); 
    if (!bAlarm){
      cuvant = cuvant + "1";
      bAlarm = true;
    }
  }
  else
  {
    if( (millis()-lastSoundDetectTime) > 5*UNIT){
      Serial.println(millis() - lastSoundDetectTime);
      cuvant = cuvant + " ";
      bAlarm = false;
    }
  }
  //translate
}


void loop ()
{
  getIt();

  
}
