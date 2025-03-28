#include "Product.h" 
#include <iostream> 

int main() { 
    std::vector<database::Product> productDatabase; 
    std::string filename = "products.txt"; 
    productDatabase = database::loadDB(filename); 

    int choice; 
    do { 
        std::cout << "\nМеню:\n"; 
        std::cout << "1.Вывести продукты\n"; 
        std::cout << "2.Поиск продуктов\n"; 
        std::cout << "3.Добавить продукт\n";    
        std::cout << "4.Удалить продукт\n"; 
        std::cout << "5.Изменить денные продукта\n";  
        std::cout << "6.Сохранить и выйии\n";  
        std::cout << "Выберите пользовалеля: ";

     

        switch (choice) { 
            case 1: 
                database::printDB(productDatabase); 
                break;
            case 2: { 
                std::string searchName; 
                double Price;      
                std::cout << "Введите название: "; 
                std::getline(std::cin, searchName); 
                std::cout << "Введите цену: "; 
                std::cin >> Price;     
                std::vector<database::Product> searchResults = database::searchDB(productDatabase, searchName, Price); 
                database::printDB(searchResults); 
                break;
            }
            case 3: 
                database::addProduct(productDatabase); 
                break;
            case 4: { 
                std::string deleteName; 
                std::cout << "Введите название продукта: "; 
                std::getline(std::cin, deleteName); 
                database::deleteProduct(productDatabase, deleteName); 
                break;
            }
            case 5: { 
                std::string editName; 
                std::cout << "Введите название продукта: "; 
                std::getline(std::cin, editName); 
                database::editProduct(productDatabase, editName); 
                break;
            }
            case 6: 
                if (database::saveDB(productDatabase, filename)) { 
                    std::cout << "Успешно сохранено." << std::endl; 
                } else {
                    std::cout << "Ошибка сохранения." << std::endl; 
                }
                break;
        }
    } while (choice != 6);

    return 0; 
}