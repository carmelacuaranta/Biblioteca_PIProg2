#include <iostream>
using namespace std;
#include "Cuota.h"
#include "ArchivoSocio.h"

Cuota::Cuota() {
    _idCuota = 0;
    _monto = 0.0f;
    _idSocio = 0;
    _pagada = false;
    _estado = true;
}

Cuota::Cuota(int idCuota, float monto, int idSocio, Fecha fecha, bool pagada) {
    _idCuota = idCuota;
    _monto = monto;
    _idSocio = idSocio;
    _fecha = fecha;
    _pagada = pagada;
    _estado=true;
}

//Getters
int Cuota::getIdCuota() const {
    return _idCuota;
}

float Cuota::getMonto() const {
    return _monto;
}

int Cuota::getIdSocio() const {
    return _idSocio;
}

bool Cuota::getPagada() const {
    return _pagada;
}

Fecha Cuota::getFecha() const {
    return _fecha;
}

bool Cuota::getEstado() const {
    return _estado;
}

//Setters
void Cuota::setIdCuota(int id) { _idCuota = id; }
void Cuota::setMonto(float m) { _monto = m; }
void Cuota::setIdSocio(int id) { _idSocio = id; }
void Cuota::setFecha(Fecha f) { _fecha = f; }
void Cuota::setPagada(bool p) { _pagada = p; }
void Cuota::setEstado(bool est) { _estado = est; }
