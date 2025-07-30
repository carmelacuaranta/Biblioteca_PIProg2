#include "ArchivoSocio.h"
#include "ArchivoCuota.h"
#include "Socio.h"
#include "Funcionalidades.h"
#include <iostream>
#include <cstring>
#include "Errores.h"
using namespace std;

bool ArchivoSocio::idRepetido(int id) {
    FILE* archivoSocioLectura = fopen(_nombreArchivo, "rb");
    if (archivoSocioLectura == nullptr) {
        return false;
    }

    Socio socioGuardado;
    while (fread(&socioGuardado, sizeof(Socio), 1, archivoSocioLectura) == 1) {
        if ((socioGuardado.getId() == id) && (socioGuardado.getEstado() == true)) {
            fclose(archivoSocioLectura);
            return true;
        }
    }

    fclose(archivoSocioLectura);
    return false;
}

bool ArchivoSocio::emailValido(const char* email) {
    bool tieneArroba = false;
    bool tienePuntoDespuesArroba = false;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            tieneArroba = true;
            // Verificar que hay al menos un caracter después del '@' y antes del '.'
            for (int j = i + 1; email[j] != '\0'; j++) {
                if (email[j] == '.') {
                    tienePuntoDespuesArroba = true;
                    break;
                }
            }
            break;
        }
    }

    return tieneArroba && tienePuntoDespuesArroba;
}

int ArchivoSocio::agregarRegistro() {
    Socio soc = cargarSocioPorConsola();

    if (idRepetido(soc.getId())) return ID_REPETIDO;
    if (!emailValido(soc.getEmail())) EMAIL_INVALIDO;

    FILE* p = fopen(_nombreArchivo, "ab");
    if (!p) return ERROR_ARCHIVO;

    fwrite(&soc, sizeof(Socio), 1, p);
    fclose(p);
    return 0;
}



int ArchivoSocio::listarSocios() {
    FILE* pSocio = fopen(_nombreArchivo, "rb");
    if (pSocio == nullptr) {
        return ERROR_ARCHIVO;
    }

    Socio soc;

    while (fread(&soc, sizeof(Socio), 1, pSocio) == 1) {
            if(soc.getEstado()==true){
                mostrarSocioPorConsola(soc);
                cout << "-----------------" << endl;
            }
    }

    fclose(pSocio);
    return 0;
}

int ArchivoSocio::buscarSocioPorID(int idBuscado) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        return ERROR_ARCHIVO;
    }
    Socio soc;
    int pos=0;
    while (fread(&soc, sizeof(Socio), 1, p) == 1) {
        if (soc.getId() == idBuscado) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return REGISTRO_NO_ENCONTRADO;
}

int ArchivoSocio::buscarSocioPorNombre(const char* nombreBuscado) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        return ERROR_ARCHIVO;
    }

    Socio soc;
    int pos = 0;

    while (fread(&soc, sizeof(Socio), 1, p) == 1) {
        if (strcmp(soc.getNombre(), nombreBuscado) == 0) {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return REGISTRO_NO_ENCONTRADO;
}

bool ArchivoSocio::cargaVariosAux(){
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) {
        return false;
    }
    Fecha fecha = Fecha(10,10,1980);
    Socio aux1 =  Socio(1, "24908987", "Juan", "Sosa", "1234", "Wallaby 12", "jsosa@mail.com", fecha);
    fwrite(&aux1, sizeof aux1, 1, p);

    fecha.setAnio(1990);
    fecha.setMes(3);
    fecha.setDia(22);
    Socio aux2 =  Socio(2, "33926749", "Juana", "Gomez", "1234", "Calle Falsa 123", "jgomez@mail.com", fecha);
    fwrite(&aux2, sizeof aux2, 1, p);

    fecha.setAnio(2000);
    fecha.setMes(1);
    fecha.setDia(12);
    Socio aux3 =  Socio(3, "44908987", "Maria", "Lopez", "1234", "Private Drive 4", "mlopez@mail.com", fecha);
    fwrite(&aux3, sizeof aux3, 1, p);

    fecha.setAnio(1985);
    fecha.setMes(10);
    fecha.setDia(5);
    Socio aux4 =  Socio(4, "39483481", "Pedro", "Gimenez", "1234", "Siempreviva 742", "pgimenez@mail.com", fecha);
    fwrite(&aux4, sizeof aux4, 1, p);

    fclose(p);
    return true;
}

