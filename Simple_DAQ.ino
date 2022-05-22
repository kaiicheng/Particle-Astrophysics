int counts=0;
bool state_trig;
bool state_ch1;
bool state_ch2;

void setup() {
  Serial.begin(9600); // for communication to PC through a serial port
  pinMode(8, INPUT);  // Muon counter ch2
  pinMode(9, INPUT);  // Muon counter ch1
  pinMode(2, INPUT);  // Trigger input
  Serial.println("Hello Muon World!");
}

void loop() {
  state_trig = digitalRead(2); //read the input pin 2
  if (state_trig == 1){
      counts=counts+1;
      state_ch1 = digitalRead(9);  // read the input pin 9
      state_ch2 = digitalRead(8);  // read the input pin 8
      Serial.println("Have a hit: ");
      Serial.println("Ch1:");
      Serial.println(state_ch1);
      Serial.println(" Ch2:");
      Serial.println(state_ch2);
      Serial.println(" total counts: ");
      Serial.println(counts);
  }

  
}
