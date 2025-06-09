#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true,  false, false, true },  // 1
            {false, false, false, false},  // 2
            {false, false, false, false},  // 3
            {true,  true,  false, false}}; // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST, unoSoloEnToroideAncho){
    toroide t = {
            {false, false, false, false, false, false, false, false},  // 1
            {false, false, false, false, false, false, false, false},  // 2
            {true,  false, false, false, false, false, false, false}}; // 3

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, toroideLleno){
    toroide t = {
            {true, true, true, true},  // 1
            {true, true, true, true},  // 2
            {true, true, true, true},  // 3
            {true, true, true, true}}; // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 16);
}

TEST(menorSuperficieVivaTEST, toroideAlto){
    toroide t = {
            {false, false, true, false},  // 1
            {false, false, true, false},  // 2
            {false, false, true, false},  // 3
            {false, false, true, false},  // 4
            {false, false, true, false},  // 5
            {false, false, true, false},  // 6
            {false, false, true, false},  // 7
            {false, false, true, false},  // 8
            {false, false, true, false}}; // 9

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 9);
}

TEST(menorSuperficieVivaTEST, toroideIntercalado){
    toroide t = {
            {false, true,  false, true, false},  // 1
            {true,  false, true,  false, true},  // 2
            {false, true,  false, true, false},  // 3
            {true,  false, true,  false, true},  // 4
            {false, true,  false, true, false}}; // 5

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 25);
}

TEST(menorSuperficieVivaTEST, toroideMuerto){
    toroide t = {
            {false, false, false, false},  // 1
            {false, false, false, false},  // 2
            {false, false, false, false}}; // 3

    EXPECT_EQ(menorSuperficieViva(t), 0);
}