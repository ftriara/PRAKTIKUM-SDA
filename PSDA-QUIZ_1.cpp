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
    tempat tujuan;
    string jarak;

    jarakTempat(tempat _tujuan, string _jarak) {
        tujuan = _tujuan;
        jarak = _jarak;
    }
};
typedef struct jarakTempat jarakT;

void printJarak(list<jarakT> place[J_TEMPAT], tempat t_asal, tempat t_tujuan) {
    list<jarakT>::iterator it = place[t_asal].begin();
    for (int i = 0; i < place[t_asal].size(); i++) {
        if(it->tujuan == t_tujuan)
            break;
        ++it;
    }{
        if(it->tujuan == t_tujuan){
            cout << "Jarak antara" << " " << arrTempat[t_asal] << " dan " << arrTempat[t_tujuan] << " " << it->jarak << endl;
        } else {
            cout << "Jarak antara" << " " << arrTempat[t_asal] << " dan " << arrTempat[t_tujuan] << " " << "Tidak Diketahui" << endl;
        }
    }

}

int main() {
    list<jarakT> place[J_TEMPAT];
    place[RUMAH].push_back(jarakT(PASAR, "Dekat"));
    place[PASAR].push_back(jarakT(SEKOLAH, "Jauh"));

    printJarak(place, RUMAH, PASAR);
    printJarak(place, PASAR, SEKOLAH);
    printJarak(place, RUMAH, SEKOLAH);
    
    return 0;
}