#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

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
    while((entries = readdir(dir)) != NULL) {
        printf("%s\n", entries->d_name);    
    }

    // Close directory
    closedir(dir);

  return 0;
}
