clear
mkdir so
cd so
curl -O https://x.nasihosting.com/so/so.zip && unzip so.zip
clear
sleep 2
echo "BY: BM"
echo "Note: Tunggu bentar COOOOOKK"
echo ""
echo ""

sleep 2
echo "Ini Nomutex:"
gcc nomutex.c -lpthread -o nomutex
./nomutex
sleep 3
echo ""
echo ""
echo "Ini Mutex:
gcc mutex.c -lpthread -o mutex
./mutex
sleep 3
echo ""
echo ""
echo "Ini Semaphore:"
gcc semaphore.c -lpthread -o mutex
./semaphore
sleep 3
echo ""
echo ""
sleep 2
echo " APA LAGI ANJ*NG !!!"
sleep 2
echo " Udah Tuh"
