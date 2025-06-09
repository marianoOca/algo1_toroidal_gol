#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

//testsad
TEST(menorSuperficieVivaTEST, areaMenorEsSinTraslacion){
    toroide t = {
            {false, false, false, false, false, false, false, false},
            {false, true, true, true, true, true, true, false},
            {false, false, false, false, false, false, false, false},
            {false, false, false, false, true, false, false, false},
            {false, false, false, false, true, false, false, false},
            {false, false, false, false, false, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 24);
}


TEST(menorSuperficieVivaTEST, unaCeldaViva){
    toroide t = {
            {false, false, false, true},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, areaMenorTrasladando1Abajo){
    toroide t = {
            {true, false, true, false},
            {false, false, false, false},
            {false, false, false, false},
            {true, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST, areamMenorTasladando1AbajoY1Derecha){
    toroide t = {
            {true, false, false, true},
            {false, true, false, false},
            {false, false, false, false},
            {true, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 9);
}

TEST(menorSuperficieVivaTEST, unaFilaViva){
    toroide t = {
            {true, true, true, true},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}

TEST(menorSuperficieVivaTEST, todoVivo){
    toroide t = {
            {true, true, true, true, true},
            {true, true, true, true, true},
            {true, true, true, true, true},
            {true, true, true, true, true},
            {true, true, true, true, true}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 25);
}

TEST(menorSuperficieVivaTEST, unaColumnaViva){
    toroide t = {
            {true, false, false, false},
            {true, false, false, false},
            {true, false, false, false},
            {true, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}

TEST(menorSuperficieVivaTEST, tor1){
    toroide t = {
            {true, true, false, false},
            {true, true, false, false},
            {false, false, false, false},
            {false, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}

TEST(menorSuperficieVivaTEST, unTrue){
    toroide t = {
            {true, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, dosTrue){
    toroide t = {
            {true, true, false, false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 2);
}

TEST(menorSuperficieVivaTEST, tresTrueCol){
    toroide t = {
            {true, false, false, false},
            {true, false, false, false},
            {false, false, false, false},
            {true, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 3);
}

TEST(menorSuperficieVivaTEST, tresTrue){
    toroide t = {
            {true, true, false, false},
            {true, false, false, false},
            {false, false, false, false},
            {false, false, false, false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}

TEST(menorSuperficieVivaTEST, esquinas){
    toroide t = {
            {true, false, false, true},
            {false, false, false, false},
            {false, false, false, false},
            {true, false, false, true}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}