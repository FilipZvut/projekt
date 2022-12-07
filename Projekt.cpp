//Projekt databaze hradu a zamku
#include "Projekt.h"

int main()
{ 
    do      //cyklus volajici zakladni funkce behu programu, dokud neni zneplatnena podminka //
    {        

        zapisdopromene(); // volani funkce zapisu dat //  //asi se bude provádět pokaždý uvidíme
        menu(); // volani funkce s menu programu //
        
    } while (vybrat()); //podminka konce cylku // volani funkce zobrazujici upravy

    finboss(); // volani funkce, zaverecny titulku //
}
