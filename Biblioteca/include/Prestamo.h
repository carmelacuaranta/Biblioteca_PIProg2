#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Fecha.h"


class Prestamo
{
    private:
        int _id;
        int _idLibro;
        int _idSocio;
        Fecha _fechaPrestado;
        Fecha _fechaDevolucion;
        bool _vencido;
        bool _finalizado;
        bool _estado;
    public:
        Prestamo();
        Prestamo(int id, int idLibro, int idSocio, Fecha fechaPrestado, Fecha fechaDevolucion, bool vencido, bool finalizado);
        void mostrarPrestamo();
        void cargarPrestamo();

        // Getters
        int getId();
        int getIdLibro();
        int getIdSocio();
        Fecha getFechaPrestado();
        Fecha getFechaDevolucion();
        bool getVencido();
        bool getFinalizado();
        bool getEstado();

        // Setters
        void setId(int id);
        void setIdLibro(int idLibro);
        void setIdSocio(int idSocio);
        void setFechaPrestado(Fecha f);
        void setFechaDevolucion(Fecha f);
        void setVencido(bool v);
        void setFinalizado(bool f);
        void setEstado(bool f);
};

#endif // PRESTAMO_H
