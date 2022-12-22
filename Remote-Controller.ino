#include <IRremote.hpp>

#define DELAY_AFTER_SEND 50

const int leftPin = 4;
const int rightPin = 5;
const int upPin = 7;
const int downPin = 6;

int leftState = 0;
int rightState = 0;
int upState = 0;
int downState = 0;

uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

void setup() {
    Serial.begin(115200);
    IrSender.begin(3, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin
    
    // initialize the pushbutton pin as an input:
    pinMode(leftPin, INPUT);
    pinMode(rightPin, INPUT);
    pinMode(upPin, INPUT);
    pinMode(downPin, INPUT);
}
    
void loop() {
    // read the state of the button values:
    leftState = digitalRead(leftPin);
    rightState = digitalRead(rightPin);
    upState = digitalRead(upPin);
    downState = digitalRead(downPin);
    
    // check which button is pressed
    if (leftState == HIGH) {
        Serial.println("LEFT");
        IrSender.sendNEC(0x0102, sCommand, sRepeats);
        delay(DELAY_AFTER_SEND); // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
    } 
    else if (rightState == HIGH) {
        Serial.println("RIGHT"); 
        IrSender.sendNEC(0x0103, sCommand, sRepeats);
        delay(DELAY_AFTER_SEND); // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal  
    }
    else if (upState == HIGH) {
        Serial.println("UP");
        IrSender.sendNEC(0x0104, sCommand, sRepeats);
        delay(DELAY_AFTER_SEND); // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
    }
    else if  (downState == HIGH) {
        Serial.println("DOWN");
        IrSender.sendNEC(0x0105, sCommand, sRepeats);
        delay(DELAY_AFTER_SEND); // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
    }
}
