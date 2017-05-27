
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

	// �������������� �� void*  �������� ��������
	char * lvalue = (char*)obj.value;

	// 1: �������� "�����" ������ � �������� ��������
	int len = strlen(lvalue);
	char * new_array = new char[len+1];
	strncpy(new_array, lvalue ,len );
	new_array[len] = '\0';

	// 2: ����������� "������" ������
	delete [] (char*)value;

	// 3: ����������� �������� � "�����" ������ �������
	value = new_array;

	return *this;
}

String::String( const String &obj)
{
    // ������� ����������
    char *currdata = (char *) obj.value;

    // �������� ����� ����
    int len = strlen(currdata);
    char * lvalue  = new char[len+1];

    //�������� ��������
    strncpy(lvalue, currdata ,len );
    lvalue[len] = '\0';
    
    // ���������� ����������
    delete [] currdata;

    value = lvalue;
}
