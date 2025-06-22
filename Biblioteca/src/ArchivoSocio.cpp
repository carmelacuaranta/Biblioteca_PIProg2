#include "ArchivoSocio.h"
#include "Socio.h"
#include <iostream>
using namespace std;

int ArchivoSocio::agregarRegistro(Socio soc){

    //para controlar que no exista el ID
    bool idRepetido=false;
    FILE* archivoSocioLectura = fopen("socios.dat","rb");
    if (archivoSocioLectura !=nullptr) {
        Socio socioGuardado;
        while (fread(&socioGuardado, sizeof(Socio),1,archivoSocioLectura) == 1){
            if (socioGuardado.getId() == soc.getId()) {
                cout << "Id repetido, no se puede guardar el socio." << endl;
                idRepetido=true;
                fclose(archivoSocioLectura);
                return -2;
            }
        }
        fclose(archivoSocioLectura);
    }

    // para controlar que el mail tenga un @
    bool tieneArroba = false;
    const char* email = soc.getEmail();
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            tieneArroba = true;
            break;
        }
    }

if (!tieneArroba) {
    cout << "El formato del email es incorrecto. Debe contener @. No se podra guardar." << endl;
}


    FILE *pSocio;
    pSocio=fopen("socios.dat", "ab");
    if(pSocio==nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    if (tieneArroba == true && idRepetido == false){
        fwrite(&soc, sizeof soc, 1, pSocio);
        cout << "Socio guardado correctamente." << endl;
    }

    fclose(pSocio);


    return 0;
}

/* esta función no la estamos usando mas

bool ArchivoSocio::listarRegistros(){
    Socio soc;
    FILE *pSocio;
    pSocio=fopen("socios.dat", "rb");

    if(pSocio==nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    fread(&soc, sizeof soc, 1, pSocio);
    soc.mostrarSocio();

    fclose(pSocio);

    return 0;
}
*/

int ArchivoSocio::listarSocios() {
    FILE* pSocio = fopen("socios.dat", "rb");
    if (pSocio == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    Socio soc;
    cout << "LISTADO DE SOCIOS:" << endl << "-------------------" << endl;

    while (fread(&soc, sizeof(Socio), 1, pSocio) == 1) {
        soc.mostrarSocio();
        cout << "-------------------" << endl;
    }

    fclose(pSocio);
    return 0;
}

bool ArchivoSocio::buscarSocioPorID(int idBuscado) {
    FILE* p = fopen("socios.dat", "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo.\n";
        return false;
    }

    Socio soc;
    while (fread(&soc, sizeof(Socio), 1, p) == 1) {
        if (soc.getId() == idBuscado) {
            cout << "Socio encontrado: " << endl;
            soc.mostrarSocio();
            fclose(p);
            return true;
        }
    }

    cout << "No se encontro un socio con ese ID.\n";
    fclose(p);
    return false;
}

#include <cstring> // Para strcmp

bool ArchivoSocio::buscarSocioPorNombre(const char* nombreBuscado) {
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
            soc.mostrarSocio();
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontro un socio con ese nombre." << endl;

    fclose(p);
    return encontrado;
}
