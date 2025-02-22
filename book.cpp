#include <string>
#include <iostream>
#include <sstream>
#include "book.h"
#include "util.h"
#include <iomanip>
using namespace std;

Book::Book(const std::string& category, const std::string& name, double price, int qty, const std::string& isbn, const std::string& author) :
    Product("book", name, price, qty), isbn_(isbn), author_(author)
{

}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
  std::set<std::string> keySet = parseStringToWords(convToLower(name_));
  std::set<std::string> authorNames = parseStringToWords(convToLower(author_));

  keySet.insert(authorNames.begin(), authorNames.end());
  keySet.insert(convToLower(isbn_));
  return keySet;
}

std::string Book::displayString() const
{
  std::ostringstream oss;
  oss << name_ << "\n" <<
  "Author: " << author_ <<
  " ISBN: " << isbn_ << "\n" << std::fixed << std::setprecision(2) <<
  price_ << " " << std::fixed << std::setprecision(2) << qty_ << " left.";
  return oss.str();

}

void Book::dump(std::ostream& os) const
{
  //cout << "DUMPING" << endl;
  os << category_ << "\n" <<
        name_ << "\n" <<
        price_ << "\n" <<
        qty_ << "\n" <<
        isbn_ << "\n" <<
        author_ << std::endl;
}