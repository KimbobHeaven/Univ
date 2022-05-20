#pragma once
#include "listClass.h"

class dequeClass {
public:
	dequeClass();
	dequeClass(const dequeClass& D); // pass
	~dequeClass();
	void AddFirst(int Item); // add Item to front
	void AddLast(int Item); // add Item to last
	void RemoveFirst(); // del front val
	void RemoveLast(); // del last val
	int GetFirst(); // return front val
	int GetLast(); // return last val
	bool IsEmpty(); // return empty
	int Length(); // return length
	void printDeque(); // debug purposses
private:
	listClass L;
};
