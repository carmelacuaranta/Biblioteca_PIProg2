#include <iostream>
#include "Prestamo.h"
using namespace std;

Prestamo::Prestamo() {
    idPrestamo = 0;
    idLibro = 0;
    idSocio = 0;
    vencido = false;
    finalizado = false;
    estado=true;
}

Prestamo::Prestamo(int _idPrestamo, int _idLibro, int _idSocio, Fecha _fechaPrestado, Fecha _fechaDevolucion, bool _vencido, bool _finalizado) {
    idPrestamo = _idPrestamo;
    idLibro = _idLibro;
    idSocio = _idSocio;
    fechaPrestado = _fechaPrestado;
    fechaDevolucion = _fechaDevolucion;
    vencido = _vencido;
    finalizado = _finalizado;
    estado=true;
}

void Prestamo::mostrarPrestamo(){
    cout<<"ID del prestamo: " << idPrestamo << endl;
    cout<<"ID del socio: " << idSocio << endl;
    cout<<"ID del libro: " << idLibro << endl;
    cout<< "Fecha de inicio: " << fechaPrestado.toString() << endl;
    cout << "Fecha de finalizacion: " << fechaDevolucion.toString() << endl;
}

void Prestamo::cargarPrestamo(){
    int aux;
    cout << "Ingrese ID del Socio: " << endl;
    cin >> idSocio;
    cout << "Ingrese ID del Libro: " << endl;
    cin >> idLibro;

    fechaPrestado.cargarFechaSistema();
    cout << "Fecha de inicio del préstamo: " << fechaPrestado.toString() << endl;

    cout << "Informacion sobre la finalización del prestamo: " << endl;
    cout << "Ingrese el dia de finalización del prestamo: " << endl;
    cin >> aux;
    this->fechaDevolucion.setDia(aux);
    cout << "Ingrese el mes de finalizacion del prestamo: " << endl;
    cin >> aux;
    this->fechaDevolucion.setMes(aux);
    cout << "Ingrese el anio de finalizacion del prestamo: " << endl;
    cin >> aux;
    this->fechaDevolucion.setAnio(aux);
}

// Getters
int Prestamo::getIdPrestamo() { return idPrestamo; }
int Prestamo::getIdLibro() { return idLibro; }
int Prestamo::getIdSocio() { return idSocio; }
Fecha Prestamo::getFechaPrestado() { return fechaPrestado; }
Fecha Prestamo::getFechaDevolucion() { return fechaDevolucion; }
bool Prestamo::getVencido() { return vencido; }
bool Prestamo::getFinalizado() { return finalizado; }
bool Prestamo::getEstado() { return estado; }

// Setters
void Prestamo::setIdPrestamo(int id) { idPrestamo = id; }
void Prestamo::setIdLibro(int idL) { idLibro = idL; }
void Prestamo::setIdSocio(int idS) { idSocio = idS; }
void Prestamo::setFechaPrestado(Fecha f) { fechaPrestado = f; }
void Prestamo::setFechaDevolucion(Fecha f) { fechaDevolucion = f; }
void Prestamo::setVencido(bool v) { vencido = v; }
void Prestamo::setFinalizado(bool f) { finalizado = f; }
void Prestamo::setEstado(bool f) { estado = f; }
