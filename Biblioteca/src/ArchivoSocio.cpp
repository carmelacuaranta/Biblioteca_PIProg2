#include "ArchivoSocio.h"
#include "Socio.h"
#include <iostream>
using namespace std;

int ArchivoSocio::AgregarRegistro(Socio soc){
    FILE *pSocio;
    pSocio=fopen("socios.dat", "ab");
    if(pSocio==nullptr) {
        cout << "Error de archivo." << endl;
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
        cout << "Error de archivo." << endl;
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
        cout << "Error de archivo." << endl;
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

bool ArchivoSocio::BuscarSocioPorID(int idBuscado) {
    FILE* p = fopen("socios.dat", "rb");
    if (p == nullptr) {
        std::cout << "No se pudo abrir el archivo.\n";
        return false;
    }

    Socio soc;
    while (fread(&soc, sizeof(Socio), 1, p) == 1) {
        if (soc.getId() == idBuscado) {
            cout << "Socio encontrado: " << endl;
            soc.MostrarSocio();
            fclose(p);
            return true;
        }
    }

    std::cout << "No se encontró un socio con ese ID.\n";
    fclose(p);
    return false;
}

#include <cstring> // Para strcmp

bool ArchivoSocio::BuscarSocioPorNombre(const char* nombreBuscado) {
    FILE* p = fopen("socios.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return false;
    }

    Socio soc;
    bool encontrado = false;

    while (fread(&soc, sizeof(Socio), 1, p) == 1) {
        if (strcmp(soc.getNombre(), nombreBuscado) == 0) {
            cout << "Socio encontrado: " << endl;
            soc.MostrarSocio();
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontró un socio con ese nombre." << endl;

    fclose(p);
    return encontrado;
}
