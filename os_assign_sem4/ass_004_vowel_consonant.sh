#!/bin/bash

# Single input and one char only
if [ $# -ne 1 ] || [ ${#1} -ne 1 ]; then
    echo "Only single character allowed."
    exit 1
fi

# Convert to lower case
char=$(echo "$1" | tr '[:upper:]' '[:lower:]')

case $char in
    [aeiou])
        echo "'$1' is a vowel."
        ;;
    [a-z])
        echo "'$1' is a consonant."
        ;;
    *)
        echo "'$1' is not a letter."
        ;;
esac
