#include "lib.h"

/** \brief Se imprime el menu donde se elije el tipo de carga que se utilizará
 *
 * \return Retorna la opcion seleccionada por el usuario
 *
 */

int opcionesDeCarga()
{
    int op;
    system("CLS");
    printf("\n\nOPCIONES DE CARGA.\n\t\t1-CARGA AUTOMATICA\n\t\t2-CARGA MANUAL\t");
    scanf("%d",&op);
    op=valNro(op,1,2);
    return op;
}

/** \brief Se imprime el menu y se pide la accion a seguir
 *
 * \return Retorna la opcion seleccionada por el usuario
 *
 */


int mEnu()
{
    int op;
    system("CLS");
    printf(" ---------------------------------\n");
    printf("|\tHangar 2016 PADRON S.A    |\n");
    printf("|\t\t  ABM Multi\t  |\n");
    printf("|\t\t by FEMA\t  |\n");
    printf(" ---------------------------------\n");
    printf("\nOPCIONES:\n\n\t1.Alta de Avion\n\t2.Modificar Datos del Avion\n\t3.Baja del Avion");
    printf("\n\t4.Nuevo Vuelo\n\t5.Suspender Vuelo");
    printf("\n\t6.Informar\n\t7.Listar\n\t8.SALIR\n\t\t");
    scanf("%d",&op);
    op=valNro(op,0,9);
    //VALIDO OP
    return op;
}

/** \brief Se Informan los resultados de los vuelos Avion con mayor cantidad de vuelos y modelo mas usado
 *  \param Se pasa un puntero a la estructura Vuelos
 *  \param Se pasa un puntero a la estructura Aviones
 *  \param Se pasa el tamaño de la estructura Vuelos
 *  \param Se pasa el tamaño de la estructura Aviones
 *  \return Retorna -1 si falla 1 si la ejecucion termino con exito.
 */

int InformarVuelo(sVuelo* Vuelos, sAvion *Aviones ,int tamAv,int tamVue)
{
    int ok=-1,MaxMat=0,ContAux=0,r,p,MaxVuel=0,POS=0,cMaxMod=0;
    char MaxMod[15];
    //sAvporVuel tabVuelodeAv[tamVue];

    system("CLS");
    printf("\n\tINFORME DEL HANGAR.\n\n");
   // cargaTABLAVuelos(tabVuelodeAv,Aviones, Vuelos, tamVue);
    for(r=0;r<tamAv-2;r++)
    {
        if(Aviones[r].aMatricula!=-1)
        {
            for(p=r+1;p<tamAv-1;p++)
            {
                if(strcmp(Aviones[r].aModel,Aviones[p].aModel)==1 && Vuelos[p].idVuelo!=-1)
                {
                    ContAux++;
                }
            }
            if(ContAux!=0)
            {
                cMaxMod=ContAux;
                strcpy(MaxMod,Aviones[r].aModel);
            }else if(ContAux>cMaxMod)
            {
                cMaxMod=ContAux;
                strcpy(MaxMod,Aviones[r].aModel);
            }
        }
    }
    printf("\tEl Modelo de Avion mas utilizado es: %s\n",MaxMod);
    ContAux=0;
    for(r=0;r<tamAv-1;r++)
    {
        for(p=0;p<tamVue-1;p++)
        {
            if(Aviones[r].aMatricula==Vuelos[p].matAv)
            {
                ContAux++;
            }
        }

       if(r==0)
        {
            MaxVuel=ContAux;
            MaxMat=Aviones[r].aMatricula;
        }else if(ContAux>MaxVuel)
        {
            MaxVuel=ContAux;
            MaxMat=Aviones[r].aMatricula;
        }
    }
    printf("\n\tEl Avion con mayor cantidad de Vuelos. Cantidad de Vuelos: %d\n",MaxVuel);
    POS=buscarMat(Aviones,tamAv,MaxMat);
    mostrarAvion(Aviones[POS]);
    ok=1;

    return ok;
}

/** \brief Se muestra el Vuelo que se envia por parametro.
 *  \param Se pasa un posicion del puntero a Vuelos.
 *  \return No retorna nada.
 */

void mostrarVuelo(sVuelo Vuelo)
{
    if(Vuelo.idVuelo!=-1)
    {
        printf("\n ----------------------------------------------------");
        printf("\n|\tMatricula del avion que realiza el vuelo: %d\t|",Vuelo.matAv);
        printf("\n|\tID de Vuelo: %d\t|",Vuelo.idVuelo);
        printf("\n|\tHorario %d:%d\t|",Vuelo.Hora,Vuelo.Min);
        printf("\n|\tOrigen: %s\t\t |",Vuelo.Origen);
        printf("\n|\tDestino: %s\t\t|",Vuelo.destino);
        printf("\n ----------------------------------------------------\n");
    }
}

