// =====================================================================================
// 
//       Filename:  timer.h
//
//    Description:  计时函数的实现
//
//        Version:  1.0
//        Created:  2014年01月11日 22时00分04秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <ctime>

class timer
{
 public:
         timer() 
	 {
		 _start_time = std::clock();
	 }

	 void restart()
	 {
		 _start_time = std::clock();
	 }

	 double elapsed() const
	 {
		 return double(std::clock() - _start_time) / CLOCKS_PER_SEC;
	 }

 private:
	 std::clock_t _start_time;
};

