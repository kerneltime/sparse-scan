#define _GNU_SOURCE
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/sendfile.h>

int main(void){
        off_t hole, data; typedef unsigned long long ull;
        for(hole = 0;; data = hole){
                if((data = lseek(0, hole, SEEK_DATA)) == -1){
                        if(errno == ENXIO) return 0;
                        err(1, "lseek +data");
                }
                if((hole = lseek(0, data, SEEK_HOLE)) == -1)
                        err(1, "lseek +hole");
                dprintf(2, "%16llx %16llx\n", (ull)data, (ull)hole);
        }
}
