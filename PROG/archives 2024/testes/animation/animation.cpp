#include "animation.h"

animation::animation(Led_Matrix &M1,Led_Matrix &M2): _M1(M1), _M2(M2){
  //
}

void animation::start(){
  state = true;
  _T0 = millis();
}

int animation::get_frame(){
  return int(_FPS*(millis()-_T0)/1000);
}

void animation::run(){
  if(state == true){
    _frame = get_frame();
    if(_frame >= _frames_number){
      state = false;
    }else if(_last_frame != _frame){
      _last_frame = _frame;
      _M2.i_Write(_M1.start_animation_1[_frame]);
      _M1.i_Write(_M2.start_animation_2[_frame]);
    }
  }
}
