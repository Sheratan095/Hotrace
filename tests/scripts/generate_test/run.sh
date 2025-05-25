#/!bin/bash
#Run this from root of folder

ROOT="../.."
TBEAUZAM="tests/tbeauzam_Hotrace/"

bash "(cd $TBEAUZAM && make && mv ./hotrace $ROOT/tbeauzam && make fclean)"
