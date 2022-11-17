#!/bin/bash

#Author: BM

clear
mkdir so
cd so
curl -O https://raw.githubusercontent.com/BM-TechID/so-pertemuan7/main/mutex.c
curl -O https://raw.githubusercontent.com/BM-TechID/so-pertemuan7/main/nomutex.c
curl -O https://raw.githubusercontent.com/BM-TechID/so-pertemuan7/main/semaphore.c
clear
sleep 2
echo "BY: BM"
echo "Note: Tunggu bentar COOOOOKK"
echo ""
echo ""

sleep 2
cat mutex.c
echo "\n"
echo "Ini Nomutex:"
gcc nomutex.c -lpthread -o nomutex
./nomutex
sleep 3
echo ""
echo ""


cat nomutex.c
echo "\n"
echo "Ini Mutex:"
gcc mutex.c -lpthread -o mutex
./mutex
sleep 3
echo ""
echo ""


echo "\n"
cat semaphore.c
echo "Ini Semaphore:"
gcc semaphore.c -lpthread -o semaphore
./semaphore
sleep 3
echo ""
echo ""

sleep 2
echo " APA LAGI ANJ*NG !!!"
sleep 2
echo " Udah Tuh"
