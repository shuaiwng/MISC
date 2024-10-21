CXX=cl
NVCC=nvcc
CUDA_LIB_DIR="C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.6\lib\x64"
CUDA_INC_DIR="C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.6\include"
MSVC_INC="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\include"
MSVC_LIB="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\lib\x64"
UCRT_INC="C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\ucrt"
UCRT_LIB="C:\Program Files (x86)\Windows Kits\10\Lib\10.0.26100.0"


kernel.exe: main.obj kernel.obj
	link kernel.obj main.obj $(CUDA_LIB_DIR)/cudart.lib $(MSVC_LIB)/libcpmt.lib $(MSVC_LIB)/libcmt.lib $(MSVC_LIB)/oldnames.lib $(UCRT_LIB)/um/x64/kernel32.Lib $(MSVC_LIB)/libvcruntime.lib $(UCRT_LIB)/ucrt/x64/libucrt.lib $(UCRT_LIB)/um/x64/uuid.lib

main.obj: main.cpp
	$(CXX) -c /EHsc -I$(UCRT_INC) -I$(MSVC_INC) main.cpp

kernel.obj: kernel.cu kernel.h
	$(NVCC) -c -I$(CUDA_INC_DIR) kernel.cu

clean:
	del *exe *.obj
