#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(evolucionDePosicionTEST, toroideDiagonalTresPorTres){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}};
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, NoRevivePorCincoVecinosVivos){
    toroide t = { {false, true, true},
                  {false, true, false},
                  {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,0)));
}

TEST(evolucionDePosicionTEST, NovivePorqueEstaSolinSolito){
    toroide t = { {false, false, false},
                  {false, true,  false},
                  {false, false, false}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, naceEnEsquinaInferiorDerecha){
    toroide t = { {true,  false, false, true },
                  {false, false, false, false},
                  {false, false, false, false},
                  {true,  false, false, false}};
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(3,3)));
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(0,0)));
}