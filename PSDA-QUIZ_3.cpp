#include <iostream>
using namespace std;

enum tempat {
  RUMAH,
  PASAR,
  SEKOLAH,
  RUMAH_SAKIT,
  J_TEMPAT  
};

string arrTempat[J_TEMPAT] = {"RUMAH", "PASAR", "SEKOLAH", "RUMAH SAKIT"};

enum jarak {
    DEKAT,
    JAUH,
    NOL
};

string arrJarak[J_TEMPAT] = {"Dekat", "Jauh", "Nol"};

int main() {
    jarak pergi[J_TEMPAT][J_TEMPAT];
    for (int i = 0; i < J_TEMPAT; i++) {
        for (int j = 0; j < J_TEMPAT; j++) {
            if (i == j) {
                pergi[i][j] = pergi[j][i] = NOL;
            } else if ((i == RUMAH && j == PASAR) || (i == RUMAH && j == SEKOLAH) || (i == PASAR && j == RUMAH_SAKIT)) {
                pergi[i][j] = pergi[j][i] = DEKAT;
            } else if ((i == PASAR && j == SEKOLAH) || (i == RUMAH && j == RUMAH_SAKIT) || (i == SEKOLAH && j == RUMAH_SAKIT)) {
                pergi[i][j] = pergi[j][i] = JAUH;
            }
        }
    }

    for (int i = 0; i < J_TEMPAT; i++) {
        for (int j = 0; j < J_TEMPAT; j++) {
            pergi[i][j] = pergi[j][i];
            cout << "Jarak antara" << " " << arrTempat[i] << " dan " << arrTempat[j] << " " << arrJarak[pergi[i][j]] << endl;
        }
        cout << endl;
    }

    return 0;
}
