#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Usage ./run.sh [name_of_source]"
    exit 1
fi

filename=$1
result="${filename:0:-2}"
gcc -o "./bin/$result.out" "$1"
shift
"./bin/$result.out" $@
