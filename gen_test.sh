#!/bin/bash
size=20
i=0
while [ $i -lt $size ];
do
    echo "key"$i
    echo "val"$i
    i=$((i + 1))
done
echo " "
i=0
while [ $i -lt $size ];
do
    echo "key"$i
    i=$((i + 1))
done