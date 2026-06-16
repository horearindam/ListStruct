#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    const char *path = (argc > 1) ? argv[1] : ".";

    DIR *dir = opendir(path);
    if(!dir) {
        perror("Error");
        return 1;
    }

    return 0;
}
