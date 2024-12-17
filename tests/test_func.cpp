#include "../src/func.h"
#include <cassert>
#include <iostream>

int main() {
    Func myFunc;
    double x = 0.5;
    int n = 3;
    
    // Перевірка результату для конкретного значення
    double result = myFunc.FuncA(n, x);
    std::cout << "Result of FuncA with n = " << n << " and x = " << x << " is: " << result << std::endl;

    assert(result > 0.479 && result < 0.48);

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
