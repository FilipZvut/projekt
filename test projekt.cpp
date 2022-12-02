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
void change();
void del();
using namespace std;


typedef struct {
    char nazev[30];
    char misto[30];
    char cena[30];
}ZAMEK;

ZAMEK zamky[5000000];

enum menu { nic, zobrazit, pridat, upravit, vymazat };
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


    FILE* wrt1;
    wrt1 = fopen("C:\\Users\\zadni\\Desktop\\code\\test projekt\\test.txt", "w");
    for (int a = 0; a < poradi; a++) {
        fprintf(wrt1, "%s,%s,%s\n", zamky[a].nazev, zamky[a].misto, zamky[a].cena);
    }
    fclose(wrt1);


}



void del() //nefunguje jeste
{   
    int dalsi;
    int radek;
    show(0);
    printf("Zadej cislo radku ktery chcete smazat:");
    scanf("%d", radek);
    for (radek; radek < (poradi + 1); radek++)
    {
        dalsi = radek + 1;
       


    }

}
