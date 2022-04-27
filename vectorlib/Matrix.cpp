#include <iostream>
#include "Matrix.h"
#include "Vector.h"
template<class T>
inline TMatrix<T>::TMatrix(int l)
{
	if (l < 0)
		throw "error";
	width = l;
	this->data = new TVector[width];
	for (int i = 0; i < width; i++)
		this->data[i].resize(len);
}

template<class T>
TMatrix<T>::TMatrix(int n1, int n2)
{
	len2 = n2;
	for (int i = 0; i < n1; i++)
	{
		this->data[i] = n2;
		for (int j = 0; j < n2; i++)
			data[i][j] = 0;
	}
}

template<class T>
TMatrix<T>::TMatrix(const TMatrix& p)
{
	this->len = p.len;
	width = p.width;
	if (p.data == 0)
		this->data = 0;
	else
	{
		this->data = new TVector[width];
		for (int i = 0; i < width; i++)
			this->data[i] = p.data[i];
	}
}
