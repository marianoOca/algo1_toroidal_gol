#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}

//testsad
TEST(densidadPoblacionTEST, toroideMuerto){
    vector<bool> a = { false, false, false , false };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 0.0, 0.00);
}

TEST(densidadPoblacionTEST, columnaMuerta){
    vector<bool> a = { true, false, true , true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 0.75, 0.001);
}

TEST(densidadPoblacionTEST, unoSoloVivo) {
    toroide t = {
            {false, false, false},
            {false, true,  false},
            {false, false, false},
            {false, false, false}
    };
    EXPECT_NEAR(densidadPoblacion(t), 0.0833, 0.001);

}

TEST(densidadPoblacionTEST, algunasVivas){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true},
            {true, false, false},
            {false, true, false},
            {false, false, true}
    };
    EXPECT_NEAR(densidadPoblacion(t), 0.3333, 0.001);
}

TEST(densidadPoblacionTEST, mitadMuerto){
    vector<bool> a = { false, false, false, false };
    vector<bool> b = { true, true, true, true };
    toroide t = { a, a, a, b, b, b};
    EXPECT_NEAR(densidadPoblacion(t), 0.5, 0.01);
}
