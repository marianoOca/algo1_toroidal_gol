#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(vistaTrasladadaTEST, muevoTerceraFilaParaArriba){
    toroide t1 = { 
                  {true, false, false}, // 1
                  {false, true, false}, // 2
                  {false, false, true}};// 3
    toroide t2 = { 
                  {false, false, true}, // 3
                  {true, false, false}, // 1
                  {false, true, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DiagonalVsTodoTrue){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}}; 
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

//testsad
TEST(vistaTrasladadaTEST, CuatroADerechaYTresHaciaAbajo){
    toroide t1 = {
            {false, false, false, false, false, false, false, false},
            {false, true, true, true, true, true, true, false},
            {false, false, false, false, false, false, false, false},
            {false, false, false, false, true, false, false, false},
            {false, false, false, false, true, false, false, false},
            {false, false, false, false, false, false, false, false}};
    toroide t2 = {
            {true, false, false, false, false, false, false, false},
            {true, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false},
            {true, true, true, false, false, true, true, true},
            {false, false, false, false, false, false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DosALaDerecha){
    toroide t1 = {
            {true, false, false, false},
            {true, false, false, false},
            {true, false, true, false}};
    toroide t2 = {
            {false, false, true, false},
            {false, false, true, false},
            {true, false, true, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, NoEsVistaTrasladada){
    toroide t1 = {
            {true, true, false, false},
            {true, false, true, false},
            {false, false, true, false}};
    toroide t2 = {
            {true, false, false, true},
            {false, true, false, false},
            {false, false, true, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

TEST(vistaTrasladadaTEST, DosALaIzquierdaYUnoHaciaAbajo){
    toroide t1 = {
            {true, true, false, false},
            {true, false, true, false},
            {false, false, true, false},
            {false, false, true, false}};
    toroide t2 = {
            {true, false, false, false},
            {false, false, true, true},
            {true, false, true, false},
            {true, false, false, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, NoEsVistaTrasladada2){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    toroide t2 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

TEST(vistaTrasladadaTEST, elMismo){
    toroide t1 = {
            {true, true, false, false},
            {true, false, true, false},
            {false, false, true, false},
            {false, false, true, false}};
    toroide t2 = {
            {true, true, false, false},
            {true, false, true, false},
            {false, false, true, false},
            {false, false, true, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, todoTrue) {
    toroide t1 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};
    toroide t2 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, esquinas){
    toroide t1 = {
            {true, true, false},
            {false, false, false},
            {false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, true, true}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, test){
    toroide t1 = {
            {false, true, true},
            {false, false, false},
            {false, false, false}};
    toroide t2 = {
            {false, false, false},
            {true, false, false},
            {false, false, true}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}