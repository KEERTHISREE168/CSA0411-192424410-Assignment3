#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int main()
{
    void *handle = dlopen("./libbankcrypto.so", RTLD_NOW);

    if (!handle) {
        printf("Error: %s\n", dlerror());
        return 1;
    }

    int (*encrypt_value)(int);
    *(void **)(&encrypt_value) = dlsym(handle, "encrypt_value");

    if (!encrypt_value) {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    printf("Runtime loading successful\n");
    printf("Encrypted value: %d\n", encrypt_value(100));

    FILE *fp = fopen("/proc/self/maps", "r");
    char line[256];

    printf("\nMemory mappings:\n");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "libbankcrypto"))
            printf("%s", line);
    }

    fclose(fp);
    dlclose(handle);
    return 0;
}
