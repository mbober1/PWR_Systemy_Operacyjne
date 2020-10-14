#!/bin/bash


VAR1= date | cut -d ',' -f 1

echo $VAR1

if [ $VAR1=="śro" ]; then
    echo "Jest zwykły dzień :/"
else
    echo "Jest weekend! Pijemy!"
fi