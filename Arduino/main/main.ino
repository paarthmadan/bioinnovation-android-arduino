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
                           A();
                      break;

                    case 'B':
                           B();                    
                      break;                    

                    case 'C':
                           C();
                      break;
                    
                    case 'D':
                           D();
                    break;
                      
                    case 'E':
                           E();
                      break;
                      
                    case 'F':
                           f();
                      break;
                      
                    case 'G':
                           G();
                      break;
                      
                    case 'H':
                           H(); 
                      break;
                      
                    case 'I':
                           I();
                      break;
                      
                    case 'J':
                           J();
                      break;
                      
                    case 'K':
                           C();
                      break;
                      
                    case 'L':
                           L();  
                      break;
                      
                    case 'M':
                           M();
                      break;
                      
                    case 'N':
                           N();
                      break;
                      
                    case 'O':
                           O();
                      break;
                      
                    case 'P':
                           P();
                      break;
                      
                    case 'Q':
                           Q();
                      break;
                      
                    case 'R':
                           R();
                      break;

                    case 'S':
                           S();
                      break;

                    case 'T':
                           T();
                      break;
                    
                    case 'U':
                           U();
                      break;

                    case 'V':
                           V();
                      break;

                    case 'W':
                           W();
                      break;

                    case 'X':
                           X();
                      break;

                    case 'Y':
                           Y();
                      break;

                    case 'Z':
                           Z();
                      break;

                    default:
                      break;
  
                  }
                
                }
                
        }

}

void A(){
  Serial.println("A");
}
void B(){
  Serial.println("B");
}
void C(){
  Serial.println("C");
}
void D(){
  Serial.println("D");
}
void E(){
  Serial.println("E");
}
//predefined term, so it is lower case
void f(){
  Serial.println("F");
}
void G(){
  Serial.println("G");
}
void H(){
  Serial.println("H");
}
void I(){
  Serial.println("I");
}
void J(){
  Serial.println("J");
}
void K(){
  Serial.println("K");
}
void L(){
  Serial.println("L");
}
void M(){
  Serial.println("M");
}
void N(){
  Serial.println("N");
}
void O(){
  Serial.println("O");
}
void P(){
  Serial.println("P");
}
void Q(){
  Serial.println("Q");
}
void R(){
  Serial.println("R");
}
void S(){
  Serial.println("S");
}
void T(){
  Serial.println("T");
}
void U(){
  Serial.println("U");
}
void V(){
  Serial.println("V");
}
void W(){
  Serial.println("W");
}
void X(){
  Serial.println("X");
}
void Y(){
  Serial.println("Y");
}
void Z(){
  Serial.println("Z");
}







