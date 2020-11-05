#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
SoftwareSerial s(D6,D5);
JsonObject root;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "cnBYMqo_6qH04vyUyIHev29s6ec4aEJm";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JioFi3_816764";
char pass[] = "ILOVEPHYSICS";


float data;
BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  float sensorData = root["data2"];
  float voltage=sensorData*10/1023;
  float current=root["data2"];
  float power=voltage*current;
  
  Blynk.virtualWrite(V5, voltage);
  Blynk.virtualWrite(V6, current);
  Blynk.virtualWrite(V7, power);
}
void setup() {
s.begin(9600);
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(10000L, myTimerEvent);
}

 
void loop() {
  StaticJsonBuffer<1000> jsonBuffer;
  &root = jsonBuffer.parseObject(s);
  if (root == JsonObject::invalid())
    return;
  
 Serial.println(data*10/1023);
 Blynk.run();
 timer.run();
 
}
