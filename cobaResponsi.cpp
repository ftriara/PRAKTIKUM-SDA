#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

struct Book {
    string title;
    int stock;
    double price;
};

void DataBuku() {
    map<string, Book> BookData;
    map<string, Book>::iterator It;

    //Deklarasi variabel CustName untuk nama customer, Code untuk kode buku, dan Saldo untuk saldo customer
    string Code;

    Book Buku[10];
    //Array dari struct Book
    Buku[0] = {"Laut Bercerita", 25, 110000};
    Buku[1] = {"Si Putih", 15, 85000};
    Buku[2] = {"Tujuh Kelana", 20, 95000};
    Buku[3] = {"Black House", 30, 50000};
    Buku[4] = {"Haru Mahameru", 25, 85000};
    Buku[5] = {"Filosofi Teras", 15, 90000};
    Buku[6] = {"Dunia Sophie", 18, 130000};
    Buku[7] = {"Second Sister", 10, 100000};
    Buku[8] = {"Katarsis", 25, 85000};

    //Mengaitkan data buku dari struct pada map BookData dengan indeks kode
    BookData["F20"] = Buku[0];
    BookData["F21"] = Buku[1];
    BookData["F22"] = Buku[2];
    BookData["H30"] = Buku[3];
    BookData["H31"] = Buku[4];
    BookData["FI40"] = Buku[5];
    BookData["FI41"] = Buku[6];
    BookData["T50"] = Buku[7];
    BookData["T51"] = Buku[8];

    cout << endl << endl ;
    cout << "\t\t*****Daftar Buku*****\t\t" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "| Kode\t|\tJudul\t\t\tHarga\t|" << endl;
    cout << "-------------------------------------------------" << endl;

    //Iterasi elemen-elemen BookData sebagai daftar buku
    for(It = BookData.begin() ; It != BookData.end() ; It++) {
        cout << "| " << It -> first << "\t|" << It -> second.title << "\t\t\t" << It -> second.price << "\t|" << endl;
    }
    cout << "-------------------------------------------------" << endl << endl;
}

enum tempat {
    IN,
    FANTASY,
    HORROR,
    FILSAFAT,
    THRILLER,
    KASIR,
    J_TEMPAT
};

void jarakTempat(double jarak[J_TEMPAT][J_TEMPAT], tempat tempatA, tempat tempatB, double s) {
    jarak[tempatA][tempatB] = jarak[tempatB][tempatA] = s;
}

