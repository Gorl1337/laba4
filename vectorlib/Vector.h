#pragma once
#include <iostream>

template<class T>
class TVector
{
protected:
	T* data;
	int len;
	bool transp;
public:
	TVector();
	TVector(int n, T v);
	TVector(const TVector<T>& p);
	~TVector();

	T* GetData();

	bool GetTransp();
	void Transp();
	int GetLen();
	void SetLen(int l);
	void Resize(int l);

	TVector<T>& operator =(const TVector<T>& p);
	bool operator==(const TVector<T>& p);
	TVector<T> operator/(const TVector<T>& p);
	TVector<T> operator +(const TVector<T>& p);
	TVector<T> operator -(const TVector<T>& p);
	TVector<T> operator *(const TVector<T>& p);
	T& operator[](int i);

};

template<class T>
std::ostream& operator <<(std::ostream& B, TVector<T>& p)
{
	if (p.GetTransp() == false)
	{
		for (int i = 0; i < p.GetLen(); i++)
			B << p[i] << "\t";
	}
	else
	{
		for (int i = 0; i < p.GetLen(); i++)
			B << p[i] << std::endl;
	}
	B << std::endl;
	return B;
}

template<class T>
inline TVector<T>::TVector()
{
	this->transp = false;
	this->len = 0;
	this->data = nullptr;
}

template<class T>
inline T* TVector<T>::GetData()
{
	return data;
}

template<class T>
inline TVector<T>::TVector(int n, T v)
{
	if (n < 1)
		throw "error";
	this->transp = false;
	this->data = new T[n];
	this->len = n;
	for (int i = 0; i < this->len; i++)
		this->data[i] = v;
}

template<class T>
TVector<T>::TVector(const TVector<T>& p)
{
	this->data = new T[p.len];
	this->len = p.len;
	this->transp = false;
	for (int i = 0; i < len; i++)
		data[i] = p.data[i];
}

template<class T>
TVector<T>::~TVector()
{
	if (this->data != nullptr)
	{
		delete[]data;
		data = nullptr;
	}
	len = 0;
}

template<class T>
inline bool TVector<T>::GetTransp()
{
	return transp;
}

template<class T>
inline void TVector<T>::Transp()
{
	if (transp == false)
		transp = true;
	else
		transp = false;
}

template<class T>
int TVector<T>::GetLen()
{
	return this->len;
}

template<class T>
inline void TVector<T>::SetLen(int l)
{
	this->len = l;
}

template<class T>
void TVector<T>::Resize(int l)
{
	if (l < 1)
		throw "error";
	T* mas = new T[l];
	int index = 0;
	if (this->len >= l)
	{
		index = l;
		for (int i = 0; i < index; i++)
			mas[i] = this->data[i];
	}
	else
	{
		index = this->len;
		for (int i = 0; i < index; i++)
			mas[i] = this->data[i];
		for (int i = index; i < this->len; i++)
			mas[i] = 0;
	}
	delete[] this->data;
	this->data = mas;
	this->len = l;
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
	this->data = new T[p.len];
	this->len = p.len;
	for (int i = 0; i < this->len; i++)
		this->data[i] = p.data[i];
	return*this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
	for (int i = 0; i < this->len; i++)
	{
		if (this->data[i] != p.data[i])
			return false;
	}
	return true;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
	TVector<T> res(*this);
	if (this->len != p.len)
		throw "error";
	for (int i = 0; i < this->len; i++)
	{
		if (p.data[i] == 0)
		{
			res[i] = 0;
			continue;
		}
		res[i] = this->data[i] / p.data[i];
	}
	return res;
}

template<class T>
TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
	TVector<T> res(this->len, 0);
	if (this->len != p.len)
		throw "error";
	for (int i = 0; i < this->len; i++)
		res[i] = (*this)[i] + p.data[i];
	return res;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
	TVector<T> res(*this);
	if (this->len != p.len)
		throw "error";
	for (int i = 0; i < this->len; i++)
		res[i] = (*this)[i] - p.data[i];
	return res;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
	TVector<T> res(1, 0);
	if (this->len != p.len)
		throw "error";
	if (p.transp == true || this->transp == false)
	{
		res.data = new T[1];
		res.len = 1;
		for (int i = 0; i < this->len; i++)
		{
			res.data[0] += (*this)[i] * p.data[i];
		}
	}
	if (p.transp == false || this->transp == true)
	{
		/*res.data = new TVector<T>[this->len];
		for (int i = 0; i < this->len; i++)
		{
			for (int j = 0; j < this->len; j++)
			{
				res.data[i][j] = (*this)[i] * p.data[j];
			}
		}*/
	}
	return res;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
	if (i < 0)
		throw "error";
	return data[i];
}

