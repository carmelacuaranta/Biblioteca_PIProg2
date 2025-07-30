#include "ArchivoSocio.h"
#include "ArchivoCuota.h"
#include "Socio.h"
#include "Funcionalidades.h"
#include <iostream>
#include <cstring>
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
            // Verificar que hay al menos un carácter después del '@' y antes del '.'
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

    if (idRepetido(soc.getId())) return -2;
    if (!emailValido(soc.getEmail())) return -3;

    FILE* p = fopen(_nombreArchivo, "ab");
    if (!p) return -1;

    fwrite(&soc, sizeof(Socio), 1, p);
    fclose(p);
    return 0; // Éxito
}

/**
int ArchivoSocio::agregarRegistro() {
    system("cls");
    Socio soc = cargarSocioPorConsola();
    int aux;

    if (idRepetido(soc.getId())) {
        cout << "ID repetido. No se puede guardar el socio. " << endl;
        return -2;
    }

    if (!emailValido(soc.getEmail())) {
        cout << "El formato del email es incorrecto. Debe contener '@' y al menos un '.' despues del '@'." << endl;
        return -3;
    }

    FILE* pSocio = fopen(_nombreArchivo, "ab");
    if (pSocio == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    fwrite(&soc, sizeof(soc), 1, pSocio);
    cout << "Socio guardado correctamente." << endl;

    fclose(pSocio);
    return 0;
}
**/


int ArchivoSocio::listarSocios() {
    FILE* pSocio = fopen(_nombreArchivo, "rb");
    if (pSocio == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    Socio soc;
    cout << "LISTADO DE SOCIOS:" << endl;
    cout << "-----------------" << endl;

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
        cout << "No se pudo abrir el archivo."<< endl;
        return -1;
    }

    Socio soc;
    int pos=0;
    while (fread(&soc, sizeof(Socio), 1, p) == 1) {
        if (soc.getId() == idBuscado) {
            cout << "Socio encontrado: " << endl;
            mostrarSocioPorConsola(soc);
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
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return false;
    }

    Socio soc;
    bool encontrado = false;

    while (fread(&soc, sizeof(Socio), 1, p) == 1) {
        if (strcmp(soc.getNombre(), nombreBuscado) == 0) {
            cout << "Socio encontrado: " << endl;
            mostrarSocioPorConsola(soc);
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontro un socio con ese nombre." << endl;

    fclose(p);
    return encontrado;
}

bool ArchivoSocio::cargaVariosAux(){
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
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
    cout << "Se han cargado 4 socios" << endl;
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

bool ArchivoSocio::bajaLogica(){
    Socio soc;
    ArchivoSocio archiSocio(_nombreArchivo);
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
            cout << "Socio elimindo con exito. " << endl;
           return true;
        } else { return false;}
    }
}

int ArchivoSocio::modificarRegistro(Socio soc, int pos){
    FILE *pSocio;
    pSocio = fopen(_nombreArchivo,"rb+");
    if (pSocio == nullptr){
        return -1;
    }
    fseek(pSocio,pos*_tamanioRegistro,0);
    int escribio=fwrite(&soc, _tamanioRegistro, 1, pSocio);
    fclose(pSocio);
    return escribio;
}

int ArchivoSocio::modificarSocio(int idSocio){
    ArchivoSocio archiSocio(_nombreArchivo);

    int pos = archiSocio.buscarSocioPorID(idSocio);
    if (pos == -1) {
        cout << "No se encontro socio con ese ID." << endl;
        return -1;
    }

    Socio soc = archiSocio.leerRegistro(pos);
    if (soc.getEstado()==false) {
        cout << "Socio eliminado, no se puede modificar." << endl;
        return -2;
    }

    cout << "Ingrese los nuevos datos del socio:" << endl;

    char nombre[30];
    char apellido[30];
    char dni[10];
    char direccion[50];
    char email[50];
    char telefono[50];
    int idSocioNuevo = soc.getId();
    Fecha fechaNac = soc.getFechaNac();

    cout << "Nombre/s: ";
    cin.ignore();
    cin.getline(nombre, 30);
    cout << "Apellido: ";
    cin.getline(apellido, 30);
    cout << "DNI: ";
    cin.getline(dni, 10);
    cout << "Direccion: ";
    cin.getline(direccion, 50);
    cout << "Email: ";
    cin.getline(email, 50);
    cout << "telefono: ";
    cin.getline(telefono, 50);

    cout << "Fecha de nacimiento:" << endl;
    fechaNac.cargarManual();

    Socio nuevoSocio(idSocioNuevo, dni, nombre, apellido, telefono, direccion, email,fechaNac);
    nuevoSocio.setEstado(true);

    if (archiSocio.modificarRegistro(nuevoSocio, pos) == 1){
        cout << "Se actualizo correctamente." << endl;
        return 0;
    } else {
        cout << "Error al modificar el socio." << endl;
        return -1;
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

    cout << "LISTADO DE SOCIOS CON DEUDAS" << endl;
    cout << "---------------------------" << endl;

    for(int i = 0; i < cantidadSocios; i++) {
        Socio socio = leerRegistro(i);
        if(socio.getEstado()) {
            FILE* pCuota = fopen(_nombreArchivo, "rb");
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
