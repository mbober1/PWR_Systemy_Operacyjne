#!/bin/

trap "echo You cant kill me!" 1
trap "echo You cant kill me!" 2
trap "echo You cant kill me!" 3
trap "echo You cant kill me!" 4
trap "echo You cant kill me!" 5
trap "echo You cant kill me!" 6
trap "echo You cant kill me!" 7
trap "echo You cant kill me!" 8
trap "echo You cant kill me!" 9
trap "echo You cant kill me!" 10
trap "echo You cant kill me!" 11
trap "echo You cant kill me!" 12
trap "echo You cant kill me!" 13
trap "echo You cant kill me!" 14
trap "echo You cant kill me!" 15


while [ True ]
do
  dt=$(date '+%d/%m/%Y %H:%M:%S');
  echo "$dt"
  sleep 1
done