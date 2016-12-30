#! /bin/bash

git pull
gcc -g -o link1 link1.c
valgrind --tool=memcheck --leak-check=full ./link1