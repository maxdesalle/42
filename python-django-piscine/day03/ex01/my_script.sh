#!/bin/sh

pip3 --version | sed 's/from.*//'
python3 -m venv local_lib
source local_lib/bin/activate
pip3 install git+https://github.com/jaraco/path.git --log local_lib/installation.log --upgrade
if [ $? != -1 ]
then
	python3 my_program.py
fi
