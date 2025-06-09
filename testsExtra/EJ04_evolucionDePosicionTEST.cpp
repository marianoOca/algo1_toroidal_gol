#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(evolucionDePosicionTEST, toroideDiagonalTresPorTres){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, NoRevivePorCincoVecinosVivos){
    toroide t = { {false, true, true}, {false, true, false}, {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,0)));
}

//testsad
TEST(evolucionDePosicionTEST, muerePorSobrepoblacion){
    toroide t = { {true, true, true},
                  {true, true, true},
                  {true, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(0,2)));
}
TEST(evolucionDePosicionTEST, muerePorSoledad){
    toroide t = { {false, false, false},
                  {false, true, false},
                  {false, false, true} };
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, pasaAVivir) {
    toroide t = {{false, true, false, true, false, true},
                 {true, true, true, false, false, true},
                 {true, false, true, false, true, false},
                 {false, true, true, true, false, false},
                 {false, false, true, false, true, false},
                 {true, false, true, false, false, true}};
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(3, 5)));
}

TEST(evolucionDePosicionTEST, toroideMuerto){
    vector<bool> fila = {false, false, false, false, false};
    toroide t = {fila, fila, fila, fila ,fila, fila, fila};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(3,3)));
}

TEST(evolucionDePosicionTEST, NoRevive){
    toroide t = {
            {true, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(0,0)));
}

TEST(evolucionDePosicionTEST, vive){
    toroide t = {
            {true, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,2)));
}
