#!/bin/bash

c_files=$(ls *.c)

gcc -c -Wall -Werror -Wextra *.c && ar -rcs liball.a *.o
