#include "Integer.h"


Integer::Integer()
{ 
	int num =0;
	value = new int[1];          
	memcpy (this->value,&num,sizeof(int) );
}

Integer::Integer(int  pValue)
{
	value = new int [1];
	memcpy (value,&pValue,sizeof(int) );					
}

Integer::~Integer()
{
   if(value)
    {
       delete[] (char*)value;
    }
}

void  Integer::print ()
{
    cout<< *(reinterpret_cast<int*>(value))<<" ";	
    cout<<" ";
}

Integer& Integer::operator=( const Integer &obj)
{
	if(this == &obj)
		return *this;	  

	int * ldata = (int*)obj.value;

	int * double_array = new int[1];
	memcpy (this->value,&double_array , sizeof(int));

	delete [] (int*)value;

	value = double_array ;

	return *this;
}


Integer::Integer( const Integer &obj)
{
	// ������� ����������        
	int * ldata = (int*)obj.value;	

	// �������� ����� ����
	int * int_array = new int[1];

	//�������� ��������
	memcpy (this->value,&int_array , sizeof(int));

	// ���������� ����������
	delete [] (int*)value;

	value = int_array ;
}
