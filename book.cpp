#ifndef BOOK
#define BOOK
#include <string>
#include "book.h"
#include "util.h"
using namespace std;

Book::Book(const std::string category, double price, int qty, int isbn, const std::string author) :
    Product (name, category, price, qty), isbn_(isbn), author_(author)
{

}

Book::~Book
{

}

std::set<std::string> Book::keywords() const
{
  std::set<std::string> keySet = parseStringToWords(name_);
  keySet.insert(parseStringToWords(author_));
  keySet.insert(parseStringToWords(isbn_));
  return keySet;
}

Book::string displayString() const
{
  std::ostringstream oss;
  oss << name_ << "\n" <<
  "Author: " << author_ <<
  "ISBN: " << isbn_ <<
  "Quantity: " << qty_ <<
  "Price: " << price_;
  return oss.str();

}

void Book::dump(std::ostream& os) const
{
  os << category_ << "\n" <<
        name_ << "\n" <<
        price_ << "\n" <<
        qty_ << "\n" <<
        isbn_ << "\n" <<
        author_ << std::endl;
}