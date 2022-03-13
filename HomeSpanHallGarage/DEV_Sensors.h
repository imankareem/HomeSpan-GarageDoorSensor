
////////////////////////////////////
//   DEVICE-SPECIFIC LED SERVICES //
////////////////////////////////////

#include <Wire.h>
#define BUTTON_PIN 21 // GIOP21 pin 

struct DEV_TempSensor : Service::TemperatureSensor {     // A standalone Temperature sensor

  SpanCharacteristic *temp;                          // reference to the Current Temperature Characteristic
  uint32_t timer=0;                                  // keep track of time since last update
  
  DEV_TempSensor() : Service::TemperatureSensor(){       // constructor() method

    double tempC=getHal();
             
    temp=new Characteristic::CurrentTemperature(tempC);       // instantiate the Current Temperature Characteristic
    temp->setRange(0,1);                                  // expand the range from the HAP default of 0-200 for Hall Effect reading.
        
    //Serial.printf("Configuring Hall Effect Sensor %0.2f C.\n",tempC);           // initialization message
    pinMode(BUTTON_PIN, INPUT_PULLUP);
  } // end constructor

  void loop(){

    char c[64];
    

    if(millis()-timer>2000){                // only sample every 2 seconds
      timer=millis();
      
          double tempC=getHal();
          

      if(abs(temp->getVal<double>()-tempC)>0){    // only update Hall only if change is more than 0.    
        temp->setVal(tempC);                        // set the new temperature; this generates an Event Notification and also resets the elapsed time        
        sprintf(c,"Hall Effect Sensor Update %g\n",tempC);
      }
    }
    
  } // loop

  double getHal(){
  double Val;
  int buttonState = digitalRead(BUTTON_PIN);  
  //Serial.println(buttonState);
    if(buttonState == LOW){
      Serial.println("The button is pressed");
      Val = 1.00;}
    else if(buttonState == HIGH){
      Serial.println("The button is released");
      Val = 0.00;}
    
    //Val = hallRead();
    //Val = abs(Val); //kill negative values (mag polarity). "The default range of allowed values is 0-240" can't have negative values.
    //Serial.println(Val);//to graph 
    return(Val);    
  }
  
};
      
//////////////////////////////////
