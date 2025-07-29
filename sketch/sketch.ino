#define RELAY_1 14
#define RELAY_2 27
#define RELAY_3 26
#define RELAY_4 25

void setup() {
    Serial.begin(115200);
    pinMode(RELAY_1, OUTPUT);
    pinMode(RELAY_2, OUTPUT);
    pinMode(RELAY_3, OUTPUT);
    pinMode(RELAY_4, OUTPUT);
}

void loop() {
    if(Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();
		if (command == "1r1") {
			digitalWrite(RELAY_1, LOW);
		} else if (command == "1r0") {
			digitalWrite(RELAY_1, HIGH);
		} else if (command == "2r1") {
			digitalWrite(RELAY_2, LOW);
		} else if (command == "2r0") {
			digitalWrite(RELAY_2, HIGH);
		} else if (command == "3r1") {
			digitalWrite(RELAY_3, LOW);
		} else if (command == "3r0") {
			digitalWrite(RELAY_3, HIGH);
		} else if (command == "4r1") {
			digitalWrite(RELAY_4, LOW);
		} else if (command == "4r0") {
			digitalWrite(RELAY_4, HIGH);
		} else {
		  Serial.println("Unknown command");
		}
}
}
