
#ifndef DECIMAL_H
#define DECIMAL_H

#include "Object.h"

class Decimal : public Object
{
    public :
		Decimal();
		Decimal(double  pValue);
		virtual ~Decimal();
		void  print (); 
		Decimal& operator=( const Decimal &obj);
		Decimal::Decimal( const Decimal &obj);
};



#endif
