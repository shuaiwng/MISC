#include "kernel.h"
#include <stdlib.h>
#include <chrono>
#include <iostream>

#define N 4096000000

using namespace std;
using namespace std::chrono;

float distance_main(float x1, float x2)
{
    return sqrt((x2-x1)*(x2-x1));
}

float scale(uint32_t i, uint32_t n)
{
    return (float(i)) / (n-1);
}

int main()
{
    float *in = (float*)calloc(N, sizeof(float));
    float *out = (float*)calloc(N, sizeof(float));
    const float ref = 0.5f;

    for (uint32_t i = 0; i < N; ++i)
    {
        in[i] = scale(i, N);
    }

    auto beg_t_cuda = steady_clock::now();
    distanceArray(out, in, ref, N);
    auto end_t_cuda = steady_clock::now();
    cout << "Elapsed Time [CUDA]: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_t_cuda-beg_t_cuda).count()
        << " [ms]" << endl;

    auto beg_t_cpu = steady_clock::now();
    for (uint32_t i = 0; i < N; ++i)
    {
        float res = distance_main(in[i], ref);
    }
    auto end_t_cpu = steady_clock::now();
    cout << "Elapsed Time [CPU]: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_t_cpu-beg_t_cpu).count()
        << " [ms]" << endl;

    free(in);
    free(out);    

    return 0;
}