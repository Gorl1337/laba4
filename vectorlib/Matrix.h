#pragma once
#include "Vector.h"
#include <iostream>

template <class A>
class TMatrix : public TVector<TVector<A>>
{
protected:
	int width;
public:
	TMatrix();
	TMatrix(int l);
	TMatrix(int n1, int n2);
	TMatrix(const TMatrix& p);
	~TMatrix();

	int GetWidth();
	void SetWidth(int w);
	TMatrix<A> operator+(const TMatrix<A>& p);
	TMatrix<A> operator-(const TMatrix<A>& p);
	TMatrix<A> operator/(const TMatrix<A>& p);
	TMatrix<A> operator*(const TMatrix<A>& p);
	TMatrix<A> operator*(TVector<A>& p);
	TMatrix<A>& operator=(const TMatrix<A>& p);
	bool operator==(const TMatrix<A>& p);
	TVector<A>& operator[](int i);
	void Resize(int w, int l);
};

template<class A>
std::ostream& operator<<(std::ostream& B, TMatrix<A>& p)
{
	for (int i = 0; i < p.GetWidth(); i++)
	{
		for (int j = 0; j < p.GetLen(); j++)
		{
			B << p[i][j] << " ";
		}
		B << std::endl;
	}
	B << std::endl;
	return B;
}

template<class A>
std::istream& operator>>(std::istream& B, TMatrix<A>& p)
{
	for (int i = 0; i < p.GetWidth(); i++)
	{
		for (int j = 0; j < p.GetLen(); j++)
		{
			B >> p[i][j];
		}
	}
	return B;
}

template<class A>
inline TMatrix<A>::TMatrix()
{
	width = 0;
	this->data = nullptr;
}

template<class A>
inline TMatrix<A>::TMatrix(int l):TMatrix()
{
	if (l < 0)
		throw "error";
	width = l;
	this->len = l;
	this->data = new TVector<A>[width];
	for (int i = 0; i < width; i++)
		this->data[i].Resize(l);
}

template<class A>
inline TMatrix<A>::TMatrix(int n1, int n2):TMatrix()
{
	if (n1 < 1 || n2 < 1)
		throw "error";
	width = n1;
	this->len = n2;
	this->data = new TVector<A>[width];
	for (int i = 0; i < width; i++)
		this->data[i].Resize(n2);
}

template<class A>
TMatrix<A>::TMatrix(const TMatrix& p)
{
	this->len = p.len;
	width = p.width;
	if (p.data == 0)
		this->data = 0;
	else
	{
		this->data = p.data;
		for (int i = 0; i < width; i++)
			this->data[i] = p.data[i];
	}
}

template<class A>
inline TMatrix<A>::~TMatrix()
{
	width = 0;
	delete[](this->data);
}

template<class A>
inline int TMatrix<A>::GetWidth()
{
	return width;
}

template<class A>
inline void TMatrix<A>::SetWidth(int w)
{
	width = w;
}

template<class A>
inline TMatrix<A> TMatrix<A>::operator+(const TMatrix<A>& p)
{
	if (p.len != this->len || p.width != width)
		throw "error";
	TMatrix<A> res(*this);
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			res[i][j] = (*this)[i][j] + p.data[i][j];
		}
	}
	return res;
}

template<class A>
inline TMatrix<A> TMatrix<A>::operator-(const TMatrix<A>& p)
{
	if (p.len != this->len || p.width != width)
		throw "error";
	TMatrix<A> res(*this);
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			res[i][j] = (*this)[i][j] - p.data[i][j];
		}
	}
	return res;
}

template<class A>
inline TMatrix<A> TMatrix<A>::operator/(const TMatrix<A>& p)
{
	
}

template<class A>
inline TMatrix<A> TMatrix<A>::operator*(const TMatrix<A>& p)
{
	if (this->width != p.len)
		throw "error";
	TMatrix res(this->len, p.width);
	for (int i= 0; i < this->len; i++)
	{
		for (int j = 0; j < p.width; j++)
		{
			for (int a = 0; a < this->width; a++) 
			{
				res[i][j] += (*this)[i][a] * p.data[a][j];
			}
		}
	}
}

template<class A>
inline TMatrix<A> TMatrix<A>::operator*(TVector<A>& p)
{
	if (this->len != p.GetLen()) 
		throw "Error";
	TVector<T> res(width, 0);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			res[i] += this->data[i][j] * p[j];
		}
	}
	return res;
}

template<class A>
inline TMatrix<A>& TMatrix<A>::operator=(const TMatrix<A>& p)
{
	this->data = p.data;
	this->len = p.len;
	width = p.width;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			(*this)[i][j] = p.data[i][j];
		}
	}
	return*this;
}

template<class A>
inline bool TMatrix<A>::operator==(const TMatrix<A>& p)
{
	if (this->len != p.len || width != p.width)
		return false;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			if ((*this)[i][j] != p.data[i][j])
				return false;
		}
	}
	return true;
}

template<class A>
inline TVector<A>& TMatrix<A>::operator[](int i)
{
	if (i < 0 || i >= width)
		throw "Error";
	return this->data[i];
}

template<class A>
TMatrix<A> operator*(TVector<A>& v, TMatrix<A>& p)
{
	if (p.GetWidth() != 1) 
		throw "Error";
	TMatrix<T> res(v.GetLen(), p.GetLen());
	for (int i = 0; i < v.GetLen(); i++)
	{
		for (int j = 0; j < v.GetLen(); j++)
		{
			res[i][j] = v[i] * p[0][j];
		}
	}
	return res;
}

template<class A>
inline void TMatrix<A>::Resize(int w, int l)
{
	if (w < 1 || l < 1)
		throw "error";
	TMatrix res(w, l);
	if (w < width)
	{
		for (int i = 0; i < w; i++)
		{
			res.data[i] = (*this)[i];
			res.data[i].Resize(l);
		}
	}
	else
	{
		for (int i = 0; i < width; i++)
		{
			res.data[i] = (*this)[i];
			res.data[i].Resize(l);
		}
		for (int i = width; i < w; i++)
		{
			for (int j = 0; j < l; j++)
				res.data[i][j] = 0;
		}
	}
	delete[]this->data;
	width = w;
	this->len = l;
	this->data = res.data;
}