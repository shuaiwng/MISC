set NVCC_PATH=C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.6\bin
set MSVC_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\Hostx64\x64
set PATH=%PATH%;%NVCC_PATH%
set PATH=%PATH%;%MSVC_PATH%

nmake
