#!/bin/bash

# File to modify
FILE="../../resources/test03.htr"

# Read even-numbered lines (starting from 0) into an array
mapfile -t even_lines < <(awk 'NR % 2 == 1' "$FILE")

# Check if there are even lines
if [ "${#even_lines[@]}" -eq 0 ]; then
    echo "No even-indexed lines found."
    exit 1
fi

# Pick a random string from the even lines
random_string="${even_lines[RANDOM % ${#even_lines[@]}]}"

# Append the random string to the end of the file
echo "$random_string" >> "$FILE"

echo "Appended random string: $random_string"
