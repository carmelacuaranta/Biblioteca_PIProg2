#include <iostream>
#include <string.h>
using namespace std;
#include "ArchivoCuota.h"

int ArchivoCuota::agregarCuota(Cuota cuot){
    FILE *pCuota;
    pCuota=fopen("cuotas.dat", "ab");
    if(pCuota==nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

        fwrite(&cuot, sizeof cuot, 1, pCuota);
        cout << "Cuota registrada correctamente." << endl;

    fclose(pCuota);


    return 0;
}

bool ArchivoCuota::listarCuotas() {
    FILE* pCuota = fopen("cuotas.dat", "rb");
    if (pCuota == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    Cuota cuot;
    cout << "LISTADO DE CUOTAS:" << endl << "-------------------" << endl;

    while (fread(&cuot, sizeof(Cuota), 1, pCuota) == 1) {
        cuot.mostrarCuota();
        cout << "-------------------" << endl;
    }

    fclose(pCuota);
    return 0;
}
