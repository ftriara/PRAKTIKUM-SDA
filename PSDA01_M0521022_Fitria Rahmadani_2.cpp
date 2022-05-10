#include <iostream>
#include <stack>

int main() {
    //Deklarasi stack
    std::stack<std::string> books_name;

    //Deklarasi variabel pick_books
    std::string pick_books;

    //Menambahkan elemen judul buku ke dalam stack
    books_name.push("Numerical Analysis");
    books_name.push("Discrete Mathematics and Its Applications");
    books_name.push("Computer Networking: A Top Down Approach");
    books_name.push("Introduction to Machine Learning");
    books_name.push("Linear Algebra and Its Applications");
    books_name.push("Fundamentals of Computer Graphics");

    //Mengeluarkan elemen judul buku dari stack
    books_name.pop();
    books_name.pop();
    books_name.pop();

    //Menambahkan elemen judul buku ke dalam stack
    books_name.push("Linear Algebra and Its Applications");
    books_name.push("Fundamentals of Computer Graphics");

    //Menampilkan isi stack setelah buku diambil
    int size = books_name.size();
    for(int i=0; i<size; i++){
        pick_books = books_name.top();
        std::cout << pick_books << std::endl;
        books_name.pop();
    }

    return 0;
}

