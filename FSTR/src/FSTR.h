//string class built by Alex Vella
#ifndef FSTR_h
#define FSTR_h

#ifndef CNT_h
#include "CNT.h"
#endif

typedef unsigned int size_t;
typedef unsigned char uint8_t;

typedef struct STR{
  public:
    //constructors
    STR(const STR& __str);
    STR(const STR& __str, const size_t maxlen);
    STR(const char *__st);
    STR(const char *__st, const size_t maxlen);
    STR(const size_t maxlen);

    ~STR();

    //functions
    const size_t& length()const;
    const size_t& capacity()const;
    const char* cstr()const;

    STR& pop(const size_t howmany = -1);

    STR& remove(const size_t pos, const size_t howmany = -1);

    STR& insert(const STR& __st, size_t pos);
    STR& insert(const char* __st, size_t pos);
    STR& insert(const char __c, size_t pos, const uint8_t howmany = 1);

    STR& overwrite(const STR& __st, size_t& pos, const size_t len);
    STR& overwrite(const char* __st, size_t& pos, const size_t len);
    STR& overwrite(const char __c, size_t& pos, const size_t howmany = 1);

    STR& replace(const STR& __st1, const STR& __st2);
    STR& replace(const STR& __st1, const char* __st2);
    STR& replace(const STR& __st, const char __c);

    STR& replace(const char* __st1, const STR& __st2);
    STR& replace(const char* __st1, const char* __st2);
    STR& replace(const char* __st, const char __c);

    STR& replace(const char __c, const STR& __st);
    STR& replace(const char __c, const char* __st);
    STR& replace(const char __c1, const char __c2);

    size_t find(const char __c, size_t pos = 0);
    size_t find(const STR& __st, size_t pos = 0);
    size_t find(const char *__st, size_t pos = 0);

    CNT count(const char __c);
    CNT count(const char *__st);
    CNT count(const STR& __st);

    STR substr(const size_t pos = 0, const size_t howmany = -1);

    STR& concat(const char __c, const size_t amount = 1);
    STR& concat(const char *__st);
    STR& concat(const STR& __st);

    STR& copy(const char __c);
    STR& copy(const char *__st);
    STR& copy(const STR& __st);

    //operators
    bool operator==(const STR& _b);
    bool operator==(const char __c);
    bool operator==(const char *__st);

    char& operator[](const size_t pos);

    STR& operator+=(const STR& _b);
    STR& operator+=(const char t);
    STR& operator+=(const char* _b);

    STR& operator=(const STR& _b);
    STR& operator=(const char t);
    STR& operator=(const char* _b);

    STR operator + (const STR& _b);
    STR operator + (const char _b);
    STR operator + (const char *_b);

  private:
    char *str;
    size_t len;
    size_t cap;

    bool alocc(const size_t amount);
    bool shiftR(size_t& pos, const size_t howmany);
    bool shiftL(size_t pos, const size_t howmany, size_t epos = 0);

    STR& master_replace(const char*__s1, const char* __s2, const size_t len1, const size_t len2);
    bool match(const char* __s, const size_t& len, size_t& pos);
}STR;

char* arcpy(char* __st1, const char* __st2);
size_t arncpy(char* __st1, const char* __st2, const size_t amount);
size_t arlen(const char* __st);

#endif
