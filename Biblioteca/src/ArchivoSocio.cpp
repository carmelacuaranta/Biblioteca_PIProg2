#include "ArchivoSocio.h"
#include "Socio.h"
#include <iostream>
using namespace std;

int ArchivoSocio::AgregarRegistro(Socio soc){
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

bool ArchivoSocio::ListarRegistros(){
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

int ArchivoSocio::ListarSocios() {
    FILE* pSocio = fopen("socios.dat", "rb");
    if (pSocio == nullptr) {
        cout << "No se pudo abrir el archivo de socios." << endl;
        return -1;
    }

    Socio soc;
    cout << "LISTADO DE SOCIOS:" << endl << "-------------------" << endl;

    while (fread(&soc, sizeof(Socio), 1, pSocio) == 1) {
        soc.MostrarSocio();
        cout << "-------------------" << endl;
    }

    fclose(pSocio);
    return 0;
}
