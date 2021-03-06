#include "rando.h"
#include <cmath>
#include <algorithm>
using namespace std;
//#include <stdlib.h>


/**
 * Worry if only one child is smiling or if all children are smiling
 **/
bool Rando::shouldWorry(bool childASmile, bool childBSmile, bool childCSmile)
{
  if( childASmile && childBSmile && childCSmile )
    return true;
  else if( childASmile ^ childBSmile ^ childCSmile )
    return true;
  else
    return false;
}
/**
 * Determines if first or second are evenly divisible by the other.
 **/
bool Rando::isDivisbleBy(int first, int second)
{
  if(first == 0 || second == 0)
  {
    throw -1;
  }

  if(first % second == 0 || 0 == second % first)
    return true;
  else
    return false;
}

/**
 * Given a number, num, says whether or not that number is prime
 * (that is, only evenly divisible by itself and 1. For the sake
 * of this function, do NOT consider 0 prime)
 **/
bool Rando::isPrime(int num)
{
  if(num < 2)
    return false;
  else if(num == 2 || num == 3 || num == 5)
    return true;
  else if(num % 2 == 0)
    return false;
  else 
  {
    bool is_prime = true;
    for(int i = 3; i <= sqrt(num); i += 2)
    {
      if(num % i == 0)
        return false;
    }
    return is_prime;
  }
  return false;//catchall
}

/**
 * Given two numbers, first and second, return the value of the one
 * that is closest to zero without actually being zero.
 **/
int Rando::nearestToZero(int a, int b)
{
  if(a == 0 && b == 0)
    return 0;
  if(a == 0)
    return b;
  if(b == 0)
    return a;
  return min(abs(a),abs(b));
}
