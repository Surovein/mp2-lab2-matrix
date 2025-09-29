// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <assert.h>
using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector()
  {
    sz = 0;
    pMem = nullptr;
  }
  TDynamicVector(size_t size) : sz(size)
  {
    if (sz <= 0)
      throw out_of_range("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE)
    {
        throw 2;
    }
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
      if (sz > MAX_VECTOR_SIZE)
      {
          throw 2;
      }
      if (sz <= 0)
      {
          throw 1;
      }
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      sz = v.sz;
      pMem = new T[sz];
      //if (pMem == nullptr)
      //{
      //    throw 2;
      //}
      for (int i = 0; i < sz; i++)
      {
          pMem[i] = v.pMem[i];
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector()
  {
      if (pMem != nullptr)
      {
          delete[] pMem;
      }

  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
      {
          return *this;
      }
      TDynamicVector tmp(v);
      swap(*this, tmp);
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      if (ind<0 || ind>=sz)
      {
          throw 2;
      }
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind < 0 || ind >= sz)
      {
          throw 2;
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind < 0 || ind >= sz)
      {
          throw 2;
      }
      return pMem[ind];
  }
  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
      {
          return false;
      }
      for (int i = 0; i < sz; i++)
      {
          if (pMem[i] != v.pMem[i])
          {
              return false;
          }
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector tmp(*this);
      for (int i = 0; i < tmp.sz; i++)
      {
          tmp.pMem[i] += val;
      }
      return tmp;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector tmp(*this);
      for (int i = 0; i < tmp.sz; i++)
      {
          tmp.pMem[i] -= val;
      }
      return tmp;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector tmp(*this);
      for (int i = 0; i < tmp.sz; i++)
      {
          tmp.pMem[i] *= val;
      }
      return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
      {
          throw 1;
      }
      TDynamicVector tmp(*this);

      for (int i = 0; i < tmp.sz; i++)
      {
          tmp.pMem[i] += v.pMem[i];
      }
      return tmp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
      {
          throw 1;
      }
      TDynamicVector tmp(*this);
      for (int i = 0; i < tmp.sz; i++)
      {
          tmp.pMem[i] -= v.pMem[i];
      }
      return tmp;
  }
  T operator*(const TDynamicVector& v) //noexcept(noexcept(T()))
  {
      if (sz != v.sz)
      {
          throw 1;
      }
      T sum = 0;
      for (int i = 0; i < sz; i++)
      {
          T tmp = pMem[i] * v.pMem[i]
          sum += tmp;
      }
      return sum;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz > MAX_MATRIX_SIZE)
      {
          throw 2;
      }
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // индексация
  TDynamicVector<T>& operator[](size_t ind)
  {
      if (ind < 0 || ind >= sz)
      {
          throw 2;
      }
      return pMem[ind];
  }
  const TDynamicVector<T>& operator[](size_t ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  TDynamicVector<T>& at(size_t ind)
  {
      if (ind < 0 || ind >= sz)
      {
          throw 2;
      }
      return pMem[ind];
  }
  const TDynamicVector<T>& at(size_t ind) const
  {
      if (ind < 0 || ind >= sz)
      {
          throw 2;
      }
      return pMem[ind];
  }
  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (sz != m.sz)
      {
          return false;
      }
      for (int i = 0; i < sz; i++)
      {
          if (pMem[i] != m.pMem[i])
          {
              return false;
          }

      }
      return true;
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix tmp(*this);
      for (int i = 0; i < tmp.sz; i++)
      {
          tmp.pMem[i] = tmp.pMem[i] * val;
      }
      return tmp
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)// имеется ввиду реализация умножения именно матрицы на вектор или Pmem на v.Pmem?
  {
      if (sz != v.sz)
      {
          throw 1;
      }
      TDynamicVector<T> tmp(v.sz);
      for (int i = 0; i < sz; i++)
      {
          tmp.pMem[i] = 0;
          for (int j = 0; j < sz; j++)
          {
              tmp.pMem[i] = tmp.pMem[i] + pMem[j][i] * v.pMem[j];
          }
      }
      return tmp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
      {
          throw 1;
      }
      TDynamicMatrix tmp(*this);
      for (int i = 0; i < tmp.sz; i++)
      {
          tmp.pMem[i] = tmp.pMem[i] + m.pMem[i];
      }
      return tmp;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
      {
          throw 1;
      }
      TDynamicVector<T> tmp(v.sz);
      for (int i = 0; i < tmp.sz; i++)
      {
          tmp.pMem[i] -= m.pMem[i];
      }
      return tmp;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
      {
          throw 1;
      }
      TDynamicMatrix<T> tmp(v.sz);
      for (int i = 0; i < sz; i++)
      {
          tmp.pMem[i] = 0;
          for (int j = 0; j < sz; j++)
          {
              tmp.pMem[j][i] = tmp.pMem[j][i] + pMem[j][i] * m.pMem[i][j];
          }
      }
      return tmp;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          istr >> v.pMem[i];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          ostr << v.pMem[i];
      return ostr;
  }
};

#endif
