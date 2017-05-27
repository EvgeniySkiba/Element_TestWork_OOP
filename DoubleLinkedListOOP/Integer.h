
#ifndef INTEGER_H
#define INTEGER_H

#include "Object.h"

class Integer : public Object
{
    public :
		Integer();
		Integer(int  pValue);  
		virtual ~Integer();
		void  print ();
		Integer& operator=( const Integer &obj);
		Integer( const Integer &obj);
};

#endif
