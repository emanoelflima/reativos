#define LED_PIN 4
#define BUT_PIN 13
#define BUT2_PIN 12

#define MIN_INTERVAL 1000

int STOP = false;
int LED_STATE = 0;
int INTERVAL = 500;
int OLD = millis();
int BT1_LASTPRESS = millis();
int BT2_LASTPRESS = millis();

void setup () {
    pinMode(LED_PIN, OUTPUT);       // Enable pin 4 for digital output
    pinMode(BUT_PIN, INPUT);        // Enable pin 13 for digital input
    pinMode(BUT2_PIN, INPUT);        // Enable pin  2 for digital input
    digitalWrite(LED_PIN, LED_STATE);
    Serial.begin(9600);
}
 
void loop () {
  //Serial.println(digitalRead(BUT2_PIN));
 if(STOP == false){ 
    int now = millis();
    if(now - INTERVAL == OLD){
      LED_STATE = !LED_STATE;
      digitalWrite(LED_PIN, LED_STATE);
      //Serial.println(LED_STATE);
      OLD = millis();
    }

    
    int but = digitalRead(BUT_PIN); // Read button state
    if(but == LOW){
      int bt1_now = millis();
      if(bt1_now - MIN_INTERVAL >= BT1_LASTPRESS){
        INTERVAL = INTERVAL - 500;
        if(INTERVAL < 1) INTERVAL = 1;
        Serial.println("button 1 pressed. New interval: ");
        Serial.println(INTERVAL);
        BT1_LASTPRESS = millis();
      }
    }
    
    int but2 = digitalRead(BUT2_PIN); // Read button state
    if(but2 == LOW){
      int bt2_now = millis();
      if(bt2_now - MIN_INTERVAL >= BT2_LASTPRESS){
        INTERVAL = INTERVAL + 500;
        Serial.println("button 2 pressed. New interval:");
        Serial.println(INTERVAL);
        BT2_LASTPRESS = millis();
      }
    }

    if(but == LOW && but2 == LOW && bt2_now - bt1_now < 500){
      Serial.println("Parando de piscar");
      STOP = true;
      digitalWrite(LED_PIN, HIGH);
    }
 }
}
