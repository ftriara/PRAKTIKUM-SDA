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

string arrTempat[J_TEMPAT] = {"RUMAH", "PASAR", "SEKOLAH", "RUMAH_SAKIT"};

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

void inputJarak(list<jarakT> *place, tempat t_asal, tempat t_tujuan, string t_jarak) {
    list<jarakT>::iterator it = place->begin();
    bool hapus = false;
    
    for (int i = 0; i < place->size() / 2; i++) {
        if (it->asal == t_asal && it->tujuan == t_tujuan) {
        hapus = true;
        break;
        }
        ++it;

        if (it->tujuan == t_asal && it->asal == t_tujuan) {
            hapus = true;
            break;
        }
        ++it;
    }

    if (hapus) {
        list<jarakT>::iterator it1 = it;
        ++it1;
        place->erase(it);
        place->erase(it1);
    }

    place->push_back(jarakT(t_asal, t_tujuan, t_jarak));
    place->push_back(jarakT(t_tujuan, t_asal, t_jarak));
}

void printJarak(list<jarakT> *place, tempat t_asal, tempat t_tujuan) {
    list<jarakT>::iterator it = place->begin();

    bool cari = false;
    for (int i = 0; i < place->size(); i++) {
        if(it->asal == t_asal && it->tujuan == t_tujuan) {
            cout << "Jarak antara" << " " << arrTempat[it->asal] << " dan " << arrTempat[it->tujuan] << " " << it->jarak << endl;
            cari = true;
            break;
        }
        ++it;
        
    }
    if(!cari) {
        cout << "Jarak antara" << " " << arrTempat[t_asal] << " dan " << arrTempat[t_tujuan] << " " << "Tidak Diketahui" << endl;
    }
}

int main() {
    list<jarakT> place;
    inputJarak(&place, RUMAH, PASAR, "Dekat");
    inputJarak(&place, PASAR, SEKOLAH, "Jauh");

    printJarak(&place, RUMAH, PASAR);
    printJarak(&place, PASAR, SEKOLAH);
    printJarak(&place, RUMAH, SEKOLAH);
    printJarak(&place, RUMAH, RUMAH);
    
    return 0;
}