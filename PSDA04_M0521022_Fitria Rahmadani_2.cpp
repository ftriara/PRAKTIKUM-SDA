#include <iostream>
#include <map>
#include <cstring>

//Struct berisi judul, stok, dan harga buku
struct Book {
    std::string Title;
    int Stock;
    double Price;
};

int main() {
    std::map<std::string, Book> BookData;
    std::map<std::string, Book>::iterator It;

    //Deklarasi variabel CustName untuk nama customer, Code untuk kode buku, dan Saldo untuk saldo customer
    std::string CustName, Code;
    int Saldo = 300000;

    Book Buku[10];
    //Array dari struct Book
    Buku[0] = {"Komet", 30, 80000};
    Buku[1] = {"Bumi", 25, 90000};
    Buku[2] = {"Bulan", 15, 120000};
    Buku[3] = {"Bintang", 20, 95000};
    Buku[4] = {"Pulang", 30, 80000};
    Buku[5] = {"Pergi", 25, 85000};

    //Mengaitkan data buku dari struct pada map BookData dengan indeks kode
    BookData["020"] = Buku[0];
    BookData["021"] = Buku[1];
    BookData["022"] = Buku[2];
    BookData["023"] = Buku[3];
    BookData["024"] = Buku[4];
    BookData["025"] = Buku[5];

    std::cout << std::endl << std::endl ;
    std::cout << "SELAMAT DATANG DI ADIWARNA BOOKSTORE" << std::endl << std::endl;
    std::cout << "\tDaftar Buku\t\t" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "| Kode\tJudul\t\tHarga\t|" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    //Iterasi elemen-elemen BookData sebagai daftar buku
    for(It = BookData.begin() ; It != BookData.end() ; It++) {
        std::cout << "| " << It -> first << "\t" << It -> second.Title << "\t\t" << It -> second.Price << "\t|" << std::endl;
    }
    std::cout << "--------------------------------" << std::endl << std::endl;

    std::cout << "Nama Pelanggan     : ";
    std::getline (std::cin, CustName);
    std::cout << std::endl << std::endl;
    std::cout << "Halo " << CustName << "!" << std::endl;
    std::cout << "Saldo anda saat ini Rp300000" << std::endl << std::endl;

    while(1) {
        std::cout << "Masukkan kode buku : ";
        std::cin >> Code;

        if(Code == "020" || Code == "021" || Code == "021" || Code == "022" || Code == "023" || Code == "024" || Code == "025"){

            int qty;

            std::cout << "Judul : " << BookData[Code].Title << std::endl;
            std::cout << "Stok  : " << BookData[Code].Stock << std::endl;
            std::cout << "Harga : " << BookData[Code].Price << std::endl << std::endl;
            std::cout << "Jumlah buku yang dipesan : ";
            std::cin >> qty;

            if(BookData[Code].Stock < qty){
                std::cout << "Stok Buku di Toko Kurang!" << std::endl;
            } else{
                std::cout << "Jumlah pesanan : " << qty << " buku " << std::endl;
                //Mengurangi stok buku sesuai dengan masukan pelanggan
                BookData[Code].Stock -= qty;
                std::cout << "Sisa stok buku : " << BookData[Code].Stock << std::endl << std::endl;
            }

            //Menghitung total harga yang dibayarkan
            int TotPrice = BookData[Code].Price * qty;

            if(Saldo < TotPrice){
                std::cout << "Saldo anda tidak cukup!" << std::endl;
            } else{
                std::cout << "Harga yang harus dibayar : " << TotPrice << std::endl;
                //Mengurangi saldo dengan jumlah harga yang harus dibayarkan
                Saldo -= TotPrice;
                std::cout << "Sisa saldo anda          : " << Saldo << std::endl;
            }
        } else{
            std::cout << "Buku Tidak Tersedia!" << std::endl << std::endl;
            continue;
        }

        char input;
        std::cout << std::endl;
        std::cout << "Apakah ingin memesan lagi? (Y/N)" << std::endl;
        std::cin >> input;
        if(input == 'N' || input == 'n'){
            break;
        } else{
            continue;
        }
    }

    std::cout << "Terima Kasih " << CustName << " Atas Kedatangannya! " << std::endl;

    return 0;
}
