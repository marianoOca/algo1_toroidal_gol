#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(primosLejanosTEST, toroideHorizontalPeriodico2){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true,  true,  true,  false},
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}};
    toroide t2 = {
                  {false, false, false, false, false}, 
                  {false, false, true,  false, false},
                  {false, false, true,  false, false},
                  {false, false, true,  false, false},
                  {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, uno3TiksDespues){
    toroide t1 = {
            {true,  false, false, false, false, false, false},
            {false, true,  true,  true,  false, false, false},
            {false, false, false, true,  true,  true,  false},
            {false, false, false, false, false, false, true }};
    toroide t2 = {
            {false, false, false, false, false, true,  false},
            {true,  false, false, false, false, false, false},
            {false, false, false, false, false, false, true },
            {false, true,  false, false, false, false, false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, parecidosPeroNoIguales){
    toroide t1 = {
            {true,  false, false, false, false, false, false},
            {false, true,  true,  true,  false, false, false},
            {false, false, false, true,  true,  true,  false},
            {false, false, false, false, false, false, true }};
    toroide t2 = {
            {false, false, false, false, false, true,  false},
            {true,  false, false, false, false, false, false},
            {false, false, false, false, false, false, true },
            {true, false,  false, false, false, false, false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, periodicoYNoPeriodico){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, true, false,  false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, mismoToroideNoPeriodico) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2) || primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, mismoToroidePeriodico) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2) || primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, toroidesIgualesNoPeriodicos) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, true, false}
    };

    EXPECT_FALSE(primosLejanos(t, t));
}

TEST(primosLejanosTEST, ambosMuertos) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, toroidesIgualesPeriodicos) {
    toroide t = {
            {true,  true,  false},
            {true,  true,  false},
            {false, false, false}
    };

    EXPECT_TRUE(primosLejanos(t, t));
}