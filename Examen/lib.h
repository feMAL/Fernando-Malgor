#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

/** \brief  Se definen las estructuras a desarrollar
 *
 * \struct sVuelo Contendra los datos del usuario
 * \struct sAvion Contentra los datos de cada comentario.
 *
 */

typedef struct{
    int idVuelo;
    int Hora;
    int Min;
    char destino[30];
    char Origen[30];
    int matAv;
}sVuelo;

typedef struct{
    int aMatricula;
    char aFabricante[15];
    char aModel[15];
    int aInfodeCap;
    int aAutoVuel;
    int CantVuel;
}sAvion;

int iniVuel(sVuelo*,int);
int iniAvion(sAvion*,int);
int mEnu();
int altaVuelo(sVuelo*,sAvion*, int, int);
int AltaAvion(sAvion*,int);
int buscarAvionLibre(sAvion*,int);
int buscarVueloLibre(sVuelo*, int);
int buscarMat(sAvion*,int,int);
int buscarIDVuelo(sVuelo*,int,int);
int BajadeVuelo(sVuelo*,int);
int BajaAvion(sAvion*,sVuelo*,int,int);
int ModificoAvion(sAvion*,int);
int ListarVuelos(sVuelo*,sAvion*,int,int);
//int cargaTABLAVuelos(sAvporVuel*,sVuelo*,sAvion*,int);
void mostrarAvion(sAvion);
void mostrarVuelo(sVuelo);
void mostrarListado(sAvion,sVuelo);
int mostrarVuelos(sVuelo*,int);
int InformarVuelo(sVuelo*,sAvion*,int,int);
int opcionesDeCarga();

 //Validaciones
int validarSiNo(char);
int valNro(int, int,int);
int valSTR(char*,int);


#endif // LIB_H_INCLUDED
