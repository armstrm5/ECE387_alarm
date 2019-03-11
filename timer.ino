  const int buzzPin = 8;
  
  int s = 0;
  int minutes = 59;
  int secs = 59;
  int hrs = 00;
  
void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);

}

void loop() {
  Serial.print(hrs);
  Serial.print(" : ");
  Serial.print(minutes);
  Serial.print(" : ");
  Serial.print(secs);
  Serial.print("-----");

}

void timer() {
  for (int i = 60; i >= minutes; i--) {
    for (int j = 60; j >= seconds; j--) {
      delay (1000);
      secs = secs -1;
      j--;
      
    }
    minutes = minutes - 1;
    i--;
  }
  if(minutes == '0') {
    tone(buzzPin, 3000);
  }
}

int seconds() {
    s = hrs*3600;
    s = s+(minutes*60);
    s = s+secs;
    s = s+(millis()/1000);
    return s;
}


int hours(){
    hrs = seconds();
    hrs = hrs/3600;
    hrs = hrs%24;
    return hrs;
}

int mins()
{
    minutes = seconds();
    minutes = minutes/60;
    minutes = minutes%60;
    return minutes;
}
