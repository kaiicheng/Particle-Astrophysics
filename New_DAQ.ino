#include <Event.h>
#include <Timer.h>

#include <IRremote.hpp>

#include <Timer.h>
#include <Event.h>

Timer t;
const byte interruptPin = 2; // Muon counter OR gate output
unsigned long muon_OR_counts = 0; // OR counts
unsigned long muon_AND_counts = 0; // AND counts
unsigned long muon_Ch1_counts = 0; // Counts when Ch1 only hit
unsigned long muon_Ch2_counts = 0; // Counts when Ch2 only hit

int report_min=1; // Report a summary line every 1 min
char input_pin_status;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // for communication to PC through a serial port
  pinMode(8, INPUT);  // Muon counter ch2
  pinMode(9, INPUT);  // Muon counter ch1

  Serial.println("Hello Muon World!");
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), trigger, RISING);
  Serial.print("Muon counts will be reported at every ");
  Serial.print(report_min);
  Serial.println(" min.");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("."); //printing "." every 6 sec.
  delay(6000); //msec

  t.update();
}

void trigger() {
  input_pin_status = (PINB & B00000011);
  muon_OR_counts++;
  if (input_pin_status == 1) muon_Ch2_counts++;
  if (input_pin_status == 2) muon_Ch1_counts++;
  if (input_pin_status == 3) muon_AND_counts++;
}

void report_events() {
  Serial.println("");
  Serial.print("Trig.:");Serial.print(muon_OR_counts);
  Serial.print(" Ch1:");Serial.print(muon_Ch1_counts);
  Serial.print(" Ch2:");Serial.print(muon_Ch2_counts);
  Serial.print(" AND:");Serial.println(muon_AND_counts);
  muon_OR_counts=0;
  muon_Ch1_counts=0;
  muon_Ch2_counts=0;
  muon_AND_counts=0;
}
