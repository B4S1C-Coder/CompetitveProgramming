#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Two strings must be specified."
    exit 1
fi

str1="$1"
str2="$2"

if [ "$str1" = "$str2" ]; then
    echo "Both strings are equal."
else
    echo "Strings are not equal."

    if [ ${#str1} -gt ${#str2} ]; then
        echo "First string i.e. '$str1' is longer."
    elif [ ${#str1} -lt ${#str2} ]; then
        echo "Second string i.e. '$str2' is longer."
    fi
fi
