#include "mybut.h"

MyBut::MyBut(int _pin, int conf, int _pass, int _time , bool _on_off) {
  pinn = _pin;
  ptime = _time;
  sure = 0;
  pass = _pass;
  on_off = _on_off;
  pinMode(_pin, conf);
}

int MyBut::look_but() {
  if (on_off) {
    //Serial.println("burada1");
    if (digitalRead(pinn) == pass) {//butona basılı mı ? A
      if (sure == 0)
        sure = millis();  //zamanı al
      //Serial.println(sure);
      if ((millis() - sure) > ptime) {  //istenilen sure doldu mu ? B
        if (digitalRead(pinn) == pass) { //buton halen low mu ? C
          sure = 0;
          return 1;
        } else {  //buton halen low değil C
          goto live_END;
        }
      }
      else { //istenilen sure dolmadı B
        if (digitalRead(pinn) == (!pass) ) { //istenilen sure dolmadıgı halde buton bırakıldı mı ?
          goto live_END;
        }
      }
    }
    else {  //butona basılı degil
live_END:
      sure = 0;
      return 0;
    }
  }
  return 0;
}
void MyBut::on_off_but(bool _on_off) {
  on_off = _on_off;
}
void MyBut::change_but_time(int _time) {
  ptime = _time;
}
