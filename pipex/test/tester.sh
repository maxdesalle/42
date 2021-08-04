#!/bin/bash

# Some nice little colors
RED="\033[91m"
WHITE="\033[97m"

if [ -e "pipex" ]
then

	< README.md ls -la | grep pipex > outfile1
	./pipex README.md "ls -la" "grep pipex" outfile2
	echo -en $RED
	diff outfile1 outfile2
	echo -en $WHITE
	rm -f outfile1
	rm -f outfile2

	< README.md grep is | wc -l > outfile1
	./pipex README.md "grep is" "wc -l" outfile2
	echo -en $RED
	diff outfile1 outfile2
	echo -en $WHITE
	rm -f outfile1
	rm -f outfile2

	< README.md cat | wc -w > outfile1
	./pipex README.md cat "wc -w" outfile2
	echo -en $RED
	diff outfile1 outfile2
	echo -en $WHITE
	rm -f outfile1
	rm -f outfile2
else
	echo -en $RED
	echo "The pipex executable is missing"
	echo "Compile it first using \"make re\""
	echo -en $WHITE
fi
