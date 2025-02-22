#include <string>
#include <iostream>
#include <sstream>
#include "movie.h"
#include "util.h"
#include <iomanip>
using namespace std;

Movie::Movie(const std::string& category, const std::string& name, double price, int qty, const std::string& rating, const std::string& genre) :
    Product("movie", name, price, qty), rating_(rating), genre_(genre)
{

}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const
{
  std::set<std::string> keySet = parseStringToWords(convToLower(name_));
  
  keySet.insert(convToLower(genre_));
  return keySet;
  
}

std::string Movie::displayString() const
{
  std::ostringstream oss;
  oss << name_ << "\n" <<
  "Genre: " << genre_ << " Rating: " << rating_ << "\n" << std::fixed << std::setprecision(2) <<
  price_ << " " << std::fixed << std::setprecision(2) << qty_ << " left.";
  return oss.str();

}

void Movie::dump(std::ostream& os) const
{
  //cout << "DUMPING" << endl;
  
  os << category_ << "\n" <<
        name_ << "\n" <<
        price_ << "\n" <<
        qty_ << "\n" <<
        genre_ << "\n" <<
        rating_ << std::endl;
}