Socio ArchivoSocio::leerRegistro(int pos){
    Socio soc;
    FILE *pSocio;
    pSocio = fopen(_nombreArchivo,"rb");
    if(pSocio==nullptr){
        cout << "Eror de archivo." << endl;
        return soc;
    }
    fseek(pSocio,pos*_tamanioRegistro,0);
    fread(&soc, _tamanioRegistro, 1, pSocio);
    fclose(pSocio);
    return soc;
}

int ArchivoSocio::bajaLogica(int id){
    Socio soc;
    int encontro = buscarSocioPorID(id);
    if (encontro < 0){
        return REGISTRO_NO_ENCONTRADO;
    }
    soc=leerRegistro(encontro);
    if (soc.getEstado()==false){
        return REGISTRO_ELIMINADO;
    } else {
        soc.setEstado(false);
        if(modificarRegistro(soc,encontro)==1){
           return OK;
        } else { return -7;}
    }
}

int ArchivoSocio::modificarRegistro(Socio soc, int pos){
    FILE *pSocio;
    pSocio = fopen(_nombreArchivo,"rb+");
    if (pSocio == nullptr){
        return ERROR_ARCHIVO;
    }
    fseek(pSocio,pos*_tamanioRegistro,0);
    int escribio=fwrite(&soc, _tamanioRegistro, 1, pSocio);
    fclose(pSocio);
    return escribio;
}

int ArchivoSocio::modificarSocio(int idSocio){
    int pos = buscarSocioPorID(idSocio);
    if (pos == -1) {
        return REGISTRO_NO_ENCONTRADO;
    }

    Socio soc = leerRegistro(pos);
    if (soc.getEstado()==false) {
        return REGISTRO_ELIMINADO;
    }

    cout << "Ingrese los nuevos datos del socio:" << endl;

    soc = cargarSocioPorConsola();

    if (modificarRegistro(soc, pos) == 1){
        return OK;
    } else {
        return ERROR_MODIFICACION;
    }
}

int ArchivoSocio::cantidadRegistros() {
    FILE* f = fopen(_nombreArchivo, "rb");
    if (f == nullptr) return 0;
    fseek(f, 0, SEEK_END);
    int tam = ftell(f);
    fclose(f);
    return tam / sizeof(Socio);
}

void ArchivoSocio::listarSociosConDeudas() {
    ArchivoCuota archivoCuota;
    int cantidadSocios = cantidadRegistros();
    bool hayDeudas = false;

    for(int i = 0; i < cantidadSocios; i++) {
        Socio socio = leerRegistro(i);
        if(socio.getEstado()) {
            FILE* pCuota = fopen("Cuotas.dat", "rb");
            if(pCuota != nullptr) {
                Cuota cuota;
                int cuotasPendientes = 0;
                float totalAdeudado = 0.0f;

                while(fread(&cuota, sizeof(Cuota), 1, pCuota) == 1) {
                    if(cuota.getIdSocio() == socio.getId() &&
                       cuota.getEstado() &&
                       !cuota.getPagada()) {
                        cuotasPendientes++;
                        totalAdeudado += cuota.getMonto();
                    }
                }
                fclose(pCuota);

                if(cuotasPendientes > 0) {
                    hayDeudas = true;
                    cout << "ID: " << socio.getId()
                         << " - " << socio.getApellido() << ", " << socio.getNombre()
                         << " - Cuotas pendientes: " << cuotasPendientes
                         << " - Total: $" << totalAdeudado << endl;
                }
            }
        }
    }

    if(!hayDeudas) {
        cout << "No hay socios con cuotas pendientes de pago." << endl;
    }

    cout << "---------------------------" << endl;
}
