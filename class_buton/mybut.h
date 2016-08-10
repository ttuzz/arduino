#ifndef mybut_h
#define mybut_h

#include "Arduino.h"

class MyBut
{
  public:
    MyBut(int _pin, int conf, int pass, int _time , bool _on_off);
    int look_but();
    void change_but_time(int _time);
    void on_off_but(bool _on_off);
  private:
    int pinn;
    unsigned long sure;
    int ptime;
    int pass;
    bool on_off;
};

#endif
