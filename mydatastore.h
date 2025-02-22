#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include "product.h"
#include "user.h"
#include "datastore.h"

class MyDataStore : public DataStore
{
  public:
  MyDataStore();
  virtual ~MyDataStore();

  void addProduct(Product *p);
  void addUser(User* u);

  void addToCart(std::string& username, Product *p);
  void viewCart(std::string& username);
  void buyCart(std::string& username);
  void dump(std::ostream& os);
  std::vector<Product*> search(std::vector<std::string>& terms, int searchType);
  User* findUser(const std::string username);
  
  private:
  std::vector<Product*> products_;
  std::unordered_map<std::string, User*> users_;
  //std::set<User*> users_;
  std::unordered_map<std::string, std::set<Product*>> keyWordsAndProducts;
  std::unordered_map<std::string, std::vector<Product*>> carts;
};

#endif