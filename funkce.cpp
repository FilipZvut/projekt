#include "Projekt.h"

//   Vyctove typy   //
enum menu { nic, zobrazit, pridat, upravit, vymazat, vyhledat, konecna };   // vsechny moznosti, ktere muze uzivatel provest //
enum menu operace;  // promenna, ktera podle sve hodnoty rika jaka moznost se ma provest //

//   Globalni promenne   //
int poradi = 0; //  :(
int konec = 1; // :(

//   Struktury   //
typedef struct {                                                           

    char nazev[30];  // nazev hradu/zamku //                                
    char misto[30];  // lokace kde se zamek/hrad nachazi                   
    char cena[30];   // cena vstupneho   //                                
    char otvdoba[15];

}ZAMEK;              // typ ZAMEK //

ZAMEK zamky[5000];   // promenna typu ZAMEK, s maximalni velikosti zamku/hradu //



void add()  // funkce pro pridani hradu/zamku //
{

    char temp;  // docasna promenna typu char //
    ZAMEK pridat[50]; //promenna typu ZAMEK, s omezenim pro jednotlive data //
    int a = 0; // dalsi pomocne/urcujici promenne //
    int pocet = 0;
    char dalsi;

    do
    {    // cylkus pro pridavani hradu/zamku //

        system("cls");  // vycisteni konzole //
        printf("Zadejte nazev: ");
        scanf("%c", &temp); // vycisteni bufferu //
        scanf("%[^\n]", pridat[a].nazev);   // pridani nazvu //
        printf("Zadejte lokaci: ");
        scanf("%c", &temp); // vycisteni bufferu //
        scanf("%[^\n]", pridat[a].misto);   // pridani lokace //
        printf("Zadejte cenu vstupu: ");
        scanf("%c", &temp); // vycisteni bufferu //
        scanf("%[^\n]", pridat[a].cena);    // pridani ceny vstupneho //
        printf("Zadejte oteviraci dobu:");
        scanf("%c", &temp); // vycisteni bufferu //
        scanf("%[^\n]", pridat[a].otvdoba);    // pridani oteviraci doby //
        a++;        // inkrementace promenne //
        pocet++;    // inkrementace promenne //
        printf("Budete chtit pridat dalsi zamek? [a/n]\n");
        dalsi = getche();   // cteni zadaneho parametru //
        system("cls");  // vycisteni konzole //

    } while (dalsi == 'a'); // podminka ukonceni cyklu //

    FILE* wrt; // promenna pro praci se souborem //
    wrt = fopen("databaze.txt", "a"); // otevirani souboru, cestu k souboru a parametr jak se ma soubor otevrit //

    for (int i = 0; i < pocet; i++) { // cyklus //

        fprintf(wrt, "%s,%s,%s,%s\n", pridat[i].nazev, pridat[i].misto, pridat[i].cena, pridat[i].otvdoba); // pridavani dat do souboru //

    }

    fclose(wrt); // uzavreti souboru //

}

void show(int stop) // funkce pro zobrazeni a formatovani dat //
{

    int dva = 0; // promenne //
    char format[30];
    system("cls");  // vycisteni konzole //
    printf(" Nazev:                           |Lokace:                       |Vstupne:  |Oteviraci doba:|\n__________________________________|______________________________|__________|_______________|\n");

    for (int poradi1 = 0; poradi1 < poradi; poradi1++)  // cyklus pro naformatovani ulozenych dat //
    {

        if (poradi1 > 9)      // urcovaci podminky pro formatovani //
            dva = 1;
        if (poradi1 > 99)
            dva = 2;
        for (int a = 0; a < 30; a++)    // cyklus pro urceni velikosti mezery //
            format[a] = ' ';    // uprava formatovani //

        format[(30 - strlen(zamky[poradi1].nazev) - dva)] = '\0';   //vypocet znaku nulove hodnoty //
        printf("%d)  %s%s|", (poradi1 + 1), zamky[poradi1].nazev, format);    //vypis formatovane casti dat //

        for (int a = 0; a < 30; a++)    // cyklus pro urceni velikosti mezery //
            format[a] = ' ';    // uprava formatovani //

        format[(30 - strlen(zamky[poradi1].misto))] = '\0';
        printf("%s%s|", zamky[poradi1].misto, format);

        for (int a = 0; a < 30; a++)    // cyklus pro urceni velikosti mezery //
            format[a] = ' ';    // uprava formatovani //

        format[(8 - strlen(zamky[poradi1].cena))] = '\0';
        printf("%sKc%s|", zamky[poradi1].cena, format);

        for (int a = 0; a < 30; a++)    // cyklus pro urceni velikosti mezery //
            format[a] = ' ';    // uprava formatovani //

        format[(15 - strlen(zamky[poradi1].otvdoba))] = '\0';
        printf("%s%s|\n", zamky[poradi1].otvdoba, format);


        printf("----------------------------------|------------------------------|----------|---------------|\n");

    }

    if (stop)
        getche();

}

