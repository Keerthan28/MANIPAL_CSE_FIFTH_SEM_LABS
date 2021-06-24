#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>

void printdir(char *dir,int depth){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp=opendir(dir))==NULL){
        fprintf(stderr,"cannot open directory: %s\n",dir);
        return;

    }
    chdir(dir);
    while ((entry=readdir(dp))!=NULL)
    {
        lstat(entry->d_name,&statbuf);
        if (S_ISDIR(statbuf.st_mode))
        {
            if((strcmp(".",entry->d_name)) || (strcmp("..",entry->d_name))){
                continue;
            }
            printf("%*s%s\n",depth,"",entry->d_name);
            printdir(entry->d_name,depth+4);
        }
        else printf("%*s%s\n",depth,"",entry->d_name);
    }
    chdir("..");
    closedir(dp);
}