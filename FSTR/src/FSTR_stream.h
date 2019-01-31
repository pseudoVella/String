#ifndef FSTR_stream_h
#define FSTR_stream_h
#include <iostream>
inline std::ostream& operator << (std::ostream& o, STR& a){
  return o << a.cstr();
}

 inline std::ostream& operator << (std::ostream& o, const STR &a) {
  return o << a.cstr();
}
#endif
