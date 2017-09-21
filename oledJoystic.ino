#include <SPI.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


 int joyPinX1 = 14;                 // slider variable connecetd to analog pin 0
 int joyPinY1 = 15;                 // slider variable connecetd to analog pin 1
 int joyPinX2 = 16;
 int joyPinY2 = 17;
 int valueX1 = 0;                  // variable to read the value from the analog pin 0
 int valueX2 = 0;                  // variable to read the value from the analog pin 1
 int valueY1 = 0;
 int valueY2 = 0;
 int joySW1 = 5;
 int joySW2 = 6;
 int valueSW1 = 0;
 int valueSW2 = 0;
 int one = 0,two = 0;
 int LED = A6;

void setup() {
 // Serial.begin(9600);

   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  pinMode(joySW1, INPUT_PULLUP);
  pinMode(joySW2, INPUT_PULLUP);
  pinMode(LED,OUTPUT);

}

void loop() {
  valueX1 = analogRead(joyPinX1);  
  valueY1 = analogRead(joyPinY1);  
  valueX2 = analogRead(joyPinX2);
  valueY2 = analogRead(joyPinY2);
  valueSW1 = digitalRead(joySW1);
  valueSW2 = digitalRead(joySW2);
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("X1 : ");
  display.print(valueX1);
  display.setCursor(65,0);
  display.print("Y1 : ");
  display.println(valueY1);
  display.print("X2 : ");
  display.print(valueX2);
  display.setCursor(65,8);
  display.print("Y2 : ");
  display.println(valueY2);
  display.print("J1: ");
  if(valueSW1 == LOW){
  display.print("True");
  one = 1;
  }
  else{
  display.print("False");
  one = 0;
  }
  display.setCursor(65,17);
  display.print("J2: ");
  if(valueSW2 == LOW){
  display.print("True");
  two = 1;
  }
  else{
  display.print("False");
  two = 0;
  }
  if(valueSW2 == HIGH && valueSW1 == HIGH){
    analogWrite(LED,0);
  }
  display.display();

  
  
  delay(100);
}
