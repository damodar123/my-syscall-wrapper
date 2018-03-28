#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

static int (*open_orig)(const char* filename, int flags) = NULL;

int open(const char* filename, int flags)
{
    printf("Damodar opening the file %s\n", filename);
    open_orig = dlsym(RTLD_NEXT, "open");
    open_orig(filename, flags);
}
