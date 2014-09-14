
#include <iostream>
#include "ora.h"

using namespace std;

int main() {

	ORA::Matrix<double> A(2, 2);
	ORA::Matrix<double> B(2, 2);
	ORA::Matrix<double> C(2, 2);

	A.set(0, 0, 1);

	B.set(1, 0, 1);
//	B.set(1, 1, 1);


	C = A + B;


	A.print();
	cout << "---- " << endl;
	B.print();
	//C.print();

	return 0;
}
