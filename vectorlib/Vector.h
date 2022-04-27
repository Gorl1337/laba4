#pragma once
#include <iostream>

template<class T>
class TVector
{
protected:
	T* data;
	int len;
public:
	TVector(int n, T v);
	TVector(int n = 1);
	TVector(const TVector<T>& p);
	~TVector();

	int GetLen();
	TVector<T>& resize(int l);

	TVector<T>& operator =(const TVector<T>& p);
	TVector<T> operator +(TVector<T>& p);
	T& operator[](int i);

	friend std::ostream& operator <<(std::ostream& B, TVector<T>& p);
};