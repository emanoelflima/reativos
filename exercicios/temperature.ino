#define LED1 1
#define LED2 2
#define LED3 3
#define TERMO 1

float temp1 = 26;   //menor temperatura
float temp2 = 26.5; //temperatura do meio
float temp3 = 27;   //maior temperatura

int LAST_EXEC = millis();
int MIN_INTERVAL = 1000;

void setup(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int now = millis();
  if(now - MIN_INTERVAL >= LAST_EXEC){
    int reading = analogRead(TERMO);
    float voltage = reading * (5000/1024);
    //Serial.println("");
    //Serial.print(voltage);
    //Serial.print(" volts");
  
    float temp = (voltage - 0.5)/10;
    Serial.println("");
    Serial.print(temp);
    Serial.print(" graus celsius");

    if(temp > temp3){
      //acende todos os leds
      digitalWrite(LED3, 1);
      digitalWrite(LED2, 1);
      digitalWrite(LED1, 1);
    }
    else if(temp > temp2){
      //acende os dois primeiros leds
      digitalWrite(LED3, 0);
      digitalWrite(LED2, 1);
      digitalWrite(LED1, 1);
    }
    else if(temp > temp1){
      //acende apenas o primeiro led
      digitalWrite(LED3, 0);
      digitalWrite(LED2, 0);
      digitalWrite(LED1, 1);
    }
    
    LAST_EXEC = millis();
  }
}

