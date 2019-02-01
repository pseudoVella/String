#include "FSTR.h"
//operators
char& fstr_t::operator[](const size_t& pos){
  return this->str[pos];
}

/****************************************/
fstr_t& fstr_t::operator+=(const fstr_t& _b){
  return this->concat(_b);
}

fstr_t& fstr_t::operator+=(const char& _b){
  return this->concat(_b);
}

fstr_t& fstr_t::operator+=(const char* _b){
  return this->concat(_b);
}
/****************************************/
fstr_t& fstr_t::operator=(const fstr_t& _b){
  return this->copy(_b);
}

fstr_t& fstr_t::operator=(const char& _b){
  return this->copy(_b);
}

fstr_t& fstr_t::operator=(const char* _b){
  return this->copy(_b);
}
/****************************************/
bool fstr_t::operator==(const fstr_t& _b){
  if(this->len != _b.len){
    return false;
  }
  else{
    for(size_t i = 0; i < this->len; i++){
      if(this->str[i] != _b.str[i]){
        return false;
      }
    }
  }
  return true;
}

bool fstr_t::operator==(const char& __c){
  if(this->len != 1 || this->str[0] != __c){
    return false;
  }
  else{
    return true;
  }
}

bool fstr_t::operator==(const char* __st){
  for(size_t i = 0; i < this->len; i++){
    if(this->str[i] != __st[i]){
      return false;
    }
  }
  return true;
}
/****************************************/
fstr_t fstr_t::operator + (const fstr_t& _b){
  fstr_t tmp(this->len + _b.len + 1);
  tmp.copy(*this);
  tmp.concat(_b);
  return tmp;
}

fstr_t fstr_t::operator + (const char& _b){
  fstr_t tmp(this->len + 2);
  tmp.copy(*this);
  tmp.concat(_b);
  return tmp;
}

fstr_t fstr_t::operator + (const char *_b){
  fstr_t tmp(this->len + arlen(_b) + 1);
  tmp.copy(*this);
  tmp.concat(_b);
  return tmp;
}
/*********************************************************/
//destructors
/*********************************************************/
fstr_t::~fstr_t(){
  delete [] this->str;
}
/*********************************************************/
//constructors
/*********************************************************/
fstr_t::fstr_t(const fstr_t& __st){
  this->cap = __st.len + 1;
  this->str = new char[this->cap];
  this->copy(__st);
}

fstr_t::fstr_t(const fstr_t& __st, const size_t& maxlen){
  this->cap = maxlen + 1;
  this->str = new char[this->cap];
  this->copy(__st);
}

fstr_t::fstr_t(const char* __st){
  this->cap = arlen(__st) + 1;
  this->str = new char[this->cap];
  this->copy(__st);
}

fstr_t::fstr_t(const char* __st, const size_t& maxlen){
  this->cap = maxlen + 1;
  this->str = new char[this->cap];
  this->copy(__st);
}

fstr_t::fstr_t(const size_t& maxlen){
  this->len = 0;
  this->cap = maxlen + 1;
  this->str = new char[this->cap];
  this->str[0] = '\0';
}
/*********************************************************/
//helper functions
/*********************************************************/
//use these instead of strlen() and strcpy() so we can omit the standard string library
size_t arlen(const char* __st){
  size_t pos = 0;
  while(__st[pos] != '\0'){
  pos++;
  }
  return pos;
}

size_t arcpy(char* __st1, const char* __st2){
  size_t pos = 0;
  while(__st2[pos] != '\0'){
    __st1[pos] = __st2[pos];
    pos++;
  }
  __st1[pos] = '\0';
  return pos;
}

size_t arncpy(char* __st1, const char* __st2, const size_t& amount){
  size_t pos;
  for(pos = 0; pos < amount; pos++){
    if(__st2[pos] == '\0') break;
    __st1[pos] = __st2[pos];
  }
  __st1[pos] = '\0';
  return pos;
}
/*********************************************************/
// public member functions
/*********************************************************/
const size_t& fstr_t::length()const{
  return this->len;
}

const size_t& fstr_t::capacity()const{
  return this->cap;
}

const char* fstr_t::cstr()const{
  return this->str;
}
/****************************************/
//remove() deletes part of fstr_t
fstr_t& fstr_t::remove(const size_t& pos, const size_t& howmany){
  if(pos < this->len){
    if(howmany >= (this->len - pos)){
      this->str[pos] = '\0';
      this->len = pos;
    }
    else{
      this->shiftL(pos, howmany);
    }
  }
  return *this;
}
/****************************************/
//substr() returns part of fstr_t
fstr_t fstr_t::substr(const size_t& pos, const size_t& howmany){
	if(pos>this->len){
		fstr_t tmp("");
		return tmp;
	}
	if(howmany > (this->len - pos)){
		fstr_t tmp(this->len - pos);
		tmp.len = arncpy(tmp.str, this->str+pos, (this->len - pos));
	  return tmp;
	}
	else{
	  fstr_t tmp(howmany + 1);
		tmp.len = arncpy(tmp.str, this->str+pos, howmany);
  	return tmp;
  }
}
/****************************************/
//pop() removes characters from end of fstr_t
fstr_t& fstr_t::pop(const size_t& howmany){
  if(howmany >= this->len){
    this->str[0] = '\0';
    this->len = 0;
  }
  else{
    this->len -= howmany;
    this->str[this->len] = '\0';
  }
  return *this;
}
/****************************************/
//inserts characters into fstr_t
fstr_t& fstr_t::insert(const fstr_t& __st, size_t pos){
  if(this->shiftR(pos, __st.len)){
    this->overwrite(__st, pos, __st.len);
  }//end if
  return *this;
}

