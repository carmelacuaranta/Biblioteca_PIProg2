#include <iostream>
#include "ArchivoPrestamo.h"
#include "ArchivoSocio.h"
#include "ArchivoLibro.h"
using namespace std;

int ArchivoPrestamo::agregarPrestamo(Prestamo pres){
    //para avlidar que existan los id de socio y libro
    ArchivoSocio soc;
    ArchivoLibro lib;
    bool idSocioValido = soc.buscarSocioPorID(pres.getIdSocio());
    bool idLibroValido = lib.buscarLibroPorID(pres.getIdLibro());

    FILE *pPrestamo;
    pPrestamo=fopen("Prestamos.dat", "ab");
    if(pPrestamo==nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    if (idSocioValido == true && idLibroValido == true){
        fwrite(&pres, sizeof pres, 1, pPrestamo);
        cout << "Prestamo registrdo correctamente." << endl;
    } else {
        cout << "No se puede realizar el prestamo." << endl;
    }

    fclose(pPrestamo);


    return 0;
}

bool ArchivoPrestamo::listarPrestamos() {
    FILE* pPrestamo = fopen("Prestamos.dat", "rb");
    if (pPrestamo == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    Prestamo pres;
    cout << "LISTADO DE PRESTAMOS:" << endl << "-------------------" << endl;

    while (fread(&pres, sizeof(Prestamo), 1, pPrestamo) == 1) {
        pres.mostrarPrestamo();
        cout << "-------------------" << endl;
    }

    fclose(pPrestamo);
    return 0;
}

int ArchivoPrestamo::buscarPrestamoPorId(int idBuscado){
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo.";
        return false;
    }

    Prestamo pres;
    int pos=0;
    while (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        if (pres.getIdPrestamo() == idBuscado) {
            cout << "Prestamo encontrado: " << endl;
            pres.mostrarPrestamo();
            fclose(p);
            return pos;
        }
        pos++;
    }
    cout << "No se encontro un prestamo con ese ID." << endl;
    fclose(p);
    return -1;
}

void ArchivoPrestamo::listarPrestamosPorIdLibro(int idBuscado){
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) {
        cout << "Error al abrir el archivo de préstamos." << endl;
        return;
    }

    Prestamo pres;
    bool encontrado = false;

    while (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        if (pres.getIdLibro() == idBuscado && pres.getEstado()) {
            pres.mostrarPrestamo();
            encontrado = true;
        }
    }

    fclose(p);

    if (!encontrado) {
        cout << "No se encontraron préstamos activos con ese ID de libro." << endl;
    }
}

void ArchivoPrestamo::listarPrestamosPorIdSocio(int idBuscado){
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return;
    }

    Prestamo pres;
    bool encontrado = false;

    while (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        if (pres.getIdSocio() == idBuscado && pres.getEstado()) {
            pres.mostrarPrestamo();
            encontrado = true;
        }
    }

    fclose(p);

    if (!encontrado) {
        cout << "No se encontraron préstamos activos con ese ID de socio." << endl;
    }
}

