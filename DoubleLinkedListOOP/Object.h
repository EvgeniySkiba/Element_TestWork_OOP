
#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

using namespace std;

class Object
{
    public  :
        void   * value;
public :

    Object(){}
    virtual  ~Object(){}
    virtual void print()= 0;

	void * get_value()
	{
		return value;
	}
};

#endif