/** \brief Se muestra el Avion que se envia por parametro.
 *  \param Se pasa un posicion del puntero a Avion.
 *  \return No retorna nada.
 */

void mostrarAvion(sAvion Avion)
{
    if(Avion.aMatricula!=-1)
    {
        printf("\n ----------------------------------------------------");
        printf("\n|\tMatricula del avion: %d\t|",Avion.aMatricula);
        printf("\n|\tFabricante: %s\t",Avion.aFabricante);
        printf("\n|\tModelo: %s\t",Avion.aModel);
        printf("\n|\tCantidad de pasajeros: %d\t\t",Avion.aInfodeCap);
        printf("\n|\tAutonomia de Vuelo: %d\t",Avion.aAutoVuel);
        printf("\n ----------------------------------------------------\n");
    }
}

/** \brief Se Valida Si o No
 *
 *  \param Se pasa el caracter ingresado
 *  \return Retorna 1 si acepta 0 si no acepta
 */

int validarSiNo(char valor)
{
    int val=0;
    char valdef=tolower(valor);

    if(valdef== 's')
    {
        val=1;
    }
    return val;
}

void BajadeVuelosXAvion(sVuelo *Vuelos,int tamVu,int Mat)
{
    int r;
    for(r=0; r<tamVu-1;r++)
    {
        if(Vuelos[r].matAv==Mat)
        {
            Vuelos[r].idVuelo=-1;
        }
    }
}

/** \brief Se da baja un Avion. ingresando alguna matricula de Aviones valido
 *  \param Se pasa un puntero a la estructura Aviones
 *  \param Se pasa el tamaño de la estructura Aviones
 *  \return Retorna -1 si falla 1 si la ejecucion termino con exito.
 */

int BajaAvion(sAvion* Aviones,sVuelo* Vuelos,int Tam, int tamVu)
{
    int ok=-1,mat,indice;
    char cont=' ';
    system("CLS");
    printf("\nBAJA DE AVIONES\n\n\tIngrese la matricula del avion que desea dar de baja.\t");
    scanf("%d",&mat);
    valNro(mat,1,1000);
    indice=buscarMat(Aviones,Tam,mat);
    if(indice==-1)
    {
        printf("\n\n\tMatricula no Existe\n");
    }else
    {
        printf("\n\tEl Avion que desea dar de baja es:\n");
        mostrarAvion(Aviones[indice]);
        printf("\n\tEsta seguro que desea eliminar? S/N\n");
        scanf("%c",&cont);
        cont= tolower(cont);
        while(cont!='s'&&cont!='n')
        {
            printf("\n\tEsta seguro que desea eliminar? S/N\n");
            scanf("%c",&cont);
            cont=tolower(cont);
        }
        if(cont=='s')
        {
            Aviones[indice].aMatricula=-1;
            BajadeVuelosXAvion(Vuelos,tamVu,mat);
            ok=1;
        }else
        {
            printf("\n\n\t\tHaz Cancelado la Baja.\n");
            ok=1;
        }
    }
    return ok;
}

/** \brief Se un numero en un determinado rango
 *  \param Se pasa el numero a validar
 *  \param Se pasa el limite minimo
 *  \param Se pasa el limite maximo
 *  \return Retorna un numero valido
 */

int valNro(int aux, int limmin,int limmax)
{
    while(aux<limmin || aux>limmax)
    {
        printf("\n\nt\tError.Reingrese el valor.\t");
        scanf("%d",&aux);
    }
    return aux;
}

/** \brief Se Modifica los datos del avion
 *  \param Se pasa un puntero a la estructura Aviones
 *  \param Se pasa el tamaño de la estructura Aviones
 *  \return Retorna -1 si falla 1 si la ejecucion termino con exito.
 */

