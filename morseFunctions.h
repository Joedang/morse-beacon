#include <Arduino.h>

// convert a String of characters into a String representing "dit"s and "dah"s.
String String2pulses (String symbStr);
// convert a single character to a string representing "dit"s and "dah"s.
String char2pulse (char symbol);
// pulse the built-in LED according to the string of morse pulses
void pulses2blinks (String pulses, int ditLength);
void blinkError (int ditLength);

void blinkError (int ditLength){
    pulses2blinks(String("........"), ditLength);
}

void pulses2blinks (String pulses, int ditLength) {
    // pulse the built-in LED according to the string of morse pulses
    int dahLength= 3*ditLength;
    int spaceLength= 7*ditLength;

    Serial.print("blinking: ");
    Serial.print(pulses);
    Serial.println();

    for (int i= 0; i < pulses.length(); i++) {
        switch (pulses.charAt(i)) {
            case '.': // dit
                digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
                delay(ditLength);
                break;
            case '-': // dah
                digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
                // subtract the dit length to compensate for the mandatory inter-pulse wait
                delay(dahLength);
                break;
            case ' ': // space
                digitalWrite(LED_BUILTIN, LOW);   // turn the LED off 
                // subtract the dit length to compensate for the mandatory inter-symbol wait
                delay(dahLength - ditLength);
                break;
            default:
                Serial.println("ERROR: unknown character in pulses given to pulses2blinks() in morseFunctions.h");
                Serial.print("ERROR: unknown character: \"");
                Serial.print(pulses.charAt(i));
                Serial.print("\"");
                Serial.println("");
                break;
        }
        digitalWrite(LED_BUILTIN, LOW);   // turn the LED off 
        delay(ditLength); // mandatory inter-symbol wait
    }
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off 
}

String String2pulses (String symbStr) {
    // convert a String of characters into a String representing "dit"s and "dah"s.
    // append a space after a character's-worth of pulses (So, spaces become double spaces.)
    String pulseStr= String();
    for (int i= 0; i < symbStr.length(); i++) {
        pulseStr+= String(char2pulse(symbStr.charAt(i)));
        pulseStr+= String(" ");
    }
    return pulseStr;
}

String char2pulse (char symbol) {
    // convert a single character to a string representing "dit"s and "dah"s.
    
    symbol= toupper(symbol);
    String pulses= String();

    switch (symbol) {
        case 'A':
            // Serial.println(".-");
            pulses+= ".-";
            break;
        case 'B':
            // Serial.println("-...");
            pulses+= "-...";
            break;
        case 'C':
            // Serial.println("-.-.");
            pulses+= "-.-.";
            break;
        case 'D':
            // Serial.println("-..");
            pulses+= "-..";
            break;
        case 'E':
            // Serial.println(".");
            pulses+= ".";
            break;
        case 'F':
            // Serial.println("..-.");
            pulses+= "..-.";
            break;
        case 'G':
            // Serial.println("--.");
            pulses+= "--.";
            break;
        case 'H':
            // Serial.println("....");
            pulses+= "....";
            break;
        case 'I':
            // Serial.println("..");
            pulses+= "..";
            break;
        case 'J':
            // Serial.println(".---");
            pulses+= ".---";
            break;
        case 'K':
            // Serial.println("-.-");
            pulses+= "-.-";
            break;
        case 'L':
            // Serial.println(".-..");
            pulses+= ".-..";
            break;
        case 'M':
            // Serial.println("--");
            pulses+= "--";
            break;
        case 'N':
            // Serial.println("-.");
            pulses+= "-.";
            break;
        case 'O':
            // Serial.println("---");
            pulses+= "---";
            break;
        case 'P':
            // Serial.println(".--.");
            pulses+= ".--.";
            break;
        case 'Q':
            // Serial.println("--.-");
            pulses+= "--.-";
            break;
        case 'R':
            // Serial.println(".-.");
            pulses+= ".-.";
            break;
        case 'S':
            // Serial.println("...");
            pulses+= "...";
            break;
        case 'T':
            // Serial.println("-");
            pulses+= "-";
            break;
        case 'U':
            // Serial.println("..-");
            pulses+= "..-";
            break;
        case 'V':
            // Serial.println("...-");
            pulses+= "...-";
            break;
        case 'W':
            // Serial.println(".--");
            pulses+= ".--";
            break;
        case 'X':
            // Serial.println("-..-");
            pulses+= "-..-";
            break;
        case 'Y':
            // Serial.println("-.--");
            pulses+= "-.--";
            break;
        case 'Z':
            // Serial.println("--..");
            pulses+= "--..";
            break;
        case '0':
            // Serial.println("-----");
            pulses+= "-----";
            break;
        case '1':
            // Serial.println(".----");
            pulses+= ".----\0 ";
            break;
        case '2':
            // Serial.println("..---");
            pulses+= "..---";
            break;
        case '3':
            // Serial.println("...--");
            pulses+= "...--";
            break;
        case '4':
            // Serial.println("....-");
            pulses+= "....-";
            break;
        case '5':
            // Serial.println(".....");
            pulses+= ".....";
            break;
        case '6':
            // Serial.println("-....");
            pulses+= "-....";
            break;
        case '7':
            // Serial.println("--...");
            pulses+= "--...";
            break;
        case '8':
            // Serial.println("---..");
            pulses+= "---..";
            break;
        case '9':
            // Serial.println("----.");
            pulses+= "----.";
            break;
        case '.':
            // Serial.println(".-.-.-");
            pulses+= ".-.-.-";
            break;
        case ',':
            // Serial.println("--..--");
            pulses+= "--..--";
            break;
        case '?':
            // Serial.println("..--..");
            pulses+= "..--..";
            break;
        case '-':
            // Serial.println("-....-");
            pulses+= "-....-";
            break;
        case '\'':
            // Serial.println(".----.");
            pulses+= ".----.";
            break;
        case ':':
            // Serial.println("---...");
            pulses+= "---...";
            break;
        case '"':
            // Serial.println(".-..-.");
            pulses+= ".-..-.";
            break;
        case '/':
            // Serial.println("-..-.");
            pulses+= "-..-.";
            break;
        case '@':
            // Serial.println(".--.-.");
            pulses+= ".--.-.";
            break;
        case '!':
            // Serial.println("-.-.--");
            pulses+= "-.-.--";
            break;
        case '(':
            // Serial.println("-.--.");
            pulses+= "-.--.";
            break;
        case ')':
            // Serial.println("-.--.-");
            pulses+= "-.--.-";
            break;
        case '&':
            // Serial.println(".-...");
            pulses+= ".-...";
            break;
        case ';':
            // Serial.println("-.-.-.");
            pulses+= "-.-.-.";
            break;
        case '=':
            // Serial.println("-...-");
            pulses+= "-...-";
            break;
        case '+':
            // Serial.println(".-.-.");
            pulses+= ".-.-.";
            break;
        case '_':
            // Serial.println("..--.-");
            pulses+= "..--.-";
            break;
        case '$':
            // Serial.println("...-..-");
            pulses+= "...-..-";
            break;
        case ' ':
            // Serial.println("  ");
            pulses+= " ";
            break;
        default:
            Serial.println("ERROR: unknown character given to char2pulse() in morseFunctions.");
            Serial.print("ERROR: unknown character: \"");
            Serial.print(symbol);
            Serial.print("\"");
            Serial.println("");
            pulses+= "";
            break;
    }
    return pulses;
}
