# include "morseFunctions.h"
int interval= 5000; // ms blinking period for debugging
int ditLength= 100; // ms length of a morse code "dit"

String callsign= "KI7PYZ";
String callsign_pulses= String2pulses(callsign);
String beacon_pulses= String2pulses(callsign + String(" beacon "));

void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off 

    Serial.begin(9600);
    delay(500);
    Serial.println("~~~~~ BEGIN SERIAL OUTPUT ~~~~~");

    Serial.print("callsign: ");
    Serial.println(callsign);
    Serial.print("callsign pulses: ");
    Serial.println(callsign_pulses);
    Serial.print("LED_BUILTIN: ");
    Serial.print(LED_BUILTIN);
    Serial.println("");
    Serial.println("");

    // blink "SOS"
    delay(2000);
    String sosString= "sos";
    // DO NOT RUN THIS ON A RADIO!!!
    Serial.print("sos example: ");
    Serial.println(sosString);
    pulses2blinks(String2pulses(sosString), ditLength);
    pulses2blinks(String2pulses(sosString), ditLength);
    pulses2blinks(String2pulses(sosString), ditLength);
    pulses2blinks(String2pulses(sosString), ditLength);
    pulses2blinks(String2pulses(sosString), ditLength);

    // blink your callsign
    Serial.println("pulsing callsign...");
    delay(2000);
    pulses2blinks(callsign_pulses, ditLength);
    Serial.println("done.");

    // blink "Hello, world!"
    delay(2000);
    String testString= "Hello, world!";
    Serial.print("test string: ");
    Serial.println(testString);
    pulses2blinks(String2pulses(testString), ditLength);

    Serial.println("exiting setup()");
    Serial.print("beaconing: ");
    Serial.println(beacon_pulses);
}

// the loop function runs over and over again forever
void loop() {

    // blink your beacon
    pulses2blinks(beacon_pulses, ditLength);

    // just blink on and off
    // digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
    // Serial.println("LED on");
    // delay(interval/2);                       // wait for half a second
    // digitalWrite(LED_BUILTIN, LOW);    // turn the LED off 
    // Serial.println("LED off");
    // delay(interval/2);                       // wait for half a second
}
