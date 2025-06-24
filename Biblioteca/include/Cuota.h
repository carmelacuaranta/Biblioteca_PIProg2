#ifndef CUOTA_H
#define CUOTA_H
#include "Fecha.h"

//cada mes emitir las cuotas de ese mes

class Cuota
{
    private:
        int idCuota;
        float monto;
        int idSocio;
        Fecha fecha;
        bool pagada;

    public:
        Cuota();
        Cuota(int _idCuota, float _monto, int _idSocio, Fecha _fecha, bool _pagada);
        //Getters y Setters
        int getIdCuota() const;
        float getMonto() const;
        int getIdSocio() const;
        Fecha getFecha() const;
        bool getPagada() const;
        void setIdCuota(int id);
        void setMonto(float m);
        void setIdSocio(int id);
        void setFecha(Fecha f);
        void setPagada(bool p);

        void mostrarCuota();
        void agregarCuota();

};

#endif // CUOTA_H
