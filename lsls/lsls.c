#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    char *path;
    // Parse command line

    // Open directory
    if (argc == 1) {
        path = "./";
    } else {
        path = argv[1];
    }

    DIR *dir;
    dir = opendir(path);

    if (dir == NULL) {
        printf("Couldn't open directory\n");
        exit(1);
    }

    // Repeatly read and print entries
    struct dirent *entries;
    struct stat buf;
    while((entries = readdir(dir)) != NULL) {
        // these two lines and using pathcpy in stat fix the problem 
        // outlined below
        // there is more unexpected behavior when the path does not end in '/'
        // the sizes will all display the same huge number 140732*********
        char * pathcpy = strdup(path);
        strcat(pathcpy, entries->d_name);
        stat(pathcpy, &buf);
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