int ModificoAvion(sAvion *Avion,int TAM)
{
    int ok =-1, indice,capacidad, AutonVuel;
    char fabricante[15], modelo[15];
    int mat,opM;

    system("CLS");
    printf("\nMODIFICACION DE AVIONES\n");
    printf("\n\tIngrese la matricula del avion que desea modificar.");
    scanf("%d", &mat);
    indice=buscarMat(Avion,TAM,mat);
    if (indice==-1)
    {
        printf("\n\n\tMatricula no Existe\n\n");
    }else
    {
        printf("\n\tIngrese la opcion que desea modificar\n\t1- Fabricante\n\t2- Modelo\n\t3- Capacidad\n\t4-Autonomia.\t");
        scanf("%d",&opM);
        opM=valNro(opM,1,4);
        switch(opM)
        {
        case 1:
            printf("\n\t Modifica Fabricante.\t");
            printf("\n\t Ingrese el fabricante del Avion\t");
            fflush(stdin);
            gets(fabricante);
            strcpy(Avion[indice].aFabricante,fabricante);

            ok=1;
            break;
        case 2:
            printf("\n\t Modifica Modelo.\t");
            printf("\n\tIngrese el modelo del Avion\t");
            fflush(stdin);
            gets(modelo);
            strcpy(Avion[indice].aModel,modelo);

            ok=1;
            break;
        case 3:
            printf("\n\tIngrese la capacidad maxima de pasajeros del Avion.\t");
            scanf("%d",&capacidad);
            capacidad=valNro(capacidad,0,1000);
            Avion[indice].aInfodeCap=capacidad;
            ok=1;
            break;
        case 4:
            printf("\n\tIngrese la autonomia de vuelo del Avion en HS.\t");
            scanf("%d",&AutonVuel);
            AutonVuel=valNro(AutonVuel,0,50000);
            Avion[indice].aAutoVuel=AutonVuel;
            ok=1;
            break;
        default:
            break;
        }
    }
    return ok;
}

 /** \brief Listar los Vuelos Ordenandolos por Distintos criterios
 *  \param Se pasa un puntero a la estructura Vuelos
 *  \param Se pasa un puntero a la estructura Aviones
 *  \param Se pasa el tamaño de la estructura Vuelos
 *  \param Se pasa el tamaño de la estructura Aviones
 *  \return Retorna -1 si falla 1 si la ejecucion termino con exito.
 */

int ListarVuelos(sVuelo *Vuelos,sAvion *Avion, int tamAv, int tamVu)
{
    int ok=-1,r,t,indice=0,indice2=0;
    sVuelo AuxVuel;
 //   sAvion AuxAvion;

    system("CLS");
    printf("\nLISTADO DE VUELOS.\n");
    for(r=0;r<tamVu-1;r++)
    {
        for(t=r+1;t<tamVu-2;t++)
        {
            if(strcmp(Vuelos[r].Origen,Vuelos[t].Origen)==0)
            {
                indice=buscarMat(Avion,tamAv,Vuelos[r].matAv);
                indice2=buscarMat(Avion,tamAv,Vuelos[t].matAv);

                if(strcmp(Avion[indice].aModel,Avion[indice2].aModel)==1)
                {
                    //mostrarListado(Avion[indice],Vuelos[r]);
                }
            }else if(strcmp(Vuelos[r].Origen,Vuelos[t].Origen)==-1)
            {
                AuxVuel = Vuelos[r];
                Vuelos[r] = Vuelos[t];
                Vuelos[t] = AuxVuel;
            }
        }
    }
    return ok;
}

/** \brief Se da de alta un vuelo. ingresando alguna matricula valida de un avion
 *  \param Se pasa un puntero a la estructura Vuelos
 *  \param Se pasa un puntero a la estructura Aviones
 *  \param Se pasa el tamaño de la estructura Vuelos
 *  \param Se pasa el tamaño de la estructura Aviones
 *  \return Retorna -1 si falla 1 si la ejecucion termino con exito.
 */

int altaVuelo(sVuelo *Vuelos,sAvion *Avion,int tamVue,int tamAv)
{
    int ok=-1,indice,matri,posVuel;
    int idVuelo,hrV,minV;
    char destinoV[30],origenV[30];

    system("CLS");
    printf("\nALTA DE VUELOS.\n\n\tIngrese la matricula del avion para Asignarle el vuelo.\t");
    scanf("%d",&matri);
    indice = buscarMat(Avion,tamAv,matri);
    if(indice!=-1)
    {
        posVuel=buscarVueloLibre(Vuelos,tamVue);
        if(posVuel==-1)
        {
            printf("\n\tNo hay espacios para cargar mas vuelos.\t\n\n");
        }else
        {
            printf("\n\t DATOS DEL AVION.\n\tMatricula:%d\n\tModelo:%s\n\tFabricante:%s\n\tCapacidad:%d.\n", Avion[indice].aMatricula, Avion[indice].aModel, Avion[indice].aFabricante, Avion[indice].aInfodeCap);
            printf("\nIngrese el ID del vuelo:\t");
            scanf("%d",&idVuelo);
            idVuelo=valNro(idVuelo,1,1000);
            printf("\nIngrese Hora de salida del Vuelo.\t");
            scanf("%d",&hrV);
            hrV=valNro(hrV,0,23);
            printf("\nIngrese minutos de salida del Vuelo.\t");
            scanf("%d",&minV);
            minV=valNro(minV,0,23);
            printf("\nIngrese Aeropuerto de Origen.\t");
            fflush(stdin);
            gets(origenV);
            printf("\nIngrese Aeropuerto de Destino.\t");
            fflush(stdin);
            gets(destinoV);
            //CARGA de la ESTRUCTURA
            Vuelos[posVuel].idVuelo =idVuelo;
            Vuelos[posVuel].matAv = Avion[indice].aMatricula;
            Vuelos[posVuel].Hora=hrV;
            Vuelos[posVuel].Min=minV;
            strcpy(Vuelos[posVuel].destino,destinoV);
            strcpy(Vuelos[posVuel].Origen,origenV);
            ok=1;
        }

    }else{
        printf("\nImposible encontrar la matricula del avion.\t");
    }
    return ok;
}

