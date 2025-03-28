#include "Product.h" 
#include <fstream> 

namespace database { 

std::ostream& operator<<(std::ostream& os, const Product& product) { 
    os << "Name: " << product.name << ", Price: " << product.price << ", Quantity: " << product.quantity; 
    return os; 
}

std::istream& operator>>(std::istream& is, Product& product) { 
    std::cout << "Введите название продукта: "; 
    is >> product.name;       
    std::cout << "Введите цену продукта: "; 
    is >> product.price;       
    std::cout << "Введите количесвто: "; 
    is >> product.quantity;      
    return is; 
}

void printDB(const std::vector<Product>& db) { 
    if (db.empty()) { 
        std::cout << "База пуста." << std::endl; 
        return; 
    }
    for (const auto& product : db) { 
        std::cout << product << std::endl; 
    }
}

std::vector<Product> searchDB(const std::vector<Product>& db, const std::string& name, double Price) { 
    std::vector<Product> results; 
    for (const auto& product : db) { 
        if (product.getName().find(name) != std::string::npos && product.getPrice() <= Price) { 
            results.push_back(product); 
        }
    }
    return results; 
}

void addProduct(std::vector<Product>& db) { 
    Product newProduct; 
    std::cin >> newProduct; 
    db.push_back(newProduct); 
}

void deleteProduct(const std::vector<Product>& db, const std::string& name) { 
    for (size_t i = 0; i < db.size(); ++i) { 
        if (db[i].getName() == name) { 
            db.erase(db.begin() + i); 
            std::cout << "Продукт '" << name << "' удалён." << std::endl; 
            return; 
        }
    }
    std::cout << "Продукт '" << name << "' не найден." << std::endl; 
}

void editProduct(const std::vector<Product>& db, const std::string& name) { 
    for (auto& product : db) { 
        if (product.getName() == name) { 
            std::cout << "Введите новые данные '" << name << "':" << std::endl; 
            std::cin >> product;
            std::cout << "Данные '" << name << "' измененны." << std::endl; 
            return; 
        }
    }
    std::cout << "Продукт '" << name << "' не найден." << std::endl; 
}

bool saveDB(const std::vector<Product>& db, const std::string& filename) { 
    std::ofstream file(filename); 
    if (!file.is_open()) { 
        std::cerr << "Ошибка загрузки." << std::endl;
        return false; 
    }

    for (const auto& product : db) { 
        file << product.getName() << std::endl; 
        file << product.getPrice() << std::endl; 
        file << product.getQuantity() << std::endl; 
    }

    file.close(); 
    return true; 
}

std::vector<Product> loadDB(const std::string& filename) {
    std::vector<Product> db; 
    std::ifstream file(filename);


    std::string name; 
    double price;    
    int quantity;   

    file.close(); 
    return db; 
}

} 