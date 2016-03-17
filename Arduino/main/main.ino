int counter = 0; 
String incomingByte;

void setup() {
  Serial.begin(9600);

}

void loop() {

if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.readString();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte);
        }
}
