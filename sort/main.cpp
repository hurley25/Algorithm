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

TEST(TEST_BOOL, ONLY_TEST)
{
	int array_1[] = {5, 6, 2, 1, 0, 7, 9, 3, 4, 8};
	int array_2[] = {5, 6, 2, 1, 0, 7, 9, 3, 4, 8};

	Sort<int>::SelectSort(array_1, array_1+(sizeof(array_1)/sizeof(int)));
	Sort<int>::InsertSort(array_2, array_2+(sizeof(array_2)/sizeof(int)));

	EXPECT_TRUE(Sort<int>::isSorted(array_1, array_1+(sizeof(array_1)/sizeof(int))));
	EXPECT_TRUE(Sort<int>::isSorted(array_2, array_2+(sizeof(array_2)/sizeof(int))));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

