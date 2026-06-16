#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *path = (argc == 2) ? argv[1] : ".";

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror(path);
        return EXIT_FAILURE;
    }

    errno = 0;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.')
            continue;

        if (printf("%s\n", entry->d_name) < 0) {
            perror("printf");
            closedir(dir);
            return EXIT_FAILURE;
        }
    }

    if (errno != 0) {
        perror("readdir");
        closedir(dir);
        return EXIT_FAILURE;
    }

    if (closedir(dir) == -1) {
        perror("closedir");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
