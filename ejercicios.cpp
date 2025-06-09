#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"


// EJERCICIO 01
bool toroideValido(vector<vector<bool>> const &t) {
    int largoCol = t.size();
    bool res = true;

    if ( filas(t) < 3 || columnas(t) < 3 ) return false;    // chequeamos que sea de al menos 3x3

    for(int i =0 ; i < largoCol-1 ; i++){                   // que todas las filas tengan el mismo largo
        res = res && (t[i].size() == t[i+1].size());
    }

    return res;
}


// EJERCICIO 02
vector<posicion> posicionesVivas(toroide const &t) {
    int largoCol = t.size(), largoFil = t[0].size();
    vector<posicion> vivos {};

    for(int i = 0 ; i < largoCol ; i++){
        for(int j = 0 ; j < largoFil ; j++){
            if( t[i][j] ) vivos.push_back(mp(i, j));    // si está vivo lo guarda
        }
    }

    return vivos;
}


// EJERCICIO 03
float densidadPoblacion(toroide const &t) {

    return 1.0 * cantidadVivas(t) / (filas(t) * columnas(t));
}


// EJERCICIO 04
bool evolucionDePosicion(toroide const &t, posicion x) {
                                                                        // para que viva tiene que
    if (cantVecinosVivos(t, x) == 3) return true;                       // tener 3 vecinos vivos o
    if (cantVecinosVivos(t, x) == 2 && estaVivo(t, x) ) return true;    // estar vivo y tener 2 vecinos vivos
                                                                        // en cualquier otro caso
    return false;                                                       // muere o permanece muerto
}


// EJERCICIO 05
void evolucionToroide(toroide &t){
    int largoCol = t.size(), largoFil = t[0].size();
    toroide t0 = t;

    for(int i = 0 ; i < largoCol ; i++) {
        for(int j = 0 ; j < largoFil ; j++) {
            t[i][j] = evolucionDePosicion(t0, mp(i, j) );
        }
    }
}


// EJERCICIO 06
toroide evolucionMultiple(toroide const &t, int n) {
    toroide out = t;

    for( int i = 0 ; i < n ; i++) evolucionToroide(out);

    return out;
}


// EJERCICIO 07
bool esPeriodico(toroide const &t, int &p) {
    int n = 1;
    toroide t1 = evolucionMultiple(t, 1);

    while( !sonIguales(t, t1) && toroideVivo(t1)){  //evoluciona hasta que se repita o muera
        t1 = evolucionMultiple(t1, 1);
        n++;
    }

    if(sonIguales(t, t1)){
        p = n;
        return true;
    } else {
        return false;
    }
}


// EJERCICIO 08
bool primosLejanos(toroide const &t, toroide const &u) {
    toroide t1 = t, u1 = u;
    int ticksT, ticksU, i = 0, q;

    if(sonIguales(t, u) && !esPeriodico(t, q)) return false;

    if (esPeriodico(u, ticksU)){                                         // si el toroide es periódico corto la búsqueda cuando
        while( !sonIguales(t, u1) && toroideVivo(u1) && i <= ticksU+1 ){    // supero los tiks que este tarda en reiterarse
            u1 = evolucionMultiple(u1, 1);
            i++;
        }
    } else {
        while( !sonIguales(t, u1) && toroideVivo(u1)){                      // igualemente corto cuando son iguales o muere
            u1 = evolucionMultiple(u1, 1);
        }
    }

    if( sonIguales(t, u1) ) return true;

    if (esPeriodico(t, ticksT)){                                        // repito lo mismo con el otro toroide
        i = 0;
        while( !sonIguales(u, t1) && toroideVivo(t1) && i <= ticksT+1 ){
            t1 = evolucionMultiple(t1, 1);
            i++;
        }
    } else {
        while( !sonIguales(u, t1) && toroideVivo(t1)){
            t1 = evolucionMultiple(t1, 1);
        }
    }

    return sonIguales(u, t1);
}


// EJERCICIO 09
int seleccionNatural(vector <toroide> const &ts) {

    vector<int> avisosFunebres = cuantoTardanEnMorirCadaUno(ts);

    return indiceDelMayor(avisosFunebres);
}


// EJERCICIO 10
toroide fusionar(toroide const &t, toroide const &u) {
    if( columnas(t) != columnas(u) || filas(t) != filas(u) ) return {{}};   // cuido que tengan el mismo tamaño

    toroide out = t;                                                        // guardo en out a t

    for(int i = 0 ; i < t.size() ; i++) {
        for(int j = 0 ; j < t[i].size() ; j++) {
            if( !u[i][j] ) out[i][j] = false;                               // donde u es false también out
        }
    }

    return out;                                                             // quedando sólo donde ambos son true
}


// EJERCICIO 11
bool vistaTrasladada(toroide const &t, toroide const &u){
    if( columnas(t) != columnas(u) || filas(t) != filas(u) ) return false;  // cuido que tengan el mismo tamaño
    int largoCol = t.size(), largoFil = t[0].size();

    bool res = false;

    for(int i = 0 ; i < largoCol ; i++) {
        for(int j = 0 ; j < largoFil ; j++) {
            res |= sonIguales(t, trasladar(u,i, j));                        // hago todas las traslaciones posibles
        }
    }

    return res;
}


// EJERCICIO 12
int menorSuperficieViva(toroide const &t){
    if( !toroideVivo(t) ) return 0;                                     // si el toroide está muerto devuelvo 0
    int largoCol = t.size(), largoFil = t[0].size();

	int res = buscarRectanguloMasChico(t), candidato;

    for(int i = 0 ; i < largoCol ; i++) {
        for(int j = 0 ; j < largoFil ; j++) {
            candidato = buscarRectanguloMasChico(trasladar(t,i, j));    // busco y guerdo el rectángulo más chico
            if(candidato < res) res = candidato;                        // de todas las traslaciones posibles
        }
    }

	return res;
}