#include "ArchivoSocio.h"
#include "Socio.h"
#include <iostream>
#include <cstring>
using namespace std;

int ArchivoSocio::agregarRegistro(Socio soc){
    system("cls");
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
            if(soc.getEstado()==true){
                soc.mostrarSocio();
                cout << "-------------------" << endl;
            }
    }

    fclose(pSocio);
    return 0;
}

int ArchivoSocio::buscarSocioPorID(int idBuscado) {
    FILE* p = fopen("socios.dat", "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo."<< endl;
        return -1;
    }

    Socio soc;
    int pos=0;
    while (fread(&soc, sizeof(Socio), 1, p) == 1) {
        if (soc.getId() == idBuscado) {
            cout << "Socio encontrado: " << endl;
            soc.mostrarSocio();
            fclose(p);
            return pos;
        }
        pos++;
    }

    cout << "No se encontro un socio con ese ID."<< endl;
    fclose(p);
    return -1;
}

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
    cout << "Se han cargado 4 socios" << endl;
}

Socio ArchivoSocio::leerRegistro(int pos){
    Socio soc;
    FILE *pSocio;
    pSocio = fopen("socios.dat","rb");
    if(pSocio==nullptr){
        cout << "Eror de archivo." << endl;
        return soc;
    }
    fseek(pSocio,pos*tamanioRegistro,0);
    fread(&soc, tamanioRegistro, 1, pSocio);
    fclose(pSocio);
    return soc;
}

bool ArchivoSocio::bajaLogica(){
    Socio soc;
    ArchivoSocio archiSocio("socios.dat");
    int id;
    cout << "ingresar id del socio a eliminar: ";
    cin >> id;
    int encontro = archiSocio.buscarSocioPorID(id);
    if (encontro < 0){
        cout << "No existe un socio con ese id." << endl;
        return false;
    }
    soc=archiSocio.leerRegistro(encontro);
    if (soc.getEstado()==false){
        cout << "El socio ya estaba eliminado. " << endl;
        return false;
    } else {
        soc.setEstado(false);
        if(archiSocio.modificarRegistro(soc,encontro)==1){
            cout << "Socio elimindo con éxito. " << endl;
           return true;
        } else { return false;}
    }
}

int ArchivoSocio::modificarRegistro(Socio soc, int pos){
    FILE *pSocio;
    pSocio = fopen("socios.dat","rb+");
    if (pSocio == nullptr){
        return -1;
    }
    fseek(pSocio,pos*tamanioRegistro,0);
    int escribio=fwrite(&soc, tamanioRegistro, 1, pSocio);
    fclose(pSocio);
    return escribio;
}

int ArchivoSocio::modificarSocio(int idSocio){
    //necesito id del socio, y nuevos datos
    ArchivoSocio archiSocio("socios.dat");
    archiSocio.buscarSocioPorID(idSocio);
}

int ArchivoSocio::cantidadRegistros() {
    FILE* f = fopen("socios.dat", "rb");
    if (f == nullptr) return 0;
    fseek(f, 0, SEEK_END);
    int tam = ftell(f);
    fclose(f);
    return tam / sizeof(Socio);
}
