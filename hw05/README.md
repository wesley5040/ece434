# HW05
Wesley Van Pelt - CM3289

## Project
I added a project with my name.

## Make
All the relevant stuff is in [`Makefile`](Makefile).  Note this only works on the bone for me because of the loader flags you had us add.

## Installing the Kernel Source
Kernel `4.18.10-bone-rt-r10` is now running on the bone.  It took about 5 minutes to compile (not including downloading all of the files) on my server.

## Cross-Compiling
### Compiled and run on x86
```
wvp@wvp-uvm:~/ece434/hw05$ gcc helloWorld.c

wvp@wvp-uvm:~/ece434/hw05$ file a.out
a.out: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=049e80612d5735fda0966f6e23c637d345447f49, not stripped

wvp@wvp-uvm:~/ece434/hw05$ ./a.out
Hello, World! Main is executing at 0x558ed999a6aa
This address (0x7ffc68f917c0) is in our stack frame
This address (0x558ed9b9b018) is in our bss section
This address (0x558ed9b9b010) is in our data section
```

### Compiled on x86 and run on ARM
```
wvp@wvp-uvm:~/ece434/hw05$ ${CROSS_COMPILE}gcc helloWorld.c -o a.arm

root@beaglebone:~/ece434/hw05# file a.arm
a.arm: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux-armhf.so.3, for GNU/Linux 3.2.0, BuildID[sha1]=2cbc392a3bb5ab575e0396e7d0d021672fdaae85, not stripped

root@beaglebone:~/ece434/hw05# ./a.arm
Hello, World! Main is executing at 0x103d5
This address (0xbeb77b94) is in our stack frame
This address (0x21030) is in our bss section
This address (0x21028) is in our data section
```

## Kernel Modules
TODO
