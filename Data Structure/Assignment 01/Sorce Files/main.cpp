#include <iostream>
#include <string>
#include "dequeClass.h"
#include "servivors.h"
using namespace std;

int inputInt();
int mainMenu(int);
servivors josephus(int, int, int);

int main() {
	// set option for showing process
	servivors result;
	int showProcess = 0;
	int n, k;

	// simple menu loop
	while (1) {
		switch (int choice = mainMenu(showProcess)) {
		case 1:  // josephus
			// input n, k. error handling
			cout << "Enter n(length of the deque) : ";
			n = inputInt();
			if (n == -1) {
				cout << "Input error : Not a positive integer\n";
				system("PAUSE");
				break;
			}
			cout << "Enter k(steps to take) : ";
			k = inputInt();
			if (n == -1) {
				cout << "Input error : Not a positive integer\n";
				system("PAUSE");
				break;
			}

			// josephus calc and output
			result = josephus(n, k, showProcess);
			cout << "Final servivors are : " << result.getFst() << ", " << result.getSnd() << "\n\n";
			system("PAUSE");
			break;
		case 2:  // toggle
			showProcess = (showProcess += 1) % 3;
			break;
		case 3:  // exit
			cout << "Exiting...\n";
			exit(0);
		default:  // impossible?
			cout << "Unknown error. Exiting...\n";
			exit(1);
		}
	}
}

int inputInt() {
	// input
	string choice;
	getline(cin, choice, '\n');

	// stoi
	int result = 0;
	for (int i = 0; i < choice.length(); i++) {
		if (((int)choice[i] >= 48) && ((int)choice[i] <= 57))
			result = result * 10 + choice[i] - 48;
		else if ((int)choice[i] != 32)  // error out. ascii code 32 = space
			return -1;
	}

	return result;
}

int mainMenu(int show) {
	// clear screen
	system("CLS");

	while (1) {
		// menu
		cout << "Choose from menu\n";
		cout << "1. Solve Josephus Problem\n";
		cout << "2. Toggle Show Process Option : ";
		switch (show) {
		case 0:
			cout << "OFF\n";
			break;
		case 1:
			cout << "Cycle ON\n";
			break;
		case 2:
			cout << "Cycle OFF\n";
			break;
		}
		cout << "3. Exit program                          : ";

		// input
		int choice = inputInt();

		// check choice
		system("CLS");
		if ((choice == 1) || (choice == 2) || (choice == 3))
			return choice;
		cout << "Choice error. Please try again.\n";
	}
}

servivors josephus(int n, int k, int show) {
	// set classes : servivors for return, deque for calc
	// set var : int for cycle off option
	servivors s(1, n);
	dequeClass d;
	int sumCycle = 0;

	// init deque
	for (int i = 0; i < n; i++)
		d.AddLast(i + 1);

	// print init deque : both cycle off and on
	if (show) {
		cout << "\nInit : ";
		for (int i = 0; i < d.Length(); i++) {
			// print front and circulate deque
			cout << d.GetFirst() << ' ';
			d.AddLast(d.GetFirst());
			d.RemoveFirst();
		}
		cout << "\n\n";
	}

	switch (show) {
	case 0:
	case 1:
		// calc : OFF , cycle ON
		for (int i = 0; i < n - 2; i++) {
			// circulate deque
			for (int j = 0; j < k - 1; j++) {
				d.AddLast(d.GetFirst());
				d.RemoveFirst();
			}

			// save and remove k th person
			int tmp = d.GetFirst();
			d.RemoveFirst();

			// print currunt deque
			if (show) {
				cout << "Cycle." << i + 1 << " : ";
				for (int j = 0; j < d.Length(); j++) {
					// print front and circulate deque
					cout << d.GetFirst() << ' ';
					d.AddLast(d.GetFirst());
					d.RemoveFirst();
				}
				cout << "\nOut : " << tmp << "\n\n";
			}
		}
		break;
	case 2:
		// calc : cycle OFF
		int preCycle = 0;
		for (int i = 0; i < n - 2; i++) {
			// circulate deque
			int curCycle = (preCycle + k - 1) % d.Length();
			preCycle = curCycle;
			for (int j = 0; j < curCycle; j++) {
				d.AddLast(d.GetFirst());
				d.RemoveFirst();
			}

			// save and remove k th person
			int tmp = d.GetFirst();
			d.RemoveFirst();

			// restore previous state
			for (int j = 0; j < curCycle; j++) {
				d.AddFirst(d.GetLast());
				d.RemoveLast();
			}

			// print currunt deque
			cout << "Cycle." << i + 1 << " : ";
			for (int j = 0; j < d.Length(); j++) {
				// print front and circulate deque
				cout << d.GetFirst() << ' ';
				d.AddLast(d.GetFirst());
				d.RemoveFirst();
			}
			cout << "\nOut : " << tmp << "\n\n";
		}
		break;
	}


	// set output servivors and return
	if (!show)
		cout << '\n';
	s.setFst(d.GetFirst());
	s.setSnd(d.GetLast());
	return s;
}
