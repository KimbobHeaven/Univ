#include <iostream>
#include "listClass.h"
using namespace std;

listClass::listClass() {
	Count = 0;
	Rear = NULL;
}

listClass::listClass(const listClass& L) {} // pass

listClass::~listClass() {
	while (!IsEmpty())
		Delete(1);
}

void listClass::Insert(int Position, int Item) {
	if ((Position > Count + 1) || (Position < 1))  // invalid index
		cout << "Error : Position out of Range\n";
	else {
		Nptr p = new node();
		if (IsEmpty()) {
			p->Data = Item;
			p->Next = p;
		}
		else {
			Nptr Temp = Rear;
			for (int i = 0; i < ((Position - 1) % Count); i++)  // find position
				Temp = Temp->Next;
			p->Data = Item;
			p->Next = Temp->Next;
			Temp->Next = p;
		}
		if (Position == (Count + 1))
			Rear = p;
		Count++;
	}
} // Position(starting from 1) insert

void listClass::Delete(int Position) {
	if (IsEmpty())  // empty
		cout << "Error : Deletion on Empty List\n";
	else if ((Position > Count) || (Position < 1))  // invalid index
		cout << "Error : Position out of Range\n";
	else {
		Nptr p;
		Nptr Temp = Rear;
		for (int i = 0; i < (Position - 1); i++)  // find position
			Temp = Temp->Next;
		p = Temp->Next;
		Temp->Next = p->Next;
		if (Position == Count)
			Rear = Temp;
		Count -= 1;

		// free
		delete p;
		p = NULL;
	}
} // Position's val del

int listClass::Retrieve(int Position) {
	if (IsEmpty())  // empty
		cout << "Error : Retrieval on Empty List\n";
	else if ((Position > Count) || (Position < 1))  // invalid index
		cout << "Error : Position out of Range\n";
	else {
		Nptr Temp = Rear->Next;
		for (int i = 0; i < (Position - 1); i++)  // find position
			Temp = Temp->Next;
		return Temp->Data;
	}
	
	// error return -1
	return -1;
} // Position's val return

bool listClass::IsEmpty() {
	return (Count == 0);
} // return empty

int listClass::Length() {
	return Count;
} // return length

void listClass::printList() {
	Nptr Temp = Rear->Next;
	for (int i = 0; i < Count; i++) {
		cout << "Pos." << i + 1 << " : " << Temp->Data << '\n';  // output
		Temp = Temp->Next;  // next index
	}
}
