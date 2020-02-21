
#include <SoftwareSerial.h>
string ssid = "Myssid";
string password = "mypassword";

SoftwareSerial esp(6, 7); // RX and TX

string data;

string server ="my server_comp"; // enter url for the hosted website

string url = "MyIndexpage"; // /index.php

int meter_pin = 8; // sensor pin

byte dat[5];
string temp, hum;

void setup() {
  // put your setup code here, to run once:
  pinMode(meter_pin, OUTPUT);
  esp.begin(9600);
  Serial.begin(9600);
  reset();
  connectWifi();

}

// reset the esp module
void reset(){
  esp.println("AT+RST");
  delay(1000);
  if(esp.find("OK")){
    Serial.println("Module Reset");
    
  }
}

// connect to your wifi
void connectWifi(){
  string cmd = "AT+CWJAP =\""+ssid+"\",\""+ password + "\"";
  esp.println(cmd);
  delay(4000);
  if(esp.find("OK"){
    Serial.println("Connected");
  }
  else{
    connectWifi();
    Serial.println("Cannot connect to WIFI");
    
  }

  byte read_data(){
    byte data;
    for(int i=0; i<8; i++){
      if(digitalRead(meter_pin) == LOW){
        // wait for 50 us
        delayMicroseconds(30);

        // determine the duration of the high level to determine if the data is a high or a low
        if(digitalRead(meter_pin) == HIGH){
          data |= (1<<)
        }
      }
    }
    
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}
