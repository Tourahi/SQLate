#!/bin/bash

platform="unix"
compiler="gcc"

if command -v ccache >/dev/null; then
  compiler="ccache $compiler"
fi

for f in `find . -name "*.c"`; do
  $compiler -c $f
  if [[ $? -ne 0 ]]; then
    got_error=true
  fi
done

if [[ ! $got_error ]]; then
  echo "linking..."
  $compiler *.o -o SQLate
fi


rm *.o
rm res.res 2>/dev/null