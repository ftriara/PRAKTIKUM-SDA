#include <iostream>
#include <list>
#include <iterator>
using namespace std;

enum tempat {
  RUMAH,
  PASAR,
  SEKOLAH,
  RUMAH_SAKIT,
  J_TEMPAT  
};

string arrTempat[J_TEMPAT] = {"RUMAH", "PASAR", "SEKOLAH", "RUMAH SAKIT"};

struct jarakTempat {
    tempat asal;
    tempat tujuan;
    string jarak;

    jarakTempat(tempat _asal, tempat _tujuan, string _jarak) {
        asal = _asal;
        tujuan = _tujuan;
        jarak = _jarak;
    }
};
typedef struct jarakTempat jarakT;

int main() {
    std::list<jarakT> place;

    place.push_back(jarakT(RUMAH, PASAR, "Dekat"));
    place.push_back(jarakT(PASAR, SEKOLAH, "Jauh"));
    place.push_back(jarakT(PASAR, RUMAH_SAKIT, "Dekat"));
    place.push_back(jarakT(SEKOLAH, RUMAH_SAKIT, "Tidak Diketahui"));
    
    for (
        list<jarakT>::iterator it = place.begin();
        it != place.end();
        ++it
    ) {
        cout << "Jarak antara" << " " << arrTempat[it->asal] << " dan " << arrTempat[it->tujuan] << " " << it->jarak << endl;
    }

    return 0;
}