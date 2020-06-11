#!/bin/bash
name=shedule

#BUILD=Release
BUILD=Debug

if [ -n "$1" ]; then
    BUILD=$1
fi

MAKE=ninja
#MAKE=make

if [ $MAKE = ninja ]; then
    makefile=build.ninja
    gen="-G Ninja"
elif [ $MAKE = make ]; then
    makefile=Makefile
    # Unix Makefiles as default
fi

build_dir=bin/$BUILD

if [ ! -d bin ]; then
    mkdir bin
fi
if [ ! -d $build_dir ]; then
    mkdir $build_dir
fi
cd $build_dir

if [ ! -e $makefile ]; then
    cmake $gen -DCMAKE_BUILD_TYPE=$BUILD ../..
fi
rm -f $name

$MAKE
if [ -e $name ]; then
    cp $name ../../$name
    cd ../..
    echo -e '\n'
    ./$name
    echo -e
    rm -f $name
fi