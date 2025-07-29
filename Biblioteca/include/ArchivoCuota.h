#ifndef ARCHIVOCUOTA_H
#define ARCHIVOCUOTA_H
#include "Cuota.h"
#include <iostream>
#include <cstring>
using namespace std;


class ArchivoCuota
{
    private:
    char _nombreArchivo[50];
    int _tamanioRegistro;

public:
    ArchivoCuota(const char *nombreArchivo = "Cuotas.dat");
    int agregarCuota(Cuota cuota);
    bool listarCuotas();
    int buscarCuotaPorID(int idBuscado);
    int buscarCuotaPorIDSocio(int idBuscado);
    bool generarCuotasDelMes(float monto, Fecha fecha);
    int modificarRegistro(Cuota cu, int pos);
    int modificarCuota(int idCuota);
    Cuota leerRegistro(int pos);
    bool bajaLogica();
    bool pagarCuota(int idCuota);
    float calcularRecaudacion(Fecha fechaInicio, Fecha fechaFin);
    ///FALTA IMPLEMENTAR
    //~ArchivoCuota();
};

#endif // ARCHIVOCUOTA_H
