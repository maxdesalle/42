#!/bin/bash

# Some nice little colors
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
BLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
WHITE="\e[97m"

echo -n "baracuda\ncrocodile\nelephant\n" > file1
echo -n "baracuda\ncrocodile\nelephant\n" > file2

< README.md ls -la | wc > outfile1
./pipex README.md "ls -la" wc outfile2
diff outfile1 outfile2

rm -f file1
rm -f file2
rm -f outfile1
rm -f outfile2
