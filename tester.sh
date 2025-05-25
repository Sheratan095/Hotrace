#!/bin/bash

#--echo
ECHO="echo"
#--outfile
OUT="test_result.txt"
#--exec
X0="./hotrace"
X1="./giacomo"
X2="./tbeauzam"

#--tests
DIR="tests/resources"
T1="$DIR/test01.htr"
T2="$DIR/test02.htr"
T3="$DIR/test03.htr"
T4="$DIR/test04.htr"
T5="$DIR/test05.htr"
T6="$DIR/test06.htr"
T7="$DIR/test07.htr"

$ECHO TESTER				> $OUT
$ECHO "---TEST 1---"		>> $OUT
$ECHO "Result for $X0"		>> $OUT
bash -c "time $X0 < $T1"	2>> $OUT
$ECHO "Result for $X1"		>> $OUT
bash -c "time $X1 < $T1"	2>> $OUT
$ECHO "Result for $X2"		>> $OUT
bash -c "time $X2 < $T1"	2>> $OUT
$ECHO next					>> $OUT
$ECHO "---TEST 2---"		>> $OUT
$ECHO "Result for $X0"		>> $OUT
bash -c "time $X0 < $T2"	2>> $OUT
$ECHO "Result for $X1"		>> $OUT
bash -c "time $X1 < $T2"	2>> $OUT
$ECHO "Result for $X2"		>> $OUT
bash -c "time $X2 < $T2"	2>> $OUT
$ECHO next					>> $OUT
$ECHO "---TEST 3---"		>> $OUT
$ECHO "Result for $X0"		>> $OUT
bash -c "time $X0 < $T3"	2>> $OUT
$ECHO "Result for $X1"		>> $OUT
bash -c "time $X1 < $T3"	2>> $OUT
$ECHO "Result for $X2"		>> $OUT
bash -c "time $X2 < $T3"	2>> $OUT
$ECHO next					>> $OUT
$ECHO "---TEST 4---"		>> $OUT
$ECHO "Result for $X0"		>> $OUT
bash -c "time $X0 < $T4"	2>> $OUT
$ECHO "Result for $X1"		>> $OUT
bash -c "time $X1 < $T4"	2>> $OUT
$ECHO "Result for $X2"		>> $OUT
bash -c "time $X2 < $T4"	2>> $OUT
$ECHO next					>> $OUT
$ECHO "---TEST 5---"		>> $OUT
$ECHO "Result for $X0"		>> $OUT
bash -c "time $X0 < $T5"	2>> $OUT
$ECHO "Result for $X1"		>> $OUT
bash -c "time $X1 < $T5"	2>> $OUT
$ECHO "Result for $X2"		>> $OUT
bash -c "time $X2 < $T5"	2>> $OUT
$ECHO next					>> $OUT
$ECHO "---TEST T6---"		>> $OUT
$ECHO "Result for $X0"		>> $OUT
bash -c "time $X0 < $T6"	2>> $OUT
$ECHO "Result for $X1"		>> $OUT
bash -c "time $X1 < $T6"	2>> $OUT
$ECHO "Result for $X2"		>> $OUT
bash -c "time $X2 < $T6"	2>> $OUT
$ECHO next					>> $OUT
$ECHO "---TEST T7---"		>> $OUT
$ECHO "Result for $X0"		>> $OUT
bash -c "time $X0 < $T7"	2>> $OUT
$ECHO "Result for $X1"		>> $OUT
bash -c "time $X1 < $T7"	2>> $OUT
$ECHO "Result for $X2"		>> $OUT
bash -c "time $X2 < $T7"	2>> $OUT