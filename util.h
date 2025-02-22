#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

using namespace std;


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> intersectionSet;

  if (s1.empty())
  {
    intersectionSet = s2;
  }

  for (const T& word : s1)
  {
    cout << "intersection called" << endl;
    if(s2.find(word) != s2.end())
    {
      cout << "intersection" << endl;
      intersectionSet.insert(word);
    }
  }
  return intersectionSet;

}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  //if (s1.empty())
  std::set<T> unionSet;
  
  for (const T& word : s2)
  {
    cout << "union" << endl;
    unionSet.insert(word);
  }
  return unionSet;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
