#include <iostream>
using namespace std;

//Deklarasi fungsi rekursif yaitu FungsiPangkat dengan parameter x dan y
long int FungsiPangkat(int x, int y);

int main() {
    //Deklarasi variabel base dan rank
    int base, rank;

    cout << "PROGRAM REKURSI HITUNG PANGKAT" << endl;
    cout << "Nilai basis      = ";
    //Meminta input user berupa nilai basis
    cin >> base;
    cout << "Nilai pangkat    = ";
    //Meminta input user berupa nilai pangkat
    cin >> rank;
    //Eksekusi fungsi rekursif
    cout << base << " Dipangkatkan " << rank << " = " << FungsiPangkat(base,rank) << endl;

    return 0;
}

//Pendefinisian fungsi rekursif yaitu FungsiPangkat
long int FungsiPangkat(int x, int y) {
    if(y==0) {//Base Case
        return 1;
    }else {
        return x*FungsiPangkat(x,y-1);
    }
}
