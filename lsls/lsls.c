#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    char *path = argv[1];
    // Parse command line

    // Open directory
    DIR *dir;
    dir = opendir(path);

    if (dir == NULL) {
        printf("Couldn't open directory");
        exit(1);
    }

    // Repeatly read and print entries
    struct dirent *entries;
    struct stat buf;
    while((entries = readdir(dir)) != NULL) {
        stat(entries->d_name, &buf);
        // just following what's outlined in the README
        // but the behavior is a bit unexpected
        // many files will have the exact same size
        // (often 256, which is wrong)
        // not sure why
        printf("%10lld %s\n", buf.st_size, entries->d_name);    
    }

    // Close directory
    closedir(dir);

  return 0;
}
