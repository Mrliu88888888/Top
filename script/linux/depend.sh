#!/bin/bash

function useage()
{
    echo
    echo "Useage: bash $0 <path to the binary> <path to copy the dependencies>"
    echo
    exit 1
}

[[ $# < 2 ]] && useage

[[ ! -e $1 ]] && echo "Not a vaild input $1" && exit 1
[[ -d $2 ]] || echo "No such directory $2 creating..."&& mkdir -p "$2"

echo "Collecting the shared library dependencies for $1..."
deps=$(ldd $1 | awk 'BEGIN{ORS=" "}$1\
~/^\//{print $1}$3~/^\//{print $3}'\
 | sed 's/,$/\n/')
echo "Copying the dependencies to $2"

for dep in $deps
do
    echo "Copying $dep to $2"
    cp "$dep" "$2"
done

echo "Done!"
