#ifndef ARCHIVOCUOTA_H
#define ARCHIVOCUOTA_H
#include "Cuota.h"
#include <iostream>
#include <cstring>
using namespace std;


class ArchivoCuota
{
    private:
    char cuota[50];
    int tamanioRegistro;

public:
    ArchivoCuota();
    int agregarCuota(Cuota cuo);
    bool listarCuotas();
    int buscarCuotaPorID(int idBuscado);
    int buscarCuotaPorIDSocio(int idBuscado);
    bool generarCuotasDelMes(float monto, Fecha fecha);
    int modificarRegistro(Cuota cu, int pos);
    int modificarCuota(int idCuota);
    Cuota leerRegistro(int pos);
    bool bajaLogica();
    bool pagarCuota(int idCuota);
};

#endif // ARCHIVOCUOTA_H
