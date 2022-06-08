#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama[100];
    int nilai[100], n;

    cout << endl << endl;
    cout << " PROGRAM PENGURUTAN NILAI SISWA " << endl;
    cout << "________________________________" << endl << endl;
    cout << "Jumlah siswa   : ";
    cin >> n;
    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << i+1 << ". " << "Nama siswa (tanpa spasi)  : ";
        cin >> nama[i];
        
        cout << "   " << "Nilai siswa               : ";
        cin >> nilai[i];
        if (nilai[i] >= 0 && nilai[i] <= 100) {
            continue;
            cout << endl;
        } else {
            cout << "     " << "Nilai tidak valid!" << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i ++) {		
		int key = i;				
		for (int j = i + 1; j < n; j ++)
			if (nilai[j] < nilai[key])
				key = j;
		if (key != i) {
			int temp = nilai[key];
            string name = nama[key];
			nilai[key] = nilai[i];
			nilai[i] = temp;
            nama[key] = nama[i];
            nama[i] = name;
		}
	}

    cout << endl << endl;
    cout << " Hasil Pengurutan Nilai dari Terkecil" << endl;
    cout << "------------------------" << endl << endl;

    for(int i = 0; i < n; i++) {
        cout << i+1 << ". " << nama[i] << "     " << " => " << nilai[i] << endl << endl;
    }

    return 0;
}