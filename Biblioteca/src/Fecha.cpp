#include <iostream>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(){
    _dia = 1;
    _mes = 1;
    _anio = 2000;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    if (dia >=1 && dia <=31){
        _dia = dia;
    } else {
        cout << "Día invalido. Queda 1 por defecto." << endl;
    }
}

void Fecha::setMes(int mes){
    if (mes >=1 && mes <=12){
        _mes = mes;
    } else {
        cout << "Mes invalido. Queda 1 por defecto." << endl;
        }
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

std::string Fecha::toString(){
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}
