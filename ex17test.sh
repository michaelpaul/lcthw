#!/usr/bin/env bash 

set -e 

make ex17;
./ex17 book.db c;
echo "create pass";
./ex17 book.db s 1 admin admin@outlook.com;
./ex17 book.db s 2 root root@gmail.com;
./ex17 book.db s 3 sudoer sudoer@hotmail.com;
echo "set pass";
./ex17 book.db l;
echo "list pass";
./ex17 book.db d 3;
echo "delete pass";
./ex17 book.db l;
echo "list pass";
./ex17 book.db g 2;
echo "get pass";
