#!/bin/bash
name=shedule
build=bin
if [ ! -d $build ]; then
    mkdir $build
fi
cd $build
if [ ! -e Makefile ]; then
    cmake ..
fi
make
if [ -e $name ]; then
    mv $name ../$name
    cd ..
    echo -e '\n'
    ./$name
    echo -e
    rm -f $name
fi