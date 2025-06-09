#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(fusionarTEST, sinInterseccion){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, true, true},
                  {true, false, true},
                  {true, true, false}};

    toroide tout = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, cincoPorCinco){
    toroide t1 = {
            {true,  false, true,  true,  true },
            {true,  true,  false, true,  false},
            {false, false, true,  false, false},
            {false, true,  false, true,  true },
            {true,  true,  false, false, true },};
    toroide t2 = {
            {false, true, false, true, false},
            {true,  true, false, true, true },
            {false, true, false, true, false},
            {true,  true, false, true, true },
            {false, true, true,  true, false},};

    toroide tout = {
            {false, false, false, true,  false},
            {true,  true,  false, true,  false},
            {false, false, false, false, false},
            {false, true,  false, true,  true },
            {false, true,  false, false, false},};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, cruzLarga){
    toroide t1 = {
            {true,  false, false, false, false, false, false},
            {false, true,  true,  true,  false, false, false},
            {false, false, false, true,  true,  true,  false},
            {false, false, false, false, false, false, true }};
    toroide t2 = {
            {false, false, false, false, false, false, true},
            {false, false, false, true,  true,  true,  false},
            {false, true,  true,  true,  false, false, false},
            {true,  false, false, false, false, false, false}};

    toroide tout = {
            {false, false, false, false, false, false, false},
            {false, false, false, true,  false, false, false},
            {false, false, false, true,  false, false, false},
            {false, false, false, false, false, false, false}};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}