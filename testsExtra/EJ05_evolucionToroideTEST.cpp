#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionToroideTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {true, true, true}, {true, true, true}, {true, true, true} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

//testsad
TEST(evolucionToroideTEST, toroideMuerto){
    toroide t = {{false, false, false},
                 {false, false, false},
                 {false, false, false},
                 {false, false, false}
    };
    toroide evo_t = t;
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}
TEST(evolucionToroideTEST, toroidePasaAMorir){
    toroide t = {{true, false, false},
                 {false, false, false},
                 {false, true, false},
                 {false, false, false}
    };
    toroide evo_t = {{false, false, false,},
                     {false, false, false,},
                     {false, false, false,},
                     {false, false, false,}
    };
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
};

TEST(evolucionToroideTEST, toroideUnaEvolucion){
    toroide t = { {false, false, false, false, false, false, false},
                  {false, true, false, false, false, false, false},
                  {false, true, true, false, false, false, false, false},
                  {false, false, false, true, false, false, false},
                  {false, false, false, false, false, false, false}};
    toroide evo_t = { {false, false, false, false, false, false, false},
                      {false, true, true, false, false, false, false},
                      {false, true, true, false, false, false, false, false},
                      {false, false, true, false, false, false, false},
                      {false, false, false, false, false, false, false}};
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideUnaEvolucion2){
    toroide t = { {false, false, false, false, false, false},
                  {false, false, false, true, true, false},
                  {false, true, false, true, false, false},
                  {false, false, true, true, false, false},
                  {false, false, false, false, false, false}};
    toroide evo_t = { {false, false, false, false, false, false},
                      {false, false, true, true, true, false},
                      {false, false, false, false, false, false},
                      {false, false, true, true, false, false},
                      {false, false, false, false, false, false}};
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, test){
    toroide t = {
            {true, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    toroide evo_t = {
            {false, false, false, false, false},
            {false, true, true, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false, false, false, false} };
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, test2){
    toroide t = {
            {true, false, false, false, true},
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, false, false, false},
            {true, false, false, false, true} };
    toroide evo_t = {
            {true, false, false, false, true},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {true, false, false, false, true} };
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}
