// =====================================================================================
// 
//       Filename:  binary_search.cpp
//
//    Description:  二分查找
//
//        Version:  1.0
//        Created:  2014年01月11日 15时36分02秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <iostream>
#include <gtest/gtest.h>

template <typename T>
int binary_search(T *elems, int size, T key)
{
	int first = 0;
	int end = size - 1;

	while (first <= end) {
		// 避免溢出，也可以用 (first & end) + ((first ^ end) >> 1)
		int mid = first + ((end - first) >> 1);
		if (key < elems[mid]) {
			end = mid - 1;
		} else if (key > elems[mid]) {
			first = mid + 1;
		} else {
			return mid;
		}
	}

	return -1;
}

// Unit Test

#define ARRAY_SIZE 1000

TEST(TEST_INT, ONLY_TEST)
{
	int array[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		array[i] = i + 1;
	}

	for (int i = 1; i < ARRAY_SIZE + 1; ++i) {
		int index =  binary_search(array, sizeof(array)/sizeof(int), i);
		EXPECT_EQ(index + 1, i);
	}

	for (int i = ARRAY_SIZE + 1; i < ARRAY_SIZE + 100; ++i) {
		int index =  binary_search(array, sizeof(array)/sizeof(int), i);
		EXPECT_EQ(index, -1);
	}
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

