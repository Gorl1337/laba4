#pragma once
#include <iostream>

template <class T>
class TVector
{
public:
  TVector();
  TVector(int l, T v);
  TVector(const TVector<T>& p);
  ~TVector();

  bool GetTransp();
  void SetTransp(bool s);
  void SetLen(int l);
  int GetLen();
  void Resize(int l);

  TVector<T> operator +(const TVector<T>& p);
  TVector<T> operator -(const TVector<T>& p);
  int operator *(const TVector<T>& p);
  TVector<T> operator /(const TVector<T>& p);
  TVector<T>& operator =(const TVector<T>& p);
  bool operator ==(const TVector<T>& p);
  T& operator [](int i);

  template <class T>
  friend std::ostream& operator << (std::ostream& B, TVector<T>& p);
  template <class T>
  friend std::istream& operator >> (std::istream& B, TVector<T>& p);

protected:
  T* data;
  int len;
  bool transp;
};

template<class T>
inline TVector<T>::TVector()
{
  this->len = 0;
  this->data = nullptr;
  this->transp = false;
}

template<class T>
inline TVector<T>::TVector(int l, T v)
{
  if (l < 1)
    throw "len < 1";
  this->transp = false;
  this->data = new T[l];
  this->len = l;
  for (int i = 0; i < len; i++)
    this->data[i] = v;
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
  if (p.data == nullptr)
  {
    this->data = nullptr;
    this->len = 0;
    this->transp = false;
  }
  else
  {
    this->len = p.len;
    this->transp = false;
    this->data = new T[len];
    for (int i = 0; i < this->len; i++)
      this->data[i] = p.data[i];
  }
}

template<class T>
inline TVector<T>::~TVector()
{
  if (this->data != nullptr)
  {
    delete[] this->data;
    this->data = nullptr;
  }
  this->len = 0;
}

template<class T>
inline bool TVector<T>::GetTransp()
{
  return transp;
}

template<class T>
inline void TVector<T>::SetTransp(bool s)
{
  this->transp = s;
}

template<class T>
inline void TVector<T>::SetLen(int l)
{
  this->Resize(l);
  this->len = l;
}

template<class T>
inline int TVector<T>::GetLen()
{
  return len;
}

template<class T>
inline void TVector<T>::Resize(int l)
{
  if (l < 1) 
    throw "len < 1";
  T* mas = new T[l];
  if (this->data != nullptr)
  {
    int a = 0;
    if (this->len > l)
      a = l;
    else a = this->len;
    for (int i = 0; i < a; i++)
      mas[i] = this->data[i];
    delete[] this->data;
  }
  this->data = mas;
  this->len = l;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
  if (this->len == 0)
    throw "len = 0";
  if (this->len != p.len)
    throw "len isn't the same";
  TVector<T> res(this->len, 0);
  for (int i = 0; i < len; i++)
    res[i] = this->data[i] + p.data[i];
  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
  if (this->len == 0)
    throw "len = 0";
  if (this->len != p.len) 
    throw "len isn't the same";
  TVector<T> res(this->len, 0);
  for (int i = 0; i < len; i++)
    res[i] = this->data[i] - p.data[i];
  return res;
}

template<class T>
int TVector<T>::operator*(const TVector<T>& p)
{
  if (this->len == 0) 
    throw "len = 0";
  if (this->len != p.len) 
    throw "len isn't the same";
  int a = 0;
  if ((p.transp == true && this->transp == false) || (this->transp == true && p.transp == false))
  {
    for (int i = 0; i < this->len; i++)
    {
      a += (*this)[i] * p.data[i];
    }
  }
  else
    throw "Error: one vector must be transposed";
  return a;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
  if (this->len == 0) 
    throw "len = 0";
  if (this->len != p.len) 
    throw "len isn't the same";
  TVector<T> A(this->len, 0);
  for (int i = 0; i < this->len; i++)
  {
    if (p.data[i] == 0)
      A[i] = 0;
    else
      A[i] = this->data[i] / p.data[i];
  }
  return A;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
  if (this == &p) 
    return *this;
  if (this->data != nullptr) 
    delete[] this->data;
  if (p.data == nullptr)
  {
    this->len = 0;
    this->data = nullptr;
  }
  else
  {
    this->len = p.len;
    this->data = new T[len];
    for (int i = 0; i < this->len; i++)
      this->data[i] = p.data[i];
  }
  return *this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
  if (this->len != p.len) 
    return false;
  for (int i = 0; i < this->len; i++)
  {
    if (this->data[i] != p.data[i])
      return false;
  }
  return true;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
  if (data == nullptr)
    throw "data = 0";
  if (i < 0 || i >= len)
    throw "i is out of range";
  return data[i];
}

template<class T>
inline std::ostream& operator<<(std::ostream& B, TVector<T>& p)
{
  if (p.GetTransp() == false)
  {
    for (int i = 0; i < p.GetLen(); i++)
      B << p[i] << "  ";
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
inline std::istream& operator>>(std::istream& B, TVector<T>& p)
{
  std::cout << "Print vector" << ", size = " << p.len << std::endl;
  for (int i = 0; i < p.len; i++)
    B >> p[i];
  return B;
}