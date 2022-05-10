#include <iostream>
#include <ctime>
#include <chrono>

class Timer {
    private :
        // Deklarasi variabel
        long int start;
        long int end;
        long int temp;

        // Fungsi reset data
        void reset() {
            this->start = 0;
            this->end = 0;
            this-> temp = 0;
        }
    public :
        Timer() {
            this->reset();
        }

        // Set
        void setStart() {
            this->reset();
            this->start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        }
        void setEnd() {
            this->end = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            this->temp = end - start;
        }
        // Get
        time_t takeTemp() {
            return this->temp;
        }
};

long int FiboRecurse(int n) {
    //Base case
    if(n<=1){
        return n;
    }

    //Pemanggilan rekursif sekaligus pembagian masalah
    return FiboRecurse(n-1) + FiboRecurse(n-2);
}

int FiboIteration(int n) {
    int x = 0, y = 1, z = 0;
    for (int i = 0; i < n; i++) {
      z = x + y;
      x = y;
      y = z;
    }
}

int main() {
    Timer CTimer;
    int n;
    CTimer.setStart();
    FiboRecurse(10);
    CTimer.setEnd();
    std::cout << "Durasi Eksekusi Rekursi : " << CTimer.takeTemp() << "ms" << std::endl;

    CTimer.setStart();
    FiboIteration(10);
    CTimer.setEnd();
    std::cout << "Durasi Eksekusi Iterasi : " << CTimer.takeTemp() << "ms" << std::endl;

    return 0;
}
