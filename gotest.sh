#!/bin/bash

for f in " ./test/*.tiny"
do
  echo --------------------- $f ------------------------------
  ./tiny $f
done
