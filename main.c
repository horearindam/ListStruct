#include <stdio.h>

int main(int argc, char *argv[]) {
    const char *path = (argc > 1) ? argv[0] : ".";

    printf("%s\n", argv[0]);
    return 0;
}
