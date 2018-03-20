#!/usr/bin/env bash 

set -ex

make ex17;
rm -f book.db;
./ex17 book.db c;
./ex17 book.db s 1 admin admin@outlook.com;
./ex17 book.db s 2 root root@gmail.com;
./ex17 book.db s 3 sudoer sudoer@hotmail.com;
./ex17 book.db l;
./ex17 book.db d 3;
./ex17 book.db l;
./ex17 book.db g 2;
