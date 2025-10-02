#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)// start
{

  int Mas[10] = {1,2,3,4,5,6,7,8,9,10};
  TDynamicVector<int> tmp(Mas, 10);
  ASSERT_NO_THROW(TDynamicVector<int> v(tmp));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	TDynamicVector<int> v(tmp);
	EXPECT_EQ(v, tmp);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	ASSERT_NO_THROW(TDynamicVector<int> v(tmp));//???
	//EXPECT_EQ(v.size(), tmp.size());
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v[-3]);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v[6]);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	ASSERT_NO_THROW(tmp = tmp);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	TDynamicVector<int> v(10);
	ASSERT_NO_THROW(v = tmp);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	TDynamicVector<int> v(5);
	v = tmp;
	EXPECT_EQ(v.size(), tmp.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	TDynamicVector<int> v(5);
	ASSERT_NO_THROW(v = tmp);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	TDynamicVector<int> v(tmp);
	EXPECT_EQ(true, v==tmp);
}


TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	EXPECT_EQ(true, tmp == tmp);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	//int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp( 10);
	TDynamicVector<int> v(5);
	EXPECT_EQ(false, v == tmp);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	//ASSERT_NO_THROW(tmp+5);
	tmp = tmp + 5;
	for (int i = 1; i <= 10; i++)
	{
		EXPECT_EQ(i + 5, tmp[i-1]);
	}
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	tmp = tmp - 5;
	for (int i = 1; i <= 10; i++)
	{
		EXPECT_EQ(i - 5, tmp[i - 1]);
	}
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	tmp = tmp * 5;
	for (int i = 1; i <= 10; i++)
	{
		EXPECT_EQ(i * 5, tmp[i - 1]);
	}
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	int Mas2[10] = { 10,20,30,40,50,60,70,80,90,100 };
	TDynamicVector<int> tmp2(Mas2, 10);
	TDynamicVector<int> tmp3 = tmp + tmp2;
	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(tmp[i] + tmp2[i], tmp3[i]);
	}
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	int Mas2[10] = { 10,20,30,40,50 };
	TDynamicVector<int> tmp2(Mas2, 5);
	ASSERT_ANY_THROW(tmp + tmp2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	int Mas2[10] = { 10,20,30,40,50,60,70,80,90,100 };
	TDynamicVector<int> tmp2(Mas2, 10);
	TDynamicVector<int> tmp3 = tmp - tmp2;
	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(tmp[i] - tmp2[i], tmp3[i]);
	}
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	int Mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
	TDynamicVector<int> tmp(Mas, 10);
	int Mas2[10] = { 10,20,30,40,50 };
	TDynamicVector<int> tmp2(Mas2, 5);
	ASSERT_ANY_THROW(tmp - tmp2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	int Mas[10] = { 1,2,3,4,5};
	TDynamicVector<int> tmp(Mas, 5);
	int Mas2[10] = { 10,20,30,40,50 };
	TDynamicVector<int> tmp2(Mas2, 5);
	EXPECT_EQ(550, tmp * tmp2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> tmp(10);
	TDynamicVector<int> tmp2(5);
	ASSERT_ANY_THROW(tmp * tmp2);
}

