﻿// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

//#include <iostream>
//#include "tmatrix.h"
//---------------------------------------------------------------------------
#include <gtest.h>
#include "tmatrix.h"
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    //TDynamicVector<int> v;
}
//
//void main()
//{
//	//TDynamicVector<int> v(5);
//	//TDynamicMatrix<int> a(5);
//  TDynamicMatrix<int> a(5), b(5), c(5);
//  int i, j;
//
//  setlocale(LC_ALL, "Russian");
//  cout << "Тестирование класс работы с матрицами"
//    << endl;
//  for (i = 0; i < 5; i++)
//    for (j = i; j < 5; j++ )
//    {
//      a[i][j] =  i * 10 + j;
//      b[i][j] = (i * 10 + j) * 100;
//    }
//  c = a + b;
//  cout << "Matrix a = " << endl << a << endl;
//  cout << "Matrix b = " << endl << b << endl;
//  cout << "Matrix c = a + b" << endl << c << endl;
//}
//---------------------------------------------------------------------------
