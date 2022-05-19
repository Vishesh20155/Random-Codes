#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

unsigned int randomm()
{
    unsigned int val;
    __asm__("rdrand  %[val]"
           : [val] "=r" (val)
            
    );
    return val;
}

int main()
{   
    unsigned int x = randomm();
    printf("Value is %u \n", x);
    return 0;
}
