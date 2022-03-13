
//////////////////////////////////
//   DEVICE-SPECIFIC SERVICES   //
//////////////////////////////////

struct DEV_Identify : Service::AccessoryInformation {

  int nBlinks;                    // number of times to blink built-in LED in identify routine
  SpanCharacteristic *identify;   // reference to the Identify Characteristic
  
  DEV_Identify(const char *name, const char *manu, const char *sn, const char *model, const char *version, int nBlinks) : Service::AccessoryInformation(){
    
    new Characteristic::Name(name);                   // create all the required Characteristics with values set based on above arguments
    new Characteristic::Manufacturer(manu);
    new Characteristic::SerialNumber(sn);    
    new Characteristic::Model(model);
    new Characteristic::FirmwareRevision(version);
    identify=new Characteristic::Identify();          // store a reference to the Identify Characteristic for use below

    this->nBlinks=nBlinks;                            // store the number of times to blink the LED

    //pinMode(2,OUTPUT);          // make sure LED is set for output
  }

  boolean update(){
       
    return(true);                               // return true
    
  } // update
  
};
