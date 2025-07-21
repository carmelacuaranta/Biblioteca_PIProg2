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
        bool estado;

    public:
        Cuota();
        Cuota(int _idCuota, float _monto, int _idSocio, Fecha _fecha, bool _pagada);

        int getIdCuota();
        float getMonto();
        int getIdSocio();
        Fecha getFecha();
        bool getPagada();
        bool getEstado();

        void setIdCuota(int id);
        void setMonto(float m);
        void setIdSocio(int id);
        void setFecha(Fecha f);
        void setPagada(bool p);
        void setEstado(bool est);

        void mostrarCuota();
        void agregarCuota();
};

#endif // CUOTA_H
