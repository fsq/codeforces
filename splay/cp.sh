#!/bin/bash
t=1
g++ gen.cpp -o gen -std=c++11
g++ 19Dsplay.cpp -std=c++11
while [[ $t -le 1000 ]]; do
    ./gen
    # echo "std done"
    ./a.out < a.in > res
    # echo "my done"
    diff std.out res > diflog
    if [[ $? -ne 0 ]]; then
        break;
    fi
    t=$[t+1]
    if [ $[t % 1] -eq 0 ]; then
        echo $t;
    fi
done