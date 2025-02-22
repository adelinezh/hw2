#include <string>
#include <set>
#include "util.h"
#include "product.h"
using namespace std;

class Clothing : public Product {
public:
  Clothing(const std::string& category, const std::string& prodName, double price, int qty, const std::string& size, const std::string& brand);
  virtual ~Clothing();

  std::set<std::string> keywords() const override;

  std::string displayString() const override;

  virtual void dump(std::ostream& os) const;

protected:
  std::string size_;
  std::string brand_;

};