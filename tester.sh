#!/bin/bash

#--echo
ECHO="echo"
#--outfile
OUT="test_result.txt"
#--exec
X0="./hotrace"
X1="./Bombatomica64"
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
T = ("$T1" "$T2" "$T3" "$T4" "$T5" "$T6" "$T7")


TEST_DIR="$PWD/test_repos"

ROOT="$PWD"

PWD=$(pwd)

TESTED_REPOS=(
	"https://github.com/tbeauzam/Rush_42_Hotrace.git"
	"https://github.com/Bombatomica64/hotrace.git"
)

RESOURCES="../../tests/resources/"
for REPO in "${TESTED_REPOS[@]}"; do
	IFS='/'
	read -ra newarr <<< "$REPO"
	REPO_NAME="${newarr[3]%.git}"  # Remove .git from the end
	git clone "$REPO" "$TEST_DIR/$REPO_NAME"
	X+="$REPO_NAME"
	cd "$TEST_DIR/$REPO_NAME" || exit
	echo "Compiling $REPO_NAME..."
	make
	if [ $? -ne 0 ]; then
		echo "Compilation failed for $REPO_NAME"
		break
	fi
	mv hotrace "../../$REPO_NAME"
done

cd ../../

$ECHO "TESTER"				> $OUT
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