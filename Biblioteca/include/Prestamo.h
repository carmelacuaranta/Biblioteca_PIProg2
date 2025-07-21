#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Fecha.h"


class Prestamo
{
    private:
        int idPrestamo;
        int idLibro;
        int idSocio;
        Fecha fechaPrestado;
        Fecha fechaDevolucion;
        bool vencido;
        bool finalizado;
        bool estado;
    public:
        Prestamo();
        Prestamo(int idPrestamo, int idLibro, int idSocio, Fecha fechaPrestado, Fecha fechaDevolucion, bool vencido, bool finalizado);
        void mostrarPrestamo();
        void cargarPrestamo();

        // Getters
        int getIdPrestamo();
        int getIdLibro();
        int getIdSocio();
        Fecha getFechaPrestado();
        Fecha getFechaDevolucion();
        bool getVencido();
        bool getFinalizado();
        bool getEstado();

        // Setters
        void setIdPrestamo(int id);
        void setIdLibro(int idLibro);
        void setIdSocio(int idSocio);
        void setFechaPrestado(Fecha f);
        void setFechaDevolucion(Fecha f);
        void setVencido(bool v);
        void setFinalizado(bool f);
        void setEstado(bool f);
};

#endif // PRESTAMO_H
