#include "func.h"
#include <cmath>

double Func::FuncA(int n, double x) {
	double sum = 0.0;
	for (int i = 0; i < 3; ++i) {  // Фіксована кількість 3 елементи
		sum += (pow(x, 2 * i + 1) / (2 * i + 1));
    }
	return sum;
}
