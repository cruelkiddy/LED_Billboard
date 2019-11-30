
#include <ESP8266WiFi.h>
#include <LedMatrix.h>
#define NUMBER_OF_DEVICES 6
#define CS_PIN 16
LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CS_PIN);
#include <cp437font.h>
#include <SPI.h>
#include "login.h"
#include "Ref.h"

const char* ssid     = "";
const char* password = "";




WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  ledMatrix.init();
  ledMatrix.setIntensity(2);
  ledMatrix.setCharWidth(8);
  ledMatrix.setText(DisplayText);
}

void loop(){
     WiFiClient client = server.available();   // Listen for incoming clients
     if (client){
        String LineBuffer = "";
        while (client.connected()) {
            if (client.available()) {
                LineBuffer = client.readStringUntil('\r');
                if(LineBuffer.indexOf("GET") >= 0){client.println("HTTP/1.1 200 OK");client.println("Content-type:text/html");client.println("Connection: close");client.println();client.println(html);client.println();LineBuffer = "";break;}
                if(LineBuffer.indexOf("EOF") >= 0){Serial.println(LineBuffer);Control_Send(LineBuffer);LineBuffer = "";break;}
                LineBuffer = "";
            }
        }
     }
     // Serial.println(Mode);
     if(Mode){
         //
         ledMatrix.clear();
         ledMatrix.scrollTextLeft();

         ledMatrix.drawText();
         ledMatrix.commit(); 
         delay(50);
     }
     else{
        //ledMatrix.setIntensity(Intensity);
        ledMatrix.clear();
        ledMatrix.commit();
        delay(50);

        ledMatrix.scrollTextLeft();

        ledMatrix.drawText();
        ledMatrix.commit(); 
        delay(50);      
    }
     
}
