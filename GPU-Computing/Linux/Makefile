CXX=g++
NVCC=nvcc
APP=test
CFLAGS=-std=c++11 -c
CUDA_LIBS=-lcudart
CUDA_LIB_DIR=-L/opt/cuda/lib64
CUDA_INC_DIR=-I/opt/cuda/include


all: $(APP)

$(APP): main.o kernel.o
	$(CXX) $^ $(CUDA_LIB_DIR) $(CUDA_LIBS) -o $@ 

main.o: main.cpp
	$(CXX) -c $<

kernel.o: kernel.cu
	$(NVCC) $(CFLAGS) $(CUDA_INC_DIR) $<


clean:
	rm $(APP) *.o
