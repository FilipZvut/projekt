// test projekt.cpp: Definuje vstupní bod pro aplikaci.
//
#include <stdio.h>
#include <cstdlib>
#include "projekt.h"
#include <conio.h>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#pragma warning(disable:4996)//proti warning
int poradi = 0; //  :(
int konec = 1; //   :(

void add();
void show(int stop);
void menu();
void vybrat();
void zapisdopromene();
void zapisdotxt();
void change();
void del();
void hledat();
void finboss();
using namespace std;

                                        //a roztridit to do hlavicek a funkci .cpp
typedef struct {                        //Dodela serazeni podle jmena(podle abecedy)
    char nazev[30];                     //upravit misto ulozeni txt na zakladni 
    char misto[30];                     //jeste budem pridavat oteviraci hodiny vsude
    char cena[30];                      // na pridani popisu zamku kaslem, to by rozhodilo celou tabulku xd
}ZAMEK;

ZAMEK zamky[5000];

enum menu { nic, zobrazit, pridat, upravit, vymazat, vyhledat, konecna };
enum menu operace;


int main() {

    do {

        zapisdopromene();   //asi se bude provádět pokaždý uvidíme
        menu();
        vybrat();

    } while (konec);

    finboss();
}



void add()
{
    char temp;
    ZAMEK pridat[50];
    int a = 0;
    int pocet = 0;
    char dalsi;

    do {
        system("cls");
        printf("Zadejte nazev: ");
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", pridat[a].nazev);
        printf("Zadejte lokaci: ");
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", pridat[a].misto);
        printf("Zadejte cenu vstupu: ");
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", pridat[a].cena);
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
        fprintf(wrt, "%s,%s,%s\n", pridat[a].nazev, pridat[a].misto, pridat[a].cena);
    }
    fclose(wrt);


}

void show(int stop) {
    int dva = 0;
    char format[30];
    system("cls");
    printf("    Nazev:                        |Lokace:                       |vstupne:            |\n__________________________________|______________________________|____________________|\n");
    for (int poradi1 = 0; poradi1 < poradi; poradi1++) {
        if (poradi1 > 9)
            dva = 1;
        if (poradi > 99)
            dva = 2;

        for (int a = 0; a < 30; a++)
            format[a] = ' ';
        format[(30 - strlen(zamky[poradi1].nazev) - dva)] = '\0';

        printf("%d)  %s%s|", poradi1, zamky[poradi1].nazev, format);
        for (int a = 0; a < 30; a++)
            format[a] = ' ';
        format[(30 - strlen(zamky[poradi1].misto))] = '\0';

        printf("%s%s|", zamky[poradi1].misto, format);
        format[(20 - strlen(zamky[poradi1].cena))] = '\0';
        printf("%s%s|\n", zamky[poradi1].cena, format);
        printf("----------------------------------|------------------------------|--------------------|\n");

    }
    //printf("--------------------------------------------------------------------------------------|");
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
    printf("        5. vyhledavani\n");
    printf("        6. Vypnout\n");
    scanf("%d", &operace);

}

void vybrat() {

    do {
        switch (operace) {
        case zobrazit: show(1);
            break;
        case pridat:   add();
            break;
        case vymazat:  del();
            break;
        case upravit:  change();
            break;
        case vyhledat: hledat();
            break;
        case konecna:  konec = 0;
            break;
        default:system("cls");
            printf("    Zadal jsi spatnou hodnotu.\n    Zkus to znovu.");
            Sleep(2000);
            menu();
            break;
        }
    } while (operace < 0 || operace>6);


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
        if (c != '\n')
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

void change()
{
    char temp;
    int radek;
    show(0);
    printf("\n\n    Zadejte radek ktery chcete upravit: ");
    scanf("%d", &radek);
    system("cls");
    printf("Upravuje se tento zamek/hrad:\n      %s, %s, %s\n\n", zamky[radek].nazev, zamky[radek].misto, zamky[radek].cena);
    printf("Zadejte novy nazev: ");
    scanf("%c", &temp); // temp statement to clear buffer
    scanf("%[^\n]", zamky[radek].nazev);
    printf("Zadejte novou lokaci: ");
    scanf("%c", &temp); // temp statement to clear buffer
    scanf("%[^\n]", zamky[radek].misto);
    printf("Zadejte novou cenu vstupu: ");
    scanf("%c", &temp); // temp statement to clear buffer
    scanf("%[^\n]", zamky[radek].cena);
    system("cls");
    printf("Nove udaje jsou:    %s, %s, %s\n", zamky[radek].nazev, zamky[radek].misto, zamky[radek].cena);
    getche();


    zapisdotxt();

}



void del() //nefunguje jeste
{
    int pom = 0;
    int dalsi;
    int radek;
    do
    {
        system("cls");
        if (pom == 1)
        {
            printf("zadal si spatne cislo radku, zkus to znova.");
            Sleep(3000);
            system("cls");
        }
        pom = 0;
        show(0);
        printf("\n  Zadej cislo radku ktery chcete smazat:");
        scanf("%d", &radek);
        pom = 1;
    } while (radek >= poradi || radek < 0);

    system("cls");
    printf("Jste si jisti ze chcete smazat tento zamek/hrad: %s,%s,%s\nano/ne [a/n]\n", zamky[radek].nazev, zamky[radek].misto, zamky[radek].cena);


    if (getch() == 'a')
    {
        for (radek; radek < poradi; radek++)
        {
            dalsi = radek + 1;
            strcpy(zamky[radek].nazev, zamky[dalsi].nazev);
            strcpy(zamky[radek].misto, zamky[dalsi].misto);
            strcpy(zamky[radek].cena, zamky[dalsi].cena);
        }
        poradi--;
        zapisdotxt();
    }

    printf("\nChcete smazat dalsi radek?\nano/ne [a/n]\n");
    if (getche() == 'a')
        del();

}

void zapisdotxt()
{
    FILE* wrt1;
    wrt1 = fopen("C:\\Users\\zadni\\Desktop\\code\\test projekt\\test.txt", "w");
    for (int a = 0; a < poradi; a++) {
        fprintf(wrt1, "%s,%s,%s\n", zamky[a].nazev, zamky[a].misto, zamky[a].cena);
    }
    fclose(wrt1);
}

void hledat()
{
    char entr;
    int pismena = 0;
    char prom[30];
    int strg = 0;
    prom[0] = '\0';


    system("cls");
    printf("Zadejte Nazev:%s");
    scanf("%c", &entr);
    scanf("%[^\n]", prom);





    for (int a = 0; a < poradi; a++)
    {
        while (zamky[a].nazev[pismena] == prom[pismena] && prom[pismena] != '\n')
        {
            if (pismena < strlen(prom));
            else
                strg = 1;
            pismena++;
        }
        if (strg == 1)
        {
            printf("%d) %s,%s,%s\n", a, zamky[a].nazev, zamky[a].misto, zamky[a].cena);
            strg = 0;
        }
        pismena = 0;
    }


    entr = getche();




}


void finboss() {
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                      ________________________________________\n");
    printf("                                      \\____projekt Databaze Hradu a Zamku____/\n");
    printf("                                       \\------------------------------------/\n");
    printf("                                        \\vytvoril: Filip Zadnik a Vit Urban/\n");
    printf("                                         \\________________________________/\n");
    Sleep(5000);
}
