// =====================================================================================
// 
//       Filename:  Sort.hpp
//
//    Description:  常见排序函数的实现
//
//        Version:  1.0
//        Created:  2014年01月11日 21时14分42秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

template <typename T>
class Sort
{
private:
	static void exch(T *elem1, T *elem2)
	{
		T tmp;
		tmp = *elem1;
		*elem1 = *elem2;
		*elem2 = tmp;
	}
public:
	static bool isSorted(T *begin, T *end)
	{
		for (T *index = begin+1; index != end; ++index) {
			if (*index < *(index-1) ) {
				return false;
			}
		}
		return true;
	}

	static void SelectSort(T *begin, T *end)
	{
		for (T *i = begin; i != end; ++i) {
			T *min = i;
			for (T *j = i+1; j != end; ++j) {
				if (*j < *min) {
					min = j;
				}
			}
			exch(i, min);
		}
	}

	static void InsertSort(T *begin, T *end)
	{
		for (T *i = begin+1; i != end; ++i) {
			for (T *j = i; j > begin && *j < *(j-1); --j) {
				exch(j, j-1);
			}
		}
	}

	static void ShellSort(T *begin, T *end)
	{
		int size = end - begin;
		int h = 1;

		while (h < size/3) {
			h = h * 3 + 1; 	// 1, 4, 13, 40, 121, 364, 1093...
		}
		while (h >= 1) {
			for (T *i = begin+h; i != end; ++i) {
				for (T *j = i; j >= begin+h && *j < *(j-h); j-=h) {
					exch(j, j-h);
				}
			}
			h /= 3;
		}
	}
};