void cekRakBuku() {
    double jarak[J_TEMPAT][J_TEMPAT];

    //Jarak dari masing-masing node yang terhubung langsung oleh edge
    jarakTempat(jarak, IN, FANTASY, 3.00);
    jarakTempat(jarak, IN, HORROR, 2.00);
    jarakTempat(jarak, IN, FILSAFAT, 2.50);
    jarakTempat(jarak, IN, THRILLER, 3.50);
    
    jarakTempat(jarak, FANTASY, HORROR, 1.00);
    jarakTempat(jarak, HORROR, FILSAFAT, 1.50);
    jarakTempat(jarak, FILSAFAT, THRILLER, 1.00);

    //jarakTempat(jarak, FANTASY, KASIR, 3.00);
    jarakTempat(jarak, HORROR, KASIR, 2.00);
    //jarakTempat(jarak, FILSAFAT, KASIR, 2.50);
    //jarakTempat(jarak, THRILLER, KASIR, 3.50);

    //Jarak dari masing-masing node yang tidak terhubung langsung oleh edge yaitu -1.0
    jarakTempat(jarak, FANTASY, FILSAFAT, -1.0);
    jarakTempat(jarak, FANTASY, THRILLER, -1.0);
    jarakTempat(jarak, HORROR, THRILLER, -1.0);
    jarakTempat(jarak, IN, KASIR, -1.0);
    jarakTempat(jarak, FANTASY, KASIR, -1.0);
    jarakTempat(jarak, FILSAFAT, KASIR, -1.0);
    jarakTempat(jarak, THRILLER, KASIR, -1.0);

    //Jarak dari masing-masing node ke dirinya sendiri
        for(int i = 0; i < J_TEMPAT; i++){
            for(int j = 0; j < J_TEMPAT; j++){
                if(i == j){
                    jarak[i][j] = 0.0;
                }
            }
        }

    //Hitung jarak total destinasi rak pengunjung
    string asal, tujuan, arah;
    int total_jarak = 0;

    cout << endl << endl ;
    cout << "*****MENU CEK TEMPAT BUKU TUJUAN*****" << endl;
    cout << "1) IN " << endl;
    cout << "2) FANTASY " << endl;
    cout << "3) HORROR " << endl;
    cout << "4) FILSAFAT " << endl;
    cout << "5) THRILLER " << endl;
    cout << "6) KASIR " << endl << endl;

    cout << "Titik asal     : ";
    cin >> asal;
    cout << "Titik tujuan   : ";
    getline(cin, tujuan);
    cin >> tujuan;

    if (asal == "IN") {
        if (tujuan == "FANTASY") {
            total_jarak = jarak[IN][FANTASY];
            arah = "Timur Laut";
        } else if (tujuan == "HORROR") {
            total_jarak = jarak[IN][HORROR];
            arah = "Timur";
        } else if (tujuan == "FILSAFAT") {
            total_jarak = jarak[IN][FILSAFAT];
            arah = "Tenggara";
        } else if (tujuan == "THRILLER") {
            total_jarak = jarak[IN][THRILLER];
            arah = "Selatan";
        } else if (tujuan == "KASIR") {
            total_jarak = jarak[IN][HORROR] + jarak[HORROR][KASIR];
            arah = "Timur";
        } else {
            cout << "Maaf, Tempat buku tujuan tidak tersedia" << endl;
        }
    } else if(asal == "FANTASY") {
        if(tujuan == "HORROR") {
            total_jarak = jarak[FANTASY][HORROR];
            arah = "Tenggara";
        } else if(tujuan == "FILSAFAT") {
            total_jarak = jarak[FANTASY][HORROR] + jarak[HORROR][FILSAFAT];
            arah = "Selatan";
        } else if(tujuan == "THRILLER") {
            total_jarak = jarak[FANTASY][HORROR] + jarak[HORROR][FILSAFAT] + jarak[FILSAFAT][THRILLER];
            arah = "Barat Daya";
        } else if(tujuan == "KASIR") {
            total_jarak = jarak[FANTASY][HORROR] + jarak[HORROR][KASIR];
            arah = "Tenggara";
        } else {
            cout << "Maaf, Tempat buku tujuan tidak tersedia" << endl;
        }
    } else if(asal == "HORROR") {
        if(tujuan == "FANTASY") {
            total_jarak = jarak[FANTASY][HORROR];
            arah = "Barat Laut";
        } else if(tujuan == "FILSAFAT") {
            total_jarak = jarak[HORROR][FILSAFAT];
            arah = "Barat Daya";
        } else if(tujuan == "THRILLER") {
            total_jarak = jarak[HORROR][FILSAFAT] + jarak[FILSAFAT][THRILLER];
            arah = "Barat Daya";
        } else if(tujuan == "KASIR") {
            total_jarak = jarak[HORROR][KASIR];
            arah = "Timur";
        } else {
            cout << "Maaf, Tempat buku tujuan tidak tersedia" << endl;
        }
    } else if(asal == "FILSAFAT") {
        if(tujuan == "FANTASY") {
            total_jarak = jarak[FILSAFAT][HORROR] + jarak[HORROR][FANTASY];
            arah = "Utara";
        } else if(tujuan == "HORROR") {
            total_jarak = jarak[FILSAFAT][HORROR];
            arah = "Timur Laut";
        } else if(tujuan == "THRILLER") {
            total_jarak = jarak[FILSAFAT][THRILLER];
            arah = "Barat Daya";
        } else if(tujuan == "KASIR") {
            total_jarak = jarak[FILSAFAT][HORROR] + jarak[HORROR][KASIR];
            arah = "Timur Laut";
        } else {
            cout << "Maaf, Tempat buku tujuan tidak tersedia" << endl;
        }
    } else if(asal == "THRILLER") {
        if(tujuan == "FANTASY") {
            total_jarak = jarak[THRILLER][FILSAFAT] + jarak[FILSAFAT][HORROR] + jarak[HORROR][FANTASY];
            arah = "Timur Laut";
        } else if(tujuan == "HORROR") {
            total_jarak = jarak[THRILLER][FILSAFAT] + jarak[FILSAFAT][HORROR];
            arah = "Timur Laut";
        } else if(tujuan == "FILSAFAT") {
            total_jarak = jarak[THRILLER][FILSAFAT];
            arah = "Timur Laut";
        } else if(tujuan == "KASIR") {
            total_jarak = jarak[THRILLER][FILSAFAT] + jarak[FILSAFAT][HORROR] + jarak[HORROR][KASIR];
            arah = "Timur Laut";
        } else {
            cout << "Maaf, Tempat buku tujuan tidak tersedia" << endl;
        }
    } else {
        cout << "Maaf, Tempat buku asal tidak tersedia" << endl;
    }

    cout << "Jarak dari " << asal << " ke " << tujuan      << " = " << total_jarak << " m ke arah " << arah << endl;
}

