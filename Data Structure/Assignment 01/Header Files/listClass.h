typedef struct nodeRecord {
	int Data;
	struct nodeRecord* Next;
} node;
typedef node* Nptr;

class listClass {
public:
	listClass();
	listClass(const listClass& L); // pass
	~listClass();
	void Insert(int Position, int Item); // Position(starting from 1) insert
	void Delete(int Position); // Position's val del
	int Retrieve(int Position); // Position's val return
	bool IsEmpty(); // return empty
	int Length(); // return length
	void printList(); // debug purposes
private:
	int Count;
	Nptr Rear;
};
