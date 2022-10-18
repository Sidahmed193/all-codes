// On Leonardo/Micro or others with hardware serial, use those! #0 is green wire, #1 is white
// uncomment this line:
// #define mySerial Serial1

// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// comment these two lines if using hardware serial
#include <Wire.h>
#include <Adafruit_Fingerprint.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h> 

#define I2C_ADDR 0x27          //LCD i2c stuff
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

SoftwareSerial mySerial(2, 3);
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin); //LCD declaring
//LiquidCrystal_I2C lcd(0x27, 16,2);//
Servo myservo;        
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int bluePin = 10; 
int redPin=11;
int pos = 0;         
void setup()  
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin,OUTPUT);
  myservo.attach(9); 
  lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();
  
  finger.getTemplateCount();        //Counts the number of templates stored in the sensor flash memory
  lcd.setCursor(0,0);
  lcd.clear();
  
  //while (!Serial);  // For Yun/Leo/Micro/Zero/...
  //delay(100);
  lcd.print("Adafruit finger");
  lcd.setCursor(0,1);
  lcd.print("detect test");
  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  lcd.clear();
  if (finger.verifyPassword()) {
    
    //lcd.setCursor(0,0);
    lcd.print("Foundfingerprint");
    lcd.setCursor(0,1);
  lcd.print(" sensor!");
  } else {
    lcd.print("Did not find ");
    lcd.setCursor(0,1);
    lcd.print("finger sensor");
    while (1) { delay(1); }
  }
  
  finger.getTemplateCount();
  lcd.clear();
  lcd.print("Sensor contains");
  lcd.setCursor(0,1);
  lcd.print(finger.templateCount);
  lcd.print(" templates");
  lcd.clear();
  lcd.print("Waiting for");
  lcd.setCursor(0,1);
  lcd.print("valid finger...");

  
}

void loop()                  
{
  getFingerprintIDez();
  delay(200);            //don't ned to run this at full speed.
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      lcd.print("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      lcd.print("No finger");
      lcd.setCursor(0,1);
      lcd.print("detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.print("Communication");
      lcd.setCursor(0,1);
      lcd.print("error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      lcd.print("Imaging error");
      return p;
    default:
      lcd.print("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      lcd.print("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      lcd.print("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.print("Communication");
      lcd.setCursor(0,1);
      lcd.print("error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      lcd.print("Could not find");
      lcd.setCursor(0,1);
      lcd.print("fingpint feature");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      lcd.clear();
      lcd.print("Could not find");
      lcd.setCursor(0,1); 
      lcd.print("fingpint feature");
      return p;
    default:
      lcd.print("Unknown error");
      return p;
  }
  
 
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    lcd.print("Found a print match!");
    
    //open the door
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    lcd.print("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    lcd.print("Did not find a match");
    return p;
  } else {
    lcd.print("Unknown error");
    return p;
  }   
  
  // lcd.clear();
  // lcd.print("Found ID #"); lcd.print(finger.fingerID); 
  // delay(200);
  //lcd.print(" with confidence of "); 
  //lcd.setCursor(0,1);
  //lcd.print(finger.confidence);
  

  return finger.fingerID;
}


int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  {
    digitalWrite(redPin,HIGH);
    delay(200);
    digitalWrite(redPin,LOW);
    delay(5);
    return -1;
  }
  lcd.print("Found ID #"); lcd.print(finger.fingerID); 
  delay(200);
  lcd.clear();
  lcd.print(" with confidence of "); lcd.println(finger.confidence);
    digitalWrite(bluePin, HIGH);
    digitalWrite(bluePin, LOW); 
    delay(5); 
     for(pos = 0; pos<90; pos+=1){
            myservo.write(pos);            
            delay(15);                       
    }
    
    for(pos = 90; pos>=1; pos -= 1) {
          myservo.write(pos);           
          delay(15);                    
    }
}