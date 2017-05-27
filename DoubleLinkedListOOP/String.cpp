
#include "String.h"

String::String()
{ 
    value = new char[1];
    char endLine = '\0';
    strcpy((char*)value,&endLine);		
}

String::String(string strValue)
{
	int len = strValue.length();
	char * lcharValue = new char[len + 1];

	strncpy(lcharValue, strValue.c_str() ,len );
	lcharValue[len] = '\0';

	value = lcharValue;			
}

String::~String()
{
   if(value)
    {
       delete[] (char*)value;
    }
}

void  String::print ()
{
    cout<<(char *) value;
    cout<<" ";
}

String& String::operator=( const String &obj)
{
	if(this == &obj)
		return *this;	  

	// преобразование из void*  текущего значения
	char * lvalue = (char*)obj.value;

	// 1: выделяем "новую" память и копируем элементы
	int len = strlen(lvalue);
	char * new_array = new char[len+1];
	strncpy(new_array, lvalue ,len );
	new_array[len] = '\0';

	// 2: освобождаем "старую" память
	delete [] (char*)value;

	// 3: присваиваем значения в "новой" памяти объекту
	value = new_array;

	return *this;
}

String::String( const String &obj)
{
    // текущее содержимое
    char *currdata = (char *) obj.value;

    // выделить новый блок
    int len = strlen(currdata);
    char * lvalue  = new char[len+1];

    //получить значение
    strncpy(lvalue, currdata ,len );
    lvalue[len] = '\0';
    
    // освободить предыдущий
    delete [] currdata;

    value = lvalue;
}
