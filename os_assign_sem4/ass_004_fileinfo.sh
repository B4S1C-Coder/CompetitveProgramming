#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Only one argument"
    exit 1
fi

if [ ! -e "$1" ]; then
    echo "'$1' does not exist"
    exit 1
fi

size=$(stat -f %z "$1" 2>/dev/null || stat -c %s "$1")
perms=$(ls -l "$1" | cut -d ' ' -f 1)
owner=$(ls -l "$1" | awk '{print $3}')
group=$(ls -l "$1" | awk '{print $4}')
modified=$(stat -f %Sm "$1" 2>/dev/null || stat -c %y "$1")
file_type=$(file -b "$1")

echo "File Information for: $1"
echo "Size: $size bytes"
echo "Permissions: $perms"
echo "Owner: $owner"
echo "Group: $group"
echo "Last Modified: $modified"
echo "File Type: $file_type"
