int counts=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200); //for communication to PC through a serial port
  Serial.println("Hello Muon World!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Hi, the counting number is "); //printing "." every 6 sec.
  Serial.println(counts); //printing "." every 1 sec.
  counts=counts+1;
  delay(1000); //msec
}
