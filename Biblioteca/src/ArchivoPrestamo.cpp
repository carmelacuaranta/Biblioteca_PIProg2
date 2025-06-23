#include <iostream>
#include "ArchivoPrestamo.h"
using namespace std;

int ArchivoPrestamo::agregarPrestamo(Prestamo pres){
    FILE *pPrestamo;
    pPrestamo=fopen("Prestamos.dat", "ab");
    if(pPrestamo==nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

        fwrite(&pres, sizeof pres, 1, pPrestamo);
        cout << "Prestamo registrdo correctamente." << endl;

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
