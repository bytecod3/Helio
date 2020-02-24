#include <Servo.h>

Servo myservo;
int ldr1 = 4;
int ldr2 = 5;
int val1;
int val2;
int pos=90;

int current_battery_voltage = 0;

void setup()
{
  myservo.attach(11);
  //Serial.begin(9600);
  myservo.write(pos);

}

 void loop(){
    // get the current battery voltage and send it over ESP::: (todo) for communication
    current_battery_voltage = voltageMeasurement();
  
    // read the brightness of the ldrs
    val1 = analogRead(ldr1);
    val2 = analogRead(ldr2);

    // convert the red value to an angle between 0 and 180
    val1 = map(val1, 0, 1023, 0, 180);
    val2 = map(val2, 0, 1023, 0, 180);
    if(val1 > (val2+50)){
     if(pos<180){
      // rotate the servo
         pos=pos+1;
         myservo.write(pos);
         //Serial.println("backward");
         delay(10);
    }
    }else if(val2 > (val1+50)){
    // rotate the servo
      if(pos>0){
      
        pos=pos-1;
        
        myservo.write(pos);
        //Serial.println("forward");
        delay(10);  
        
      }
    }
 }

 // function to measure voltage from the battery being charged
 float voltageMeasurement(){
    // voltage measurement variables
   
    int sum = 0;
    unsigned char sample_count = 10; // current sample number
    float voltage = 0.0; // calculated voltage
    int NUM_SAMPLES =10;
      
    // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES){
      sum += analogRead(A2);
      sample_count++;
      delay(10);
      
    }

    // calculate the voltage using the 5.0 V reference voltage. 5.015 is the callibrated value of the reference voltage
    voltage = (float(sum) / float(NUM_SAMPLES) * 5.015) / 1024.0;

    // todo: send the voltage display for communication

    // voltage multiplied by 11 when using divider that divides by 11. (11.132 is the callibrated voltage divider value)

    // Serial.print(voltage * 11.132);
    // Serial.println(" V");

    // reset variables for the next loop
    sample_count = 0;
    sum = 0;

    return voltage;
 }
