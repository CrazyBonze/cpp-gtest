/**
 * Unit Tests for Rando Test
 **/

#include <gtest/gtest.h>
#include "rando.h"

/*  
    FUNCTIONS WE NEED TO TEST:

    bool shouldWorry(bool,bool,bool);
    bool isDivisbleBy(int,int);
    bool isPrime(int);
    int nearestToZero(int,int);
    */

class RandoTest : public ::testing::Test
{
  protected:
    RandoTest(){} //constructor runs before each test
    virtual ~RandoTest(){} //destructor cleans up after tests
    virtual void SetUp(){} //sets up before each test (after constructor)
    virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(RandoTest, allChildrenSmile)
{
  Rando rando;
  ASSERT_TRUE( rando.shouldWorry(true,true,true) );
}

TEST(RandoTest, oneChildeSmiles)
{
  Rando rando;
  ASSERT_TRUE( rando.shouldWorry(false,false,true) );
  ASSERT_TRUE( rando.shouldWorry(false,true,false) );
  ASSERT_TRUE( rando.shouldWorry(true,false,false) );
}

TEST(RandoTest, isDivisbleBy)
{
  Rando rando;
  ASSERT_TRUE( rando.isDivisbleBy(12,1) );
  ASSERT_FALSE( rando.isDivisbleBy(11,2) );
  ASSERT_FALSE( rando.isDivisbleBy(10,3) );
  ASSERT_FALSE( rando.isDivisbleBy(9,4) );
  ASSERT_FALSE( rando.isDivisbleBy(8,5) );
  ASSERT_FALSE( rando.isDivisbleBy(7,6) );
  ASSERT_FALSE( rando.isDivisbleBy(6,7) );
  ASSERT_FALSE( rando.isDivisbleBy(5,8) );
  ASSERT_FALSE( rando.isDivisbleBy(4,9) );
  ASSERT_FALSE( rando.isDivisbleBy(3,10) );
  ASSERT_FALSE( rando.isDivisbleBy(2,11) );
  ASSERT_TRUE( rando.isDivisbleBy(1,12) );
  ASSERT_TRUE( rando.isDivisbleBy(8,8) );
  ASSERT_TRUE( rando.isDivisbleBy(8,2) );
  ASSERT_TRUE( rando.isDivisbleBy(2,8) );
}

TEST(RandoTest, devideByZero)
{
  Rando rando;
  bool exceptionThrown = false;
  try
  {
    ASSERT_TRUE( rando.isDivisbleBy(0,8) );
    ASSERT_TRUE( rando.isDivisbleBy(2,0) );
    ASSERT_TRUE( rando.isDivisbleBy(0,0) );
  }catch(int ex)
  {
    if(ex == -1)
    {
      exceptionThrown = true;
    }
  }
  ASSERT_TRUE(exceptionThrown);
}

TEST(RandoTest, isPrime)
{
  Rando rando;
  ASSERT_TRUE( rando.isPrime(2) );
  ASSERT_TRUE( rando.isPrime(3) );
  ASSERT_TRUE( rando.isPrime(5) );
  ASSERT_TRUE( rando.isPrime(7) );
  ASSERT_TRUE( rando.isPrime(11) );
  ASSERT_TRUE( rando.isPrime(13) );
  ASSERT_TRUE( rando.isPrime(17) );
  ASSERT_TRUE( rando.isPrime(19) );
  ASSERT_TRUE( rando.isPrime(23) );
}

TEST(RandoTest, isNotPrime)
{
  Rando rando;
  ASSERT_FALSE( rando.isPrime(0) );
  ASSERT_FALSE( rando.isPrime(1) );
  ASSERT_FALSE( rando.isPrime(4) );
  ASSERT_FALSE( rando.isPrime(6) );
  ASSERT_FALSE( rando.isPrime(8) );
  ASSERT_FALSE( rando.isPrime(9) );
  ASSERT_FALSE( rando.isPrime(21) );
  ASSERT_FALSE( rando.isPrime(12) );
  ASSERT_FALSE( rando.isPrime(-30) );
  ASSERT_FALSE( rando.isPrime(-1000) );
  ASSERT_FALSE( rando.isPrime(1000) );
  ASSERT_FALSE( rando.isPrime(14) );
}

TEST(RandoTest, nearestToZero)
{
  Rando rando;
  ASSERT_TRUE( 1 == rando.nearestToZero(5,1) );
  ASSERT_TRUE( 1 == rando.nearestToZero(1,1) );
  ASSERT_TRUE( 1 == rando.nearestToZero(1,5) );
  ASSERT_TRUE( 1 == rando.nearestToZero(-5,1) );
  ASSERT_TRUE( 1 == rando.nearestToZero(5,-1) );
  ASSERT_TRUE( 1 == rando.nearestToZero(-1,5) );
  ASSERT_TRUE( 1 == rando.nearestToZero(-5,-1) );
  ASSERT_TRUE( 1 == rando.nearestToZero(1,-1) );
}

TEST(RandoTest, atZero)
{
  Rando rando;
  ASSERT_TRUE( 0 == rando.nearestToZero(0,0) );
  ASSERT_TRUE( 1 == rando.nearestToZero(0,1) );
  ASSERT_TRUE( 5 == rando.nearestToZero(0,5) );
  ASSERT_TRUE( -5 == rando.nearestToZero(-5,0) );
  ASSERT_TRUE( -1 == rando.nearestToZero(0,-1) );
  ASSERT_TRUE( -1 == rando.nearestToZero(-1,0) );
  ASSERT_TRUE( -1 == rando.nearestToZero(0*0,-1) );
  ASSERT_TRUE( 0 == rando.nearestToZero(1-1,5-5) );
}
