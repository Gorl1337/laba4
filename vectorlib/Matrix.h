#pragma once
#include "Vector.h"
#include <iostream>

template <class T>
class TMatrix : public TVector<TVector<T>>
{
protected:
	int width;
public:
	TMatrix(int l = 1);
	TMatrix(int n1, int n2);
	TMatrix(const TMatrix& p);
};