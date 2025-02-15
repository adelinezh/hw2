#ifndef BOOK
#define BOOK
#include <string>
using namespace std;

class Book : public Product {
public:
  Book(const std::string category, double price, int qty, int isbn, const std::string author);
  virtual ~Book;

  std::set<std::string> keywords() const override;

  std::string displayString() const override;

  void dump(std::ostream& os) const override;

private;
  std::string isbn_;
  std::string author_;

};