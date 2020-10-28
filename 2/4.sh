#!/bin/bash

while getopts ":m:n:a:" OPTION; do
    case $OPTION in
    m)
        marg0=$OPTARG
        ;;
    n)
        marg1=$OPTARG
        ;;
    a)
        marg2=$OPTARG
        ;;
    \?)
        echo "bledny argument $OPTARG"
        exit 1
        ;;
    esac
done

if [ -z "$marg0" ]
then
      echo "Podaj Maske: ";
      read;
      marg0=${REPLY}
fi

if [ -z "$marg1" ]
then
      echo "Podaj ilosc dni: ";
      read;
      marg1=${REPLY}
fi

if [ -z "$marg2" ]
then
      echo "Podaj nazwe archiwum: ";
      read;
      marg2=${REPLY}
fi

echo 'Maska = ' $marg0
echo 'Dni = ' $marg1
echo 'Archiwum = ' $marg2

echo "find -mtime -$marg1 -iname "$marg0""
VAR=`find -mtime -$marg1 -iname "$marg0"`
echo $VAR
echo `tar -czvf $marg2 $VAR `


# Jeśli dany parametr nie wystąpił,
# a istnieje zmienna środowiskowa zadająca wartość
# danego parametru (wymyśl dobre nazwy dla tych zmiennych),
# to będzie użyta wartość tej zmiennej.

# Nie wiem o co z tym chodzi /\
# strasznie enigmatycznie napisane
# zrobilem tak jak uważam za stosowne