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
        cout << "No se puede realizar el préstamo." << endl;
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