void menu() // funkce zobrazujici mozne operace //
{

    system("cls");
    printf(" __________________________________\n");
    printf(" |................................|\n");
    printf(" |      Projekt hrady a zamky     |\n");
    printf(" |................................|\n");
    printf(" |                                |\n");
    printf(" | vyberte operaci:               |\n");
    printf(" |                                |\n");
    printf(" |        1. zobrazit             |\n");
    printf(" |        2. pridat               |\n");
    printf(" |        3. upravit              |\n");
    printf(" |        4. smazat               |\n");
    printf(" |        5. vyhledavani          |\n");
    printf(" |        6. Vypnout              |\n");
    printf(" |                                |\n");
    printf(" |________________________________|\n");


    scanf("%d", &operace);  // precteni zadane hodnoty //

}

int vybrat()
{

    do
    {

        switch (operace) {  // case pro prepinani podle urcite hodnoty //
        case zobrazit: show(1); // pokud se hodnota promenne "operace" rovna hodnote "zobrazit" provede se zavolani funkce //
            break;  // ukonci switch //
        case pridat:   add();
            break;
        case vymazat:  del();
            break;
        case upravit:  change();
            break;
        case vyhledat: hledat();
            break;
        case konecna: return 0;
            break;
        default:system("cls"); // vycisteni konzole //
            printf("    Zadal jsi spatnou hodnotu.\n    Zkus to znovu."); // uzivateli vzdornost //
            Sleep(2000);    // cekani, protoze muzeme //
            menu(); // volani funkce //
            break;  // ukonci cyklus //
        }

    } while (operace < 0 || operace>6); // podminka cyklu //

    return 1;

}

void zapisdopromene()   //funkce pro zapis do promenne //
{

    poradi = 0; // promenne... //
    int typ = 0;
    int a = 0;
    char c;

    FILE* rd;   // promenna pro praci se souborem //
    rd = fopen("databaze.txt", "r"); // otevirani souboru, cesta k souboru a parametr jak otevrit soubor //

    while ((c = fgetc(rd)) != EOF)  // podminka cyklu zda promenna nerovna konci souboru //
        if (c != '\n')  // podminka zda se promenna nerovna konci radku //
        {

            if (c != ',') { // formatovaci podminka //

                if (typ == 0)   // overeni podminky //
                    zamky[poradi].nazev[a] = c; // zapisovani textu do promennych ve strukture //
                if (typ == 1)
                    zamky[poradi].misto[a] = c;
                if (typ == 2)
                    zamky[poradi].cena[a] = c;
                if (typ == 3)
                    zamky[poradi].otvdoba[a] = c;
                a++;    // inkrementace promenne //

            }
            else
            {

                if (typ == 0)
                    zamky[poradi].nazev[a] = '\0';  //ulozi to promenne nulovaci znak //
                if (typ == 1)
                    zamky[poradi].misto[a] = '\0';
                if (typ == 2)
                    zamky[poradi].cena[a] = '\0';

                a = 0;  // deklarace promenne //
                typ++;  // inkrementace promenne //

            }
        }
        else
        {

            zamky[poradi].otvdoba[a] = '\0';
            a = 0;
            typ = 0;
            poradi++;

        }

    fclose(rd); // uzavreni souboru //

}