fstr_t& fstr_t::insert(const char* __st, size_t pos){
  const size_t stlen = arlen(__st);
  if(this->shiftR(pos, stlen)){
    this->overwrite(__st, pos, stlen);
  }//end if
  return *this;
}

fstr_t& fstr_t::insert(const char& __c, size_t pos, const uint8_t& howmany){
  if(this->shiftR(pos, howmany)){
    this->overwrite(__c, pos, howmany);
  }//end if
  return *this;
}
/****************************************/
//overwrite() writes syring or chars over prev string staring at pos
fstr_t& fstr_t::overwrite(const fstr_t& __st, size_t& pos, const size_t& len){
  for(size_t _pos = 0; _pos < len; _pos++){
    this->str[pos] = __st.str[_pos];
    pos++;
  }
  return *this;
}

fstr_t& fstr_t::overwrite(const char* __st, size_t& pos,const size_t& len){
  for(size_t _pos = 0; _pos < len; _pos++){
    this->str[pos] = __st[_pos];
    pos++;
  }
  return *this;
}

fstr_t& fstr_t::overwrite(const char& __c, size_t& pos, const size_t& howmany){
  size_t epos = pos + howmany;
  while(pos < epos){
    this->str[pos] = __c;
    pos++;
  }
  return *this;
}
/****************************************/
fstr_t& fstr_t::replace(const fstr_t& __st1, const fstr_t& __st2){
  this->master_replace(__st1.str, __st2.str, __st1.len, __st2.len);
  return *this;
}

fstr_t& fstr_t::replace(const fstr_t& __st, const char& __c){
  this->master_replace(__st.str, &__c, __st.len, 1);
  return *this;
}

fstr_t& fstr_t::replace(const fstr_t& __st1, const char * __st2){
  this->master_replace(__st1.str, __st2, __st1.len, arlen(__st2));
  return *this;
}

fstr_t& fstr_t::replace(const char* __st1, const fstr_t& __st2){
  this->master_replace(__st1, __st2.str, arlen(__st1), __st2.len);
  return *this;
}

fstr_t& fstr_t::replace(const char* __st, const char& __c){
  this->master_replace(__st, &__c, arlen(__st), 1);
  return *this;
}

fstr_t& fstr_t::replace(const char* __st1, const char* __st2){
  this->master_replace(__st1, __st2, arlen(__st1), arlen(__st2));
  return *this;
}

fstr_t& fstr_t::replace(const char& __c, const fstr_t& __st){
  this->master_replace(&__c, __st.str, 1, __st.len);
  return *this;
}

fstr_t& fstr_t::replace(const char& __c, const char* __st){
  this->master_replace(&__c, __st, 1, arlen(__st));
  return *this;
}

fstr_t& fstr_t::replace(const char& __c1, const char& __c2){
  this->master_replace(&__c1, &__c2, 1, 1);
  return *this;
}
/****************************************/
//find() finds substring position in fstr_t
size_t fstr_t::find(const char& __c, size_t pos){
  while(pos < this->len){
    if(this->str[pos] == __c){
      return pos;
    }//end if
    pos++;
  }//end while
  return -1;
}//end find()

size_t fstr_t::find(const fstr_t& __st, size_t pos){
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->match(__st.str, __st.len, pos)){//check for string match
      return pos;
    }//end if
  }//end while
  return -1;
}//end find

size_t fstr_t::find(const char* __st, size_t pos){
  size_t stlen = arlen(__st);
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->match(__st, stlen, pos)){//check for first character match
      return pos;
    }//end if
  }//end while
  return -1;
}
/****************************************/
CNT fstr_t::count(const char& __c){
  CNT cnt;
  size_t pos = 0;
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->str[pos] == __c){
      cnt.set(pos);
    }//end if
    pos++;
  }//end while
  return cnt;
}

CNT fstr_t::count(const char* __st){
  CNT cnt;
  size_t stlen = arlen(__st);
  size_t pos = 0;
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->match(__st, stlen, pos)){//check for first character match
      cnt.set(pos); //increment occurence counter
      pos += stlen;
    }//end if
  }//end while
  return cnt;
}

CNT fstr_t::count(const fstr_t& __st){
  CNT cnt;
  size_t pos = 0;
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->match(__st.str, __st.len, pos)){//check for first character match
      cnt.set(pos); //increment occurence counter
      pos += __st.len;
    }//end if
  }//end while
  return cnt;
}
/****************************************/
fstr_t& fstr_t::concat(const char& __c, const size_t& amount){
  if(this->alocc(this->len + amount)){
    this->overwrite(__c, this->len, amount);
    this->str[this->len] = '\0';
  }
  return *this;
}

