#!/bin/bash

function usage {
    echo "gen.sh [int|int3d]"
}

if [ "$#" != "1" ]; then
    usage
    exit 1
fi

if [ "$1" == "int" ]; then
    # Generate random ints.
    for i in {1..1000000}; do
	echo $RANDOM; 
    done
elif [ "$1" == "int3d" ]; then
    # Generate random 3 digit ints.
    for i in {1..1000000}; do
	echo $(( RANDOM % 1000 ))
    done
else
    usage
fi
