#ifndef ARCHIVOSOCIO_H
#define ARCHIVOSOCIO_H

#include "Socio.h"
#include <cstring>

class ArchivoSocio {
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoSocio(const char *n = "Socios.dat") {
        strncpy(nombre, n, sizeof(nombre));
        nombre[sizeof(nombre) - 1] = '\0';
        tamanioRegistro = sizeof(Socio);
    }

    int agregarRegistro(Socio soc);
    bool listarRegistros();
    int listarSocios();
    bool buscarSocioPorID(int idBuscado);
    bool buscarSocioPorNombre(const char* nombreBuscado);
};

#endif // ARCHIVOSOCIO_H