void change()
{

    char temp;  // promenne //
    int radek;

    show(0);    // volani funkce s parametrem //
    printf("\n\n    Zadejte radek ktery chcete upravit: ");
    scanf("%d", &radek);    // cteni parametru z konzole //
    radek--;
    system("cls");  // vycisteni konzole //
    printf("Upravuje se tento zamek/hrad:\n      %s, %s, %s, %s\n\n", zamky[radek].nazev, zamky[radek].misto, zamky[radek].cena, zamky[radek].otvdoba);   // vypis co upravujeme //
    printf("Zadejte novy nazev: ");
    scanf("%c", &temp); // vycisteni bufferu //
    scanf("%[^\n]", zamky[radek].nazev);    // ukladani dat do promenne //
    printf("Zadejte novou lokaci: ");
    scanf("%c", &temp); // vycisteni bufferu //
    scanf("%[^\n]", zamky[radek].misto);
    printf("Zadejte novou cenu vstupu: ");
    scanf("%c", &temp); // vycisteni bufferu //
    scanf("%[^\n]", zamky[radek].cena); // cteni z konzole //
    printf("Zadejte novou oteviraci dobu: ");
    scanf("%c", &temp); // vycisteni bufferu //
    scanf("%[^\n]", zamky[radek].otvdoba); // cteni z konzole //

    system("cls");  // vycisteni konzole //
    printf("Nove udaje jsou:    %s, %s, %s, %s\n", zamky[radek].nazev, zamky[radek].misto, zamky[radek].cena, zamky[radek].otvdoba);  // vypis upravenych dat //
    getche();   // cteni z konzole
    zapisdotxt();   // volani funkce //

}

void del()
{
    int pom = 0;    // promenne //
    int dalsi;
    int radek;

    do
    {
        system("cls");  // vycisteni konzole //
        if (pom == 1)   // overeni podminky //
        {

            printf("zadal si spatne cislo radku, zkus to znova.");
            Sleep(3000);    // cekani //
            system("cls");  // vycisteni konzole //

        }

        pom = 0;
        show(0);    // volani funkce //
        printf("\n  Zadej cislo radku ktery chcete smazat:");
        scanf("%d", &radek);    //ukladani dat do promenne //
        radek--;
        pom = 1;

    } while (radek >= poradi || radek < 0); // podminka cyklu //

    system("cls");  // vycisteni konzole //
    printf("Jste si jisti ze chcete smazat tento zamek/hrad: %s, %s, %s, %s\nano/ne [a/n]\n", zamky[radek].nazev, zamky[radek].misto, zamky[radek].cena, zamky[radek].otvdoba);

    if (getch() == 'a') // overeni podminky //
    {

        for (radek; radek < poradi; radek++)
        {

            dalsi = radek + 1;
            strcpy(zamky[radek].nazev, zamky[dalsi].nazev); // nahrazeni radku jinym //
            strcpy(zamky[radek].misto, zamky[dalsi].misto); // nahrazeni mista jinym //
            strcpy(zamky[radek].cena, zamky[dalsi].cena);   // nahrazeni ceny jinou //
            strcpy(zamky[radek].otvdoba, zamky[dalsi].otvdoba);

        }

        poradi--;   // odecet od promenne //
        zapisdotxt();   // volani funkce //

    }

    printf("\nChcete smazat dalsi radek?\nano/ne [a/n]\n");
    if (getche() == 'a')    // overeni podminky //
        del();  // pri splneni podminky zavolani funkce del //

}

void zapisdotxt()
{
    FILE* wrt1; // promenna pro praci se soubory //
    wrt1 = fopen("databaze.txt", "w");   // // otevirani souboru, cestu k souboru a parametr jak se ma se souborem pracovat //

    for (int a = 0; a < poradi; a++)    // podminka pro ulozeni vsech radku do souboru //
    {

        fprintf(wrt1, "%s,%s,%s,%s\n", zamky[a].nazev, zamky[a].misto, zamky[a].cena, zamky[a].otvdoba); // psani do souboru //

    }
    fclose(wrt1);   // uzavreni souboru //
}

