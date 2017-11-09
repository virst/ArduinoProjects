#include "v_split.h"
#include "Arduino.h"



int Split(String s,char c)
{
	 int str_l = s.length();
	 int n=1;
	 for(int i=0;i<str_l;i++)
	    if(s[i] == c)
	       n++;
	       
	return n;
}

String* Split(String s,char c,int n)
{
	int str_l = s.length();
	int p = 0;
	int k = 0;
	 	       
	String *ss = new String[n];
	for(int i=0;i<str_l;i++)
	   if(s[i] == c)
	   {
	   	  ss[k] = s.substring(p,(i));
	   	  p=i+1;
	   	  k++;
	   }
	   else if(i==(str_l-1))
	   {
	   	  ss[k] = s.substring(p,(str_l));
	   	  k++;
	   }
	   
	    
	return ss;
}
