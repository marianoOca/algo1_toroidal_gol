#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}

TEST(densidadPoblacionTEST, toroideSinDensidad){
    vector<bool> a = { false, false, false, false };
    toroide t = { a, a, a, a, a, a };
    EXPECT_EQ(densidadPoblacion(t), 0);
}

TEST (densidadPoblacionTEST, mediaDensidad){
    toroide t= { {true, false, true, false},
                 {true, false, true, false},
                 {true, false, true, false},
                 {true, false, true, false}};
    EXPECT_EQ(densidadPoblacion(t), 0.5);
}

TEST (densidadPoblacionTEST, unNovenoDensidad){
    toroide t= { {true, false, false},
                 {false, false, false},
                 {false, false, false}};
    EXPECT_NEAR(densidadPoblacion(t), 1.0/9, 0.01);
}