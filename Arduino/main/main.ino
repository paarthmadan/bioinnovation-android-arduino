int counter = 0; 
String incomingString;

void setup() {
  Serial.begin(9600);
  Serial.println("starting...");

}

void loop() {

if (Serial.available() > 0) {

       
                incomingString = Serial.readString();

                Serial.println(incomingString);

                int lengthOfString = incomingString.length() + 1;

                char letters[lengthOfString]; 
                
                incomingString.toCharArray(letters, lengthOfString);

                for(int i = 0; i < sizeof(letters); i++){
                  
                  switch(letters[i]){

                    case 'A':
                      break;

                    case 'B':
                      break;                    

                    case 'C':
                      break;
                    
                    case 'D':
                      break;
                      
                    case 'E':
                      break;
                      
                    case 'F':
                      break;
                      
                    case 'G':
                      break;
                      
                    case 'H':
                      break;
                      
                    case 'I':
                      break;
                      
                    case 'J':
                      break;
                      
                    case 'K':
                      break;
                      
                    case 'L':
                      break;
                      
                    case 'M':
                      break;
                      
                    case 'N':
                      break;
                      
                    case 'O':
                      break;
                      
                    case 'P':
                      break;
                      
                    case 'Q':
                      break;
                      
                    case 'R':
                      break;

                    case 'S':
                      break;

                    case 'T':
                      break;
                    
                    case 'U':
                      break;

                    case 'V':
                      break;

                    case 'W':
                      break;

                    case 'X':
                      break;

                    case 'Y':
                      break;

                    case 'Z':
                      break;

                    default:
                      break;
  
                  }
                
                }
                
        }

}







