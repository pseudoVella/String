#include "STR.h"
//operators
char& STR::operator[](size_t pos){
  return this->str[pos];
}

char STR::operator[](size_t pos) const{
  return this->str[pos];
}
/****************************************/

STR& STR::operator += (STR const &_b){
  return this->concat(_b);
}

STR& STR::operator += (char *_b){
  return this->concat(_b);
}

STR& STR::operator += (const char *_b){
  return this->concat(_b);
}

STR& STR::operator += (char _b){
  return this->concat(_b);
}
/****************************************/

STR& STR::operator = (STR const &_b){
  return this->copy(_b);
}

STR& STR::operator=(char *_b){
  return this->copy(_b);
}

STR& STR::operator=(const char *_b){
  return this->copy(_b);
}

STR& STR::operator=(char _b){
  return this->copy(_b);
}
/****************************************/

bool STR::operator==(STR const &_b){
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

bool STR::operator==(char __c){
  if(this->len != 1 || this->str[0] != __c){
    return false;
  }
  else{
    return true;
  }
}

bool STR::operator==(char * __st){
  for(size_t i = 0; i < this->len; i++){
    if(this->str[i] != __st[i]){
      return false;
    }
  }
  return true;
}

bool STR::operator==(const char * __st){
  for(size_t i = 0; i < this->len; i++){
    if(this->str[i] != __st[i]){
      return false;
    }
  }
  return true;
}
/****************************************/

STR STR::operator + (STR const &_b){
  STR tmp(this->len + _b.len + 1);
  tmp = *this;
  tmp += _b;
  return tmp;
}

STR STR::operator + (char _b){
  STR tmp(this->len + 2);
  tmp = *this;
  tmp += _b;
  return tmp;
}

STR STR::operator + (char *_b){
  STR tmp(this->len + arlen(_b) + 1);
  tmp = *this;
  tmp += _b;
  return tmp;
}

STR STR::operator + (const char *_b){
  STR tmp(this->len + arlen(_b) + 1);
  tmp = *this;
  tmp += _b;
  return tmp;
}

/*********************************************************/
//destructors
/*********************************************************/
STR::~STR(){
  delete [] this->str;
}

/*********************************************************/
//constructors
/*********************************************************/
STR::STR(){
  this->len = 0;
  this->cap = 12;
  this->str = new char[this->cap];
  this->str[0] = (char)NULL;
}

STR::STR(STR const &__st){
  this->len = __st.len;
  this->cap = this->len + 1;
  this->str = new char[this->cap];
  arcpy(this->str, __st.str);
}

STR::STR(STR const &__st, size_t _size){
  this->len = __st.len;
  this->cap = _size;
  this->str = new char[this->cap];
  arcpy(this->str, __st.str);
}

STR::STR(const char *__st){
  this->len = arlen(__st);
  this->cap = this->len + 1;
  this->str = new char[this->cap];
  arcpy(this->str, __st);
}

STR::STR(size_t _size){
  this->len = 0;
  this->cap = _size;
  this->str = new char[this->cap];
  this->str[0] = (char)NULL;
}

STR::STR(const char *__st, size_t _size){
  this->len = arlen(__st);
  this->cap = _size;
  this->str = new char[_size];
  arcpy(this->str, __st);
}

STR::STR(char *__st){
  this->len = arlen(__st);
  this->cap = this->len + 1;
  this->str = new char[this->cap];
  arcpy(this->str, __st);
}

STR::STR(char *__st, size_t _size){
  this->len = arlen(__st);
  this->cap = _size;
  this->str = new char[_size];
  arcpy(this->str, __st);
}

/*********************************************************/
//helper functions
/*********************************************************/
size_t arlen(char *__st){
  size_t pos = 0;
  while(__st[pos] != '\0'){
  pos++;
  }
  return pos;
}

size_t arlen(const char *__st){
  size_t pos = 0;
  while(__st[pos] != '\0'){
  pos++;
  }
  return pos;
}

char * arcpy(char *__st1, char * __st2){
  size_t pos = 0;
  while(__st2[pos] != '\0'){
    __st1[pos] = __st2[pos];
    pos++;
  }
  __st1[pos] = '\0';
  return __st1;
}

char * arcpy(char *__st1, const char * __st2){
  size_t pos = 0;
  while(__st2[pos] != '\0'){
    __st1[pos] = __st2[pos];
    pos++;
  }
  __st1[pos] = '\0';
  return __st1;
}

/*********************************************************/
//member functions
/*********************************************************/

size_t STR::length(){
  return this->len;
}

size_t STR::capacity(){
  return this->cap;
}

char const* const STR::cstr()const{
  return this->str;
}
/****************************************/

bool STR::alocc(size_t amount){
  if(amount >= this->cap){
    char* tmp = new char[amount + 1];
    if(!tmp){
      return false;
    }// end if
    else{
      this->cap = amount + 1;
      arcpy(tmp, this->str);
      delete [] this->str;
      this->str = tmp;
    }//end else
  }//end if
  return true;
}//end alocc()
/****************************************/

bool STR::shiftR(size_t pos, size_t howmany){
  if(this->alocc(this->len + howmany)){
    for(size_t _pos = this->len; _pos >= pos; _pos--){
      this->str[_pos + howmany] = this->str[_pos];
    }
    this->len += howmany;
    return true;
  }
  else{
    return false;
  }
}
/****************************************/

bool STR::shiftL(size_t pos, size_t howmany){
  this->len -= (howmany - 1);
  while(pos <= this->len){
    this->str[pos] = this->str[pos + howmany];
    pos++;
  }
  return true;
}
/****************************************/

//remove() deletes part of string
STR& STR::remove(size_t pos, size_t howmany){
  if(howmany == -1 || howmany >= (this->len - pos)){
    this->str[pos] = '\0';
    this->len = pos;
  }
  else{
    this->shiftL(pos, howmany);
  }
  return *this;
}
/****************************************/

//substr() returns part of string
STR STR::substr(size_t pos, size_t howmany){
  if(howmany == -1 || howmany > (this->len - pos)){
    howmany = this->len - pos +1;
  }
  size_t count = 0;
  STR tmp(howmany + 1);
  while(count < howmany){
  tmp[count] = this->operator[](pos);
  pos++;
  count++;
  }
  tmp[howmany] = '\0';
  return tmp;
}
/****************************************/

//pop() removes characters from end of string
STR& STR::pop(size_t howmany){
  if(howmany == -1 || howmany > this->len){
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

//inserts characters into string
STR& STR::insert(STR& __st, size_t pos){
  if(this->shiftR(pos, __st.len)){
    for(size_t _pos = 0; _pos < __st.len; _pos++){
      this->str[pos] = __st.str[_pos];
      pos++;
    }//end for
  }//end if
  return *this;
}

STR& STR::insert(const char* __st, size_t pos){
  size_t stlen = arlen(__st);
  if(this->shiftR(pos, stlen)){
    for(size_t _pos = 0; _pos < stlen; _pos++){
      this->str[pos] = __st[_pos];
      pos++;
    }
  }//end if
  return *this;
}

STR& STR::insert(char* __st, size_t pos){
  size_t stlen = arlen(__st);
  if(this->shiftR(pos, stlen)){
    for(size_t _pos = 0; _pos < stlen; _pos++){
      this->str[pos] = __st[_pos];
      pos++;
    }//end for
  }//end if
  return *this;
}

STR& STR::insert(char __c, size_t pos, uint8_t howmany){
  if(this->shiftR(pos, howmany)){
    for(size_t _pos = 0; _pos < howmany; _pos++){
      this->str[pos +_pos] = __c;
    }//end for
  }//end if
  return *this;
}
/****************************************/

//overwrite() writes string or chars over prev string staring at pos
//does not affect length unless the replavement string is larger than
//the remaining string.
STR& STR::overwrite(STR const& __st, size_t pos, size_t len){
  for(size_t _pos = 0; _pos < len; _pos++){
    this->str[pos+_pos] = __st.str[_pos];
  }
  return *this;
}

STR& STR::overwrite(const char* __st, size_t pos, size_t len){
  for(size_t _pos = 0; _pos < len; _pos++){
    this->str[pos+_pos] = __st[_pos];
  }
  return *this;
}

STR& STR::overwrite(char* __st, size_t pos, size_t len){
  for(size_t _pos = 0; _pos < len; _pos++){
    this->str[pos+_pos] = __st[_pos];
  }
  return *this;
}

STR& STR::overwrite(char __c, size_t pos, uint8_t howmany){
  for(size_t _pos = 0; _pos < howmany; _pos++){
    this->str[pos+_pos] = __c;
  }
  return *this;
}
/****************************************/

STR& STR::master_replace(const char* __s1, const char* __s2, size_t len1, size_t len2){
  size_t pos = 0;
  bool match = false;
  if(len1 == len2){
    while(pos < this->len){
      if(this->str[pos] == __s1[0]){//match for first char
        for(size_t _pos = 0; _pos < len1; _pos++){//match for remaining chars
          if(this->str[pos + _pos] != __s1[_pos]){
            match = false;
            pos++;
            break;
          }
          else{
            match = true;
          }
        }//end for
        if(match == true){
          this->overwrite(__s2, pos, len2);
          pos += len2;
          match = false;
        }//end if
      }//end if
      else{
        pos++;
      }//end else
    }//end while
  }//endif
  else if(len1 > len2){
    size_t dlen = len1 - len2;
    size_t tdiff = 0;
    size_t lastpos;
    size_t matches = 0;
    while(pos < this->len){//check for valid match
      if(this->str[pos] == __s1[0]){//check for first char match
        for(size_t _pos = 0; _pos < len1; _pos++){//check remaining chars
          if(this->str[pos + _pos] != __s1[_pos]){
            match = false;
            pos++;
            break;
          }//end if
          else{
            match = true;
          }
        }//end for
        if(match == true){
          matches++;
          if(matches == 1){
            this->overwrite(__s2, pos, len2);
            pos += len2;
          }//end if
          else{
            pos -= tdiff;
            for(size_t _pos = lastpos; _pos < pos; _pos++){
              this->str[_pos] = this->str[_pos+tdiff];//move char's over
            }
            this->overwrite(__s2, pos, len2);
            pos += len2;
          }//end else
          tdiff += dlen;
          lastpos = pos;//save pos
          pos += tdiff;
          match = false;
        }//end if
      }//end if
      else{
        pos++;
      }//end else
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
          this->str[y + tdiff] = this->str[y]; //moves end of string copies null
        }//end for
        this->len += tdiff;//update string length
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

STR& STR::replace(STR& __st1, STR& __st2){
  this->master_replace(__st1.str, __st2.str, __st1.len, __st2.len);
  return *this;
}

STR& STR::replace(STR& __st, char __c){
  this->master_replace(__st.str, &__c, __st.len, 1);
  return *this;
}

STR& STR::replace(STR& __st1, const char * __st2){
  this->master_replace(__st1.str, __st2, __st1.len, arlen(__st2));
  return *this;
}

STR& STR::replace(STR& __st1, char* __st2){
  this->master_replace(__st1.str, __st2, __st1.len, arlen(__st2));
  return *this;
}

STR& STR::replace(const char* __st1, STR& __st2){
  this->master_replace(__st1, __st2.str, arlen(__st1), __st2.len);
  return *this;
}

STR& STR::replace(const char* __st, char __c){
  this->master_replace(__st, &__c, arlen(__st), 1);
  return *this;
}

STR& STR::replace(const char* __st1, const char* __st2){
  this->master_replace(__st1, __st2, arlen(__st1), arlen(__st2));
  return *this;
}

STR& STR::replace(const char* __st1, char* __st2){
  this->master_replace(__st1, __st2, arlen(__st1), arlen(__st2));
  return *this;
}

STR& STR::replace(char* __st1, STR& __st2){
  this->master_replace(__st1, __st2.str, arlen(__st1), __st2.len);
  return *this;
}

STR& STR::replace(char* __st1, const char* __st2){
  this->master_replace(__st1, __st2, arlen(__st1), arlen(__st2));
  return *this;
}

STR& STR::replace(char* __st1, char* __st2){
  this->master_replace(__st1, __st2, arlen(__st1), arlen(__st2));
  return *this;
}

STR& STR::replace(char* __st, char __c){
  this->master_replace(__st, &__c, arlen(__st), 1);
  return *this;
}

STR& STR::replace(char __c, STR& __st){
  this->master_replace(&__c, __st.str, 1, __st.len);
  return *this;
}

STR& STR::replace(char __c, const char* __st){
  this->master_replace(&__c, __st, 1, arlen(__st));
  return *this;
}

STR& STR::replace(char __c, char* __st){
  this->master_replace(&__c, __st, 1, arlen(__st));
  return *this;
}

STR& STR::replace(char __c1, char __c2){
  this->master_replace(&__c1, &__c2, 1, 1);
  return *this;
}
/****************************************/

//find() finds substring position in string
size_t STR::find(char __c, size_t pos){
  while(pos < this->len){
    if(this->str[pos] == __c){
      return pos;
    }//end if
    pos++;
  }//end while
  return -1;
}//end find()

size_t STR::find(STR const &__st, size_t pos){
  size_t _pos = 0;
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->str[pos] == __st[_pos]){//check for first character match
      _pos++;			//got a match check for the rest of the string
      while(_pos < __st.len){   //only check as many characters as we need to
        if(this->str[pos+_pos] == __st[_pos]){//check for secondary char match
          _pos++;		//got a match prep for next secondary check
          if(_pos == __st.len){//reached end of string to find
            return pos;
          }//end if
        }//end if
        else{
          _pos = 0;
          break;
        }//end else
      }//end while
    }//end if
    pos++;
  }//end while
  return -1;
}//end find

size_t STR::find(char *__st, size_t pos){
  size_t _pos = 0;
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->str[pos] == __st[_pos]){//check for first character match
      _pos++;			//got a match check for the rest of the string
      while(__st[_pos] != '\0'){   //only check as many characters as we need to
        if(this->str[pos+_pos] == __st[_pos]){//check for secondary char match
          _pos++;		//got a match prep for next secondary check
          if(__st[_pos] == '\0'){//reached end of string to find
            return pos;
          }//end if
        }//end if
        else{
          _pos = 0;
          break;
        }//end else
      }//end while
    }//end if
    pos++;
  }//end while
  return -1;
}

size_t STR::find(const char *__st, size_t pos){
  size_t _pos = 0;
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->str[pos] == __st[_pos]){//check for first character match
      _pos++;			//got a match check for the rest of the string
      while(__st[_pos] != '\0'){   //only check as many characters as we need to
        if(this->str[pos+_pos] == __st[_pos]){//check for secondary char match
          _pos++;		//got a match prep for next secondary check
          if(__st[_pos] == '\0'){//reached end of string to find
            return pos;
          }//end if
        }//end if
        else{
          _pos = 0;
          break;
        }//end else
      }//end while
    }//end if
    pos++;
  }//end while
  return -1;
}

