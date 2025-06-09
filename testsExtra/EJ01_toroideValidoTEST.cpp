#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(toroideValidoTEST, toroideVacio){
    toroide t = { vector<bool> () };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, toroideVacio5Filas){
    vector<bool> vacio;
    toroide t = { vacio, vacio, vacio, vacio, vacio };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, diagonalTresPorTres) {
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}
    };
    EXPECT_TRUE(toroideValido(t));
}

//testsad
TEST(toroideValidoTEST, distintaCantidadColumnas){
    toroide t = { {true, false, false},
                  {false, true, false, true},
                  {false, false, true}
    };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, distintaCantidadColumnas2) {
    toroide t = { {true, false, false},
                  {false, true, true},
                  {false, false}
    };
    EXPECT_FALSE(toroideValido(t));
}
