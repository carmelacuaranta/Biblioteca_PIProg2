#include <iostream>
#include <ctime>
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
        cout << "Dia invalido. Queda 1 por defecto." << endl;
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

void Fecha::cargarFechaSistema(){
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    _dia = now->tm_mday;
    _mes = now->tm_mon + 1;  // tm_mon va de 0 a 11
    _anio = now->tm_year + 1900;  // tm_year cuenta desde 1900
}

bool Fecha::esMayorQue(Fecha otraFecha, Fecha fechaActual) const{
    if (otraFecha.getAnio() > fechaActual.getAnio()){
        //la mayor es la otra, todavia no paso
        return false;
    }
    if (otraFecha.getAnio() < fechaActual.getAnio()){
        //ya paso la otra fecha, está vencido
        return true;
    }
    if (otraFecha.getAnio() == fechaActual.getAnio()){
        //mismo anio, hay que comparar mes
        if (otraFecha.getMes() > fechaActual.getMes()){
            //el mes todavia no llego
            return false;
        }
        if (otraFecha.getMes() < fechaActual.getMes()){
            //el mes ya paso
            return true;
        }
        if (otraFecha.getMes() == fechaActual.getMes()){
            //mismo mes, comparo dias.
            if (otraFecha.getDia() > fechaActual.getDia()){
                //el dia todavia no llego
                return false;
            }
            if (otraFecha.getDia() < fechaActual.getDia()){
                //el dia ya paso
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

bool Fecha::esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

bool Fecha::esFechaValida(int d, int m, int a) {
    if (a < 1 || m < 1 || m > 12 || d < 1) return false;

    int diasDelMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m == 2 && esBisiesto(a)) {
        return d <= 29;
    }

    return d <= diasDelMes[m - 1];
}

bool Fecha::esValida() {
    return esFechaValida(_dia, _mes, _anio);
}

void Fecha::cargarManual() {
    int d, m, a;
    do {
        std::cout << "Ingrese dia: ";
        std::cin >> d;
        std::cout << "Ingrese mes: ";
        std::cin >> m;
        std::cout << "Ingrese anio: ";
        std::cin >> a;

        if (!esFechaValida(d, m, a)) {
            std::cout << "Fecha invalida. Intente de nuevo.\n";
        }
    } while (!esFechaValida(d, m, a));

    _dia = d;
    _mes = m;
    _anio = a;
}

void Fecha::cargarManualAnioMes() {
    int m, a;
    do {
        std::cout << "Ingrese mes: ";
        std::cin >> m;
        std::cout << "Ingrese anio: ";
        std::cin >> a;

        if (!esFechaValida(1, m, a)) {
            std::cout << "Fecha invalida. Intente de nuevo.\n";
        }
    } while (!esFechaValida(1, m, a));

    _dia = 1;
    _mes = m;
    _anio = a;
}

const bool Fecha::estaEntre(Fecha inicio, Fecha fin) {
    return !inicio.esMayorQue(inicio, fin) && !esMayorQue(inicio, fin);
}
