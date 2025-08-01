#include <Arduino.h>
#line 1 "/home/ksullivan/micro/sketch/sketch.ino"

#define RELAY_1 14
#define RELAY_2 27
#define RELAY_3 26
#define RELAY_4 25

#define RELAY_SIZE 4

struct relayData {
    int logicalPin;
    int physicalPin;
};

    relayData relays[RELAY_SIZE] = {
        {1, 14},
        {2, 27},
        {3, 26},
        {4, 25}
    };

#line 21 "/home/ksullivan/micro/sketch/sketch.ino"
void setup();
#line 36 "/home/ksullivan/micro/sketch/sketch.ino"
void loop();
#line 21 "/home/ksullivan/micro/sketch/sketch.ino"
void setup() {
    Serial.begin(115200);



    pinMode(RELAY_1, OUTPUT);
    pinMode(RELAY_2, OUTPUT);
    pinMode(RELAY_3, OUTPUT);
    pinMode(RELAY_4, OUTPUT);
	digitalWrite(RELAY_1, HIGH);
	digitalWrite(RELAY_2, HIGH);
	digitalWrite(RELAY_3, HIGH);
	digitalWrite(RELAY_4, HIGH);
}

void loop() {
if(Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    char buffer[50];
    command.toCharArray(buffer, 50);
    int logicalPin = atoi(strtok(buffer, "-"));
    int power = atoi(strtok(NULL, "-"));
    Serial.println(logicalPin);
    Serial.println(power);

    for(int i=0;i<RELAY_SIZE;i++) {
        if(relays[i].logicalPin == logicalPin) {
            if(power == 1) {
                digitalWrite(relays[i].physicalPin, LOW);
            } else if (power == 0) {
                digitalWrite(relays[i].physicalPin, HIGH);
            } else {
                Serial.println("Invalid power option.");
            }
        }
    }

        // if (command == "1r1") {
        //         digitalWrite(RELAY_1, LOW);
        // } else if (command == "1r0") {
        //         digitalWrite(RELAY_1, HIGH);
        // } else if (command == "2r1") {
        //         digitalWrite(RELAY_2, LOW);
        // } else if (command == "2r0") {
        //         digitalWrite(RELAY_2, HIGH);
        // } else if (command == "3r1") {
        //         digitalWrite(RELAY_3, LOW);
        // } else if (command == "3r0") {
        //         digitalWrite(RELAY_3, HIGH);
        // } else if (command == "4r1") {
        //         digitalWrite(RELAY_4, LOW);
        // } else if (command == "4r0") {
        //         digitalWrite(RELAY_4, HIGH);
        // } else {
        //     Serial.println("Unknown command");
        // }
    }
}

