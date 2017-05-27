
#ifndef STRING_H
#define STRING_H

#include "Object.h"

class String : public Object
{
    public :
		String();
		String(string strValue);
		virtual ~String();
		void  print ();
		String& operator=( const String &obj); 
		String::String( const String &obj);
};
#endif
