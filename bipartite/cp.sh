#!/bin/bash

g++ gen.cpp -o gen -std=c++11
g++ lg1129.cpp -std=c++11
g++ std.cpp -o std -std=c++11

while [[ true ]]; do
    ./gen
    ./a.out < a.in > res
    ./std < a.in > ans
    diff ans res > diflog
    if [[ $? -ne 0 ]]; then
        break;
    fi
    # t=$[t+1]
    # if [ $[t % 1] -eq 0 ]; then
    #     echo $t;
    # fi
done