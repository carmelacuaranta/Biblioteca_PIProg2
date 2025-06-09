#ifndef ARCHIVOSOCIO_H
#define ARCHIVOSOCIO_H

#include "Socio.h"
#include "string.h"


class ArchivoSocio
{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
        ArchivoSocios(const char *n="Socios.dat"){
        strcpy(nombre,n);
        tamanioRegistro=sizeof(Socio);
};
    int agregarRegistro(Socio soc);
    bool listarRegistros();
   // int buscarSocio(int idSocio);

#endif // ARCHIVOSOCIO_H
