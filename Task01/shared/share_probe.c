#include <stdio.h>
#include <unistd.h>
#include "banklib.h"

int main()
{
    printf("PID: %d\n", getpid());
    printf("Encryption result: %d\n", encrypt_value(100));
    fflush(stdout);
    sleep(20);
    return 0;
}
