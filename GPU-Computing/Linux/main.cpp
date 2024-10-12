// main.cpp
#include <iostream>
#include <chrono>
#include "kernel.h"

using namespace std;
using namespace std::chrono;

int main() {
    const int n = 600000;
    float h_A[n] = {1};
    float h_B[n] = {2};
    float h_C[n];

    // GPU
    cuda_vec_add(h_A, h_B, h_C, n);
    cout << "h_C[0] = " << h_C[0] << endl;

    // CPU
    auto beg_cpu = steady_clock::now();
    for (int i = 0; i < n; i++){
        h_C[i] = h_A[i] + h_B[i];
    }
    auto end_cpu = steady_clock::now();

    cout << "Elapsed Time [CPU]: " << std::chrono::duration_cast<std::chrono::microseconds>(end_cpu-beg_cpu).count()
        << " [us]" << endl;

    return 0;
}