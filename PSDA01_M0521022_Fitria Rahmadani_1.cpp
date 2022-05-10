#include <iostream>
#include <vector>

int main() {
    //Deklarasi array list
    std::vector<std::string> fruits_name;

    //Menambahkan elemen nama buah
    fruits_name.push_back("Apple");
    fruits_name.push_back("Orange");
    fruits_name.push_back("Banana");
    fruits_name.push_back("Orange");
    fruits_name.push_back("Banana");
    fruits_name.push_back("Mango");

    //Menghapus elemen "Orange"
    fruits_name.erase(fruits_name.begin() + 1);
    fruits_name.erase(fruits_name.begin() + 2);

    //Menampilkan array list
    for (int i = 0; i < fruits_name.size(); i++) {
        std::cout << "Fruits [" << i << "] : " << fruits_name[i] << std::endl;
    }

    return 0;
}
