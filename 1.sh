#!/bin/bash

# a = date | cut -d ',' -f 1
STR= date | cut -d ',' -f 1 | grep "śro"

echo $VAR1
if [ "$VAR1" = "śro" ]; then
    echo "Jest zwykły dzień :/"
else
    echo "Jest weekend! Pijemy!"
fi