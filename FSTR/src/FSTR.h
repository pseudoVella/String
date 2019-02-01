//string class built by Alex Vella
#ifndef FSTR_h
#define FSTR_h

#ifndef CNT_h
#include "CNT.h"
#endif

typedef unsigned int size_t;
typedef unsigned char uint8_t;

typedef struct fstr_t{
  public:
    //constructors
    fstr_t(const fstr_t& __st);
    fstr_t(const fstr_t& __st, const size_t& maxlen);
    fstr_t(const char* __st);
    fstr_t(const char* __st, const size_t& maxlen);
    fstr_t(const size_t& maxlen);

    ~fstr_t();

    //functions
    const size_t& length()const;
    const size_t& capacity()const;
    const char* cstr()const;

    fstr_t& pop(const size_t& howmany = -1);

    fstr_t& remove(const size_t& pos, const size_t& howmany = -1);

    fstr_t& insert(const fstr_t& __st, size_t pos);
    fstr_t& insert(const char* __st, size_t pos);
    fstr_t& insert(const char& __c, size_t pos, const uint8_t& howmany = 1);

    fstr_t& overwrite(const fstr_t& __st, size_t& pos, const size_t& len);
    fstr_t& overwrite(const char* __st, size_t& pos, const size_t& len);
    fstr_t& overwrite(const char& __c, size_t& pos, const size_t& howmany = 1);

    fstr_t& replace(const fstr_t& __st1, const fstr_t& __st2);
    fstr_t& replace(const fstr_t& __st1, const char* __st2);
    fstr_t& replace(const fstr_t& __st, const char& __c);

    fstr_t& replace(const char* __st1, const fstr_t& __st2);
    fstr_t& replace(const char* __st1, const char* __st2);
    fstr_t& replace(const char* __st, const char& __c);

    fstr_t& replace(const char& __c, const fstr_t& __st);
    fstr_t& replace(const char& __c, const char* __st);
    fstr_t& replace(const char& __c1, const char& __c2);

    size_t find(const char& __c, size_t pos = 0);
    size_t find(const fstr_t& __st, size_t pos = 0);
    size_t find(const char* __st, size_t pos = 0);

    CNT count(const char& __c);
    CNT count(const char* __st);
    CNT count(const fstr_t& __st);

    fstr_t substr(const size_t& pos, const size_t& howmany = -1);

    fstr_t& concat(const char& __c, const size_t& amount = 1);
    fstr_t& concat(const char* __st);
    fstr_t& concat(const fstr_t& __st);

    fstr_t& copy(const char& __c);
    fstr_t& copy(const char* __st);
    fstr_t& copy(const fstr_t& __st);

    //operators
    bool operator==(const fstr_t& _b);
    bool operator==(const char& __c);
    bool operator==(const char* __st);

    char& operator[](const size_t& pos);

    fstr_t& operator+=(const fstr_t& _b);
    fstr_t& operator+=(const char& t);
    fstr_t& operator+=(const char* _b);

    fstr_t& operator=(const fstr_t& _b);
    fstr_t& operator=(const char& t);
    fstr_t& operator=(const char* _b);

    fstr_t operator + (const fstr_t& _b);
    fstr_t operator + (const char& _b);
    fstr_t operator + (const char* _b);

  private:
    char *str;
    size_t len;
    size_t cap;

    bool alocc(const size_t& amount);
    bool shiftR(size_t& pos, const size_t& howmany);
    bool shiftL(size_t pos, const size_t& howmany, size_t epos = 0);

    fstr_t& master_replace(const char*__s1, const char* __s2, const size_t& len1, const size_t& len2);
    bool match(const char* __s, const size_t& len, size_t& pos);
}fstr_t;

char* arcpy(char* __st1, const char* __st2);
size_t arncpy(char* __st1, const char* __st2, const size_t& amount);
size_t arlen(const char* __st);

#endif