int buyBook() {
    queue<string> custName;
    string name;
    int jml, Code;

    DataBuku();

    cout << "Jumlah pelanggan   : ";
    cin >> jml;

    for(int i = 0; i < jml; i++) {
        cout << "Nama Pelanggan     : ";
        cin >> name;
        custName.push(name);
    }

    for(int i = 0; i < jml; i++) {
        cout << endl;
        cout << "Halo " << custName.front() << "!" << endl;
        cout << "Nomor antrian anda saat ini adalah " << i + 1 << endl;

        /*cout << "Masukkan kode buku : ";
        cin >> Code;

        if(Code == "F20" || Code == "F21" || Code == "F22" || Code == "H30" || Code == "H31" || Code == "FI40" || Code == "FI41" ||Code == "T50" || Code == "T51") {

            int qty;

            cout << "Judul : " << BookData[Code].title << endl;
            cout << "Stok  : " << BookData[Code].stock << endl;
            cout << "Harga : " << BookData[Code].price << endl << endl;
            cout << "Jumlah buku yang dipesan : ";
            cin >> qty;

            if(BookData[Code].Stock < qty){
                std::cout << "Stok Buku di Toko Kurang!" << std::endl;
            } else{
                std::cout << "Jumlah pesanan : " << qty << " buku " << std::endl;
                //Mengurangi stok buku sesuai dengan masukan pelanggan
                BookData[Code].Stock -= qty;
                std::cout << "Sisa stok buku : " << BookData[Code].Stock << std::endl << std::endl;
            }
        } else{
            cout << "Buku Tidak Tersedia!" << endl << endl;
            continue;
        }
        cout << endl << endl;*/

        custName.pop();
    }

    return 0;
}

void menu() {
    cout << endl << endl ;
    cout << "================ MENU BOOKSTORE ===============" << endl;
    cout << "1) Informasi Data Buku Berdasarkan Genre" << endl;
    cout << "2) Cek Tempat Buku Berdasarkan Genre" << endl;
    cout << "3) Pembelian Buku" << endl;
    cout << "4) Keluar Program" << endl;
    cout << "===============================================" << endl << endl;
}

int main() {
    int pilih;

    cout << endl << endl ;
    cout << "#########################################################" << endl;
    cout << "###########SELAMAT DATANG DI ADIWARNA BOOKSTORE##########" << endl;
    cout << "#########################################################" << endl;

    while(true) {
        menu();
        cout << "Masukkan pilihan anda (1-3) : ";
        cin >> pilih;

        switch (pilih) {
            case 1 :
                DataBuku();
                break;
            case 2 :
                cekRakBuku();
                break;
            case 3 :
                buyBook();
                break;
            default:
                cout << "Pilihan yang Anda masukkan salah!" << endl; 
                break;
        }
    }

    return 0;
}