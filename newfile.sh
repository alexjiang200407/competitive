#!/bin/bash

for file in $@; do
    cp lib/template.cpp "$file.cpp"
    touch "$file.in"
done