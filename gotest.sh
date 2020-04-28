#!/bin/bash

for f in " ./test/*.mc"
do
  echo --------------------- $f ------------------------------
  ./minic $f
done
