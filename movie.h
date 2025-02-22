#include <string>
#include <set>
#include "util.h"
#include "product.h"
using namespace std;

class Movie : public Product {
public:
  Movie(const std::string& category, const std::string& prodName, double price, int qty, const std::string& rating, const std::string& genre);
  virtual ~Movie();

  std::set<std::string> keywords() const override;

  std::string displayString() const override;

  virtual void dump(std::ostream& os) const;

protected:
  std::string rating_;
  std::string genre_;

};