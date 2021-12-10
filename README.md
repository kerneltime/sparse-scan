# sparse-scan
## Tool to quickly report ranges with data
```
cc -Wall -O2 scan.c -s -o scan 
dd of=./file if=/dev/random seek=1024 count=1
./scan < file
           80000            80073
```
## Report mismatch in apparent vs reported 
This uses the `du` command
Running it across a cluster
```
 while true; do for i in {71..78}; do echo $i; ssh -f  10.12.1.${i} 'find /data/disk*/hadoop-ozone/datanode/ -type f -name "*.block"| parallel ~/scan2.sh {} '; done; sleep 60; done
 ```
