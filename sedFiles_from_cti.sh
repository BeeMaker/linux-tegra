#!/bin/bash

# define function of bash script

if [ -z $1 ]; then
  echo "Need parameter file like display, nvgpu, nvhost, nvmap, nvmap-t18x, t18x"
  exit 1
fi

function copy_and_replace {

  # prepare old path of directory
  argOfGrep="../$1"
  echo $argOfGrep

  # copy filename into nvidia root
  cp -r $argOfGrep ./nvidia/

  # sed all occurancy with pattern "../$filename" to "nvidia/$filename"
  sed -e "s#\.\./$1#nvidia/$1#g" $(find . -type f \( -name "*Kconfig*" -o -name "*Makefile*" \) -exec grep -F $argOfGrep {} \+ | cut -d: -f1 | sort | uniq)

}

# Copy and modify file in ../ path
# filename = (display, nvgpu, nvhost, nvmap, nvmap-t18x, t18x)

copy_and_replace "$1"
