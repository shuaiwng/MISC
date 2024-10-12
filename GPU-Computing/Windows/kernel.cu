// kernel.cu
#include "kernel.h"
#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

__global__ void vec_add_kernel(float *a, float *b, float *c, int n) {
    int i = threadIdx.x + blockDim.x * blockIdx.x;
    if (i < n) c[i] = a[i] + b[i];
}

int cuda_vec_add(float *h_a, float *h_b, float *h_c, int n) {
    float *d_a, *d_b, *d_c;

    cudaMalloc(&d_a, n*sizeof(float));
    cudaMalloc(&d_b, n*sizeof(float));
    cudaMalloc(&d_c, n*sizeof(float));

    cudaMemcpy(d_a, h_a, n*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, n*sizeof(float), cudaMemcpyHostToDevice);

    auto beg_cuda = steady_clock::now();
    vec_add_kernel<<<1,1>>>(d_a, d_b, d_c, n);
    auto end_cuda = steady_clock::now();

    cout << "Elapsed Time [CUDA]: " << std::chrono::duration_cast<std::chrono::microseconds>(end_cuda-beg_cuda).count()
        << " [us]" << endl;

    cudaMemcpy(h_c, d_c, n*sizeof(float), cudaMemcpyDeviceToHost);

    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);

    return 0;
}