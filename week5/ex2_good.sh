#!/bin/bash

ln ex2.txt ex2.txt.lock

num=$(tail -n 1 ex2.txt)
num=($num+1)

echo $num >> ex2.txt

ln ex2.txt.lock ex2.txt
