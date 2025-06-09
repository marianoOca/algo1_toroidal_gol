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

//testsad
TEST(fusionarTEST, interseccion1){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};
    toroide tout = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, toroideMuerto){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    toroide t2 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};
    toroide tout = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, todosVivos){
    toroide t1 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};
    toroide t2 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};
    toroide tout = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};
    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, todosMuertos){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    toroide tout = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, intersec){
    toroide t1 = {
            {true, true, false},
            {false, true, false},
            {false, true, true}};
    toroide t2 = {
            {false, true, true},
            {true, true, true},
            {true, true, false}};
    toroide tout = {
            {false, true, false},
            {false, true, false},
            {false, true, false}};
    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}
