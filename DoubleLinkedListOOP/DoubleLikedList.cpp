#include "DoubleLikedList.h"

DoubleLikedList::DoubleLikedList()
{
	Head = NULL;
	pPrev = NULL;
	countElem = 0;
}

DoubleLikedList::~DoubleLikedList()
{
	DeleteList();
}

void DoubleLikedList::AddToList(Object * pdata)
{
	Element *temp = new Element(pdata);

    if(Head == NULL)
    {
        temp->pred = NULL;
        temp->next = NULL;
        Head = temp;
    }
    else
        pPrev->next = temp;

    temp->data = pdata;
    temp->next = NULL;
    temp->pred = pPrev;
    pPrev = temp;

    countElem++;
}

void DoubleLikedList::PrintList()
{
	Element *pTemp = Head;

	if(IsEmpty())
	{
		cout << "—писок пуст  "<<endl; 
		return;
	}

	pTemp->data->print();
	pTemp = pTemp->next;

	while(pTemp)
	{		   
		cout<<", ";

		(*pTemp->data).print();
		pTemp = pTemp->next;
	}

	cout<< endl;  
}
// печать элемента но пор€дковому номеру 
void DoubleLikedList::PrintElem(int number_)
{
	if(IsEmpty())
	{
		cout << "—писок пуст  "<<endl; 
		return;
	}

	Element *pTemp = Head;

	if ((number_>countElem) || (number_<0)) 
	{
		cout << "Ёлемент с указанным индексом не найден" << endl; 
	}
	else
	{
		for(int i=0; i!=number_; i++) 
		{ 
			pTemp = pTemp->next;
		}
	}

	cout << "«начение элемента по номеру   " << number_ <<"  -  ";
	pTemp->data->print();
	
	cout<< endl;
	return;

}

void DoubleLikedList::DeleteList()
{
	while(Head != NULL)            
    {
        Element *pTemp = Head;     
        Head = Head->next;        
        delete pTemp;               
    }
 
    Head = NULL;
    countElem =0;
}

DoubleLikedList& DoubleLikedList::operator=(const DoubleLikedList & list)
{
	// самоприсваивание
	if(this == &list)
		return *this;

	if(Head)
		DeleteList();

	Element * currElement = list.Head;
	Head = NULL;		

    while(currElement)            
    {
		// создать элемент из текущего 
		Element *pTemp = new Element(*currElement);		

		//добавить в список 
		AddToList(pTemp->data);			

		currElement = currElement->next;

		delete pTemp;
	}	

	return *this;
}


DoubleLikedList::DoubleLikedList(const DoubleLikedList & list)
{	
	Element * currElement = list.Head;
	Head = NULL;		
	Element *pTemp = NULL;
    while(currElement)            
    {
		// создать элемент из текущего 
		pTemp = new Element(*currElement);		

		//добавить в список 
		AddToList(pTemp->data);			

		currElement = currElement->next;

		delete pTemp;
	}	
}

// проверка списка на пустоту 
bool DoubleLikedList::IsEmpty()
{
	return Head==NULL;
}
