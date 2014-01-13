// =====================================================================================
// 
//       Filename:  main.cpp
//
//    Description:  排序算法的单元测试
//
//        Version:  1.0
//        Created:  2014年01月11日 21时40分36秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <iostream>
#include <gtest/gtest.h>

#include "Sort.hpp"

#define TEST_COUNTS 10000

TEST(TEST_SELECT_SORT, ONLY_TEST)
{
	int *array = new int[TEST_COUNTS];
	for (int i = 0; i < TEST_COUNTS; ++i) {
		array[i] = TEST_COUNTS - i;
	}
	Sort<int>::SelectSort(array, array+TEST_COUNTS);
	EXPECT_TRUE(Sort<int>::isSorted(array, array+TEST_COUNTS));
	delete []array;
}

TEST(TEST_INSERT_SORT, ONLY_TEST)
{
	int *array = new int[TEST_COUNTS];
	for (int i = 0; i < TEST_COUNTS; ++i) {
		array[i] = TEST_COUNTS - i;
	}
	Sort<int>::InsertSort(array, array+TEST_COUNTS);
	EXPECT_TRUE(Sort<int>::isSorted(array, array+TEST_COUNTS));
	delete []array;
}

TEST(TEST_INSERT_SORT_SECOND, ONLY_TEST)
{
	int *array = new int[TEST_COUNTS];
	for (int i = 0; i < TEST_COUNTS; ++i) {
		array[i] = TEST_COUNTS - i;
	}
	Sort<int>::InsertSortSecond(array, array+TEST_COUNTS);
	EXPECT_TRUE(Sort<int>::isSorted(array, array+TEST_COUNTS));
	delete []array;
}

TEST(TEST_INSERT_SORT_THRID, ONLY_TEST)
{
	int *array = new int[TEST_COUNTS];
	for (int i = 0; i < TEST_COUNTS; ++i) {
		array[i] = TEST_COUNTS - i;
	}
	Sort<int>::InsertSortThrid(array, array+TEST_COUNTS);
	EXPECT_TRUE(Sort<int>::isSorted(array, array+TEST_COUNTS));
	delete []array;
}

TEST(TEST_BUBBLE_SORT, ONLY_TEST)
{
	int *array = new int[TEST_COUNTS];
	for (int i = 0; i < TEST_COUNTS; ++i) {
		array[i] = TEST_COUNTS - i;
	}
	Sort<int>::BubbleSort(array, array+TEST_COUNTS);
	EXPECT_TRUE(Sort<int>::isSorted(array, array+TEST_COUNTS));
	delete []array;
}

TEST(TEST_SHELL_SORT, ONLY_TEST)
{
	int *array = new int[TEST_COUNTS];
	for (int i = 0; i < TEST_COUNTS; ++i) {
		array[i] = TEST_COUNTS - i;
	}
	Sort<int>::ShellSort(array, array+TEST_COUNTS);
	EXPECT_TRUE(Sort<int>::isSorted(array, array+TEST_COUNTS));
	delete []array;
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

