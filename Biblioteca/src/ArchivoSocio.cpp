#include "ArchivoSocio.h"
#include "Socio.h"
#include <iostream>
using namespace std;

int AgregarRegistro(Socio soc){
    FILE *pSocio;
    pSocio=fopen("socios.dat", "ab");
    if(pSocio==nullptr) {
        cout << "Error de archivo" << endl;
        return -1;
    }

    fwrite(&soc, sizeof soc, 1, pSocio);

    fclose(pSocio);

    return 0;
}

int ListarRegistros(){
    Socio soc;
    FILE *pSocio;
    pSocio=fopen("socios.dat", "rb");

    if(pSocio==nullptr) {
        cout << "Error de archivo" << endl;
        return -1;
    }

    fread(&soc, sizeof soc, 1, pSocio);
    soc.MostrarSocio();

    fclose(pSocio);

    return 0;
}