void hledat()
{

    char entr;  // promenne //
    int pismena = 0;
    char prom[30];
    int strg = 0;
    prom[0] = '\0'; // hodnota uvodni hodnoty v poli //

    system("cls");  // vycisteni konzole //
    printf("Zadejte Nazev:%s");
    scanf("%c", &entr); // vycisteni bufferu //
    scanf("%[^\n]", prom);  // nacteni dat do promenne //

    for (int a = 0; a < poradi; a++)    // podminka kontrolujici zda jiz nebyl prekrocen pocet radku v databazi //
    {

        while (zamky[a].nazev[pismena] == prom[pismena] && prom[pismena] != '\n') // podminka cyklu, pokud se vyhledavany text naleza v databazy a zaroven neni roven konci radku //
        {

            if (pismena < strlen(prom));    // kontrola probiha po jednom znaku, tato podminka tedy kontroluje zda jsme dosli ke konci slova //
            else    // pokud ano, nastavi hodnotu "strg" na jedna a kod muze pokracovat k vypisu // 
                strg = 1;
            pismena++;

        }
        if (strg == 1)
        {

            printf("%d) %s, %s, %s, %s\n", a, zamky[a].nazev, zamky[a].misto, zamky[a].cena, zamky[a].otvdoba);
            strg = 0;

        }

        pismena = 0;

    }

    entr = getche();    // precte znaky v konzoli //

}

void finboss()  // :) //
{

    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                      ________________________________________\n");
    printf("                                      \\    Projekt Databaze Hradu a Zamku    /\n");
    printf("                                       \\------------------------------------/\n");
    printf("                                        \\vytvoril: Filip Zadnik a Vit Urban/\n");
    printf("                                         \\________________________________/\n");
    Sleep(3000);

}


