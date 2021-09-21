
#include <HX711_ADC.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif

//pins:
const int HX711_dout = 3; //mcu > HX711 dout pin
const int HX711_sck = 2; //mcu > HX711 sck pin

//2nd load cell
const int HX711_dout2 = 6; //mcu > HX711 dout pin
const int HX711_sck2 = 7; //mcu > HX711 sck pin

//3rd load cell
const int HX711_dout3 = 5; //mcu > HX711 dout pin
const int HX711_sck3 = 4; //mcu > HX711 sck pin

//4th load cell
const int HX711_dout4 = 9; //mcu > HX711 dout pin
const int HX711_sck4 = 8; //mcu > HX711 sck pin

//HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);

//2nd load cell
HX711_ADC LoadCell2(HX711_dout2, HX711_sck2);

//3rd load cell
HX711_ADC LoadCell3(HX711_dout3, HX711_sck3);

//4th load cell
HX711_ADC LoadCell4(HX711_dout4, HX711_sck4);

const int calVal_calVal_eepromAdress = 0;
unsigned long t = 0;
float j,i ;
void setup() {
  Serial.begin(57600); delay(10);
  Serial.println();
  Serial.println("Starting...");

  float calibrationValue; // calibration value
  calibrationValue = 65.43; // uncomment this if you want to set this value in the sketch
#if defined(ESP8266) || defined(ESP32)
  //EEPROM.begin(512); // uncomment this if you use ESP8266 and want to fetch this value from eeprom
#endif
  //EEPROM.get(calVal_eepromAdress, calibrationValue); // uncomment this if you want to fetch this value from eeprom

//2nd load cell
float calibrationValue2; // calibration value
  calibrationValue2 = 65.43*2; // uncomment this if you want to set this value in the sketch

//3rd load cell
float calibrationValue3; // calibration value
  calibrationValue2 = 65.43*2; // uncomment this if you want to set this value in the sketch

//4th load cell
float calibrationValue4; // calibration value
  calibrationValue2 = 65.43*2; // uncomment this if you want to set this value in the sketch


  LoadCell.begin();
  unsigned long stabilizingtime = 2000; // tare preciscion can be improved by adding a few seconds of stabilizing time
  boolean _tare = true; //set this to false if you don't want tare to be performed in the next step
  LoadCell.start(stabilizingtime, _tare);
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
  }
  else {
    LoadCell.setCalFactor(calibrationValue); // set calibration factor (float)
    Serial.println("Startup is complete");
  }
  while (!LoadCell.update());
  Serial.print("Calibration value: ");
  Serial.println(LoadCell.getCalFactor());
  Serial.print("HX711 measured conversion time ms: ");
  Serial.println(LoadCell.getConversionTime());
  Serial.print("HX711 measured sampling rate HZ: ");
  Serial.println(LoadCell.getSPS());
  Serial.print("HX711 measured settlingtime ms: ");
  Serial.println(LoadCell.getSettlingTime());
  Serial.println("Note that the settling time may increase significantly if you use delay() in your sketch!");
  if (LoadCell.getSPS() < 7) {
    Serial.println("!!Sampling rate is lower than specification, check MCU>HX711 wiring and pin designations");
  }
  else if (LoadCell.getSPS() > 100) {
    Serial.println("!!Sampling rate is higher than specification, check MCU>HX711 wiring and pin designations");
  }

//2nd load cell
  LoadCell2.begin();
  unsigned long stabilizingtime2 = 2000; // tare preciscion can be improved by adding a few seconds of stabilizing time
  boolean _tare2 = true; //set this to false if you don't want tare to be performed in the next step
  LoadCell2.start(stabilizingtime2, _tare2);
  if (LoadCell2.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
  }
  else {
    LoadCell2.setCalFactor(calibrationValue2); // set calibration factor (float)
    Serial.println("Startup is complete");
  }
  while (!LoadCell2.update());
  Serial.print("Calibration value: ");
  Serial.println(LoadCell2.getCalFactor());
  Serial.print("HX711 measured conversion time ms: ");
  Serial.println(LoadCell2.getConversionTime());
  Serial.print("HX711 measured sampling rate HZ: ");
  Serial.println(LoadCell2.getSPS());
  Serial.print("HX711 measured settlingtime ms: ");
  Serial.println(LoadCell2.getSettlingTime());
  Serial.println("Note that the settling time may increase significantly if you use delay() in your sketch!");
  if (LoadCell2.getSPS() < 7) {
    Serial.println("!!Sampling rate is lower than specification, check MCU>HX711 wiring and pin designations");
  }
  else if (LoadCell2.getSPS() > 100) {
    Serial.println("!!Sampling rate is higher than specification, check MCU>HX711 wiring and pin designations");
  }

