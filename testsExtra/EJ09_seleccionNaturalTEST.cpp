#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;


TEST(seleccionNaturalTEST, toroideDiagonalVsUnoVivo){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, false, false}, 
                  {false, false, false}, 
                  {false, true, false},
                  {false, false, false}, 
                  {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

//TEST(seleccionNaturalTEST, DiagonalVsHorizontal){
//    toroide t1 = {
//                  {false, false, false, false, false},
//                  {false, false, false, false, false},
//                  {false, true, true, true, false},
//                  {false, false, false, false, false},
//                  {false, false,false, false, false} };
//    toroide t2 = {
//                  {true, false, false},
//                  {false, true, false},
//                  {false, false, true}};
//    vector<toroide> ts;
//    ts.push_back(t2);
//    ts.push_back(t1);
//    ts.push_back(t2);
//    int res = seleccionNatural(ts);
//    EXPECT_EQ(res, 1);
//}

//testsad
TEST(seleccionNaturalTEST, toroide2){
    toroide t1 = { {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, true, false, true, false, false, false, false, false},
                   {false, false, false, false, true, false, false, false, false, false, false},
                   {false, false, false, true, true, true, false, false, false, false, false},
                   {false, false, false, false, false, true, false, false, false, false, false},
                   {false, false, false, false, false, true, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false, false, false}};
    toroide t2 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t3 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

TEST(seleccionNaturalTEST, toroide3){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    toroide t3{{false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, true,  false, false, false, false, false, false},
               {false, false, true,  false, false, false, false, false, true,  false, false},
               {false, false, false, false, true,  false, false, false, false, false, false},
               {false, false, true,  false, false, true,  false, false, false, false, false},
               {false, false, false, false, false, false, false, true,  false, false, false},
               {false, false, false, false, true,  false, true,  false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false},
               {false, false, false, false, false, false, false, false, false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

TEST(seleccionNaturalTEST, tercerToroideMuereUltimo){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    toroide t3 = { {false, false, false, false, false, false, false},
                   {false, true, false, false, false, false, false},
                   {false, true, true, false, false, false, false, false},
                   {false, false, false, true, false, false, false},
                   {false, false, false, false, false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 2);
}

TEST(seleccionNaturalTEST, toroideEnPosicion2MuereUltimo){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    toroide t3 = { {false, false, false, false, false, false, false},
                   {false, true, false, false, false, false, false},
                   {false, true, true, false, false, false, false, false},
                   {false, false, false, true, false, false, false},
                   {false, false, false, false, false, false, false}};
    toroide t4 = {{false, false, false, false, false, false},
                  {false, false, false, true, true, false},
                  {false, true, false, true, false, false},
                  {false, false, true, true, false, false},
                  {false, false, false, false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    ts.push_back(t4);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 2);
}

TEST(seleccionNaturalTEST, repe){
    toroide t2 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}

TEST(seleccionNaturalTEST, test){
    toroide t3={{false, false, false, false, true},
                {false, true, false, false, false},
                {false, false, true, false, false},
                {true, false, true, false, false},
                {false, false, false, false, true}};
    toroide t2 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    toroide t0={
            {false, false, true},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t0);
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    ts.push_back(t0);
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 3);
}

TEST(seleccionNaturalTEST, test1){
    toroide t3={{false, false, false, false, true},
                {false, true, false, false, false},
                {false, false, true, false, false},
                {true, false, true, false, false},
                {false, false, false, false, true}};
    vector<toroide> ts;
    ts.push_back(t3);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}
