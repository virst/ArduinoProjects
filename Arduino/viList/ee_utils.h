#ifndef ee_utils_h
#define ee_utils_h
#include "Arduino.h"
#include <EEPROM.h>

template <typename T>
class ee_utils {
	public :
	
	ee_utils(void)
	{
		sz = sizeof(T);
		raw = new byte[sz];
	}
	T EEPROM_read(int addr)
	{
		for(byte i = 0; i < sz; i++) raw[i] = EEPROM.read(addr+i);
		T &num = (T&)*raw;
		return num;
	}

	int EEPROM_write(int addr,T num)
	{
		int sz = sizeof(T);	
		(T&)*raw = num;
		for(byte i = 0; i < sz; i++) EEPROM.write(addr+i, raw[i]);
    return addr + sz;
	}

  int GetTypeSize()
  {
    return sz;
  }

	private : 
		int sz; 
		byte *raw;
};

#endif
