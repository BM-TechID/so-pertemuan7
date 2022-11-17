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
echo "Ini Nomutex:"
cat mutex.c
gcc nomutex.c -lpthread -o nomutex
./nomutex
sleep 3
echo ""
echo ""

echo "Ini Mutex:"
cat nomutex.c
gcc mutex.c -lpthread -o mutex
./mutex
sleep 3
echo ""
echo ""

echo "Ini Semaphore:"
cat semaphore.c
gcc semaphore.c -lpthread -o mutex
./semaphore
sleep 3
echo ""
echo ""

sleep 2
echo " APA LAGI ANJ*NG !!!"
sleep 2
echo " Udah Tuh"
