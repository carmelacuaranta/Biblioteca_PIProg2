#ifndef ARCHIVOSOCIO_H
#define ARCHIVOSOCIO_H

#include "Socio.h"
#include <cstring>

class ArchivoSocio {
private:
    char nombre[30];
    int tamanioRegistro;
    bool idRepetido(int id);              // para verificar ID repetido
    bool emailValido(const char* email);  // para validar email

public:
    ArchivoSocio(const char *n = "Socios.dat") {
        strncpy(nombre, n, sizeof(nombre));
        nombre[sizeof(nombre) - 1] = '\0';
        tamanioRegistro = sizeof(Socio);
    }

    int agregarRegistro();
    bool listarRegistros();
    int listarSocios();
    int buscarSocioPorID(int idBuscado);
    bool buscarSocioPorNombre(const char* nombreBuscado);
    bool cargaVariosAux();
    int modificarRegistro(Socio soc, int pos);
    int modificarSocio(int idSocio);
    Socio leerRegistro(int pos);
    bool bajaLogica();
    int cantidadRegistros();
    void listarSociosConDeudas();
};

#endif // ARCHIVOSOCIO_H
