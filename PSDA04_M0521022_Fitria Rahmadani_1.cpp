#include <iostream>
#include <set>

// mengecek apakah `n` adalah bilangan prima
// return: `true` jika bilangan prima, `false` jika tidak
bool is_prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::set<int> prime_numbers;

    // generate bilangan prima dari 1 sampai 100
    // dan masukkan ke dalam himpunan `prime_numbers`
    for(int i=0; i<=99; i++){
        //If digunakan sebagai bentuk pemilihan apabila termasuk bilangan prima maka akan di-insert
        if (is_prime(i+1)){
            prime_numbers.insert(i+1);
        }
    }

    // cek bilangan prima
    std::cout << "Send Ctrl+C to exit" << std::endl;
    while (true) {
        int num;
        std::cout << "Enter a number: ";
        std::cin >> num;

        // cek apakah `num` adalah bilangan prima dari 1 dan 100
        // fungsi is_prime() memiliki kompleksitas O(N), adakah versi yang lebih baik? Ada
        // jika ada, perbaiki kondisi dalam if di bawah
        std::set<int>::iterator iteration = prime_numbers.find(num);
        if (iteration != prime_numbers.end()) {
            std::cout << num << " is a prime number between 1 and 100" << std::endl;
        }else {
            std::cout << num << " is not a prime number between 1 and 100" << std::endl;
        }
    }

    return 0;
}
