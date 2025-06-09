#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresUnPaso){
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
    toroide res = evolucionMultiple(t, 1);
    EXPECT_EQ(res, evo_t);
}

//testsad
TEST(evolucionMultipleTEST, toroidePeriodico){
    toroide t = {{false, false, false, false, false},
                 {false, false, true, false, false},
                 {false, false, true, false, false},
                 {false, false, true, false, false},
                 {false,false, false, false, false}
    };
    toroide evo_t={{false, false, false, false, false},
                   {false, false, true, false, false},
                   {false, false, true, false, false},
                   {false, false, true, false, false},
                   {false,false, false, false, false}
    };
    toroide res = evolucionMultiple(t, 6);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideMuerto){
    toroide t = {{false, false, false, false, false},
                 {false, false, false, false, false},
                 {false, false, false, false, false},
                 {false, false, false, false, false},
                 {false,false, false, false, false}
    };
    toroide evo_t={{false, false, false, false, false},
                   {false, false, false, false, false},
                   {false, false, false, false, false},
                   {false, false, false, false, false},
                   {false,false, false, false, false}
    };
    toroide res = evolucionMultiple(t, 10);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroidePanal){
    toroide t = { {false, false, false, false, false, false},
                  {false, false, true, false, false, false},
                  {false, false, true, true, true, false},
                  {false, false, false, false, false, false},
                  {false, false, false, false, false, false} };
    toroide evo_t = { {false, false, false, false, false, false},
                      {false, false, true, true, false, false},
                      {false, true, false, false, true, false},
                      {false, false, true, true, false, false},
                      {false, false, false, false, false, false} };
    toroide res = evolucionMultiple(t, 3);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroidePasaAMorir){
    toroide t = { {false, true, true},
                  {false, true, true},
                  {false, true, false}
    };
    toroide evo_t = { {false, false, false},
                      {false, false, false},
                      {false, false, false}
    };
    toroide res = evolucionMultiple(t, 4);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, test){
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
    toroide res=evolucionMultiple(t,20);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, test2){
    toroide t = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    toroide evo_t = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    toroide res=evolucionMultiple(t,15);
    EXPECT_EQ(res, evo_t);
}
