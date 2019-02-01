#ifndef FSTR_stream_h
#define FSTR_stream_h
#include <iostream>
inline std::ostream& operator << (std::ostream& o, const fstr_t& a){
  return o << a.cstr();
}

#endif
