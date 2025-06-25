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

bool ArchivoSocio::cargaVariosAux(){
    FILE* p = fopen("socios.dat", "ab");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return false;
    }
    Fecha fecha = Fecha(10,10,1980);
    Socio aux1 =  Socio(1, 01, "24908987", "Juan", "Sosa", "1234", "Wallaby 12", "jsosa@mail.com", fecha);
    fwrite(&aux1, sizeof aux1, 1, p);

    fecha.setAnio(1990);
    fecha.setMes(3);
    fecha.setDia(22);
    Socio aux2 =  Socio(2, 02, "33926749", "Juana", "LopezGomez", "1234", "Calle Falsa 123", "jgomez@mail.com", fecha);
    fwrite(&aux2, sizeof aux2, 1, p);

    fecha.setAnio(2000);
    fecha.setMes(1);
    fecha.setDia(12);
    Socio aux3 =  Socio(3, 03, "44908987", "Maria", "Lopez", "1234", "Private Drive 4", "mlopez@mail.com", fecha);
    fwrite(&aux3, sizeof aux3, 1, p);

    fecha.setAnio(1985);
    fecha.setMes(10);
    fecha.setDia(5);
    Socio aux4 =  Socio(4, 04, "39483481", "Pedro", "Gimenez", "1234", "Siempreviva 742", "pgimenez@mail.com", fecha);
    fwrite(&aux4, sizeof aux4, 1, p);

    fclose(p);
}
