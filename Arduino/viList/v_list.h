#ifndef v_list_h
#define v_list_h
#include "Arduino.h"

template <typename T>
class vList
{
public:

vList(void)
{
  len = 0;
  real_len = 5;
  growth_mult = 1;
  growth_plus = 5;

  ss = new T[real_len];
}

~vList(void)
{
}


void Add(T s)
{
  if(len<real_len)
  {
    ss[len]=s;
    len++;
  }
  else
  {
    chSizeMas();
    Add(s);
  }
}

T GetItem(int n)
{
  if(n>=real_len)
    return "";
  return ss[n];
}

void SetItem(int n,T s)
{
  if(n>=real_len)
    return;
  ss[n] = s;
}


int Length()
{
  return len;
}

private:

void chSizeMas()
{
  tmp_len = real_len*growth_mult+growth_plus;
  T *tmp = new T[tmp_len];
  for(int i=0;i<real_len;i++)
    tmp[i]=ss[i];
  delete ss;
  real_len = tmp_len;
  ss = tmp;
}
  T *ss;
  int len;
  int real_len;
  int tmp_len;
  int growth_mult;
  int growth_plus;
};

#endif