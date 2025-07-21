#include <iostream>
#include "ArchivoPrestamo.h"
#include "ArchivoSocio.h"
#include "ArchivoLibro.h"
using namespace std;

int ArchivoPrestamo::agregarPrestamo(Prestamo pres){
    ArchivoLibro lib;
    ArchivoSocio soc;

    int idSocioValido = soc.buscarSocioPorID(pres.getIdSocio());
    int idLibroValido = lib.buscarLibroPorID(pres.getIdLibro());

    if (idSocioValido < 0 || idLibroValido < 0) {
        cout << "No se puede realizar el préstamo. ID inválido." << endl;
        return -1;
    }

    FILE *pPrestamo = fopen("prestamos.dat", "ab");
    if(pPrestamo == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    int nuevoID = obtenerUltimoID() + 1;
    pres.setIdPrestamo(nuevoID);      // ID autoincremental
    pres.setEstado(true);     // Estado activo

    fwrite(&pres, sizeof(Prestamo), 1, pPrestamo);
    fclose(pPrestamo);

    cout << "Préstamo registrado con ID: " << nuevoID << endl;
    return nuevoID;
}

bool ArchivoPrestamo::listarPrestamos() {
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    Prestamo pres;
    cout << "LISTADO DE PRESTAMOS:" << endl << "-------------------" << endl;

    while (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        if(pres.getEstado()==true){
            pres.mostrarPrestamo();
            cout << "-------------------" << endl;
        }
    }

    fclose(p);
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

int ArchivoPrestamo::obtenerUltimoID() {
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) return 0;

    Prestamo pres;
    fseek(p, -sizeof(Prestamo), SEEK_END);  // Nos posicionamos al final
    if (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        fclose(p);
        return pres.getIdPrestamo();
    }

    fclose(p);
    return 0;
}

