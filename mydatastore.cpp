#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <unordered_map>
#include <map>
#include "product_parser.h"
#include "util.h"
#include "mydatastore.h"
#include "user.h"

using namespace std;

MyDataStore :: MyDataStore()
{

}

MyDataStore :: ~MyDataStore()
{
  for (Product* p : products_)
  {
    delete p;
  }
  for (std::unordered_map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it)
  {
    delete it -> second;
  }

}

void MyDataStore::addProduct(Product *p)
{
  products_.push_back(p);
  
}

void MyDataStore::addUser(User* u)
{
    std::string username = convToLower(u -> getName());
    users_[username] = u;
}

void MyDataStore::addToCart(std::string& username, Product *p)
{
    username = convToLower(username);
    if(users_.find(username) == users_.end())
    {
      std::cout << "Invalid request" << endl;
      return;
    }
    carts[username].push_back(p);
}

void MyDataStore::viewCart(std::string& username)
{
  
  if(carts.find(username) == carts.end())
  {
    std::cout << "Invalid username" << endl;
    return;
  }
  else
  {
    int itemCount = 1;
    for(std::vector<Product*>::iterator it = carts[username].begin(); it != carts[username].end(); ++it)
    {
      cout << "Item " << itemCount << endl;
      std::cout << (*it) -> displayString() << endl;
      cout << endl;
      itemCount++;
    }
  }
  cout << endl;
}

void MyDataStore::buyCart(std::string& username)
{ 

  if(users_.find(username) == users_.end())
  {
    std::cout << "Invalid username" << endl;
    return;
  }
  username = convToLower(username);

  User* user = users_[username];
  std::vector<Product*>& userCart = carts[username];
  std::vector<Product*> remainingItems;

  for (Product* p : userCart)
  {
    if (p -> getQty() > 0 && user -> getBalance() >= p -> getPrice())
    {
      
      user -> deductAmount(p -> getPrice());
      p -> subtractQty(1);
      
    }
    else
    {
      remainingItems.push_back(p);
    }
  }
  userCart = remainingItems;
}

void MyDataStore::dump(std::ostream& os)
{
  os << "<products>" << "\n";
  for(std::vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it)
    {
      (*it) -> dump(os);
    }
  os << "</products>" << "\n";

  os << "<users>" << "\n";
    for(std::unordered_map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it)
    {
      it -> second -> dump(os);
    } 
  os << "</users>" << "\n";
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    std::vector<Product*> intersectionSearchResults;
    if (terms.empty())
    {
      return intersectionSearchResults;
    }
    for (std::string& term : terms)
    {
      term = convToLower(term);
    }

  if (type == 0) //and
  {
      for (Product* product : products_) //check each product
      {
        bool found = true;
        std::set<std::string> keyWordSet = product -> keywords();
        for (const std::string& term : terms)
        {
          
          if (keyWordSet.find(term) == keyWordSet.end())
          {
            found = false;
            break;
          }
        }
        if (found == true)
        {
          intersectionSearchResults.push_back(product);
          //found = false;
        }
      }
    return intersectionSearchResults;
  }

  else if (type == 1) //or
  {
    for (Product* product : products_)
    {
      bool found = false;
      std::set<std::string> keyWordSet = product -> keywords();
      for (const std::string& term : terms)
      {
        if (keyWordSet.find(term) != keyWordSet.end())
        {
          found = true;
        }
      }
      if (found == true)
      {
        intersectionSearchResults.push_back(product);
      }
    }
    return intersectionSearchResults;
  }
  else
  {
    cout << "Invalid request" << endl;
  }
}
