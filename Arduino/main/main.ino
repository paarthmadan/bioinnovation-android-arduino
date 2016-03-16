int counter = 0; 

void setup() {
  Serial.begin(9600);

}

void loop() {
 counter++;
 Serial.println(counter);
 delay(1000); 
}
