#!/bin/bash
# Init kattis folder and download test files.

URL="https://www.hackerrank.com/rest/contests/master/challenges/$1/download_testcases"
wget -q  "$URL" 
if [ $? -ne 0 ] ; then
  echo "Failed"
else
  mkdir $1
  ln -s ../Makefile ./$1/Makefile
  cp ./main.cpp $1/main.cpp
  mkdir $1/test
  unzip download_testcases -d $1/test/ > /dev/null
  rm download_testcases
  rename txt in $1/test/input/*.txt
  rename txt ans $1/test/output/*.txt
  mv $1/test/input/* $1/test/
  mv $1/test/output/* $1/test/
  rmdir $1/test/input
  rmdir $1/test/output
  cd $1/test/
  for file in input*; do mv $file ${file#input};done;
  for file in output*; do mv $file ${file#output};done;
fi

