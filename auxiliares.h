#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;

pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);

//Ejercicio 01
int filas (vector<vector<bool>> const &t);
int columnas (vector<vector<bool>> const &t);

//Ejercicio 02
int cantidadVivas (toroide const &t);

//Ejercicio 04
int nuevaF(toroide const &t, int f);
int nuevaC(toroide const &t, int c);
bool estaVivo(toroide const &t, posicion x);
int cantVecinosVivos(toroide const &t, posicion x);

//Ejercicio 07
bool sonIguales(toroide const &t0,toroide const &t1);
bool toroideVivo(toroide const &t);

//Ejercicio 09
int indiceDelMayor(vector<int> v);
int ticksHastaMorir(toroide const &t);
vector<int> cuantoTardanEnMorirCadaUno(vector <toroide> const &ts);

//Ejercicio 11
toroide trasladar(toroide const &t, int f, int c);

//Ejercicio 12
int buscarRectanguloMasChico(toroide const &t);


#endif //REUNIONESREMOTAS_AUXILIARES_H