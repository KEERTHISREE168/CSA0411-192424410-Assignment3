#include <stdio.h>
#include "banklib.h"

int main()
{
    int value = 100;
    printf("Original value: %d\n", value);
    printf("Encrypted value: %d\n", encrypt_value(value));
    printf("Function address: %p\n", (void *)encrypt_value);
    return 0;
}
