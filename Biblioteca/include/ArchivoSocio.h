#ifndef ARCHIVOSOCIO_H
#define ARCHIVOSOCIO_H

#include "Socio.h"
#include <cstring>  // Mejor que "string.h" en C++

class ArchivoSocio {
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoSocio(const char *n = "Socios.dat") {
        strncpy(nombre, n, sizeof(nombre));
        nombre[sizeof(nombre) - 1] = '\0';  // Seguridad: asegurar null-terminado
        tamanioRegistro = sizeof(Socio);
    }

    int AgregarRegistro(Socio soc);
    bool ListarRegistros();
    int ListarSocios();
    // int buscarSocio(int idSocio);
};

#endif // ARCHIVOSOCIO_H
