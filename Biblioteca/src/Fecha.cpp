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

bool Fecha::esMayorQue(Fecha otraFecha, Fecha fechaActual){
    if (otraFecha.getAnio() > fechaActual.getAnio()){
        //la mayor es la otra, todavía no pasó xD
        return false;
    }
    if (otraFecha.getAnio() < fechaActual.getAnio()){
        //ya pasó la otra fecha, está vencido
        return true;
    }
    if (otraFecha.getAnio() == fechaActual.getAnio()){
        //mismo año, hay que comparar mes
        if (otraFecha.getMes() > fechaActual.getMes()){
            //el mes todavía no llegó
            return false;
        }
        if (otraFecha.getMes() < fechaActual.getMes()){
            //el mes ya pasó
            return true;
        }
        if (otraFecha.getMes() == fechaActual.getMes()){
            //mismo mes, comparo días.
            if (otraFecha.getDia() > fechaActual.getDia()){
                //el dia todavía no llegó
                return false;
            }
            if (otraFecha.getDia() < fechaActual.getDia()){
                //el dia ya pasó
                return true;
            }
            if (otraFecha.getDia() == fechaActual.getDia()){
                    //vence hoy
                return false;
            }
        }

    }
    return false;
}
