#!/bin/sh

for i in $(seq 0 400)
do 
    ./generator >input.txt
    sleep 0.01
    ./a.out <input.txt
done 
