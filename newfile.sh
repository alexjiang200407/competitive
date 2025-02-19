#!/bin/bash

for file in $@; do
    mkdir -p "$(dirname "$file")"
    cp lib/template.cpp "$file.cpp"
    touch "$file.in"
done