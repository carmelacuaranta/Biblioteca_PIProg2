#ifndef CUOTA_H
#define CUOTA_H
#include "Fecha.h"

//cada mes emitir las cuotas de ese mes

class Cuota
{
    private:
        int _idCuota;
        float _monto;
        int _idSocio;
        Fecha _fecha;
        bool _pagada;
        bool _estado;

    public:
        Cuota();
        Cuota(int idCuota, float monto, int idSocio, Fecha fecha, bool pagada);

        int getIdCuota() const;
        float getMonto() const;
        int getIdSocio() const;
        Fecha getFecha() const;
        bool getPagada() const;
        bool getEstado() const;

        void setIdCuota(int id);
        void setMonto(float m);
        void setIdSocio(int id);
        void setFecha(Fecha f);
        void setPagada(bool p);
        void setEstado(bool est);
};

#endif // CUOTA_H
