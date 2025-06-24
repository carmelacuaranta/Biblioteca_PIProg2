#include <iostream>
using namespace std;
#include "Cuota.h"
#include "ArchivoSocio.h"

Cuota::Cuota() {
    idCuota = 0;
    monto = 0.0f;
    idSocio = 0;
    pagada = false;
}

Cuota::Cuota(int _idCuota, float _monto, int _idSocio, Fecha _fecha, bool _pagada) {
    idCuota = _idCuota;
    monto = _monto;
    idSocio = _idSocio;
    fecha = _fecha;
    pagada = _pagada;
}

//Getters
int Cuota::getIdCuota() const { return idCuota; }
float Cuota::getMonto() const { return monto; }
int Cuota::getIdSocio() const { return idSocio; }
Fecha Cuota::getFecha() const { return fecha; }
bool Cuota::getPagada() const { return pagada; }

//Setters
void Cuota::setIdCuota(int id) { idCuota = id; }
void Cuota::setMonto(float m) { monto = m; }
void Cuota::setIdSocio(int id) { idSocio = id; }
void Cuota::setFecha(Fecha f) { fecha = f; }
void Cuota::setPagada(bool p) { pagada = p; }

void Cuota::agregarCuota(){
    //para validar que exista el id del socio
    ArchivoSocio archivoSoc;
    bool idSocioValido = false;

    int aux = 0;
    cout << "Ingrese ID: ";
    cin >> idCuota;
    cin.ignore();

    cout << "Ingrese ID del socio: ";
    cin >> aux;
    cin.ignore();
    idSocioValido = archivoSoc.buscarSocioPorID(aux);
    if (idSocioValido == true ){
        setIdSocio(aux);
    }

    cout << "Ingrese monto: ";
    cin >> monto;
    cin.ignore();

    cout << "¿Está pagada? para SI ingrese 1, para NO, 0: ";
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
        cout << "Valor inválido." << endl;
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
}

void Cuota::mostrarCuota() {
    cout << "ID: " << idCuota << endl;
    cout << "ID Socio: " << idSocio << endl;
    cout << "Monto: " << monto << endl;
    cout << "Está pagada: " << endl;
    if (pagada == true ){
        cout << "SI" << endl;
    } else { cout << "NO" << endl;}
    cout << "Fecha de pago: " << fecha.toString() << endl;
}






