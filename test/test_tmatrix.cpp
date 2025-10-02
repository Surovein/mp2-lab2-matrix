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
	EXPECT_NE(nullptr, tmp1.pMem);

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

	TDynamicMatrix<int> tmp(3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tmp[i][j] = i * 10 + j;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			EXPECT_EQ (i * 10 + j, tmp[i][j]);
		}
	}
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> tmp(5);
	ASSERT_ANY_THROW(tmp[-5]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> tmp(5);
	ASSERT_ANY_THROW(tmp[100]);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> tmp(2);
	tmp[0][0] = 10;
	tmp[0][1] = 20;
	tmp[1][0] = 10;
	tmp[1][1] = 20;
	TDynamicMatrix<int> tmp1 = tmp;
	tmp1 = tmp1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			EXPECT_EQ(tmp[i][j], tmp1[i][j]);
		}
	}
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> tmp(2);
	tmp[0][0] = 10;
	tmp[0][1] = 20;
	tmp[1][0] = 10;
	tmp[1][1] = 20;
	TDynamicMatrix<int> tmp2(2);
	tmp = tmp2;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			EXPECT_EQ(tmp2[i][j], tmp[i][j]);
		}
	}
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)//???
{
	TDynamicMatrix<int> tmp(2);
	TDynamicMatrix<int> tmp2(4);
	tmp2 = tmp;
	EXPECT_EQ(2, tmp2.sz);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> tmp(2);
	TDynamicMatrix<int> tmp2(4);
	tmp = tmp2;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			EXPECT_EQ(tmp2[i][j], tmp[i][j]);
		}
	}
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> tmp(2);
	tmp[0][0] = 10;
	tmp[0][1] = 20;
	tmp[1][0] = 10;
	tmp[1][1] = 20;
	TDynamicMatrix<int> tmp2(2);
	tmp2[0][0] = 10;
	tmp2[0][1] = 20;
	tmp2[1][0] = 10;
	tmp2[1][1] = 20;
	EXPECT_EQ(true, tmp2 == tmp);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> tmp(2);
	tmp[0][0] = 10;
	tmp[0][1] = 20;
	tmp[1][0] = 10;
	tmp[1][1] = 20;
	EXPECT_EQ(true, tmp == tmp);

}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> tmp(2);
	TDynamicMatrix<int> tmp2(5);
	EXPECT_EQ(false, tmp2 == tmp);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> tmp(2);
	tmp[0][0] = 10;
	tmp[0][1] = 20;
	tmp[1][0] = 10;
	tmp[1][1] = 20;
	TDynamicMatrix<int> tmp2(2);
	tmp2[0][0] = 10;
	tmp2[0][1] = 20;
	tmp2[1][0] = 10;
	tmp2[1][1] = 20;
	TDynamicMatrix<int>tmp3 = tmp2 + tmp;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			EXPECT_EQ(tmp2[i][j]+tmp[i][j], tmp3[i][j]);
		}
	}
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> tmp(5);
	TDynamicMatrix<int> tmp2(2);
	ASSERT_ANY_THROW(tmp + tmp2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> tmp(2);
	tmp[0][0] = 10;
	tmp[0][1] = 20;
	tmp[1][0] = 10;
	tmp[1][1] = 20;
	TDynamicMatrix<int> tmp2(2);
	tmp2[0][0] = 10;
	tmp2[0][1] = 20;
	tmp2[1][0] = 10;
	tmp2[1][1] = 20;
	TDynamicMatrix<int>tmp3 = tmp2 - tmp;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			EXPECT_EQ(tmp2[i][j] - tmp[i][j], tmp3[i][j]);
		}
	}
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> tmp(5);
	TDynamicMatrix<int> tmp2(2);
	ASSERT_ANY_THROW(tmp - tmp2);
}

