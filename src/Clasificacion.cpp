#include "Clasificacion.h"
#include "Prueba.h"
#include <iostream>


using namespace std;

#define SALTO 4

Clasificacion::Clasificacion(){
    Participante par;
    par.indice = 0;
    par.dorsal = 0;
    par.marca = 0;
    tamano=SALTO;
    participantes=0;
    elementos = new Participante [tamano];

}
Clasificacion::~Clasificacion()
{
    Participante par;
    participantes = 0;
    tamano = 0;
    par.indice = 0;
    par.dorsal = 0;
    par.marca = 0;
    delete[] elementos;

}
void Clasificacion::anadirparticipante(Participante a){
    if(participantes==tamano){
        tamano=tamano+SALTO;
        Participante *aux= new Participante[tamano];

        for(int i=0;i<=participantes;i++){
            aux[i]=elementos[i];
        }
        delete[] elementos;
        elementos = aux;
        elementos[participantes] = a;
        participantes++;
    }else{
        elementos[participantes]=a;
        participantes++;
    }

}

void Clasificacion::eliminar(int i){
    if(i > 0 && i<= participantes){
        Participante *aux= new Participante[tamano];

        for(int x=0; x<=participantes;x++){
            if(x != i-1){
                aux[x] = elementos[x];
            }
        }
        delete[] elementos;
        elementos=aux;
        delete[] aux;
        participantes--;

    }else{
        cout << "No existe esa posicion. "<<endl;

    }
}

void Clasificacion::ordenar(){
    int pos,ele;
        for (pos=0; pos<numpartipantes(); pos++){
            for (ele=numpartipantes(); ele>pos; ele--){
                if(elementos[ele-1].marca>elementos[ele].marca){
                    //intercambiar(elementos[ele-1],elementos[ele]);//Función genérica que tendrá que ser implementada
                    Participante par = elementos[ele];
                    elementos[ele]=elementos[ele-1];
                    elementos[ele-1]=par;
                }
            }
        }
}

Participante Clasificacion::consultar(int i){
    Participante pa;
    if(i >= 0 && i <= participantes){
        pa=elementos[i];
    }
    return pa;

}

bool Clasificacion::vacio(){
    bool vacio = false;
    if(participantes==0){
        vacio = true;
    }
    return vacio;
}

int Clasificacion::numpartipantes(){
    return participantes;
}
