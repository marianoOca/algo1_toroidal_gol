#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(esPeriodicoTEST, toroideHorizontalPeriodico2){
    toroide t = { 
                  {false, false, false, false, false},
                  {false, false, false, false, false},
                  {false, true,  true,  true,  false},
                  {false, false, false, false, false},
                  {false, false, false, false, false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

TEST(esPeriodicoTEST, sarmientoEnHoraPico){
    toroide t = {
            {true, true, true, true, true,  true, true, true, true},
            {true, true, true, true, true,  true, true, true, true},
            {true, true, true, true, true,  true, true, true, true},
            {true, true, true, true, true,  true, true, true, true},
            {true, true, true, true, false, true, true, true, true}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
}

TEST(esPeriodicoTEST, miniPeriodico){
    toroide t = {
            {true, false, true },
            {false, true, false},
            {false, true, false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}

TEST(esPeriodicoTEST, miniNoPeriodico){
    toroide t = {
            {true,  true, true },
            {false, true, false},
            {false, true, false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
}

TEST(esPeriodicoTEST, patronNoPeriodico){

    toroide t = {{false, false, false, false, false, false, false, false},
                 {true,  false, false, false, false, false, false, false},
                 {false,  true, true,  false, false, false, false, false},
                 {true,  false, false, true,  false, false, false, false},
                 {false,  true, true,  false, false, false, false, false},
                 {false, false, false, false, false, false, false, false},
                 {false, false, false, false, false, false, true,  true},
                 {false, false, false, false, false, false, true,  true}};
    int p;
    int p0 = p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, p0);
}

TEST(esPeriodicoTEST, smallExplosion) {
    toroide t = {
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, true, false, false ,false, false, false},
            {false, false, false, false, true, true, true, false ,false, false, false},
            {false, false, false, false, true, false, true, false ,false, false, false},
            {false, false, false, false, false, true, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false}};
    int p = 0;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, 0);
}