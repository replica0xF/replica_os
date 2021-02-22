# Create an empty zeroed out 64MiB image file.
dd if=/dev/zero bs=1M count=0 seek=64 of=image.hdd
 
# Create a GPT partition layout.
parted -s image.hdd mklabel gpt
 
# Create a partition that spans the whole disk.
parted -s image.hdd mkpart primary 2048s 100%
 
# Format this new GPT partition as echfs (blocks of 512 bytes in size).
# -g stands for GPT, use -m alternatively for MBR.
echfs-utils -g -p0 image.hdd quick-format 512
 
# Copy config file and kernel file(s) over into the image.
echfs-utils -g -p0 image.hdd import limine.cfg limine.cfg
echfs-utils -g -p0 image.hdd import replica.elf replica.elf
 
# Finally, install Limine onto the image.
limine-install image.hdd
