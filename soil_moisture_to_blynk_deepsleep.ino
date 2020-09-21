//// ################################################################################
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "<TOKEN>";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "<SSID>";
char pass[] = "<PASS>";

BlynkTimer timer;

// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void readSensor()
{
  #define SensorPin A0
  float sensorData = analogRead(SensorPin);
  Blynk.virtualWrite(V5, sensorData);
   
}

void goToSleep(){

  // Go to sleep for 60 minutes
  ESP.deepSleep(60 * 60e6);
  
}

void setup()
{
  
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every second
  timer.setInterval(1000L, readSensor);
  timer.setInterval(5000L, goToSleep); goToSleep;
  
}

void loop()
{
  
Blynk.run();
timer.run(); // Initiates BlynkTimer

}
