#!/bin/bash

file="adresy.txt"
file2="tresc.txt"
file3="spec*.pdf"

while IFS= read -r line
do
  echo "$line"
  mail -a $file3 -s "Oferta" $line < $file2
done < "$file"