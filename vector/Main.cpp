#include <iostream>
#include "Vector.h"
#include "Matrix.h"
int main()
{
	TVector<int> a(5, 5);
	TVector<double> b(10, 3.5);
	TVector<char> c(10, 'a');
	TVector<int> A(5, 3);
	TVector<int> res(10, 0);
	TVector<double> k(10, 5.5);
	TVector<double> n(10, 0);

	n = k + b;
	std::cout << n;

	A = A - a;
	std::cout << A;

	A = A / a;
	std::cout << std::endl << A;

	A.Transp();
	std::cout << A;

	res = A * a;
	std::cout << res;

	std::cout << (A == a) << std::endl;


	TMatrix<int> D(2,1);
	TMatrix<int> C(3,4);
	for (int i = 0; i < D.GetWidth(); i++)
		for (int j = 0; j < D.GetLen(); j++)
			D[i][j] = rand();
	TMatrix<int> E(D);
	TMatrix<int> F(3, 4);
	TMatrix<int> G(F);
	for (int i = 0; i < F.GetWidth(); i++)
		for (int j = 0; j < F.GetLen(); j++)
			F[i][j] = rand();
	C = F;
	G.Resize(4, 3);
	E = G * C;
	std::cout << D;
	std::cout << C;
	std::cout << E;
	return 0;
}