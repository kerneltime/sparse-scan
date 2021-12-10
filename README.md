# sparse-scan
Tool to quickly report ranges with data
```
cc -Wall -O2 scan.c -s -o scan 
dd of=./file if=/dev/random seek=1024 count=1
./scan < file
           80000            80073
```
