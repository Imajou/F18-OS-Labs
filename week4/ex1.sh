#!/bin/bash

LOOPS=$1

gcc ex1.c -o ex1
for ((i=1;i<=LOOPS;i++)); do
./ex1 $i
done

