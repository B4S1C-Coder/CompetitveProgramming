#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Only onee argument."
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "Error: File '$1' not found"
    exit 1
fi

word_count=$(wc -w < "$1")
line_count=$(wc -l < "$1")

echo "File: $1"
echo "Total words: $word_count"
echo "Total lines: $line_count"
