#include <string>
#include <iostream>
#include <sstream>
#include "clothing.h"
#include "util.h"
#include <iomanip>
using namespace std;

Clothing::Clothing(const std::string& category, const std::string& name, double price, int qty, const std::string& size, const std::string& brand) :
    Product("clothing", name, price, qty), size_(size), brand_(brand)
{

}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const
{
  std::set<std::string> keySet = parseStringToWords(convToLower(name_));
  std::set<std::string> brandNames = parseStringToWords(convToLower(brand_));

  keySet.insert(brandNames.begin(), brandNames.end());
  return keySet;
  
}

std::string Clothing::displayString() const
{
  //qty_.setprecision(2);
  std::ostringstream oss;
  oss << name_ << "\n" <<
  "Size: " << size_ << " Brand: " << brand_ << "\n" << std::fixed << std::setprecision(2) <<
  price_ << " " << std::fixed << std::setprecision(2) << qty_ << " left.";
  return oss.str();

}

void Clothing::dump(std::ostream& os) const
{
  //cout << "DUMPING" << endl;
  
  os << category_ << "\n" <<
        name_ << "\n" <<
        price_ << "\n" <<
        qty_ << "\n" <<
        size_ << "\n" <<
        brand_ << std::endl;
}