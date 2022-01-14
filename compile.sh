#!/usr/bin/env bash

for i in *.c
do
    echo "gcc -g -o0 -fno-stack-protector -no-pie $i -o ${i%.c}.out"
    gcc -g -o0 -fno-stack-protector -no-pie "$i" -o "${i%.c}.out"
done
