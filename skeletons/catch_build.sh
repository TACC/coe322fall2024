#!/bin/bash

rm -rf build
mkdir -p build
cd build
cmake -D PROJECT_NAME=require ../catch2
make
