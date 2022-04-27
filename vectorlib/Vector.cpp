#include "Vector.h"
#include <iostream>

template<class T>
inline TVector<T>::TVector(int n, T v)
{
	if (n < 1)
		throw "error";
	this->data = new T[n];
	this->len = n;
	for (int i = 0; i < len; i++)
		this->data[i] = v;
}

template<class T>
TVector<T>::TVector(int n)
{
	if (n < 1)
		throw "error";
	data = new T[n];
	len = n;
	for (int i = 0; i < len; i++)
		data[i] = 0;
}

template<class T>
TVector<T>::TVector(const TVector<T>& p)
{
	data = new T[p.len];
	len = p.len;
	for (int i = 0; i < len; i++)
		data[i] = p.data[i];
}

template<class T>
TVector<T>::~TVector()
{
	if (data != 0)
		delete[] data;
	data = 0;
}

template<class T>
int TVector<T>::GetLen()
{
	return len;
}

template<class T>
TVector<T>& TVector<T>::resize(int l)
{
	TVector res(l);
	if (this->len >= l)
	{
		for (int i = 0; i < l; i++)
			res.data[i] = this->data[i];
	}
	else 
	{
		for (int i = 0; i < this->len; i++);
		{
			res.data[i] = this->data[i];
		}
		for (int i = this->len; i < l; i++)
			res.data[i] = 0;
	}
	return res;
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{

	data = new T[p.len];
	len = p.len;
	for (int i = 0; i < len; i++)
		data[i] = p.data[i];
	return*this;
}

template<class T>
TVector<T> TVector<T>::operator+(TVector<T>& p)
{
	TVector<T> res(this->len);
	if (this->len != p.len)
		throw "error";
	for (int i = 0; i < this->len; i++)
		res[i] = (*this)[i] + p[i];

	return res;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
	if (i < 0)
		throw "error";
	return data[i];
}

template<class T>
std::ostream& operator<<(std::ostream& B, TVector<T>& p)
{
	for (int i = 0; i < p.GetLen(); i++)
	{
		B << p[i] << "\t";
	}
	std::cout << std::endl;
	return B;
}