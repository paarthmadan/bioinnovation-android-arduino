int counter = 0; 
String incomingByte;

void setup() {
  Serial.begin(9600);
  Serial.println("starting...");

}

void loop() {

if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.readString();

                // say what you got:
                
                Serial.println(incomingByte);

               
               
                char letters[incomingByte.length()+1]; 
                incomingByte.toCharArray(letters, incomingByte.length() + 1);

                for(int i = 0; i < sizeof(letters); i++){
                  Serial.println(letters[i]);
                }
                
        }

}
