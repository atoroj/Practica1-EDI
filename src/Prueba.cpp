#include "Prueba.h"
#include "Clasificacion.h"

#include <iostream>;
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
Prueba::Prueba(char FicheroOrigen[],char FicheroDestino[])
{
    int a;
    Ciclista C;
    fich.open(FicheroOrigen, ios::in | ios::binary);
    fichero.open(FicheroDestino,ios::out);
    if(!fich)
    {
       numCiclistas=0;
       fichero.write((char*)numCiclistas,sizeof(int));
    }
    else
    {
        numCiclistas=0;
        fich.read((char*)&a, sizeof(int));
        fichero.seekp(sizeof(int),ios::beg);
        while(!fich.eof())
        {
            numCiclistas=numCiclistas+a;
            for(int i=0;i<a;i++)
            {

                fich.read((char*)&C,sizeof(Ciclista));
                fichero.write((char*)&C,sizeof(Ciclista));
            }
            fich.read((char*)&a, sizeof(int));
        }
        fich.close();
        fichero.seekp(0,ios::beg);
        fichero.write((char*)&numCiclistas,sizeof(int));
        fichero.close();
        fichero.open(FicheroDestino,ios::in|ios::out|ios::binary);
    }

}
int Prueba::getNumCiclistas()
{
    return numCiclistas;
}

void Prueba::mostrar(cadena pais)
{
    Ciclista c;
    fichero.seekg(sizeof(int),ios::beg);
    for(int i = 0; i<getNumCiclistas(); i++)
    {
        fichero.read((char*)&c, sizeof(Ciclista));

        if(strcmp(pais, "*")==0)
        {
            cout << "Dorsal " <<c.dorsal << endl;
            cout << "Pais " <<c.pais << endl;
            cout << "Nombre " <<c.nombre << endl;
            cout << "Apellidos " <<c.apellidos << endl;
            cout << "Marca " <<c.marca << endl;
            cout << "Posicion " <<c.posicion << endl;
            cout << endl;
        }
        else if(strcmp(pais, c.pais)==0)
        {
            cout << "Dorsal " <<c.dorsal << endl;
            cout << "Pais " <<c.pais << endl;
            cout << "Nombre " <<c.nombre << endl;
            cout << "Apellidos " <<c.apellidos << endl;
            cout << "Marca " <<c.marca << endl;
            cout << "Posicion " <<c.posicion << endl;
            cout << endl;
        }
        else
        {
            cout << "No existe el pais" << endl;
            break;
        }
    }
}

Ciclista Prueba::consultar(int posicion)
{
    Ciclista ciclista, c;
    fichero.seekg(sizeof(int),ios::beg);
    for(int i = 0; i<=getNumCiclistas(); i++)
    {
        fichero.read((char*)&c, sizeof(Ciclista));
        if(posicion==i)
        {
            ciclista=c;
            break;
        }
    }
    return ciclista;
}

int Prueba::buscar(int dor){
    Ciclista c;
    int posi = -1;
    fichero.seekg(sizeof(int),ios::beg);
    for(int i = 1; i<=getNumCiclistas(); i++){
        fichero.read((char*)&c, sizeof(Ciclista));
        if(dor==c.dorsal){
            posi=i;
        }
    }
    return posi;
}

void Prueba::insertar(Ciclista c){
    Ciclista ci, sigCiclista;
    bool encontrado = false;
    int posi = -1;
    if(buscar(c.dorsal)==-1){
        for(int i = 1; i<getNumCiclistas(); i++){
                ci = consultar(i);
            if(strcmp(c.pais,ci.pais)==0){
                encontrado = true;
                posi = i;
            }
        }
        if(!encontrado){
            fichero.seekp(ios::app);
            fichero.write((char*)&c, sizeof(Ciclista));
        }else{
            sigCiclista = consultar(posi+1);
            numCiclistas++;
            while(posi<getNumCiclistas()){
                fichero.clear();
                fichero.seekp(sizeof(int)+sizeof(Ciclista)*(posi+1), ios::beg);
                fichero.write((char*)&c, sizeof(Ciclista));
                c=sigCiclista;
                posi++;
                sigCiclista = consultar(posi+1);
           }
        }
    }else{
        cout << "El dorsal ya existe" << endl;
    }

}

void Prueba::modificar(Ciclista c,int posicion)
{
    Ciclista aux;
    if(fichero.is_open())
    {
        if(buscar(c.dorsal) != -1)
        {
            fichero.seekg(sizeof(int)+(sizeof(Ciclista)*posicion),ios::beg);
            fichero.read((char*) &aux,sizeof(Ciclista));
            strcpy(c.pais,aux.pais);
            fichero.seekp(sizeof(int)+(sizeof(Ciclista)*posicion),ios::beg);//me posiciono en la posicion pasada por parametro
            fichero.write((char*) &c, sizeof(Ciclista));//escribo en el fichero el ciclista pasado por parametro.
        }else
        {
            cout << "No se ha encontrado el ciclista";
        }
    }
}

void Prueba::eliminar(int posicion){
    int i = 0;
    Ciclista aux,aux1;
    int numerocicli = 0;
    bool encontrado = false;
    if(fichero.is_open())
    {
        for(int e = posicion; e < numCiclistas;e++)
        {
            fichero.seekg(sizeof(int)+sizeof(Ciclista)*(e+1));//nos posicionamos en la posicion siguiente
            fichero.read((char*) &aux1,sizeof(Ciclista));//lo guardamos en el aux1
            fichero.seekp(sizeof(int)+sizeof(Ciclista)*e);
            fichero.write((char*) &aux1,sizeof(Ciclista));
        }
        numCiclistas--;
    }
}
int marcas() {
    return (rand()%300 + 7000);
}

void horasMinutosSegundos(int sec){
    int segundos, hor, minutos;
    segundos = sec;
    hor = segundos / (60*60);
    segundos %= 60*60;
    minutos = segundos / 60;
    segundos %= 60;
    cout << "La marca es "<< hor << " : " << minutos << " : " << segundos << endl;
}

void Prueba::ClasificacionCarrera(){
    Participante *p;
    Clasificacion c;
    Ciclista cic;
    p = new Participante[getNumCiclistas()];
    srand((unsigned) time(0));
    for(int i = 0; i<getNumCiclistas(); i++){

        //AÑADO LOS DATOS A EL ARRAY DE PARTICIPANTES
        p[i].marca = marcas();
        cic = consultar(i);
        p[i].indice = i;
        p[i].dorsal = cic.dorsal;

        //MODIFICO DATOS DEL CICLISTA PARA PONERLE LA MARCA Y POSICION
        cic.marca = p[i].marca;
        cic.posicion = i;
        modificar(cic,i);

        //AÑADO TODOS LOS PARTICIPANTES QUE HE CREADO EN EL ARRAY
        c.anadirparticipante(p[i]);
    }
    c.ordenar();

    for(int i = 0; i<getNumCiclistas(); i++){
        cic = consultar(c.consultar(i).indice);
        cout << "El nombre es: " <<cic.nombre << endl;
        cout << "El apellido es: " <<cic.apellidos << endl;
        cout << "El pais es: " <<cic.pais<< endl;
        cout << "El dorsal es: " <<cic.dorsal<< endl;
        horasMinutosSegundos(cic.marca);
        cout << "La posicion es: " <<cic.posicion << endl;
        cout << endl;
    }
}