/** \brief Se da baja un vuelo. ingresando algun ID de vuelo Valido
 *  \param Se pasa un puntero a la estructura Vuelos
 *  \param Se pasa el tamaño de la estructura Vuelos
 *  \return Retorna -1 si falla 1 si la ejecucion termino con exito.
 */

int BajadeVuelo(sVuelo *Vuelos,int tam)
{
    int ok=-1,auxmat,indice;
    char cont=' ';

    system("CLS");
    printf("\nBAJA DE VUELOS.\n\nIngrese el ID de vuelo que desea dar de baja.\t\n");
    scanf("%d",&auxmat);
    auxmat = valNro(auxmat,1,1000);
    indice= buscarIDVuelo(Vuelos,tam,auxmat);
    if(indice!=-1)
    {
        printf("\n\tEl Vuelo que desea dar de baja es:\n");
        mostrarVuelo(Vuelos[indice]);
        printf("\n\tEsta seguro que desea eliminar? S/N\n");
        scanf("%c",&cont);
        cont= tolower(cont);
        while(cont!='s'&&cont!='n')
        {
            printf("\n\tEsta seguro que desea eliminar? S/N\n");
            scanf("%c",&cont);
            cont=tolower(cont);
        }
        if(cont=='s')
        {
            Vuelos[indice].idVuelo=-1;
            ok=1;
        }else
        {
            printf("\n\n\t\tHaz Cancelado la Baja.\n");
            ok=1;
        }
    }else
    {
          printf("\n\n\tID de Vuelo no Existe");
    }

    return ok;
}

/** \brief Se busca IDVuelo en el Array de vuelos y se devuelve la posicion de ese ID.
 *  \param Se pasa un puntero a la estructura Vuelos
 *  \param Se pasa el tamaño de la estructura Vuelos
 *  \param Se pasa el ID del Vuelo
 *  \return Retorna la posicion en el array del ID buscado
 */

int buscarIDVuelo(sVuelo *Vuelos,int TAM,int ID)
{
    int ok=-1,r;
    for(r=0;r<TAM;r++)
    {
        if(Vuelos[r].idVuelo==ID)
        {
            //printf("Encontrado %d",r);
            ok=r;
            break;
        }
    }
    return ok;
}

/** \brief Se busca la Matricula de un avion en el Array de Aviones y se devuelve la posicion de esa matricula.
 *  \param Se pasa un puntero a la estructura Aviones
 *  \param Se pasa el tamaño de la estructura Aviones
 *  \param Se pasa la matricula del Vuelo
 *  \return Retorna la posicion en el array del ID buscado
 */

int buscarMat(sAvion *Aviones,int TAM,int mat)
{
    int ok=-1,r;
    for(r=0;r<TAM;r++)
    {
        if(Aviones[r].aMatricula==mat)
        {
            //printf("Encontrado %d",r);
            ok=r;
            break;
        }
    }
    return ok;
}

/** \brief Se da de alta un Avion. permitiendote elegir 2 modos de carga, Automatica y manual.
 *  \param Se pasa un puntero a la estructura Aviones
 *  \param Se pasa el tamaño de la estructura Aviones
 *  \return Retorna -1 si falla 1 si la ejecucion termino con exito.
 */

