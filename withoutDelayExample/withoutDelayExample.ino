#include "withoutDelayH.h"

int deg = 2200;
withoutDelay aa(deg);
withoutDelay bb(877);


void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  delay(10);
  Serial.println("basladi");
}

void loop() {
  if (aa.timeOver()) {
    deg += 100;
    aa.changeInterval(deg);
    Serial.print("new interval : ");
    Serial.println(deg);
    Serial.println("Here 1 ");
  }
  if (bb.timeOver()) {
    Serial.println("Here 2 ");
  }
  delay(1);
}
