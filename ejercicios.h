#ifndef EJERCICIOS_H
#define EJERCICIOS_H

#include "definiciones.h"

bool toroideValido(vector<vector<bool>> const &t);
vector<posicion> posicionesVivas(toroide const &t);
float densidadPoblacion(toroide const &t);
bool evolucionDePosicion(toroide const &t, posicion x);
void evolucionToroide(toroide &t);
toroide evolucionMultiple(toroide const &t, int K);
bool esPeriodico(toroide const &t, int &p);
bool primosLejanos(toroide const &t, toroide const &u);
int seleccionNatural(vector <toroide> const &ts);
toroide fusionar(toroide const &t, toroide const &u);
bool vistaTrasladada(toroide const &t, toroide const &u);
int menorSuperficieViva(toroide const &t);


#endif //
