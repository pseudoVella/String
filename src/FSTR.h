//string class built by Alex Vella
#ifndef FSTR_h
#define FSTR_h

#ifndef CNT_h
#include "CNT.h"
#endif

#ifndef size_t
typedef unsigned int size_t;
#endif
#ifndef uint8_t
typedef unsigned char uint8_t;
#endif

typedef struct STR{
  public:
    //constructors
    STR(STR const &__str);
    STR(STR const &__str, size_t maxlen);
    STR(const char *__st);
    STR(size_t maxlen);
    STR(const char *__st, size_t maxlen);
    STR(char *__st);
    STR(char *__st, size_t maxlen);

    ~STR();

    //functions
    const size_t& length()const;
    const size_t& capacity()const;
    const char* cstr()const;

    STR& pop(size_t howmany = -1);

    STR& remove(size_t pos, size_t howmany = -1);

    STR& insert(STR& __st, size_t pos);
    STR& insert(const char* __st, size_t pos);
    STR& insert(char* __st, size_t pos);
    STR& insert(char __c, size_t pos, uint8_t howmany = 1);

    STR& overwrite(const STR& __st, size_t& pos, size_t len);
    STR& overwrite(const char* __st, size_t& pos, size_t len);
    STR& overwrite(char* __st, size_t& pos, size_t len);
    STR& overwrite(const char __c, size_t& pos, size_t howmany = 1);

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

    STR& copy(char& __c);
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

    STR& operator+=(STR const& _b);
    STR& operator+=(char t);
    STR& operator+=(char* _b);
    STR& operator+=(const char* _b);

    STR& operator=(STR const& _b);
    STR& operator=(char t);
    STR& operator=(char* _b);
    STR& operator=(const char* _b);

    STR operator + (STR const &_b);
    STR operator + (char _b);
    STR operator + (char *_b);
    STR operator + (const char *_b);

  private:
    char *str;
    size_t len;
    size_t cap;

    bool alocc(size_t amount);
    bool shiftR(size_t& pos, size_t howmany);
    bool shiftL(size_t pos, size_t howmany, size_t epos = 0);

    STR& master_replace(const char*__s1, const char* __s2, size_t len1, size_t len2);
    bool match(const char* __s, size_t const& len, size_t& pos);
}STR;

char* arcpy(char *__st1, const char * __st2);
size_t arncpy(char* __st1, const char* __st2, size_t amount);
size_t arlen(const char * __st);

#endif
