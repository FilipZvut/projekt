// test projekt.cpp: Definuje vstupní bod pro aplikaci.
//
#include <stdio.h>
#include <cstdlib>
#include "test projekt.h"
#include <conio.h>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#pragma warning(disable:4996)//proti warning
int poradi = 0; //:(

void add();
void show(int stop);
void menu();
void vybrat();
void zapisdopromene();
void zapisdotxt();
void change();
void del();
void hledat();
using namespace std;


typedef struct {
    char nazev[30];
    char misto[30];
    char cena[30];
}ZAMEK;

ZAMEK zamky[5000000];

enum menu { nic, zobrazit, pridat, upravit, vymazat, vyhledat };
enum menu operace;


int main(){   
   
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
        scanf("%s", &pridat[a].nazev);
        printf("Zadejte lokaci: ");
        scanf("%s", &pridat[a].misto);
        printf("Zadejte cenu vstupu: ");
        scanf("%s", &pridat[a].cena);
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

        system("cls");
        printf("Nazev,    Lokace,    vstupne\n-------------------------------\n");
        for (int poradi1 = 0; poradi1 < poradi; poradi1++) {
           
            
            printf("%d)  %s,",poradi1, zamky[poradi1].nazev);
            printf("%s,", zamky[poradi1].misto);
            printf("%s\n", zamky[poradi1].cena);
            
        }
        if(stop)
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
        scanf("%d", &operace);

}

void vybrat() {

     do{
        switch (operace) {
        case zobrazit: show(1);
            break;
        case pridat: add();
            break;
        case vymazat: del();
            break;
        case upravit: change();
            break;
        case vyhledat: hledat();
        default:system("cls");
                printf("    Zadal jsi spatnou hodnotu.\n    Zkus to znovu.");
                Sleep(2000);
                menu();
                break;
        }
     } while (operace<0||operace>4);
    
        
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
    int radek;
    show(0);
    printf("\n\n    Zadejte radek ktery chcete upravit: ");
    scanf("%d", &radek);
    system("cls");
    printf("Upravuje se tento zamek/hrad:\n      %s, %s, %s\n\n", zamky[radek].nazev, zamky[radek].misto, zamky[radek].cena);
    printf("Zadejte novy nazev: ");
    scanf("%s", &zamky[radek].nazev);
    printf("Zadejte novou lokaci: ");
    scanf("%s", &zamky[radek].misto);
    printf("Zadejte novou cenu vstupu: ");
    scanf("%s", &zamky[radek].cena);
    system("cls");
    printf("Nove udaje jsou:    %s, %s, %s\n", zamky[radek].nazev, zamky[radek].misto, zamky[radek].cena);
    getche();

    
    zapisdotxt();

}



void del() //nefunguje jeste
{
    int pom=0;
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
    int pismena=0;
    char entr;
    char prom[30];
    int strg=0;
    prom[0] = '\0';
   

        system("cls");
        printf("Zadejte Nazev:%s");
        scanf("%s", &prom);
        
        
        


        for (int a=0; a < poradi; a++)
        {
            while (zamky[a].nazev[pismena] == prom[pismena]&&prom[pismena]!='\n')
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
        
        getche();



    


}