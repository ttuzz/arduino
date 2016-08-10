/*zcnzkn
 * 10.8.2016
 * rev 1.1
 */
#include "mybut.h"
int pers = 500;
//pin,mode,hangi konumda buton aktif,gecikme suresi,buton nesnesi acik-kapali
MyBut ust(10, INPUT_PULLUP, LOW, 1000, true);
MyBut ust2(10, INPUT_PULLUP, LOW, 4000, false);
MyBut alt(7, INPUT_PULLUP, HIGH, pers, true);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("basladi");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ust.look_but()) {
    Serial.println("ust");
    ust.on_off_but(false);
    ust2.on_off_but(true);
  }
  if (alt.look_but()) {
    Serial.println("alt");
    pers += 500;
    alt.change_but_time(pers);
  }
  if (ust2.look_but()) {
    ust.on_off_but(true);
    ust2.on_off_but(false);
    Serial.println("ust2");
  }
}
