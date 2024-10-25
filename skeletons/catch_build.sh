#!/bin/bash

rm -rf build
mkdir build
cd build
cmake -D PROJECT_NAME=require ../catch2
make
