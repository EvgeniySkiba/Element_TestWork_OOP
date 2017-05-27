
#include <string.h>
#include <iostream>

#include "Object.h"

#ifndef DOUBLELIKEDLIST_H
#define DOUBLELIKEDLIST_H

using namespace std;

struct Element
{
	Object *data;

	Element *next;
	Element *pred;
	
	Element (Object * obj)
	{
		data = obj;	
	}	
};


class DoubleLikedList
{
private:
	Element *Head;
	Element *pPrev;
	int countElem;
public:
	DoubleLikedList(void);
	~DoubleLikedList(void);
	
	DoubleLikedList& operator=(const DoubleLikedList & list);
	DoubleLikedList(const DoubleLikedList & list);
	
	 void AddToList(Object * data_);
	
	 // отобразить по индексу
     void PrintElem(int numb_);

     void PrintList();

     void DeleteList();

	 //проверка на пустоту 
	 bool IsEmpty();

};

#endif
