#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>
#include <httplib.h>  // HTTP server library
#include "func.h"

Func myFunc;

void handle_get(const httplib::Request &req, httplib::Response &res) {
    int n = 100000; // Кількість елементів
    double x = 0.5; // Значення для обчислення

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<double> results;
    for (int i = 0; i < n; ++i) {
        results.push_back(myFunc.FuncA(3, x));
    }

    std::sort(results.begin(), results.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    res.set_content("Elapsed time: " + std::to_string(elapsed.count()) + " seconds", "text/plain");
}

int main() {
    httplib::Server svr;
    svr.Get("/", handle_get);

    std::cout << "Server started at http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);
}
