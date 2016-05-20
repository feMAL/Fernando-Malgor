#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "lib.c"
#define A 5
#define V 5


int main()
{
    sVuelo Vuelos[V];
    sAvion Aviones[A];
    int passAv=0,passVue=0;
    char cont='s';

    if(iniAvion(Aviones,A)!=1)
    {
        printf("\n\t\t ERROR AL INICIALIZAR AVIONES\n\n");
    }else{}
    if(iniVuel(Vuelos,V)!=1)
    {
        printf("\n\t\t ERROR AL INICIALIZAR VUELOS\n\n");
    }else{}

    while(cont=='s')
    {
        switch(mEnu())
        {
            case 1:
                if(AltaAvion(Aviones,A) != 1)
                {
                    printf("\n\tError al Realizar el Alta Del Avion.\n\n");
                }else
                {
                    printf("\n\tOperacion Realizada con exito.\n\n");
                    passAv++;
                }
                break;
            case 2:
                if(passAv!=0)
                {
                    if(ModificoAvion(Aviones,A) != 1)
                    {
                        printf("\n\tError al Realizar el Modificacion Del Avion.\n\n");
                    }else
                    {
                        printf("\n\tOperacion Realizada con exito.\n\n");
                    }
                }else
                {
                    printf("\n\tDebe ingresar al menos un avion para poder modificarlo.\n\n");
                }
                break;
            case 3:
                if(passAv!=0)
                {
                    if(BajaAvion(Aviones,Vuelos,A,V) != 1)
                    {
                        printf("\n\tError al Realizar el Baja Del Avion.\n\n");
                    }else
                    {
                        printf("\n\tOperacion Realizada con exito.\n\n");
                    }
                }else
                {
                    printf("\n\t\tDebe ingresar al menos un avion para poder dar de Baja alguno.\n\n");
                }
                break;
            case 4:
                if(passAv!=0)
                {
                    if(altaVuelo(Vuelos,Aviones,V,A) != 1)
                    {
                        printf("\n\tError al Realizar el Alta Del Vuelo.\n\n");
                    }else
                    {
                        printf("\n\tOperacion Realizada con exito.\n\n");
                        passVue++;
                    }
                }else
                {
                    printf("\n\t\tDebe ingresar al menos un Avion para poder dar de alta un vuelo.\n\n");
                }
                break;
            case 5:
                if(passVue!=0)
                {
                    if(BajadeVuelo(Vuelos,V) != 1)
                    {
                        printf("\n\tError al Realizar la Suspencion Del Vuelo.\n\n");
                    }else
                    {
                        printf("\n\tOperacion Realizada con exito.\n\n");
                    }
                }else
                {
                    printf("\n\t\tDebe ingresar al menos un Vuelo para poder dar de baja un vuelo.\n\n");
                }
                break;
            case 6:
                if(passVue!=0)
                {
                    if(InformarVuelo(Vuelos,Aviones,V,A) != 1)
                    {
                        printf("\n\tError al informar detalles del Hangar.\n\n");
                    }else
                    {
                        printf("\n\tOperacion Realizada con exito.\n\n");
                    }
                }else
                {
                    printf("\n\t\tDebe ingresar al menos un Vuelo para poder informar los vuelos.\n\n");
                }
                break;
            case 7:
                if(passVue!=0)
                {
                    if(ListarVuelos(Vuelos,Aviones,A,V) != 1)
                    {
                        printf("\n\tError al listar Vuelos.\n\n");
                    }else
                    {
                        printf("\n\tOperacion Realizada con exito.\n\n");
                    }
                }else
                {
                    printf("\n\t\tDebe ingresar al menos un Vuelo para poder Listar los vuelos.\n\n");
                }
                break;
            case 8:
                cont='n';

                break;
        }
        system("PAUSE");
    }
    return 0;
}
