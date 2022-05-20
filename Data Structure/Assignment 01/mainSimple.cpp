#include <iostream>
#include <string>
#include "dequeClass.h"
#include "servivors.h"
using namespace std;

void josephus(int, int, int*, int*);

int main() {
	// set servivors, input var
	int fst, snd;
	int n, k;

	// simple menu loop
	cout << "Enter n, k : ";
	cin >> n >> k;
	// josephus calc and output
	josephus(n, k, &fst, &snd);
	cout << "\nFinal servivors are : " << fst << ", " << snd << '\n';
}


void josephus(int n, int k, int* fst, int* snd) {
	// set classes : servivors for return, deque for calc
	dequeClass d;

	// init deque
	for (int i = 0; i < n; i++)
		d.AddLast(i + 1);

	// calc
	for (int i = 0; i < n - 2; i++) {
		// circulate deque
		for (int j = 0; j < k - 1; j++) {
			d.AddLast(d.GetFirst());
			d.RemoveFirst();
		}

		// remove person
		d.RemoveFirst();
	}

	// set output servivors and return
	*fst = d.GetFirst();
	*snd = d.GetLast();
}
