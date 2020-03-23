#!/bin/bash

if cl -E test_x32.cpp > /dev/null 2>&1 ; then
echo "Win32"
fi

if cl -E test_x64.cpp > /dev/null 2>&1 ; then
echo "x64"
fi
