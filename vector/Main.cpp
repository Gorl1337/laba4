#include <iostream>
#include "Vector.h"
#include "Matrix.h"
int main()
{
	TVector<int> a(10, 2);
	TVector<double> b(10, 3.5);
	TVector<char> c(10, 'a');

	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << c << std::endl;

	//TMatrix<int> D(5);
	return 0;
}