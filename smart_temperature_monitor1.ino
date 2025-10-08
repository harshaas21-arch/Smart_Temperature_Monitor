#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Setting the LCD address and dimensions (e.g., 0x27 for a 16x2 LCD)
// You may need to change the address if it's different.
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// C++ code
void setup()
{
  // Initializing the LCD
  lcd.init();
  lcd.backlight();
  
  // Printing a welcome message on the LCD
  lcd.print("Temp Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  
  // Setting up pins for LEDs
  pinMode(8, OUTPUT); // Red LED
  pinMode(9, OUTPUT); // Green LED 
  pinMode(10, OUTPUT);// Yellow LED
  pinMode(A0, INPUT);// Temperature sensor

  delay(2000); 
  lcd.clear(); // Clearing the screen after the message is shown
}

void loop()
{
  int sensor_value = analogRead(A0); //Reading the sensor_value from pin A0
  float Voltage = (sensor_value / 1023.0) * 5.0; // Converting it to a set of distinct values
  float Temperature_C = (Voltage - 0.5) * 100.0;
  
  // Displaying the temperature on the LCD
  lcd.setCursor(0, 0); // Settng cursor to the first line, first character
  lcd.print("Temp: ");
  lcd.print(Temperature_C, 1); // Printing temperature with one decimal place
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("                "); // Printing spaces to clear the line
  lcd.setCursor(0, 1);
  
  if(Temperature_C <= 10) { // 1st condition
    digitalWrite(10, HIGH); 
    digitalWrite(9, LOW);  
    digitalWrite(8, LOW);
    lcd.print("Too Cold!!");
  } 
  else if(Temperature_C > 10 && Temperature_C <= 35) { // 2nd condition
    digitalWrite(9, HIGH); 
    digitalWrite(10, LOW);  
    digitalWrite(8, LOW);
    lcd.print("Perfect Temp");
  } 
  else if(Temperature_C > 35) { // 3rd condition
    digitalWrite(8, HIGH); 
    digitalWrite(9, LOW);  
    digitalWrite(10, LOW);
    lcd.print("Too Hot!!");
  }
}