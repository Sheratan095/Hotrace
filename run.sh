#!/bin/bash
# Run this from root of folder

TEST_FILES=(
	"test01.htr"
	"test02.htr"
	"test03.htr"
	"test04.htr"
	"test05.htr"
	"test06.htr"
	"test07.htr"
)

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
	cd "$TEST_DIR/$REPO_NAME" || exit
	echo "Compiling $REPO_NAME..."
	make
	if [ $? -ne 0 ]; then
		echo "Compilation failed for $REPO_NAME"
		break
	fi
	for x in {0..6}; do
		TEST_FILE="${TEST_FILES[$x]}"
		time "./hotrace < $RESOURCES$TEST_FILE"
	done
done

#bash -c "cd '$TBEAUZAM' && make && mv hotrace '$ROOT/tbeauzam' && make fclean"
