#!/bin/bash


# while [ "$1" != "" ];
# do
#    case $1 in
#    -m ) shift
#         marg0=$1
#         ;;
#    -n ) shift
#         marg1=$1
#         ;;
#    -a ) shift
#         marg2=$1
#         ;;
#    *)                     
#         echo "bledny argument $1"
#         exit 1 # error
#         ;;
#     esac
#     shift
# done

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
    *)
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
# # echo `tar -czvf $4 $VAR `
