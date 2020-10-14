#!/bin/bash

VAR1=`date | cut -d ',' -f 1`

echo $VAR1

if [ $VAR1=="sob" ]
then
  echo "Jest weekend! Pijemy!"
elif [ $VAR1=="ndz" ]
  echo "Jest weekend! Ale dzisiaj nie pijemy :/"
else
  echo "Jest zwykły dzień :/"
fi