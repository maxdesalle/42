#!/bin/sh

pip --version
mkdir local_lib
pip install git+https://github.com/jaraco/path.git -t local_lib
