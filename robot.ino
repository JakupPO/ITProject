#include <Arduino.h>
#include <IRremote.hpp>

int PWM1 = 6;
int DIR1 = 7;
int PWM2 = 5;
int DIR2 = 4;

void setup()
{
  pinMode(DIR1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  Serial.begin(115200);

  IrReceiver.begin(2, ENABLE_LED_FEEDBACK);
}
void loop()
{
  // Motor power
  int leftMotor = 205;
  int rightMotor = 250;
  
  digitalWrite(DIR1,HIGH);
  digitalWrite(DIR2, HIGH);
  analogWrite(PWM1, leftMotor);   //PWM Speed Control
  analogWrite(PWM2, rightMotor);   //PWM Speed Control
  
  // Print out IR sensor readings
  Serial.print("Sensor A0: ");
  Serial.print(analogRead(A0));
  Serial.print("    ");
  delay(1);
  Serial.print("Sensor A1: ");
  Serial.print(analogRead(A1));
  Serial.print("    ");
  delay(1);
  Serial.print("Sensor A2: ");
  Serial.println(analogRead(A2));

  if (IrReceiver.decode()) {
        if (IrReceiver.decodedIRData.address == 258) {
          Serial.println("LEFT");
        }
        if (IrReceiver.decodedIRData.address == 259) {
          Serial.println("RIGHT");
        }
        if (IrReceiver.decodedIRData.address == 260) {
          Serial.println("UP");
        }
        if (IrReceiver.decodedIRData.address == 261) {
          Serial.println("DOWN");
        }

        IrReceiver.resume();
    }

  // Loop delay
  delay(500);
}
