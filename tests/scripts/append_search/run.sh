#!/bin/bash
#Run this from here

# Number of times to run the script
N=10000

# Path to your append script
APPEND_SCRIPT="./append_one.sh"

# Counter
i=0

while [ $i -lt $N ]; do
    echo "Run $((i + 1))/$N"
    bash "$APPEND_SCRIPT"
    ((i++))
done

echo "Done running $APPEND_SCRIPT $N times."
