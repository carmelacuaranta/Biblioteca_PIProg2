#ifndef ARCHIVOCUOTA_H
#define ARCHIVOCUOTA_H
#include "Cuota.h"
#include <iostream>
using namespace std;


class ArchivoCuota
{
    private:
    char cuota[50];
    int tamanioRegistro;

public:
    ArchivoCuota(const char *n = "Cuota.dat") {
        strncpy(cuota, n, sizeof(cuota));
        cuota[sizeof(cuota) - 1] = '\0';
        tamanioRegistro = sizeof(Cuota);
    }

    int agregarCuota(Cuota cuo);
    bool listarCuotas();
};

#endif // ARCHIVOCUOTA_H
