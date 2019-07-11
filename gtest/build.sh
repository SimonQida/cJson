g++ -fprofile-arcs -ftest-coverage -pthread constructApi_test.cc gtest-all.o ../src/jsonfunctionq.c ../src/jsonfunctiony.c /usr/src/googletest/googletest/src/gtest_main.cc -o interface_test -lgcov
./interface_test

lcov -d ./ -t 'interface_test' -o 'interface_test.info' -b . -c

genhtml -o interface_test_web interface_test.info

