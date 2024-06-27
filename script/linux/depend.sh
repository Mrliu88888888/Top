#!/bin/bash

DEBUG=false

while getopts ":d" opt; do
    case ${opt} in
        d )
            DEBUG=true
            ;;
        \? )
            echo "Invalid option: -$OPTARG" 1>&2
            ;;
    esac
done
shift $((OPTIND -1))

function useage()
{
    echo
    echo "Useage: bash $0 [-d] <path to the binary> <path to copy the dependencies>"
    echo "  -d    Enable debug mode"
    echo
    exit 1
}

[[ $# < 2 ]] && useage

[[ ! -e $1 ]] && echo "Not a valid input $1" && exit 1
[[ -d $2 ]] || echo "No such directory $2 creating..." && mkdir -p "$2"

debug_echo() {
    if [ "$DEBUG" = true ]; then
        echo "$@"
    fi
}

debug_echo "Collecting the shared library dependencies for $1..."
deps=$(ldd $1 | awk 'BEGIN{ORS=" "}$1~/^\//{print $1}$3~/^\//{print $3}' | sed 's/,$/\n/')
debug_echo "Copying the dependencies to $2"

for dep in $deps
do
    debug_echo "Copying $dep to $2"
    cp "$dep" "$2"
done

debug_echo "Done!"
