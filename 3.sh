#!/bin/bash

VAR=`find $1 -mtime $2 -iname "$3"`
# echo $VAR
echo `tar -czvf $4 $VAR `