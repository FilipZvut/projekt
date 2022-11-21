#include "Projekt.h"
#include <dirent.h>
#include <stdio.h> 
#include <errno.h>
#include <stdlib.h>
#include "funkce.cpp"

//https://iq.opengenus.org/ls-command-in-c/     //okomentovat kod
//
char test[1500];
void _ls(const char *dir,  int op_a, int op_l)
{
    dir = "C:\\Users\\zadni\\Desktop\\code\\projekt\\da";
    struct dirent *d;
    DIR *dh = opendir(dir);
    if(!dh)
    {
        if(errno = ENOENT)
        {
            perror("Slozka neexistuje");
        }
        else
        {
            perror("Nelze precist slozku.");
        }
    }
    while ((d = readdir(dh)) != NULL)
    {
        if(!op_a && d->d_name[0] == '.')
            continue;
        //printf("%s\n", d->d_name);
     char *tuktuk = strtok(d->d_name, ".txt");
        while(tuktuk != NULL)
        {
            printf("%s\n", tuktuk);

            tuktuk = strtok(NULL, ".txt");
        }
        //for(int i = 0; i <150; i++)
        //{
        //    if (test[i] == '.')
        //        i += 3;
        //    test[i];
        //}   

        if(op_l) printf("\n");
    }
    if(!op_l)
    printf("\n");

}
int main(int argc, char* argv[])
{
 
    if (argc == 1)
    {
        _ls(".", 0, 0);
    }
    else if(argc == 2)
    {
        if(argv[1][0] == '-')
        {
            int op_a = 0, op_l = 0;
            char *p = (char*)(argv[1] + 1);
            while(*p)
            {
                if(*p == 'a') op_a = 1;
                else if(*p == '1') op_l = 1;
                else
                {
                    perror("Neexistuje kokote.");   
                    exit(EXIT_FAILURE);
                }
                p++;
            }
            _ls(".", op_a, op_l);
        }
    }

    return 0;
}
