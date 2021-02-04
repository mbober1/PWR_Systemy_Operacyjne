#!/bin/bash

VAR1=`date | cut -d ',' -f 1`

if [ "$VAR1" = "sob" ] || [ "$VAR1" = "nie" ]
then
  echo "Jest weekend! Pijemy!"
else
  echo "Jest zwykły dzień :/"
fi