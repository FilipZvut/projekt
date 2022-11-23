// test projekt.cpp: Definuje vstupní bod pro aplikaci.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projekt.h"
#include <conio.h>
#include <iostream>
void add();
void show();
void menu();
void vybrat();
using namespace std;


typedef struct {
    char nazev[100];
    char misto[100];
    char cena[20];
}ZAMEK;

enum menu { nic, zobrazit, pridat, upravit, vymazat };
enum menu operace;


int main() {

    do {
        menu();
        vybrat();

    } while (true);

}



void add()
{
    ZAMEK zamky[50];
    int a = 0;
    int pocet = 0;
    char dalsi;

    do {

        printf("Zadejte nazev: ");
        scanf("%s", zamky[a].nazev);
        printf("Zadejte lokaci: ");
        scanf("%s", zamky[a].misto);
        printf("Zadejte cenu vstupu: ");
        scanf("%s", zamky[a].cena);
        a++;
        pocet++;
        printf("Budete chtit pridat dalsi zamek? [a/n]");
        dalsi = getch();
        system("cls");

    } while (dalsi == 'a');
    ;
    FILE* wrt;
    wrt = fopen("C:\\Users\\zadni\\Desktop\\code\\projekt\\test.txt", "a");
    for (int a = 0; a < pocet; a++) {
        fprintf(wrt, "%s,    %s,     %s\n", zamky[a].nazev, zamky[a].misto, zamky[a].cena);
    }
    fclose(wrt);


}

void show() {

    FILE* read;
    read = fopen("C:\\Users\\zadni\\Desktop\\code\\projekt\\test.txt", "r");
    system("cls");
    printf("Nazev,    Lokace,    vstupne\n-------------------------------\n");

    char c;
    while ((c = fgetc(read)) != EOF)
        if (c != '*')
            printf("%c", c);
    fclose(read);
    getch();
}

void menu() {

    system("cls");
    printf("\n ______Projekt hrady a zamky______\n");
    printf("\n          vyberte operaci:\n\n");
    printf("        1. zobrazit\n");
    printf("        2. pridat\n");
    printf("        3. upravit\n");
    printf("        4. smazat\n");
    scanf("%d", &operace);

}

void vybrat() {

    do {
        switch (operace) {
        case zobrazit: show();
            break;
        case pridat: add();
            break;
        default:system("cls");
            printf("    Zadal jsi spatnou hodnotu.\n    Zkus to znovu.");
            scanf("%d", (&operace - 1));
            break;
        }
    } while (operace < 0 || operace>3);


}



//#include "Projekt.h"
//#include <dirent.h>
//#include <stdio.h> 
//#include <errno.h>
//#include <stdlib.h>
//#include "funkce.cpp"
//
////https://iq.opengenus.org/ls-command-in-c/     //okomentovat kod
////
//char test[1500];
//void _ls(const char *dir,  int op_a, int op_l)
//{
//    dir = "C:\\Users\\zadni\\Desktop\\code\\projekt\\da";
//    struct dirent *d;
//    DIR *dh = opendir(dir);
//    if(!dh)
//    {
//        if(errno = ENOENT)
//        {
//            perror("Slozka neexistuje");
//        }
//        else
//        {
//            perror("Nelze precist slozku.");
//        }
//    }
//    while ((d = readdir(dh)) != NULL)
//    {
//        if(!op_a && d->d_name[0] == '.')
//            continue;
//        //printf("%s\n", d->d_name);
//     char *tuktuk = strtok(d->d_name, ".txt");
//        while(tuktuk != NULL)
//        {
//            printf("%s\n", tuktuk);
//
//            tuktuk = strtok(NULL, ".txt");
//        }
//        //for(int i = 0; i <150; i++)
//        //{
//        //    if (test[i] == '.')
//        //        i += 3;
//        //    test[i];
//        //}   
//
//        if(op_l) printf("\n");
//    }
//    if(!op_l)
//    printf("\n");
//
//}
//int main(int argc, char* argv[])
//{
// 
//    if (argc == 1)
//    {
//        _ls(".", 0, 0);
//    }
//    else if(argc == 2)
//    {
//        if(argv[1][0] == '-')
//        {
//            int op_a = 0, op_l = 0;
//            char *p = (char*)(argv[1] + 1);
//            while(*p)
//            {
//                if(*p == 'a') op_a = 1;
//                else if(*p == '1') op_l = 1;
//                else
//                {
//                    perror("Neexistuje kokote.");   
//                    exit(EXIT_FAILURE);
//                }
//                p++;
//            }
//            _ls(".", op_a, op_l);
//        }
//    }
//
//    return 0;
//}
