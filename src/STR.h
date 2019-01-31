//string class built by Alex Vella
#ifndef STR_h
#define STR_h
#include <iostream>

typedef struct CNT{
  size_t* occ;
  size_t count = 0;
  size_t cap;

  CNT(){
    cap = 10;
    occ = new size_t[cap];
  }

  CNT& operator=(CNT const & _cnt){
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

  CNT& set(size_t pos){
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
}CNT;


typedef struct STR{
  public:
    //constructors
    STR();
    STR(STR const &__str);
    STR(STR const &__str, size_t _size);
    STR(const char *__st);
    STR(size_t _size);
    STR(const char *__st, size_t _size);
    STR(char *__st);
    STR(char *__st, size_t _size);

    ~STR();

    //functions
    size_t length();
    size_t capacity();
    char const* const cstr()const;

    STR& pop(size_t howmany = -1);

    STR& remove(size_t pos, size_t howmany = -1);

    STR& insert(STR& __st, size_t pos);
    STR& insert(const char* __st, size_t pos);
    STR& insert(char* __st, size_t pos);
    STR& insert(char __c, size_t pos, uint8_t howmany = 1);

    STR& overwrite(STR const& __st, size_t pos, size_t len);
    STR& overwrite(const char* __st, size_t pos, size_t len);
    STR& overwrite(char* __st, size_t pos, size_t len);
    STR& overwrite(char __c, size_t pos, uint8_t howmany = 1);

    STR& replace(STR& __st1, STR& __st2);
    STR& replace(STR& __st1, const char* __st2);
    STR& replace(STR& __st1, char* __st2);
    STR& replace(STR& __st, char __c);

    STR& replace(const char* __st1, STR& __st2);
    STR& replace(const char* __st1, const char* __st2);
    STR& replace(const char* __st1, char* __st2);
    STR& replace(const char* __st, char __c);

    STR& replace(char* __st1, STR& __st2);
    STR& replace(char* __st1, const char* __st2);
    STR& replace(char* __st1, char* __st2);
    STR& replace(char* __st, char __c);

    STR& replace(char __c, STR& __st);
    STR& replace(char __c, const char* __st);
    STR& replace(char __c, char* __s);
    STR& replace(char __c1, char __c2);

    size_t find(char __c, size_t pos = 0);
    size_t find(STR const &__st, size_t pos = 0);
    size_t find(char *__st, size_t pos = 0);
    size_t find(const char *__st, size_t pos = 0);

    CNT count(char __c);
    CNT count(char *__st);
    CNT count(const char *__st);
    CNT count(STR &__st);

    STR substr(size_t pos = 0, size_t howmany = -1);

    STR& concat(char __c, size_t amount = 1);
    STR& concat(const char *__st);
    STR& concat(char *__st);
    STR& concat(STR const &__st);

    STR& copy(char __c);
    STR& copy(const char *__st);
    STR& copy(char *__st);
    STR& copy(STR const &__st);

    //operators
    bool operator==(STR const &_b);
    bool operator==(char __c);
    bool operator==(char *__st);
    bool operator==(const char *__st);

    char operator[](size_t pos) const;
    char& operator[](size_t pos);

    STR& operator += (STR const &_b);
    STR& operator += (const char * _b);
    STR& operator += (char *_b);
    STR& operator += (char _b);

    STR& operator = (STR const &_b);
    STR& operator = (char _b);
    STR& operator = (const char *_b);
    STR& operator = (char *_b);

    STR operator + (STR const &_b);
    STR operator + (char _b);
    STR operator + (char *_b);
    STR operator + (const char *_b);

  private:
    char *str;
    size_t len;
    size_t cap;

    bool alocc(size_t amount);
    bool shiftR(size_t pos, size_t howmany);
    bool shiftL(size_t pos, size_t howmany);

    STR& master_replace(const char*__s1, const char* __s2, size_t len1, size_t len2);

}STR;

inline std::ostream& operator << (std::ostream& o, STR& a){
  return o << a.cstr();
}

inline std::ostream& operator << (std::ostream& o, const STR &a) {
  return o << a.cstr();
}


char * arcpy(char *__st1, char * __st2);
char * arcpy(char *__st1, const char * __st2);

size_t arlen(char *__st);
size_t arlen(const char * __st);

#endif
