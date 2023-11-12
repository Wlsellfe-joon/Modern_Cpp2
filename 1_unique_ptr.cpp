#include<iostream>
#include<memory>
using namespace std;


int main() {
	int* ex = new int;
	*ex = 3;
	cout << "general ptr alloc address: "<< ex << "; the value is: " << *ex << endl; // General memory allocation to ptr

	int* ex1 = new int[10];

	cout << "array mem alloc example, the value before initialization: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << ex1[i] << ", ";
		ex1[i] = i;
	}

	cout << "The value after initialization: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << ex1[i] << ", ";
	}

	// ex2 unique pointer alloc
	unique_ptr<int> ptr{ new int };
	*ptr = 5;
	cout << endl << *ptr << endl;

	//The array pointed by uniq_ptr can not be initialized using '*' operator
	unique_ptr<int[]> ptr1{ new int[10] };
	for (unsigned i = 0; i < 10; i++) {
		ptr1[i] = i; 
	}

	// there is no requirement of deleting memory in the case of unique pointers
	delete ex;
	delete[] ex1;
	return 0;
}