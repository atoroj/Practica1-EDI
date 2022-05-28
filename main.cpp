#include "Prueba.h"
#include "Clasificacion.h"

#include <iostream>

using namespace std;
    Ciclista c;
    cadena h;
    Participante part;
    Prueba p("huelvaextremapro.dat", "huelvaextrema.dat");
    Clasificacion cla;
    int opc;
int main()
{
do{
cout<< "Huelva extrema\n";
cout<< "--------------------------------------------------"<<endl;
cout<< "Ciclistas = "<< p.getNumCiclistas()<< "\n\n"<< endl;

    cout<<"1- Consulta de inscripcion"<<endl;
    cout<<"2- Inscripcion a la prueba"<<endl;
    cout<<"3- Busqueda de una inscripcion"<<endl;
    cout<<"4- Modificar datos de una inscripcion"<<endl;
    cout<<"5- Eliminar una inscripcion"<<endl;
    cout<<"6- Mostrar Clasificacion"<<endl;
    cout<<"7-Salir"<<endl;
    cout<<"\nIndique la opcion deseada:";
    cin>>opc;
    switch(opc){
        case 1:
            cadena a;
            cout<< "Mostrar participantes en la carrera. "<<endl;
            cin >>a;
            p.mostrar(a);
            break;
        case 2:
            cout << "Introduce un ciclista" << endl;
                cin >> c.nombre;
                cout << "Apellido" << endl;
                cin >> c.apellidos;
                cout << "Dorsal" << endl;
                cin >> c.dorsal;
                cout << "Marca" << endl;
                cin >> c.marca;
                cout << "Posicion" << endl;
                cin >> c.posicion;
                cout << "Pais" << endl;
                cin >> c.pais;
                p.insertar(c);
            break;
        case 3:
            int dor;
            cout << "Pasame un dorsal. "<<endl;
            cin >>dor;
            c=p.consultar(p.buscar(dor));
            cout << "Dorsal= " <<c.dorsal << endl;
            cout << "Pais= " <<c.pais << endl;
            cout << "Nombre= " <<c.nombre << endl;
            cout << "Apellidos= " <<c.apellidos << endl;
            cout << "Marca= " <<c.marca << endl;
            break;
        case 4:
            int n;
            cout << "Posicion del ciclista a modificar. "<<endl;
            cin >> n;
            cout << "Dorsal"<<endl;
            cin >>c.dorsal;
            cout << "Nombre"<<endl;
            cin >>c.nombre;
            cout << "Apellidos"<<endl;
            cin >>c.apellidos;
            cout << "Marca"<<endl;
            cin >>c.marca;
            p.modificar(c,n);
            break;
        case 5:
            int dors;
            cout << "Dorsal del ciclista a eliminar. "<<endl;
            cin >> dors;
            p.eliminar(dors);
            break;
        case 6:
            p.ClasificacionCarrera();
            break;
        case 7:
            int pos;
            cout << "Posicion a eliminar. "<<endl;
            cin >> pos;
            cla.eliminar(pos);
            cout<< "participantes: "<< cla.numpartipantes()<< "\n\n"<< endl;
            break;
    }
    } while(opc != 0);
}
