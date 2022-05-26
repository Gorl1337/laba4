#pragma once
#include "Vector.h"

template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
  TMatrix();
  TMatrix(int l);
  TMatrix(int w, int l);
  TMatrix(const TMatrix<T>& p);
  ~TMatrix();

  TMatrix<T> operator + (const TMatrix<T>& p);
  TMatrix<T> operator - (const TMatrix<T>& p);
  TMatrix<T> operator * (const TMatrix<T>& p);
  TVector<T> operator * (TVector<T>& p);
  TMatrix<T>& operator = (const TMatrix<T>& p);
  bool operator == (const TMatrix<T>& p);
  TVector<T>& operator [] (const int i);

  int GetWidth();
  void SetWidth(int w);
  void Resize(int w, int l);

  template <class T>
  friend std::ostream& operator << (std::ostream& B, TMatrix<T>& A);
  template <class T>
  friend std::istream& operator >> (std::istream& B, TMatrix<T>& A);

protected:
  int width;
};

template<class T>
inline TMatrix<T>::TMatrix()
{
  width = 0;
  this->data = nullptr;
}

template<class T>
inline TMatrix<T>::TMatrix(int l) : TMatrix()
{
  if (l < 0) throw "Error";
  this->len = l;
  width = l;
  this->data = new TVector<T>[width];
  for (int i = 0; i < len; i++)
    this->data[i].Resize(len);
}

template<class T>
inline TMatrix<T>::TMatrix(int w, int l) : TMatrix()
{
  if (l < 0 || w < 0) 
    throw "len < 0 or width < 0";
  this->len = l;
  width = w;
  this->data = new TVector<T>[width];
  for (int i = 0; i < width; i++)
    this->data[i].Resize(len);
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& p)
{
  this->len = p.len;
  width = p.width;
  if (p.data == nullptr) 
    this->data = nullptr;
  else
  {
    this->data = new TVector<T>[width];
    for (int i = 0; i < width; i++)
      this->data[i] = p.data[i];
  }
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
  if (this->data != nullptr)
  {
    delete[] this->data;
    this->data = nullptr;
  }
  width = 0;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& p)
{
  if (this->len != p.len || width != p.width) 
    throw "len or width aren't the same";
  TMatrix<T> res(*this);
  for (int i = 0; i < width; i++)
    res.data[i] = this->data[i] + p.data[i];
  return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& p)
{
  if (this->len != p.len || width != p.width) 
    throw "len or width aren't the same";
  TMatrix<T> res(width, this->len);
  for (int i = 0; i < width; i++)
    res.data[i] = this->data[i] - p.data[i];
  return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& p)
{
  if (width != p.len) 
    throw "1st matrix width != 2nd matrix len";
  TMatrix<T> res(width, p.len);
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < p.len; j++)
    {
      res[i][j] = 0;
      for (int k = 0; k < len; k++)
      {
        res[i][j] += this->data[i][k] * p.data[k][j];
      }
    }
  }
  return res;
}

template<class T>
inline TVector<T> TMatrix<T>::operator*(TVector<T>& p)
{
  if (width != p.GetLen())
    throw "matrix width != vector len";
  if (p.GetTransp() == false)
    throw "vector isn't transposed";
  TVector<T> res(width, 0);
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < this->len; j++)
    {
      res[i] += (this->data)[i][j] * p[j];
    }
  }
  res.SetTransp(true);
  return res;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& p)
{
  if (this == &p) 
    return *this;
  this->len = p.len;
  width = p.width;
  if (this->data != nullptr) 
    delete[] data;
  if (p.data == nullptr) 
    data = nullptr;
  else 
    data = new TVector<T>[p.width];
  for (int i = 0; i < p.width; i++)
    this->data[i] = p.data[i];
  return *this;
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T>& p)
{
  if (this->len != p.len || width != p.width) 
    return false;
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < this->len; j++)
      if (this->data[i][j] != this->p.data[i][j]) return false;
  }
  return true;
}

template<class T>
inline TVector<T>& TMatrix<T>::operator[](const int i)
{
  if (i < 0 || i >= width) 
    throw "i is out of range";
  return this->data[i];
}

template<class T>
inline int TMatrix<T>::GetWidth()
{
  return width;
}

template<class T>
inline void TMatrix<T>::SetWidth(int w)
{
  this->Resize(this->len, w);
}

template<class T>
inline void TMatrix<T>::Resize(int w, int l)
{
  TVector<T>* res = new TVector<T>[w];
  if (this->data != nullptr)
  {
    int w1, l1;
    if (width > w) 
      w1 = w;
    else 
      w1 = width;
    if (this->len > l) 
      l1 = l;
    else 
      l1 = this->len;
    for (int i = 0; i < w1; i++)
    {
      res[i].Resize(l);
      for (int j = 0; j < l1; j++)
        res[i][j] = this->data[i][j];
    }
    delete[] data;
  }
  this->data = res;
  this->len = l;
  width = w;
}


template<class T>
inline std::ostream& operator<<(std::ostream& B, TMatrix<T>& p)
{
  for (int i = 0; i < p.width; i++)
  {
    for (int j = 0; j < p.len; j++)
    {
      B << p[i][j] << "  ";
    }
    B << std::endl;
  }
  return B;
}

template<class T>
inline std::istream& operator>>(std::istream& B, TMatrix<T>& p)
{
  std::cout << "Print matrix, size = " << p.GetLen() << ", width = " << p.GetWidth() << std::endl;
  for (int i = 0; i < p.width; i++)
  {
    for (int j = 0; j < p.len; j++)
    {
      B >> p.data[i][j];
    }
  }
  return B;
}