/****************************************/
CNT STR::count(char __c){
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

CNT STR::count(char *__st){
  CNT cnt;
  size_t pos = 0;
  size_t _pos = 0;
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->str[pos] == __st[_pos]){//check for first character match
      _pos++;			//got a match check for the rest of the string
      while(__st[_pos] != '\0'){   //only check as many characters as we need to
        if(this->str[pos+_pos] == __st[_pos]){//check for secondary char match
          _pos++;		//got a match prep for next secondary check
          if(__st[_pos] == '\0'){//reached end of string to find
            cnt.set(pos); //increment occurence counter
            pos += _pos;//add length of string to pos
            _pos = 0;//reset _pos as we found our string
            break;
          }//end if
        }//end if
        else{
          _pos = 0;//reset pos as we didn't find a match
          break;
        }//end else
      }//end while
    }//end if
    pos++;
  }//end while
  return cnt;
}

CNT STR::count(const char *__st){
  CNT cnt;
  size_t pos = 0;
  size_t _pos = 0;
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->str[pos] == __st[_pos]){//check for first character match
      _pos++;			//got a match check for the rest of the string
      while(__st[_pos] != '\0'){   //only check as many characters as we need to
        if(this->str[pos+_pos] == __st[_pos]){//check for secondary char match
          _pos++;		//got a match prep for next secondary check
          if(__st[_pos] == '\0'){//reached end of string to find
            cnt.set(pos); //increment occurence counter
            pos += _pos;
            _pos = 0;//reset _pos as we found our string
            break;
          }//end if
        }//end if
        else{
          _pos = 0;//reset pos as we didn't find a match
          break;//break while loop
        }//end else
      }//end while
    }//end if
    pos++;
  }//end while
  return cnt;
}

