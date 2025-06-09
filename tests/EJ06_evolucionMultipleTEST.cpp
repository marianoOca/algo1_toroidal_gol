#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}};

    toroide evo_t = { {true, true, true},
                      {true, true, true},
                      {true, true, true}};

    toroide res = evolucionMultiple(t, 1);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresDosPasos){
toroide t = { {true,  false, false},
              {false, true,  false},
              {false, false, true}};

toroide evo_t = { {false, false, false},
                  {false, false, false},
                  {false, false, false}};

toroide res = evolucionMultiple(t, 2);
EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresTresPasos){
    toroide t = { {true,  false, false},
                  {false, true,  false},
                  {false, false, true}};

    toroide evo_t = { {false, false, false},
                      {false, false, false},
                      {false, false, false}};

    toroide res = evolucionMultiple(t, 3);
    EXPECT_EQ(res, evo_t);
}