fstr_t& fstr_t::concat(const char* __st){
  size_t stlen = arlen(__st);
  if(this->alocc(this->len + stlen)){
    this->overwrite(__st, this->len, stlen);
    this->str[this->len] = '\0';
  }
  return *this;
}

fstr_t& fstr_t::concat(const fstr_t& __st){
  if(this->alocc(this->len + __st.len)){
    this->overwrite(__st, this->len, __st.len);
    this->str[this->len] = '\0';
  }
  return *this;
}
/****************************************/
fstr_t& fstr_t::copy(const char& __c){
  if(__c == '\0'){
    this->len = 0;
    this->str[0] = __c;
  }
  else{
    this->len = 1;
    this->str[0] = __c;
    this->str[1] = '\0';
  }
  return *this;
}

fstr_t& fstr_t::copy(const char* __st){
  size_t stlen = arlen(__st);
  if(this->alocc(stlen)){
     this->len = arcpy(this->str, __st);
  }
  return *this;
}

fstr_t& fstr_t::copy(const fstr_t& __st){
  if(this->alocc(__st.len)){
    this->len = arcpy(this->str, __st.str);
  }
  return *this;
}
/****************************************/
// private member functions
/****************************************/
bool fstr_t::alocc(const size_t& amount){
  if(amount >= this->cap) return false;
  else return true;
}//end alocc()
/****************************************/
bool fstr_t::shiftR(size_t& pos, const size_t& howmany){
  if(this->alocc(this->len + howmany)){
    if(pos > this->len){
      pos = this->len;
    }
    if(this->len != pos){
      for(size_t _pos = this->len; _pos >= pos; _pos--){
        this->str[_pos + howmany] = this->str[_pos];
      }
    }
    else {
      this->str[this->len + howmany] = this->str[this->len];
    }
    this->len += howmany;
    return true;
  }
  else{
    return false;
  }
}
/****************************************/
bool fstr_t::shiftL(size_t pos, const size_t& howmany, const size_t& epos){
  if(epos >= this->len || epos == 0){
    this->len -= howmany;
	  while(pos < this->len){
  	  this->str[pos] = this->str[pos + howmany];
    	pos++;
		}
	}
	else{
	  while(pos < epos){
  	  this->str[pos] = this->str[pos + howmany];
    	pos++;
  	}
	}
  return true;
}
/****************************************/
bool fstr_t::match(const char* __s, size_t const& len, size_t& pos){
  if(this->str[pos] == __s[0]){//match for first char
    for(size_t _pos = 0; _pos < len; _pos++){//match for remaining chars
      if(this->str[pos + _pos] != __s[_pos]){
        pos++;
        return false;
      }
    }//end for
    return true;
  }//end if
  pos++;
  return false;
}
/****************************************/
fstr_t& fstr_t::master_replace(const char* __s1, const char* __s2, const size_t& len1, const size_t& len2){
  size_t pos = 0;
  if(len1 == len2){
    while(pos < this->len){
      if(this->match(__s1, len1, pos)){//check for string match
        this->overwrite(__s2, pos, len2);
      }//end if
    }//end while
  }//endif
  else if(len1 > len2){
    size_t dlen = len1 - len2;
    size_t tdiff = 0;
    size_t lastpos;
    size_t matches = 0;
    while(pos < this->len){//check for valid match
      if(this->match(__s1, len1, pos)){//check for string match
        matches++;
        if(matches == 1){
          this->overwrite(__s2, pos, len2);
        }//end if
        else{
          pos -= tdiff;
          this->shiftL(lastpos, tdiff, pos);
          this->overwrite(__s2, pos, len2);
        }//end else
        tdiff += dlen;
        lastpos = pos;//save pos
        pos += tdiff;
      }//end if
      if(pos >= this->len && matches > 0){//no next string match, remove blank spaces
        this->remove(lastpos, tdiff);
      }//end if
    }//end while
  }//end else if
  else if(len1 < len2){
    CNT cnt;
    cnt = this->count(__s1);
    size_t dlen = len2 - len1;
    size_t tdiff = cnt.count * dlen;
    for(size_t x = 1; x <= cnt.count; x++){
      pos = cnt.occ[cnt.count - x] + len1;
      if(x == 1){
        for(size_t y = this->len; y >= pos; y--){
          this->str[y + tdiff] = this->str[y]; //moves end of fstr_t copies null
        }//end for
        this->len += tdiff;//update fstr_t length
      }//end if
      else{
        for(size_t y = cnt.occ[cnt.count - x + 1] - 1; y >= pos; y--){
          this->str[y + tdiff] = this->str[y];
        }//end for
      }//end else
      pos = (cnt.occ[cnt.count - x] - dlen) + tdiff;
      this->overwrite(__s2, pos, len2);
      tdiff -= dlen;
    }//end for
  }//end else if
  return *this;
}
