#include "dequeClass.h"

dequeClass::dequeClass() {}

dequeClass::dequeClass(const dequeClass& D) {} // pass

dequeClass::~dequeClass() {}

void dequeClass::AddFirst(int Item) {
	L.Insert(1, Item);
} // add Item to front

void dequeClass::AddLast(int Item) {
	L.Insert(L.Length() + 1, Item);
} // add Item to last

void dequeClass::RemoveFirst() {
	L.Delete(1);
} // del front val

void dequeClass::RemoveLast() {
	L.Delete(L.Length());
} // del last val

int dequeClass::GetFirst() {
	return L.Retrieve(1);
} // return front val

int dequeClass::GetLast() {
	return L.Retrieve(L.Length());
} // return last val

bool dequeClass::IsEmpty() {
	return L.IsEmpty();
} // return empty

int dequeClass::Length() {
	return L.Length();
} // return length

void dequeClass::printDeque() {
	L.printList();
} // debug purposses
