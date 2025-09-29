#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)//start
{
	TDynamicMatrix <TDynamicVector<int>> tmp (10);
	TDynamicMatrix <TDynamicVector<int>> tmp1(tmp);
	EXPECT_EQ(tmp1, tmp);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix <TDynamicVector<int>> tmp(10);
	TDynamicMatrix <TDynamicVector<int>> tmp1(tmp);
	ASSERT_NO_THROW(TDynamicMatrix <TDynamicVector<int>> tmp1(tmp));
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix <TDynamicVector<int>> tmp(10);
	ASSERT_NO_THROW ( 10, tmp.size());/// должно работать без 10
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	int A[3] = { 1,2,3 };
	int B[3] = { 10,20,30 };
	int C[3] = { 100,200,300 };
	TDynamicVector<int> tmp1 (A, 3);
	TDynamicVector<int> tmp2 (B, 3);
	TDynamicVector<int> tmp3 (C, 3);
	TDynamicVector<int> Mas[3] = {tmp1,tmp2,tmp3};
	TDynamicMatrix<int> tmp(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tmp[i][j] = Mas[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			EXPECT_EQ(tmp.at(i).at(j), Mas[i][j]);
		}
	}
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  ADD_FAILURE();
}

