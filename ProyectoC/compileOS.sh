dd if=/dev/zero of=floppya.img bs=512 count=2880
dd if=bootload of=floppya.img bs=512 count=1 conv=notrunc
bcc -ansi -c -o kernel.o kernel.c
as86 kernel.asm -o kernel_asm.o
ld86 -o kernel -d kernel.o kernel_asm.o
dd if=kernel of=floppya.img bs=512 conv=notrunc seek=3
dd if=message.txt of=floppya.img bs=512 count=1 seek=30 conv=notrunc
dd if=messag.txt of=floppya.img bs=512 count=1 seek=31 conv=notrunc
bcc -ansi -c -o shell.o shell.c
as86 -o os_api.o os_api.asm
ld86 -o shell -d shell.o os_api.o
dd if=shell of=floppya.img bs=512 count=1 seek=11 conv=notrunc
