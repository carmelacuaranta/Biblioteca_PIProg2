#ifndef ERRORES_H
#define ERRORES_H

const int OK = 0;
const int ERROR_ARCHIVO = -1;
const int ID_REPETIDO = -2;
const int EMAIL_INVALIDO = -3;
const int REGISTRO_NO_ENCONTRADO = -4;
const int REGISTRO_ELIMINADO = -5;
const int ERROR_MODIFICACION = -6;

void mostrarMensajeError(int codigo);

#endif // ERRORES_H
