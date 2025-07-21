#ifndef ARCHIVOPRESTAMO_H
#define ARCHIVOPRESTAMO_H
#include "Prestamo.h"
#include <iostream>
#include <string.h>
using namespace std;

class ArchivoPrestamo
{
private:
    char prest[50];
    int tamanioRegistro;

public:
    ArchivoPrestamo(const char *n = "Prestamos.dat") {
        strncpy(prest, n, sizeof(prest));
        prest[sizeof(prest) - 1] = '\0';
        tamanioRegistro = sizeof(Prestamo);
    }

    int agregarPrestamo(Prestamo pres);
    bool listarPrestamos();
    int buscarPrestamoPorId(int idBuscado);
    void listarPrestamosPorIdLibro(int idBuscado);
    void listarPrestamosPorIdSocio(int idBuscado);
    int obtenerUltimoID();
    int modificarRegistro(Prestamo pres, int pos);
    bool bajaLogica();
    Prestamo leerRegistro(int pos);
    int modificarPrestamo(int idPrestamo);
    int extenderFechaDevolucion(int idPrestamo);
    int registrarDevolucion(int idPrestamo);
    void listarPrestamosVencidos();
};

#endif // ARCHIVOPRESTAMO_H
