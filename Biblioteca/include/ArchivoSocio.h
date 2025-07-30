#ifndef ARCHIVOSOCIO_H
#define ARCHIVOSOCIO_H

#include "Socio.h"
#include <cstring>

class ArchivoSocio {
private:
    char _nombreArchivo[30];
    int _tamanioRegistro;
    bool idRepetido(int id);
    bool emailValido(const char* email);


public:
    ArchivoSocio(const char *nombreArchivo = "Socios.dat") {
        strncpy(_nombreArchivo, nombreArchivo, sizeof(_nombreArchivo));
        _nombreArchivo[sizeof(_nombreArchivo) - 1] = '\0';
        _tamanioRegistro = sizeof(Socio);
    }

    int agregarRegistro();
    bool listarRegistros();
    int listarSocios();
    int buscarSocioPorID(int idBuscado);
    int buscarSocioPorNombre(const char* nombreBuscado);
    bool cargaVariosAux();
    int modificarRegistro(Socio soc, int pos);
    int modificarSocio(int idSocio);
    Socio leerRegistro(int pos);
    int bajaLogica(int id);
    int cantidadRegistros();
    void listarSociosConDeudas();

};

#endif // ARCHIVOSOCIO_H
