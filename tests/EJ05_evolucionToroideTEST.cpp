#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionToroideTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}};

    toroide evo_t = { {true, true, true},
                      {true, true, true},
                      {true, true, true}};

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideMuerto){
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    toroide evo_t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}