#ifndef FECHA_H
#define FECHA_H
#pragma once
#include <string>

class Fecha{
    private:
        int _dia;
        int _mes;
        int _anio;

    public:
        Fecha();
        Fecha(int dia, int mes, int anio);

        int getDia();
        int getMes();
        int getAnio();

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        void cargarFechaSistema();
        void cargarManual();
        void cargarManualAnioMes();
        std::string toString();

        bool esValida();

        static bool esBisiesto(int anio);
        bool esFechaValida(int d, int m, int a);

        bool esMayorQue(const Fecha& otraFecha) const;

        bool estaEntre(const Fecha& inicio, const Fecha& fin) const;
};

#endif // FECHA_H
