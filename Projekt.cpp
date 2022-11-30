﻿// test projekt.cpp: Definuje vstupní bod pro aplikaci.
//
#include <stdio.h>

#include "Projekt.h"
#include <conio.h>
#include <Windows.h>
#pragma warning(disable:4996)//proti warning

int poradi = 0; //:(

void add();
void show(int stop);
void menu();
void vybrat();
void zapisdopromene();
void del();
using namespace std;


typedef struct {
    char nazev[30];
    char misto[30];
    char cena[30];
}ZAMEK;

ZAMEK zamky[500];

enum menu { nic, zobrazit, pridat, upravit, vymazat };
enum menu operace;


int main() {

    do {
        zapisdopromene();   //asi se bude provádět pokaždý uvidíme
        menu();
        vybrat();

    } while (true);

}



void add()
{

    ZAMEK pridat[50];
    int a = 0;
    int pocet = 0;
    char dalsi;

    do {
        system("cls");
        printf("Zadejte nazev: ");
        scanf("%s", pridat[a].nazev);
        printf("Zadejte lokaci: ");
        scanf("%s", pridat[a].misto);
        printf("Zadejte cenu vstupu: ");
        scanf("%s", pridat[a].cena);
        a++;
        pocet++;
        printf("Budete chtit pridat dalsi zamek? [a/n]\n");
        dalsi = getche();
        system("cls");

    } while (dalsi == 'a');
    ;
    FILE* wrt;
    wrt = fopen("C:\\Users\\zadni\\Desktop\\code\\test projekt\\test.txt", "a");
    for (int a = 0; a < pocet; a++) {
        fprintf(wrt, "%s,%s,%s*\n", pridat[a].nazev, pridat[a].misto, pridat[a].cena);
    }
    fclose(wrt);


}

void show(int stop) {

    system("cls");
    printf("Nazev,    Lokace,    vstupne\n-------------------------------\n");
    for (int poradi1 = 0; poradi1 < poradi; poradi1++) {


        printf("%s,", zamky[poradi1].nazev);
        printf("%s,", zamky[poradi1].misto);
        printf("%s", zamky[poradi1].cena);

    }
    if (stop)
        getche();

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
        case zobrazit: show(1);
            break;
        case pridat: add();
            break;
        case vymazat: del();
            break;
        default:system("cls");
            printf("    Zadal jsi spatnou hodnotu.\n    Zkus to znovu.");
            Sleep(2000);
            menu();
            break;
        }
    } while (operace < 0 || operace>4);


}


void zapisdopromene()
{
    poradi = 0;
    int typ = 0;
    int a = 0;
    char c;


    FILE* rd;
    rd = fopen("C:\\Users\\zadni\\Desktop\\code\\test projekt\\test.txt", "r");

    while ((c = fgetc(rd)) != EOF)
        if (c != '*')
        {
            if (c != ',') {
                if (typ == 0)
                    zamky[poradi].nazev[a] = c;
                if (typ == 1)
                    zamky[poradi].misto[a] = c;
                if (typ == 2)
                    zamky[poradi].cena[a] = c;

                a++;
            }
            else {
                if (typ == 0)
                    zamky[poradi].nazev[a] = '\0';
                if (typ == 1)
                    zamky[poradi].misto[a] = '\0';

                a = 0;
                typ++;
            }
        }
        else {
            zamky[poradi].cena[a] = '\0';
            a = 0;
            typ = 0;
            poradi++;
        }

    fclose(rd);

}

void del()
{
    show(0);
    printf("Zadej cislo radku ktery chcete smazat:");
}
