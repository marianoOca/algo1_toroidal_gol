#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(esPeriodicoTEST, toroideHorizontalPeriodico2){
    toroide t = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

//testsad
TEST(esPeriodicoTEST, toroide_PentaDecathlon){
    toroide t = {{false, false, false, false, false, false, false, false, false, false, false},
                 {false, false, false, false, false, false, false, false, false, false, false},
                 {false, false, false, false, true, true, true, false, false, false, false},
                 {false, false, false, false, false, false, false, false, false, false, false},
                 {false, false, false, true, false, false, false, true, false, false, false},
                 {false, false, false, true, false, false, false, true, false, false, false},
                 {false, false, false, false, false, false, false, false, false, false, false},
                 {false, false, false, false, true, true, true, false, false, false, false},
                 {false, false, false, false, false, false, false, false, false, false, false},
                 {false, false, false, false, false, false, false, false, false, false, false},
                 {false, false, false, false, true, true, true, false, false, false, false},
                 {false, false, false, false, false, false, false, false, false, false, false},
                 {false, false, false, true, false, false, false, true, false, false, false},
                 {false, false, false, true, false, false, false, true, false, false, false},
                 {false, false, false, false, false, false, false, false, false, false, false},
                 {false, false, false, false, true, true, true, false, false, false, false},
                 {false, false, false, false, false, false, false, false, false, false, false},
                 {false, false, false, false, false, false, false, false, false, false, false}

    };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 15);
}

TEST(esPeriodicoTEST, toroideMuerto){
    toroide t = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}

TEST(esPeriodicoTEST, toroidePasaAMorir){
    toroide t ={{false, false, false, false, false},
                {true, false, false, false, false},
                {false, false, false, false, false},
                {false, false, false, true, false},
                {false, false,false, false, false}
    };
    int p;
    int p0=p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    //EXPECT_EQ(p0, p);
}

TEST(esPeriodicoTEST, torroideConPeriodo1){
    toroide t = {
            {false, false, false, false, false},
            {false, false, true, true, false},
            {false, false, true, true, false},
            {false, false, false, false, false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}

TEST(esPeriodicoTEST, torCte){
    toroide t = {
            {true, false, false, false, true},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {true, false,false, false, true} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}

TEST(esPeriodicoTEST, torNorm){
    toroide t = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false, false, true, false} };
    int p;
    int p0=p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    //EXPECT_EQ(p0, p);
}
/*
//testIlegal
TEST(esPeriodicoTEST, pseudoPer){
    toroide t = {
            {true, false, false, false, true},
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, false, false, false},
            {true, false,false, false, true} };
    int p;
    int p0=p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p0, p);
}*/
