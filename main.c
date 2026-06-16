#include <stdio.h>
#include <dirent.h>
#include <getopt.h>
#include <unistd.h>

int show_all = 0;

int main(int argc, char *argv[]) {

    int opt;
    while((opt = getopt(argc, argv, "a")) != -1) {
        switch(opt) {
            case 'a':
                show_all = 1;
                break;
            default:
                fprintf(stderr, "usage: %s [-a] [path]\n", argv[0]);
                return 1;
            }
        }

    const char *path = (optind < argc) ? argv[optind] : ".";

    DIR *dir = opendir(path);
    if (!dir) {
        perror(path);
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (entry->d_name[0] == '.' && !show_all) {
            continue;
        }
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
