#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Specify a source file"
    exit 1
fi

filename="$1"
extension="${filename##*.}"

outDir="out"
mkdir -p "$outDir"

javaMain="Main"

case "$extension" in
    "java")
        javac "$filename" -d "$outDir"
        java -cp "$outDir" "${javaMain}"
        ;;
    "c")
        clang "$filename" -o "$outDir/a.out"
        "./$outDir/a.out"
        ;;
    "cc")
        clang++ -std=c++17 "$filename" -o "$outDir/a.out"
        "./$outDir/a.out"
        ;;
    *)
        echo "Unsupported file type"
        exit 1
        ;;
esac