/*                  ____Shrek pro stesti :)____
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣄⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠟⠋⠙⠋⠉⠙⢷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣶⣶⣄⠀⠀⠀⢠⣾⣿⣁⡀⠀⠀⠀⠀⠀⠀⢑⣿⡆⠀⠀⠀⢠⣾⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣾⣦⡀⢠⣾⡿⣛⣛⡻⢷⣄⠀⠀⣴⣾⣿⠛⠻⠦⣄⣴⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠻⢿⣿⣿⣿⣿⣿⢿⣿⣿⣧⢼⣿⣿⣿⠿⣿⣇⢸⡟⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠿⢿⣾⣿⣤⠿⠋⠀⠈⠻⢿⣿⣧⣿⠟⣬⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠃⠀⠀⢀⣴⣖⣶⠀⠀⠀⠀⠀⢀⡈⠀⠀⢘⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣶⣶⣶⠿⠿⠿⠿⠷⠶⠶⠶⠛⠋⠻⣦⣤⣀⡼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡇⠀⣿⠻⢷⣤⣀⠀⠀⠀⠈⠀⠀⠀⣀⣈⡻⢿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⡿⠛⡏⠁⠂⠘⠭⢿⣒⣒⡒⠒⠒⠊⠉⠁⠀⠀⣿⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠟⠁⡄⠣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡌⠙⠲⣤⣀⠠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣏⠀⠀⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠋⠀⠀⠀⠀⠈⠙⠚⠓⠶⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣶⣀⡴⠛⢷⣄⣠⣄⡀⠀⠀⠀⠀⠀⠀⠀⠐⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠳⢦⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⠴⠾⣿⣿⣿⣿⣿⠟⠛⠿⣿⣦⣄⠙⢻⣿⣷⣦⡤⠤⠶⠒⠛⠁⣠⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢠⣴⡾⠏⠁⠀⠀⠀⠀⠰⠿⠟⠋⠀⠀⠀⠀⠈⠉⠛⠙⠋⠉⠉⠀⠀⠀⠀⠀⣀⡴⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣾⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢉⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⠀⠀⠀
⠀⠀⠀⠀⢄⣾⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⢸⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣧⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣧⠀⠀⠀
⠀⠀⠀⠀⣼⣋⣧⣶⠀⠀⠀⢀⡀⣀⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⣼⣿⣿⣟⣤⡀⠀⠀⠀⠀⠀⠀⠘⣦⠀⠀
⠀⠀⠀⠀⣿⡟⡇⣿⣤⣤⣴⣼⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣷⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠏⣴⣿⣿⠋⠉⠉⠛⠋⡄⠂⠀⠀⠀⠀⠈⣇⠀
⠀⠀⠀⢀⣿⣷⣜⢿⣿⣿⣿⣿⣿⣿⣟⢿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⠾⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠐⠖⣠⣶⣿⣟⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡀
⠀⠀⢀⣾⠋⠻⣿⡶⠍⠙⠛⢿⣿⣿⣿⣮⡙⠿⣿⣶⣤⣄⣀⣤⣤⣤⣤⡀⢀⣈⣁⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇
⠀⠀⣾⠇⠀⠀⠘⢷⡇⠀⠀⠀⢿⣿⣿⣿⣿⣶⣼⣿⣿⣟⣻⣿⣿⣿⣿⡿⠟⠛⠁⠀⠉⠻⢿⣿⣶⣤⣴⣶⣶⣤⣶⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇
⠀⢸⣿⠀⠀⠀⢠⡞⠀⠀⠀⠀⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣋⣠⣀⠀⠀⠀⠀⠀⠀⠀⢉⣛⢻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀
⠀⢸⡏⠀⠀⠀⣼⠁⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠿⡿⠛⠉⠉⠉⠁⠀⢀⠀⠀⠀⠀⠀⠉⠰⠿⠿⠛⠻⠟⠉⠁⢩⢹⣿⣿⣄⠀⠸⣆⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀
⠀⣿⢿⠀⠀⣰⠇⠀⠀⠀⠀⠀⣿⡟⢻⣿⣿⣿⣿⣿⡟⠻⢶⣤⠀⠀⠀⠀⠀⠀⠀⢸⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⢿⣿⣿⣦⠀⢹⣆⠀⠀⠀⠀⠀⠀⠀⡇⠀
⢀⡟⠺⠀⢐⡿⠀⠀⠀⠀⢀⣼⣿⠁⠀⢻⣿⣿⣿⣿⣿⣷⣤⣿⣤⣤⣤⣤⣶⡄⠀⠀⣿⣇⣤⣤⣀⣀⡀⠀⠀⠀⠀⠀⠈⢿⣷⣿⡾⠁⢿⣿⣷⣿⣿⡷⠀⠀⠀⠀⠀⠀⡇⠀
⢸⡇⠀⠘⣿⡁⠀⠀⢀⣰⣿⣿⠃⠀⠀⠀⢻⣿⣽⠋⠛⢯⢿⣿⠛⠛⠋⠉⠙⠛⠲⣄⠉⠉⠁⠈⠉⠙⠛⠷⣦⣤⣤⣌⠀⠀⢸⡟⠁⠀⠀⠻⣿⣿⣿⣍⠀⠀⠀⠀⠀⠀⢧⠀
⢸⠁⠀⠀⢹⣷⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⢸⣿⢢⠀⠂⠀⣭⣿⡀⠀⠀⠀⠀⠀⠀⢸⡉⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀⠀⢹⣿⡿⠉⠀⠀⠀⠀⠀⠀⡾⠀
⠀⠀⠀⠀⠀⠋⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⣼⣏⠈⠁⢰⠀⢨⣿⣧⣀⡀⣠⠀⠀⠀⣸⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⠀⠀⠀⠀⠀⣸⡍⠁⠀⠀⠀⠀⠀⠀⣠⣷⠀
⠀⠀⠀⠀⠀⠀⠙⢿⣿⡇⠀⠀⠀⠀⠀⢠⣿⠟⠇⠀⠈⠑⢦⣿⠿⠿⠿⠿⠶⢀⢀⣸⠿⣶⣦⣠⡖⠀⠀⠀⠀⠀⠀⠀⢀⣿⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠘⢻⡆
⠀⠀⠀⠀⠀⠀⠀⠀⣼⡇⠀⠀⠀⠀⠀⣸⡗⠀⠀⠀⠀⠀⠀⠙⠷⡄⣀⠀⠀⠻⠟⠃⠀⠀⠀⠀⠤⠀⠀⠀⠀⠀⠀⠀⣾⡟⠀⠀⠀⠀⠀⢰⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠹⠇⠀⠀⠀⠀⠀⣸⣿⠠⢰⣶⠄⠀⠀⠀⢀⣀⠀⢠⠀⠀⢠⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣙⣿⠁⠀⠀⠀⠀⠀⣸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠇
*/