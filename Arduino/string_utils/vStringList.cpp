#include "vStringList.h"


vStringList::vStringList(void)
{
	len = 0;
	real_len = 5;
	growth_mult = 1;
	growth_plus = 5;

	ss = new String[real_len];
}


vStringList::~vStringList(void)
{
}

void vStringList::chSizeMas()
{
	tmp_len = real_len*growth_mult+growth_plus;
	String *tmp = new String[tmp_len];
	for(int i=0;i<real_len;i++)
		tmp[i]=ss[i];
	delete ss;
	real_len = tmp_len;
	ss = tmp;
}

void vStringList::Add(String s)
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
String vStringList::GetItem(int n)
{
	if(n>=real_len)
		return "";
	return ss[n];
}
void vStringList::SetItem(int n,String s)
{
	if(n>=real_len)
		return;
	ss[n] = s;
}

int vStringList::Length()
{
	return len;
}
