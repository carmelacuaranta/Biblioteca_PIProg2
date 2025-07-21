#include <iostream>
using namespace std;
#include "Cuota.h"
#include "ArchivoSocio.h"

Cuota::Cuota() {
    idCuota = 0;
    monto = 0.0f;
    idSocio = 0;
    pagada = false;
    estado=true;
}

Cuota::Cuota(int _idCuota, float _monto, int _idSocio, Fecha _fecha, bool _pagada) {
    idCuota = _idCuota;
    monto = _monto;
    idSocio = _idSocio;
    fecha = _fecha;
    pagada = _pagada;
    estado=true;
}

//Getters
int Cuota::getIdCuota() { return idCuota; }
float Cuota::getMonto() { return monto; }
int Cuota::getIdSocio() { return idSocio; }
Fecha Cuota::getFecha() { return fecha; }
bool Cuota::getPagada() { return pagada; }
bool Cuota::getEstado() { return estado; }

//Setters
void Cuota::setIdCuota(int id) { idCuota = id; }
void Cuota::setMonto(float m) { monto = m; }
void Cuota::setIdSocio(int id) { idSocio = id; }
void Cuota::setFecha(Fecha f) { fecha = f; }
void Cuota::setPagada(bool p) { pagada = p; }
void Cuota::setEstado(bool est) { estado = est; }

void Cuota::agregarCuota(){
    //para validar que exista el id del socio
    ArchivoSocio archivoSoc;
    int idSocioValido = -1;

    int aux = 0;
    cout << "Ingrese ID: ";
    cin >> idCuota;
    cin.ignore();

    cout << "Ingrese ID del socio: ";
    cin >> aux;
    cin.ignore();
    idSocioValido = archivoSoc.buscarSocioPorID(aux);
    if (idSocioValido < 0 ){
        setIdSocio(aux);
    }

    cout << "Ingrese monto: ";
    cin >> monto;
    cin.ignore();

    cout << "Esta pagada? para SI ingrese 1, para NO, 0: ";
    cin >> aux;
    cin.ignore();
    switch (aux) {
    case 0:
        pagada=false;
        break;
    case 1:
        pagada = true;
        break;
    default:
        cout << "Valor invalido." << endl;
        break;
    }

    cout << "Ingrese anio de Pago: ";
    cin >> aux;
    this->fecha.setAnio(aux);
    cout << "Ingrese mes de Pago: ";
    cin >> aux;
    this->fecha.setMes(aux);
    cout << "Ingrese dia de pago: ";
    cin >> aux;
    this->fecha.setDia(aux);
    estado = true;
}

void Cuota::mostrarCuota() {
    cout << "ID: " << idCuota << endl;
    cout << "ID Socio: " << idSocio << endl;
    cout << "Monto: " << monto << endl;
    cout << "Esta pagada: " << endl;
    if (pagada == true ){
        cout << "SI" << endl;
    } else { cout << "NO" << endl;}
    cout << "Fecha de pago: " << fecha.toString() << endl;
}
