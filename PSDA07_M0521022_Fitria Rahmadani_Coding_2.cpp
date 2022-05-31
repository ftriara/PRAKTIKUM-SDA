#include <iostream>
using namespace std;

enum tempat {
    RUMAH,
    UNIVERSITAS_SEBELAS_MARET,
    RUMAH_SAKIT_DR_MOEWARDI,
    SMP_NEGERI_8_SURAKARTA,
    PECEL_MADIUN_PUCANGSAWIT,
    SMP_NEGERI_4_SURAKARTA,
    SMA_NEGERI_3_SURAKARTA,
    J_TEMPAT
};

void jarakTempat(double jarak[J_TEMPAT][J_TEMPAT], tempat tempatA, tempat tempatB, double s) {
    jarak[tempatA][tempatB] = jarak[tempatB][tempatA] = s;
}

int main() {
    double jarak[J_TEMPAT][J_TEMPAT];

    //Jarak dari masing-masing node yang terhubung langsung oleh edge
    jarakTempat(jarak, RUMAH, UNIVERSITAS_SEBELAS_MARET, 2.97);
    jarakTempat(jarak, RUMAH, PECEL_MADIUN_PUCANGSAWIT, 2.54);

    jarakTempat(jarak, UNIVERSITAS_SEBELAS_MARET, RUMAH_SAKIT_DR_MOEWARDI, 2.86);
    jarakTempat(jarak, UNIVERSITAS_SEBELAS_MARET, SMP_NEGERI_8_SURAKARTA, 1.61);
    
    jarakTempat(jarak, RUMAH_SAKIT_DR_MOEWARDI, SMP_NEGERI_4_SURAKARTA, 1.43);

    jarakTempat(jarak, SMP_NEGERI_8_SURAKARTA, SMP_NEGERI_4_SURAKARTA, 2.99);
    jarakTempat(jarak, SMP_NEGERI_8_SURAKARTA, SMA_NEGERI_3_SURAKARTA, 1.25);

    jarakTempat(jarak, PECEL_MADIUN_PUCANGSAWIT, SMP_NEGERI_4_SURAKARTA, 4.00);
    jarakTempat(jarak, PECEL_MADIUN_PUCANGSAWIT, SMA_NEGERI_3_SURAKARTA, 2.28);

    //Jarak dari masing-masing node yang tidak terhubung langsung oleh edge yaitu -1.0
    jarakTempat(jarak, RUMAH, RUMAH_SAKIT_DR_MOEWARDI, -1.0);
    jarakTempat(jarak, RUMAH, SMP_NEGERI_8_SURAKARTA, -1.0);
    jarakTempat(jarak, RUMAH, SMP_NEGERI_4_SURAKARTA, -1.0);
    jarakTempat(jarak, RUMAH, SMA_NEGERI_3_SURAKARTA, -1.0);

    jarakTempat(jarak, UNIVERSITAS_SEBELAS_MARET, SMP_NEGERI_4_SURAKARTA, -1.0);
    jarakTempat(jarak, UNIVERSITAS_SEBELAS_MARET, SMA_NEGERI_3_SURAKARTA, -1.0);
    jarakTempat(jarak, UNIVERSITAS_SEBELAS_MARET, PECEL_MADIUN_PUCANGSAWIT, -1.0);

    jarakTempat(jarak, RUMAH_SAKIT_DR_MOEWARDI, SMA_NEGERI_3_SURAKARTA, -1.0);
    jarakTempat(jarak, RUMAH_SAKIT_DR_MOEWARDI, SMP_NEGERI_8_SURAKARTA, -1.0);
    jarakTempat(jarak, RUMAH_SAKIT_DR_MOEWARDI, PECEL_MADIUN_PUCANGSAWIT, -1.0);

    jarakTempat(jarak, SMP_NEGERI_8_SURAKARTA, PECEL_MADIUN_PUCANGSAWIT, -1.0);

    jarakTempat(jarak, SMP_NEGERI_4_SURAKARTA, SMA_NEGERI_3_SURAKARTA, -1.0);

    //Jarak dari masing-masing node ke dirinya sendiri
        for(int i = 0; i < J_TEMPAT; i++){
            for(int j = 0; j < J_TEMPAT; j++){
                if(i == j){
                    jarak[i][j] = 0.0;
                }
            }
        }

    //Hitung jarak dari Rumah - SMA Negeri 3 Surakarta
    double total_jarak = 0.0;
    double waktu = 10.0 / 60.0;
    double kecepatan;
    total_jarak = jarak[RUMAH][UNIVERSITAS_SEBELAS_MARET] + jarak[UNIVERSITAS_SEBELAS_MARET][SMP_NEGERI_8_SURAKARTA] + jarak[SMP_NEGERI_8_SURAKARTA][SMA_NEGERI_3_SURAKARTA];

    kecepatan = total_jarak / waktu;

    cout << "Jarak dari Rumah - SMA Negeri 3 Surakarta               = " << total_jarak << " km" << endl;
    cout << "Waktu dari Rumah - SMA Negeri 3 Surakarta               = " << waktu << " jam" << endl;
    cout << "Kecepatan rata-rata dari Rumah - SMA Negeri 3 Surakarta = " << kecepatan << " km/jam ";

    return 0;
}