CNT STR::count(STR& __st){
  CNT cnt;
  size_t pos = 0;
  size_t _pos = 0;
  while(pos < this->len){//make sure we don't go passed our strings length
    if(this->str[pos] == __st.str[_pos]){//check for first character match
      _pos++;			//got a match check for the rest of the string
      while(__st.str[_pos] != '\0'){   //only check as many characters as we need to
        if(this->str[pos+_pos] == __st.str[_pos]){//check for secondary char match
          _pos++;		//got a match prep for next secondary check
          if(__st.str[_pos] == '\0'){//reached end of string to find
            cnt.set(pos); //increment occurence counter
            pos += _pos;
            _pos = 0;//reset _pos as we found our string
            break;
          }//end if
        }//end if
        else{
          _pos = 0;//reset _pos as we didn't find a match
          break;//break while loop
        }//end else
      }//end while
    }//end if
    pos++;
  }//end while
  return cnt;
}

/****************************************/
STR&  STR::concat(char __c, size_t amount){
  if(this->alocc(this->len + amount)){
    for(size_t pos = 0; pos < amount; pos++){
      this->str[this->len] = __c;
      this->len++;
    }
    this->str[this->len] = '\0';
  }
  return *this;
}

STR& STR::concat(const char *__st){
  size_t stlen = arlen(__st);
  if(this->alocc(this->len + stlen)){
    this->overwrite(__st, this->len, stlen);
    this->len += stlen;
    this->str[this->len] = '\0';
  }
  return *this;
}

