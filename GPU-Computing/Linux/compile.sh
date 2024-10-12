#!/bin/sh

export CUDA_HOME=/opt/cuda
export PATH=$PATH:$CUDA_HOME/bin

make