int AltaAvion(sAvion* Aviones,int TAM)
{
    //Variables de control.
    int r=0,ok=-1,op;

    //Variables de carga Manual.
    int indice,matAv,capaci,AutonVuel;
    char fabricante[15],modelo[15];


    /*VARIABLES DE CARGA AUTOMATICA*/
    int matriculas[5]={1,2,3,4,5};
    char Fabricantes[15][5]={"HONDA","BMW","MERCEDES","VELTA","AIRLINE"};
    char modelos[15][5]={"x923","747","442","747","5312"};
    int horasVuelo[5]={1500,1240,350,4056,1234};
    int capa[5]={450,550,600,300,1000};


    op = opcionesDeCarga();

    system("CLS");
    if(op==2)
    {
        indice = buscarAvionLibre(Aviones,TAM);
        if(indice==-1)
        {
            printf("\n\n\tNo hay lugares disponibles\n\n");
            system("PAUSE");
        }else
        {
            printf("\n\tALTA MANUAL DEL AVION\n\n\tIngrese la Matricula del Avion.\t");
            scanf("%d",&matAv);
            //matAv=valNro(matAv,0,1000);
            Aviones[indice].aMatricula=matAv;

            printf("\n\tIngrese el fabricante del Avion\t");
            fflush(stdin);
            gets(fabricante);
            strcpy(Aviones[indice].aFabricante,fabricante);

            printf("\n\tIngrese el modelo del Avion\t");
            fflush(stdin);
            gets(modelo);
            strcpy(Aviones[indice].aModel,modelo);

            printf("\n\tIngrese la capacidad maxima de pasajeros del Avion.\t");
            scanf("%d",&capaci);
            capaci=valNro(capaci,0,1000);
            Aviones[indice].aInfodeCap=capaci;

            printf("\n\tIngrese la autonomia de vuelo del Avion en HS.\t");
            scanf("%d",&AutonVuel);
            AutonVuel=valNro(AutonVuel,0,50000);
            Aviones[indice].aAutoVuel=AutonVuel;

            ok=1;
        }
    }else
    {
        for(r=0;r<TAM-1;r++)
        {
            Aviones[r].aMatricula=matriculas[r];
            strcpy(Aviones[r].aFabricante,Fabricantes[r]);
            strcpy(Aviones[r].aModel,modelos[r]);
            Aviones[r].aInfodeCap=capa[r];
            Aviones[r].aAutoVuel=horasVuelo[r];
            if(r==TAM-1)
            {
                ok=1;
            }
        }
    }
    return ok;
}

/*int ValSTR(char* STRNG, int Tama)
{
    int ok=-1,r;
    for(r=0; r<strlen(STRNG)-1; r++)
    {
        if(STRNG[r]=='\0')
        {
            ok=1;
            break;
        }
    }
    return ok;
}*/

/** \brief Se busca la posicion libre mas proxima, dentro del array Vuelos
 *  \param Se pasa un puntero a la estructura Vuelos
 *  \param Se pasa el tamaño de la estructura Vuelos
 *  \return Retorna la posicion libre encontrada o -1 si falla no lo encuentra
 */

int buscarVueloLibre(sVuelo *Vuelos,int Tam)
{
    int ok=-1,r;

    for(r=0; r<Tam-1; r++)
    {
        if(Vuelos[r].idVuelo == -1)
        {
            ok=r;
            break;
        }
    }
    return ok;
}
/** \brief Se busca la posicion libre mas proxima, dentro del array Aviones
 *  \param Se pasa un puntero a la estructura Aviones
 *  \param Se pasa el tamaño de la estructura Aviones
 *  \return Retorna la posicion libre encontrada o -1 si falla no lo encuentra
 */

int buscarAvionLibre(sAvion *Avion,int Tam)
{
    int ok=-1,r;

    for(r=0; r<Tam-1; r++)
    {
        if(Avion[r].aMatricula == -1)
        {
            ok=r;
            break;
        }
    }
    return ok;
}
/** \brief Inicializa las matriculas de los aviones en -1 permitiendo el ingreso de datos
 *  \param Se pasa un puntero a la estructura Vuelos
 *  \param Se pasa el tamaño de la estructura Vuelos
 *  \return Retorna la posicion libre encontrada o -1 si falla no lo encuentra
 */

int iniVuel(sVuelo *x,int cant)
{
    int r,p=0;
    for(r=0;r<cant;r++)
    {
        x[r].idVuelo=-1;
        if(cant-1==r)
        {
            p=1;
        }
    }
    return p;
}

/** \brief Inicializa las matriculas de los aviones en -1 permitiendo el ingreso de datos
 *  \param Se pasa un puntero a la estructura Aviones
 *  \param Se pasa el tamaño de la estructura Aviones
 *  \return Retorna la posicion libre encontrada o -1 si falla no lo encuentra
 */
int iniAvion(sAvion *x,int cant)
{
    int r,p=0;
    for(r=0;r<cant;r++)
    {
        x[r].aMatricula =-1;
        if(cant-1==r)
        {
            p=1;
        }
    }
    return p;
}
