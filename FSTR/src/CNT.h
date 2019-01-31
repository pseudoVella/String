#ifndef CNT_h
#define CNT_h

typedef unsigned int size_t;

typedef struct CNT{
  size_t* occ;
  size_t count = 0;
  size_t cap;

  CNT();
  ~CNT();

  CNT& operator=(CNT const & _cnt);

  CNT& set(size_t pos);
}CNT;
#endif
