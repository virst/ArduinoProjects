#ifndef v_stringlist_h
#define v_stringlist_h
#include "Arduino.h"

class vStringList
{
public:
	vStringList(void);
	~vStringList(void);

	void Add(String s);
	String GetItem(int n);
	void SetItem(int n,String s);
	int Length();

private:
    void chSizeMas();
	String *ss;
	int len;
	int real_len;
	int tmp_len;
	int growth_mult;
	int growth_plus;
};

#endif
