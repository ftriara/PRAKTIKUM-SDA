#include <iostream>
using namespace std;

enum klub {
    REAL_MADRID,
    CHELSEA,
    AC_MILAN,
    VALENCIA,
    J_KLUB
};

enum hasil {
    MENANG,
    SERI,
    KALAH
};

struct Pertandingan {
    int j_gol;
    int poin;
    hasil result;

    Pertandingan()
    {
        j_gol = 0;
        poin = 0;
    }
}; typedef struct Pertandingan match;

//Fungsi untuk mengonversi nama klub
string namaKlub(klub name) {
    switch (name) {
        case REAL_MADRID :
            return "Real Madrid";
            break;
        case CHELSEA :
            return "Chelsea";
            break;
        case AC_MILAN :
            return "AC Milan";
            break;
        case VALENCIA :
            return "Valencia";
            break;
        default :
            return "Data tidak tersedia";
            break;
    }
}

//Fungsi untuk mengonversi hasil pertandingan
string hasilKlub(hasil result) {
    switch (result) {
        case MENANG:
            return " mengalahkan ";
            break;
        case SERI:
            return " diimbangi ";
            break;
        case KALAH:
            return " dikalahkan ";
            break;
        default:
            return "Data tidak tersedia";
            break;
    }
}

//Fungsi untuk menginput jumlah gol klub dan lawan
void insertSkor(match pertandingan[J_KLUB][J_KLUB], klub Klub, klub Lawan, int golKlub, int golLawan) {
    pertandingan[Klub][Lawan].j_gol = golKlub;
    pertandingan[Lawan][Klub].j_gol = golLawan;

    if (golKlub > golLawan) {
        pertandingan[Klub][Lawan].result = MENANG;
        pertandingan[Lawan][Klub].result = KALAH;
    } else if (golKlub == golLawan) {
        pertandingan[Klub][Lawan].result = pertandingan[Lawan][Klub].result = SERI;
    } else if (golKlub < golLawan) {
        pertandingan[Klub][Lawan].result = KALAH;
        pertandingan[Lawan][Klub].result = MENANG;
    } else {
        cout << "Data tidak tersedia" << endl;
    }
}

//Fungsi untuk mencetak skor klub dan skor lawan
void printSkor(match pertandingan[J_KLUB][J_KLUB], klub Klub, klub Lawan) {
    cout << "   " << namaKlub(Klub) << hasilKlub(pertandingan[Klub][Lawan].result) << namaKlub(Lawan) << " dengan skor " << pertandingan[Klub][Lawan].j_gol << " - " << pertandingan[Lawan][Klub].j_gol << endl;
}

//Fungsi untuk menghitung selisih gol antara 2 klub
int selisihGol(match pertandingan[J_KLUB][J_KLUB], klub Klub, klub Lawan) {
    return (pertandingan[Klub][Lawan].j_gol - pertandingan[Lawan][Klub].j_gol);
}

//Fungsi untuk mencetak selisih gol antara 2 klub
void printSelisihGol(match pertandingan[J_KLUB][J_KLUB], klub Klub, klub Lawan) {
    cout << "   " << "Selisih gol antara " << namaKlub(Klub) << " dan " << namaKlub(Lawan) << " adalah " << selisihGol(pertandingan, Klub, Lawan) << endl;
}

//Fungsi untuk menghitung total poin klub
int totalPoin(match pertandingan[J_KLUB][J_KLUB], klub Klub)
{
    int temp = 0;
    for (int i = 0; i < J_KLUB; i++) {
        switch (pertandingan[Klub][i].result) {
                case MENANG :
                temp += 3;
                break;
            case SERI :
                temp += 1;
                break;
            case KALAH :
                temp += 0;
                break;
            default :
                break;
        }
    }
    return temp;
}

//Fungsi untuk mencetak total poin klub
void printTotalPoin(match pertandingan[J_KLUB][J_KLUB], klub Klub) {
    cout << "       " << "Total poin dari " << namaKlub(Klub) << " ===> " << totalPoin(pertandingan, Klub);
}

int main () {
    match pertandingan[J_KLUB][J_KLUB];

    insertSkor(pertandingan, REAL_MADRID, VALENCIA, 3, 4);
    insertSkor(pertandingan, AC_MILAN, VALENCIA, 3, 2);
    insertSkor(pertandingan, CHELSEA, AC_MILAN, 4, 5);
    insertSkor(pertandingan, REAL_MADRID, CHELSEA, 3, 3);
    insertSkor(pertandingan, VALENCIA, CHELSEA, 2, 3);
    insertSkor(pertandingan, REAL_MADRID, AC_MILAN, 2, 2);

    cout << endl << "_____________________________________________________________" << endl << endl;
    for (int i = 0; i < J_KLUB; i++) {
        klub itI = static_cast<klub>(i);
        for (int j = 0; j < J_KLUB; j++) {
            klub itJ = static_cast<klub>(j);
            if (i == j) {
                continue;
            }
            printSkor(pertandingan, itI, itJ);
            printSelisihGol(pertandingan, itI, itJ);
            cout << endl;
        }
        printTotalPoin(pertandingan, itI);
        cout << endl << "_____________________________________________________________" << endl << endl;
    }
    return 0;
}
