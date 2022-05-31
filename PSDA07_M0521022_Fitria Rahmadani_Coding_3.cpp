#include <iostream>
#include <map>
using namespace std;

map<string, string> bus;
map<string, string> kereta;
map<string, string> pesawat;
map<string, string> kapal;

enum transportasi {
    BUS,
    KERETA_API,
    PESAWAT,
    KAPAL_FERRY,
    J_TRANSPORT
};

string transport[J_TRANSPORT] = {"Bus", "Kereta Api", "Pesawat", "Kapal Ferry"};

//Fungsi untuk menemukan tipe transportasi yang sesuai
string tipeTransportasi(string loc, int modaTransport) {
    if (modaTransport == BUS) {
        if (bus[loc] == loc) {
            return loc;
        }
        return tipeTransportasi(bus[loc], BUS);
    } else if (modaTransport == KERETA_API) {
        if (kereta[loc] == loc) {
            return loc;
        }
        return tipeTransportasi(kereta[loc], KERETA_API);
    } else if (modaTransport == PESAWAT) {
        if (pesawat[loc] == loc) {
            return loc;
        }
        return tipeTransportasi(pesawat[loc], PESAWAT);
    } else if (modaTransport == KAPAL_FERRY) {
        if (kapal[loc] == loc) {
            return loc;
        }
        return tipeTransportasi(kapal[loc], KAPAL_FERRY);
    }
}

//Fungsi untuk menginput tipe transportasi antar kota
void mapTransportasi(string kotaA, string kotaB, int modaTransport) {
    string transKotaA, transKotaB;
    transKotaA = tipeTransportasi(kotaA, modaTransport);
    transKotaB = tipeTransportasi(kotaB, modaTransport);
    if (modaTransport == BUS) {
        bus[transKotaA] = transKotaB;
    } else if (modaTransport == KERETA_API) {
        kereta[transKotaA] = transKotaB;
    } else if  (modaTransport == PESAWAT) {
        pesawat[transKotaA] = transKotaB;
    } else if (modaTransport == KAPAL_FERRY) {
        kapal[transKotaA] = transKotaB;
    }
}

int main () {
    string loc [7] = {"Semarang", "Jakarta", "Aceh", "Banjarmasin", "Denpasar", "Kupang", "Jayapura"};
    
    mapTransportasi(loc[0], loc[1], BUS);
    mapTransportasi(loc[0], loc[1], KERETA_API);
    mapTransportasi(loc[0], loc[1], PESAWAT);
    mapTransportasi(loc[0], loc[2], PESAWAT);
    mapTransportasi(loc[0], loc[3], PESAWAT);
    mapTransportasi(loc[0], loc[4], BUS);
    mapTransportasi(loc[0], loc[5], KAPAL_FERRY);
    mapTransportasi(loc[0], loc[6], PESAWAT);
    mapTransportasi(loc[1], loc[2], PESAWAT);
    mapTransportasi(loc[1], loc[3], PESAWAT);
    mapTransportasi(loc[1], loc[4], BUS);
    mapTransportasi(loc[1], loc[4], PESAWAT);
    mapTransportasi(loc[1], loc[5], PESAWAT);
    mapTransportasi(loc[1], loc[6], KAPAL_FERRY);
    mapTransportasi(loc[1], loc[6], PESAWAT);
    mapTransportasi(loc[2], loc[3], PESAWAT);
    mapTransportasi(loc[2], loc[4], PESAWAT);
    mapTransportasi(loc[2], loc[5], PESAWAT);
    mapTransportasi(loc[2], loc[6], PESAWAT);
    mapTransportasi(loc[3], loc[4], PESAWAT);
    mapTransportasi(loc[3], loc[5], PESAWAT);
    mapTransportasi(loc[3], loc[6], PESAWAT);
    mapTransportasi(loc[4], loc[5], KAPAL_FERRY);
    mapTransportasi(loc[4], loc[6], PESAWAT);
    mapTransportasi(loc[5], loc[6], PESAWAT);

    for (int i = 0; i < J_TRANSPORT; i++) {
        pesawat[loc[i]] = loc[i];
        kapal[loc[i]] = loc[i];
        kereta[loc[i]] = loc[i];
        bus[loc[i]] = loc[i];
    }

    string asal, tujuan;

    while (1) {
        cout << "Lokasi asal    : ";
        cin >> asal;

        cout << "Lokasi tujuan  : ";
        cin >> tujuan;

        cout << "Moda transportasi yang mungkin dari " << asal << " ke " << tujuan << " : " << endl;
        
        for (int i = 0; i < J_TRANSPORT; i++) {
            mapTransportasi(asal, tujuan, i);
            if (tipeTransportasi(asal, i) == tipeTransportasi(tujuan, i)) {
                cout << "- " << transport[i] << endl;
            } else {
                cout << "Transportasi tidak diketahui" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}