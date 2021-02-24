rm image.hdd
make clean
make 
./create.sh
echo done ----
 
qemu-system-x86_64 image.hdd