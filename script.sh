#!/bin/bash

if [ "$1" == "clear" ]; then
    rm -f quad*
elif [ "$3" != "" ]; then
    for name in prog integrate
    do
        make -f subMakefile $name project=$name
        make -f subMakefile clean project=$name
        ./$name $1 $2 $3
    done
else
    echo "You have to write three parameters."
    echo "n means gaussian quadrature rank"
    echo "a is the 'left' = lower bound"
    echo "b is the 'right' = upper bound"
    echo "Please enter n, a, b. Try to ./script.sh 30 0.0 1.0"
fi
