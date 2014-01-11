// =====================================================================================
// 
//       Filename:  expression_evaluation.cpp
//
//    Description:  Dijkstra 的双栈表达式求值
//
//        Version:  1.0
//        Created:  2014年01月11日 16时39分21秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <stack>
#include <cstdlib>

const char *movetonext(const char *pstr)
{
	while (*pstr != '\0' && ((*pstr >= '0' && *pstr <= '9') || *pstr == '.')) {
		pstr++;
	}

	return pstr;
}

double hstrtof(const char *nptr)
{
	const char *pstr = movetonext(nptr);

	int size = pstr - nptr + 1;
	char *psz = new char[size];
	
	strncpy(psz, nptr, size-1);
	psz[size-1] = '\0';
	
	double result = atof(psz);
	delete []psz;

	return result;
}

double expression_evaluation(const char *nptr)
{
	std::stack<double> vals;
	std::stack<char> ops;

	const char *index = nptr; 
	while (*index != '\0') {
		if (*index == '(') {
			index++;
		} else if (*index == '+' || *index == '-' || *index == '*' || *index == '/') {
			ops.push(*index);
			index++;
		} else if (*index == ')') {
			char op = ops.top();
			ops.pop();
			double val = vals.top();
			vals.pop();
			switch (op) {
				case '+':
					val = vals.top() + val;
					vals.pop();
					break;
				case '-':
					val = vals.top() - val;
					vals.pop();
					break;
				case '*':
					val = vals.top() * val;
					vals.pop();
					break;
				case '/':
					val = vals.top() / val;
					vals.pop();
					break;
			}
			vals.push(val);
			index++;
		} else {
			vals.push(hstrtof(index));
			index = movetonext(index);
		}
	}

	return vals.top();
}

TEST(TEST_FLOAT_DOUBLE, ONLY_TEST)
{
	EXPECT_DOUBLE_EQ(expression_evaluation("(10.0+5.2)"), 15.2);
	EXPECT_DOUBLE_EQ(expression_evaluation("(3.14*(4*4))"), 50.24);
	EXPECT_DOUBLE_EQ(expression_evaluation("((5+1)*(3+6))"), 54);
	EXPECT_DOUBLE_EQ(expression_evaluation("((5/2)+(3*5))"), 17.5);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
}

