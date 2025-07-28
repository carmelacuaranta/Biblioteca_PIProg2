#include <iostream>
#include "Prestamo.h"
using namespace std;

Prestamo::Prestamo() {
    _id = 0;
    _idLibro = 0;
    _idSocio = 0;
    _vencido = false;
    _finalizado = false;
    _estado=true;
}

Prestamo::Prestamo(int id, int idLibro, int idSocio, Fecha fechaPrestado, Fecha fechaDevolucion, bool vencido, bool finalizado) {
    _id = id;
    _idLibro = idLibro;
    _idSocio = idSocio;
    _fechaPrestado = fechaPrestado;
    _fechaDevolucion = fechaDevolucion;
    _vencido = vencido;
    _finalizado = finalizado;
    _estado=true;
}

// Getters
int Prestamo::getId() {
    return _id;
    }
int Prestamo::getIdLibro() {
    return _idLibro;
    }
int Prestamo::getIdSocio() {
    return _idSocio;
    }
Fecha Prestamo::getFechaPrestado() {
    return _fechaPrestado;
    }
Fecha Prestamo::getFechaDevolucion() {
    return _fechaDevolucion;
    }
bool Prestamo::getVencido() {
    return _vencido;
    }
bool Prestamo::getFinalizado() {
    return _finalizado;
    }
bool Prestamo::getEstado() {
    return _estado;
    }

// Setters
void Prestamo::setId(int id) {
    _id = id;
    }
void Prestamo::setIdLibro(int idLibro) {
    _idLibro = idLibro;
    }
void Prestamo::setIdSocio(int idSocio) {
    _idSocio = idSocio;
    }
void Prestamo::setFechaPrestado(Fecha fechaPrestado) {
    _fechaPrestado = fechaPrestado;
    }
void Prestamo::setFechaDevolucion(Fecha fechaDevolucion) {
    _fechaDevolucion = fechaDevolucion;
    }
void Prestamo::setVencido(bool vencido) {
    _vencido = vencido;
    }
void Prestamo::setFinalizado(bool finalizado) {
    _finalizado = finalizado;
    }
void Prestamo::setEstado(bool estado) {
    _estado = estado;
    }
