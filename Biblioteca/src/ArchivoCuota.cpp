#include <iostream>
#include <string.h>
using namespace std;
#include "ArchivoCuota.h"
#include "ArchivoSocio.h"
#include "Socio.h"

ArchivoCuota::ArchivoCuota(){
    tamanioRegistro = sizeof(Cuota);
}

int ArchivoCuota::agregarCuota(Cuota cuot){
    bool idRepetido=false;
    FILE* archivoCuotaLectura = fopen("cuotas.dat","rb");
    if (archivoCuotaLectura !=nullptr) {
        Cuota cuotaGuardada;
        while (fread(&cuotaGuardada, sizeof(Cuota),1,archivoCuotaLectura) == 1){
            if (cuotaGuardada.getIdCuota() == cuot.getIdCuota()) {
                cout << "El ID ya existe. No se pudo guardar." << endl;
                idRepetido=true;
                fclose(archivoCuotaLectura);
                return -2;
            }
        }
        fclose(archivoCuotaLectura);
    }
    if (idRepetido == false){
        FILE *pCuota;
        pCuota=fopen("cuotas.dat", "ab");

        if(pCuota==nullptr) {
            cout << "Error de archivo." << endl;
            return -1;
        }

        fwrite(&cuot, sizeof cuot, 1, pCuota);
        cout << "Cuota registrada correctamente." << endl;
        fclose(pCuota);
        return 0;
    } else {
        return -1;
    }
}

bool ArchivoCuota::listarCuotas() {
    FILE* pCuota = fopen("cuotas.dat", "rb");
    if (pCuota == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    Cuota cuot;
    cout << "LISTADO DE CUOTAS:" << endl << "-------------------" << endl;

    while (fread(&cuot, sizeof(Cuota), 1, pCuota) == 1) {
        if (cuot.getEstado()==true){
                cuot.mostrarCuota();
                cout << "-------------------" << endl;
            }
    }
    fclose(pCuota);
    return 0;
}

int ArchivoCuota::buscarCuotaPorID(int idBuscado) {
    FILE* p = fopen("cuotas.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo."<< endl;
        return -1;
    }

    Cuota cu;
    int pos=0;
    while (fread(&cu, sizeof(Cuota), 1, p) == 1) {
        if (cu.getIdCuota() == idBuscado) {
            cout << "Cuota encontrada: " << endl;
            cu.mostrarCuota();
            fclose(p);
            return pos;
        }
        pos++;
    }

    cout << "No se encontro una cuota con ese ID. "<< endl;
    fclose(p);
    return -1;
}

int ArchivoCuota::buscarCuotaPorIDSocio(int idBuscado) {
    FILE* p = fopen("cuotas.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo."<< endl;
        return -1;
    }

    Cuota cu;
    int pos=0;
    while (fread(&cu, sizeof(Cuota), 1, p) == 1) {
        if (cu.getIdSocio() == idBuscado) {
            cout << "Cuota encontrada: " << endl;
            cu.mostrarCuota();
            fclose(p);
            return pos;
        }
        pos++;
    }

    cout << "No se encontro una cuota asociada a esa ID de socio."<< endl;
    fclose(p);
    return -1;
}

bool ArchivoCuota::generarCuotasDelMes(float monto, Fecha fecha) {
    ArchivoSocio archiSocio;
    Socio socio;
    int idCuota = 1;

    // Obtener el último ID usado para continuar
    FILE* f = fopen("cuotas.dat", "rb");
    if (f != nullptr) {
        Cuota c;
        while (fread(&c, sizeof(Cuota), 1, f) == 1) {
            if (c.getIdCuota() >= idCuota) {
                idCuota = c.getIdCuota() + 1;
            }
        }
        fclose(f);
    }

    int total = archiSocio.cantidadRegistros();
    for (int pos = 0; pos < total; pos++) {
        socio = archiSocio.leerRegistro(pos);
        if (socio.getEstado()==true) {
            Cuota cuo(idCuota, monto, socio.getId(), fecha, false);
            agregarCuota(cuo);
            idCuota++;
        }
    }

    cout << "Se generaron las cuotas exitosamente." << endl;
    return true;
}

int ArchivoCuota::modificarRegistro(Cuota cu, int pos){
    FILE *pCuota;
    pCuota = fopen("cuotas.dat","rb+");
    if (pCuota == nullptr){
        return -1;
    }
    fseek(pCuota,pos*sizeof(Cuota),0);
    int escribio=fwrite(&cu, sizeof(Cuota), 1, pCuota);
    fclose(pCuota);
    return escribio;
}
int ArchivoCuota::modificarCuota(int idCuota){}

Cuota ArchivoCuota::leerRegistro(int pos){
    Cuota cu;
    FILE *pCuota;
    pCuota = fopen("cuotas.dat","rb");
    if(pCuota==nullptr){
        cout << "Eror de archivo." << endl;
        return cu;
    }
    fseek(pCuota,pos*sizeof(Cuota),0);
    fread(&cu, sizeof(Cuota), 1, pCuota);
    fclose(pCuota);
    return cu;
}

bool ArchivoCuota::bajaLogica(){
    Cuota cu;
    ArchivoCuota archiCuota;
    int id;
    cout << "ingresar id de la cuota a eliminar: ";
    cin >> id;
    int encontro = archiCuota.buscarCuotaPorID(id);
    if (encontro < 0){
        cout << "No existe un registro con ese id." << endl;
        return false;
    }
    cu=archiCuota.leerRegistro(encontro);
    if (cu.getEstado()==false){
        cout << "Ya estaba eliminado. " << endl;
        return false;
    } else {
        cu.setEstado(false);
        if(archiCuota.modificarRegistro(cu,encontro)==1){
            cout << "Eliminado con éxito. " << endl;
           return true;
        } else { return false;}
    }
}

bool ArchivoCuota::pagarCuota(int idCuota) {
    ArchivoCuota archi;
    int pos = archi.buscarCuotaPorID(idCuota);
    if (pos == -1) {
        cout << "No hay una cuota con ese ID." << endl;
        return false;
    }

    Cuota cu = archi.leerRegistro(pos);

    if (!cu.getEstado()) {
        cout << "La cuota fue eliminada y no puede pagarse." << endl;
        return false;
    }

    if (cu.getPagada()) {
        cout << "La cuota ya estaba pagada." << endl;
        return false;
    }

    cu.setPagada(true);

    if (archi.modificarRegistro(cu, pos) == 1) {
        cout << "Registro de pago exitoso." << endl;
        return true;
    } else {
        cout << "No se pudo modificar el registro." << endl;
        return false;
    }
}
