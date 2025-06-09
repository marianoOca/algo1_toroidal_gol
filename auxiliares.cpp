#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;

pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

//Ejercicio 01
int filas(vector<vector<bool>> const &t){ return t.size(); }

int columnas(vector<vector<bool>> const &t){
    int largoCol = t.size();
    if (largoCol != 0) return t[0].size();
    return 0;
}

//Ejercicio 03
int cantidadVivas(toroide const &t){
    int largoCol = t.size(), largoFil = t[0].size();
    int vivas=0;

    for(int i = 0 ; i < largoCol ; i++){
        for(int j = 0 ; j < largoFil ; j++){
            if (t[i][j] == true) vivas++;
        }
    }

    return vivas;
}

//Ejercicio 04
int nuevaF(toroide const &t, int f){            // hago que f quede dentro del rango del toroide
    while ( f < 0) f += filas(t);
    while ( f > filas(t) - 1) f -= filas(t);
    return f;
}

int nuevaC(toroide const &t, int c){            // hago que c quede dentro del rango del toroide
    while ( c < 0) c += columnas(t);
    while ( c > columnas(t) - 1) c -= columnas(t);
    return c;
}

bool estaVivo(toroide const &t, posicion x){

    return t[ nuevaF(t, get<0>(x) ) ][ nuevaC(t, get<1>(x) ) ];
}

int cantVecinosVivos(toroide const &t, posicion x){
    int vivos = 0;

    for(int i = get<0>(x)-1 ; i <= get<0>(x)+1 ; i++){
        for(int j = get<1>(x)-1 ; j <= get<1>(x)+1 ; j++){
            if( estaVivo(t, mp(i, j))  ) vivos ++;
        }
    }

    if(estaVivo(t, x)) vivos--;

    return vivos;
}

//Ejercicio 07
bool sonIguales(toroide const &t0,toroide const &t1){
    if( columnas(t0) != columnas(t1) || filas(t0) != filas(t1) ) return false;  // cuido que tengan el mismo tamaño
    int largoCol = t0.size(), largoFil = t0[0].size();
    bool res = true;

    for(int i = 0 ; i < largoCol ; i++) {
        for(int j = 0 ; j < largoFil ; j++) {
            res &=  t0[i][j] == t1[i][j];
        }
    }

    return res;
}

bool toroideVivo(toroide const &t){
    return cantidadVivas(t) >= 1;
}

//Ejercicio 09
vector<int> cuantoTardanEnMorirCadaUno(vector <toroide> const &ts) {
    int largoVector = ts.size();
    if (largoVector == 0) return {-1};

    vector<int> v {};
    v.reserve(largoVector);

    for(int i = 0 ; i < largoVector ; i++){
        v.push_back(ticksHastaMorir(ts[i]));
    }

    return v;
}

int ticksHastaMorir( toroide const &t){
    if ( !toroideVivo(t) ) return 0;                // si está muerto devuelve 0

    toroide t1 = evolucionMultiple(t, 1);
    int tiks = 1;

    while( !sonIguales(t, t1) && toroideVivo(t1)){
        t1 = evolucionMultiple(t1, 1);
        tiks++;
    }

    if( sonIguales(t, t1) ) return (-1);            //si se cumple son periódicos
    return tiks;
}

int indiceDelMayor(vector<int> v){
    int largoVec = v.size();
    if (largoVec == 0) return (-1);                 // cuida que el vector no esté vacío

    int m = 0;
    for(int i = 1 ; i < largoVec ; i++){
        if( v[i] > v[m] ) m = i;
    }

    return m;
}


//Ejercicio 11
toroide trasladar(toroide const &t, int f, int c){
    int largoCol = t.size(), largoFil = t[0].size();
    toroide out = t;                                            // forma fácil de hacer que out tenga el mismo tamaño de t

    for(int i = 0 ; i < largoCol ; i++) {
        for(int j = 0 ; j < largoFil ; j++) {
            out[i][j] = t[nuevaF(t,i+f)][nuevaC(t,j+c)];
        }
    }

    return out;
}

//Ejercicio 12
int buscarRectanguloMasChico(toroide const &t){
    int largoCol = t.size(), largoFil = t[0].size();
    int h = -1, b = largoCol, i = -1, d = largoFil, j;

    bool buscador = false;                          // busco el más alto
    while(!buscador && h < largoCol){
        h++;
        j = 0;
        while( !buscador && j < largoFil ){
            buscador = t[h][j];
            j++;
        }
    }

    buscador = false;                               //busco el más bajo
    while(!buscador && b >=0){
        b--;
        j = largoFil-1;
        while( !buscador && j >= 0 ){
            buscador = t[b][j];
            j--;
        }
    }

    buscador = false;                               //busco el más a la izquierda
    while(!buscador && i < largoCol){
        i++;
        j = 0 ;
        while(!buscador && j < largoCol){
            buscador = t[j][i];
            j++;
        }
    }

    buscador = false;                               //busco el más a la derecha
    while(!buscador && d >=0){
        d--;
        j = largoCol-1;
        while( !buscador && j >=0 ) {
            buscador = t[j][d];
            j--;
        }
    }

    return (b - h + 1)*(d - i + 1);                 // sumo 1 para corregir la diferencia
}