#!/bin/bash
# Run this from root of folder

ROOT="../.."
TBEAUZAM="tests/tbeauzam_Hotrace/"
GIACOMO="tests/giacomoguiulfo_Hotrace/"

bash -c "cd '$TBEAUZAM' && make && mv hotrace '$ROOT/tbeauzam' && make fclean"
bash -c "cd '$GIACOMO' && make && mv hotrace '$ROOT/giacomo' && make fclean"