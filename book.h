//#ifndef BOOK_H
//#define BOOK_H
#include <string>
#include <set>
#include "util.h"
#include "product.h"
using namespace std;

class Book : public Product {
public:
  Book(const std::string& category, const std::string& name, double price, int qty, const std::string& isbn, const std::string& author);
  virtual ~Book();

  std::set<std::string> keywords() const override;

  std::string displayString() const override;

  virtual void dump(std::ostream& os) const;

protected:
  std::string isbn_;
  std::string author_;

};