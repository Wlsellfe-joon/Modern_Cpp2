#include<memory>
#include<iostream>
using namespace std;

shared_ptr<double> F() {
	shared_ptr<double> p1{ new double };
	shared_ptr<double> p2{ new double }, p3 = p1;
	cout << "p3.use_count(): " << p3.use_count() << endl;
	return p3;
}


int main() {
	shared_ptr<double> p = F();
	// p2 is not used forever in F(), so it is deleted after calling F(),
	// but p get a return value from F(), and also it is shared with p1, p3
	// So, p, p1, p3 is not deleted yet.

	shared_ptr<double> p4 = make_shared<double>(); 
	// If using this func, it can be set at the same space of the mem, the manager and data to pe pointed.

	auto p5 = make_shared<double>(); // Best!!!
	
	return 0;
}