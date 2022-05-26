#include <iostream>
#include "Vector.h"
#include "Matrix.h"
int main()
{	
	TVector<int> A(3, 0);
	TVector<int> B(3, 0);
	TVector<int> C(3, 0);
	int a = 0;

	std::cin >> A >> B;
	std::cout << std::endl;

	C = A + B;
	std::cout << "A + B = " << C << std::endl;

	A.SetTransp(true);
	std::cout << "Vector A is now transposed" << std::endl;
	a = A * B;
	std::cout << "A * B = " << a << std::endl << std::endl;

	std::cout << "Is A = B? ->" << (A == B) << std::endl << std::endl;

	C = A / B;
	std::cout << "A / B = " << C << std::endl;

	C = C - A;
	std::cout << "(A / B) - A = " << C << std::endl;

	int i = 0;
	std::cout << "Print i ";
	std::cin >> i;
	std::cout << "A[i] = " << A[i] << std::endl;

	TMatrix<int> m1(3, 3);
	TMatrix<int> m2(3, 3);
	TMatrix<int> m3(3, 3);

	for (int j = 0; j < m2.GetLen(); j++)
		for (int k = 0; k < m2.GetWidth(); k++)
			m2[j][k] = rand() % 100 + 100;
	std::cin >> m1;

	m3 = m1 + m2;
	std::cout << "m1 + m2 = " << std::endl << m3 << std::endl;

	m3 = m1 * m2;
	std::cout << "m1 * m2 = " << std::endl << m3 << std::endl;

	TVector<int> M(3, 0);
	M = m1 * A;

	std::cout << "vector A * matrix m1 = " << std::endl;
	std::cout << M;

	TMatrix<int> N(3, 3);
	N = m1;
	std::cout << "N = m1, N = " << std::endl << N;

	return 0;
}