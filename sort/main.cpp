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

#define TEST_COUNTS 100000

TEST(TEST_SELECT_SORT, ONLY_TEST)
{
	int array[] = {5, 6, 2, 1, 0, 7, 9, 3, 4, 8};
	
	for (int i = 0; i < TEST_COUNTS; ++i) {
		Sort<int>::SelectSort(array, array+(sizeof(array)/sizeof(int)));
	}

	EXPECT_TRUE(Sort<int>::isSorted(array, array+(sizeof(array)/sizeof(int))));
}

TEST(TEST_INSERT_SORT, ONLY_TEST)
{
	int array[] = {5, 6, 2, 1, 0, 7, 9, 3, 4, 8};

	for (int i = 0; i < TEST_COUNTS; ++i) {
		Sort<int>::InsertSort(array, array+(sizeof(array)/sizeof(int)));
	}

	EXPECT_TRUE(Sort<int>::isSorted(array, array+(sizeof(array)/sizeof(int))));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

