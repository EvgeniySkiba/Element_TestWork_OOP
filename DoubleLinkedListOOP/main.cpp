#include <conio.h>

#include "Object.h"
#include "String.h"
#include "Integer.h"
#include "Decimal.h"

#include "DoubleLikedList.h"

//������ �������������� � ������������� ���������� �������
#define  _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{	
	//������ ������� ����
	setlocale(LC_ALL,"Russian");

	DoubleLikedList list; 

	String * obj = new String("������");	
	Element elem(obj);
	list.AddToList(elem.data);

	Integer * obj2 = new Integer(115);	
	Element elem2(obj2);
	list.AddToList(elem2.data);

	Decimal * obj3= new Decimal(30.1667);	
	Element elem3(obj3);
	list.AddToList(elem3.data);
 

	cout<<"���������� ������� ������ :"<<endl;
	list.PrintList();
	cout<<endl;	
	
	DoubleLikedList list2 = list;	
	cout<<"������ ������ :"<<endl;
	list2.PrintList();
    cout<<endl;	

	
	DoubleLikedList list3;
	list3 = list2;
    cout<<"������ ������ :"<<endl;
	list3.PrintList();
	cout<<endl;	

	list3.PrintElem(2);
	list3.PrintElem(1);

	delete obj;
	delete obj2;
	delete obj3;
	
    cout<<"\nPlease press any key to continue..."<<endl;    
    _getch();
    return 0;
}