//3rd load cell
  LoadCell3.begin();
  unsigned long stabilizingtime3 = 2000; // tare preciscion can be improved by adding a few seconds of stabilizing time
  boolean _tare3 = true; //set this to false if you don't want tare to be performed in the next step
  LoadCell3.start(stabilizingtime3, _tare3);
  if (LoadCell3.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
  }
  else {
    LoadCell3.setCalFactor(calibrationValue3); // set calibration factor (float)
    Serial.println("Startup is complete");
  }
  while (!LoadCell3.update());
  Serial.print("Calibration value: ");
  Serial.println(LoadCell3.getCalFactor());
  Serial.print("HX711 measured conversion time ms: ");
  Serial.println(LoadCell3.getConversionTime());
  Serial.print("HX711 measured sampling rate HZ: ");
  Serial.println(LoadCell3.getSPS());
  Serial.print("HX711 measured settlingtime ms: ");
  Serial.println(LoadCell3.getSettlingTime());
  Serial.println("Note that the settling time may increase significantly if you use delay() in your sketch!");
  if (LoadCell3.getSPS() < 7) {
    Serial.println("!!Sampling rate is lower than specification, check MCU>HX711 wiring and pin designations");
  }
  else if (LoadCell3.getSPS() > 100) {
    Serial.println("!!Sampling rate is higher than specification, check MCU>HX711 wiring and pin designations");
  }

//4th load cell
  LoadCell4.begin();
  unsigned long stabilizingtime4 = 2000; // tare preciscion can be improved by adding a few seconds of stabilizing time
  boolean _tare4 = true; //set this to false if you don't want tare to be performed in the next step
  LoadCell4.start(stabilizingtime4, _tare4);
  if (LoadCell4.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
  }
  else {
    LoadCell4.setCalFactor(calibrationValue4); // set calibration factor (float)
    Serial.println("Startup is complete");
  }
  while (!LoadCell4.update());
  Serial.print("Calibration value: ");
  Serial.println(LoadCell4.getCalFactor());
  Serial.print("HX711 measured conversion time ms: ");
  Serial.println(LoadCell4.getConversionTime());
  Serial.print("HX711 measured sampling rate HZ: ");
  Serial.println(LoadCell4.getSPS());
  Serial.print("HX711 measured settlingtime ms: ");
  Serial.println(LoadCell4.getSettlingTime());
  Serial.println("Note that the settling time may increase significantly if you use delay() in your sketch!");
  if (LoadCell4.getSPS() < 7) {
    Serial.println("!!Sampling rate is lower than specification, check MCU>HX711 wiring and pin designations");
  }
  else if (LoadCell4.getSPS() > 100) {
    Serial.println("!!Sampling rate is higher than specification, check MCU>HX711 wiring and pin designations");
  }

}

void loop() {
  static boolean newDataReady = 0;
  const int serialPrintInterval = 500; //increase value to slow down serial print activity

//2nd load cell
   static boolean newDataReady2 = 0;
  const int serialPrintInterval2 = 500; //increase value to slow down serial print activity

//3rd load cell
   static boolean newDataReady3 = 0;
  const int serialPrintInterval3 = 500; //increase value to slow down serial print activity

//4th load cell
   static boolean newDataReady4 = 0;
  const int serialPrintInterval4 = 500; //increase value to slow down serial print activity


  // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;

//2nd load cell
  // check for new data/start next conversion:
  if (LoadCell2.update()) newDataReady2 = true;

//3rd load cell
  // check for new data/start next conversion:
  if (LoadCell3.update()) newDataReady3 = true;

//4th load cell
  // check for new data/start next conversion:
  if (LoadCell4.update()) newDataReady4 = true;

  

   //get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell.getData();
      
      newDataReady = 0;
      t = millis();
    }
  }

//2nd load cell
  if (newDataReady2) {
    if (millis() > t + serialPrintInterval2) {
      float j = LoadCell2.getData();
      newDataReady2 = 0;
      t = millis();
    }
  }

//3rd load cell
  if (newDataReady3) {
    if (millis() > t + serialPrintInterval3) {
      float j = LoadCell3.getData();
      newDataReady3 = 0;
      t = millis();
    }
  }

//4th load cell
  if (newDataReady4) {
    if (millis() > t + serialPrintInterval4) {
      float j = LoadCell4.getData();
      newDataReady4 = 0;
      t = millis();
    }
  }
     // Serial.print("Load_cell : ");
      //Serial.print("\t");
      Serial.print(LoadCell.getData());
      Serial.print("\t");
      Serial.print(LoadCell2.getData());
      Serial.print("\t");
      Serial.print(LoadCell3.getData());
      Serial.print("\t");
      Serial.println(LoadCell4.getData());
      Serial.print("\t");
  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }

}
