#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream> 
#include <string>   
#include <vector>   

namespace database { 

class Product { 
private:
    std::string name;   
    double price;       
    int quantity;      
public:
    Product() : name(""), price(0.0), quantity(0) {} 
    Product(const std::string& name, double price, int quantity) : name(name_), price(price_), quantity(quantity_) {} 

    std::string getName() const { return name; }    
    double getPrice() const { return price; }       
    int getQuantity() const { return quantity; } 

    void setName(const std::string& Namenew) { name = Namenew; }    
    void setPrice(double Pricenew) { price = Pricenew; }       
    void setQuantity(int Quantitynew) { quantity = Quantitynew; }  

    friend std::ostream& operator<<(std::ostream& os, const Product& product);
    friend std::istream& operator>>(std::istream& is, Product& product); 
};

std::ostream& operator<<(std::ostream& os, const Product& product); 
std::istream& operator>>(std::istream& is, Product& product); 

void printDB(const std::vector<Product>& db);   
std::vector<Product> searchDB(const std::vector<Product>& db, const std::string& name, double Price); 
void addProduct(std::vector<Product>& db);      
void deleteProduct(const std::vector<Product>& db, const std::string& name); 
void editProduct(const std::vector<Product>& db, const std::string& name);   
bool saveDB(const std::vector<Product>& db, const std::string& filename);   
std::vector<Product> loadDB(const std::string& filename);   

}

#endif