STR& STR::concat(char *__st){
  size_t stlen = arlen(__st);
  if(this->alocc(this->len + stlen)){
    this->overwrite(__st, this->len, stlen);
    this->len += stlen;
    this->str[this->len] = '\0';
  }
  return *this;
}

STR& STR::concat(STR const &__st){
  if(this->alocc(this->len + __st.len)){
    this->overwrite(__st, this->len, __st.len);
    this->len += __st.len;
    this->str[this->len] = '\0';
  }
  return *this;
}

/****************************************/
STR& STR::copy(char __c){
  switch(__c){
    case '\0':
      this->len = 0;
      this->str[0] = __c;
      break;
    default:
      this->len = 1;
      this->str[0] = __c;
      this->str[1] = (char)NULL;
      break;
  }
  return *this;
}

STR& STR::copy(char *__st){
  size_t stlen = arlen(__st);
  if(this->alocc(stlen)){
    arcpy(this->str, __st);
    this->len = stlen;
  }
  return *this;
}

STR& STR::copy(const char *__st){
  size_t stlen = arlen(__st);
  if(this->alocc(stlen)){
    arcpy(this->str, __st);
    this->len = stlen;
  }
  return *this;
}

STR& STR::copy(STR const &__st){
  if(this->alocc(__st.len)){
    arcpy(this->str, __st.str);
    this->len = __st.len;
  }
  return *this;
}


