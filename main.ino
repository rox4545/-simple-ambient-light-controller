const int ldr=39;
const int pot=36;
const int led1=33;
const int sw=32;

void setup(){
  pinMode(ldr,INPUT);
  pinMode(pot,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(sw,INPUT_PULLUP);
  Serial.begin(115200);
  delay(1000);
  const char* title = 1+R"(
        ___            _     _            _     _     _       _     _     _____             _             _ _            
       / _ \          | |   (_)          | |   | |   (_)     | |   | |   /  __ \           | |           | | |           
      / /_\ \_ __ ___ | |__  _  ___ _ __ | |_  | |    _  __ _| |__ | |_  | /  \/ ___  _ __ | |_ _ __ ___ | | | ___ _ __  
      |  _  | '_ ` _ \| '_ \| |/ _ \ '_ \| __| | |   | |/ _` | '_ \| __| | |    / _ \| '_ \| __| '__/ _ \| | |/ _ \ '__| 
      | | | | | | | | | |_) | |  __/ | | | |_  | |___| | (_| | | | | |_  | \__/\ (_) | | | | |_| | | (_) | | |  __/ |    
      \_| |_|_| |_| |_|_.__/|_|\___|_| |_|\__| \_____|_|\__, |_| |_|\__|  \____/\___/|_| |_|\__|_|  \___/|_|_|\___|_|    
                                                         __/ |                                                           
                                                        |___/                                                            
)";

  Serial.print(title);
  }

void loop(){
  int analogLDR = analogRead(ldr);
  int sw_mode = digitalRead(sw);
  int analogPOT = analogRead(pot);
  int brightness_pot = map(analogPOT,0,4095,1,255);
  int brightness_ldr = map(analogLDR,0,4093,253,0);
  if (sw_mode == LOW){
    analogWrite(led1,brightness_ldr);
    
  }
  else{
    
    analogWrite(led1,brightness_pot);
  }
  int serialNum = 0;
    Serial.print("\rmode: ");
  if (digitalRead(sw) == HIGH) {          
    serialNum = brightness_pot;
    Serial.print("manual"); 
  } else {                   
    serialNum = brightness_ldr;
    Serial.print("automatic");
  }
  Serial.print("\t serial number: ");
  Serial.println(serialNum);
  
  
  delay(500);
  
}