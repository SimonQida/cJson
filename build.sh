gcc -g -fprofile-arcs -ftest-coverage -c -o json.o json.c
gcc -g -fprofile-arcs -ftest-coverage -c -o demo.o demo.c
gcc -o demo demo.o json.o -lgcov

./demo

lcov -d ./ -t 'demo' -o 'demo.info' -b . -c

genhtml -o demo_web demo.info

