#include "Decimal.h"

Decimal::Decimal()
{ 
	int num =0;
    value = new double[1];          
	memcpy (this->value,&num,sizeof(double) );
  
}

Decimal::Decimal(double  pValue)
{
	value = new double [1];
	memcpy (value,&pValue,sizeof(double) );					
}

Decimal::~Decimal()
{
   if(value)
    {
       delete[] (double*)value;
    }
}

void  Decimal::print ()
{
    cout<< *(reinterpret_cast<double*>(value))<<" ";	
    cout<<" ";
}


Decimal& Decimal::operator=( const Decimal &obj)
{
if(this == &obj)
  return *this;	  

double * ldata = (double*)obj.value;

double * double_array = new double[1];
memcpy (this->value,&double_array , sizeof(double));

delete [] (double*)value;

value = double_array ;

return *this;
}


Decimal::Decimal( const Decimal &obj)
{
// текущее содержимое        
double * ldata = (double*)obj.value;		

// выделить новый блок
 double * double_array = new double[1];

//получить значение
memcpy (this->value,&double_array , sizeof(double));

// освободить предыдущий
delete [] (double*)value;

value = double_array ;
}