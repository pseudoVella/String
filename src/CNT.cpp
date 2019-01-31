#include "CNT.h"

CNT::~CNT(){
  delete [] occ;
}

CNT::CNT(){
  cap = 10;
  occ = new size_t[cap];
}

CNT& CNT::set(size_t pos){
  if(count == cap){
    cap += 10;
    size_t * tmp = new size_t[cap];
    for(size_t i = 0; i < count; i++){
      tmp[i] = occ[i];
    }//end for
    delete[] occ;
    occ = tmp;
  }//end if
  occ[count] = pos;
  count++;
  return *this;
}//end set()

CNT& CNT::operator=(CNT const & _cnt){
  if(_cnt.count > this->cap){
    delete [] this->occ;
    size_t *tmp = new size_t[_cnt.cap];
    for(size_t i = 0; i < _cnt.count; i++){
      tmp[i] = _cnt.occ[i];
    }
    this->occ = tmp;
    this->cap = _cnt.cap;
  }
  else{
    for(size_t i = 0; i < _cnt.count; i++){
      this->occ[i] = _cnt.occ[i];
    }
  }
  this->count = _cnt.count;
  return *this;
}
