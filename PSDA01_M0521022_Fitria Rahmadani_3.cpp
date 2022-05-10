#include <iostream>
#include <queue>
#include <stack>

int main() {
    //Deklarasi queue
    std::queue<std::string> input;

    //Deklarasi stack
    std::stack<int> output;

    //Menambahkan elemen berupa instruksi
    input.push("PUSH 0");
    input.push("PUSH 0");
    input.push("TOP");
    input.push("PUSH 1");
    input.push("TOP");
    input.push("POP");
    input.push("POP");
    input.push("TOP");

    //Deklarasi variabel process
    std::string process;
    //Deklarasi variabel printout
    int printout;

    //Menjalankan instruksi
    int size = input.size();
    for(int i=0; i<size; i++){
        process = input.front();
        if (process == "PUSH 0"){
            output.push(0);
        }else if (process == "PUSH 1"){
            output.push(1);
        }else if (process == "TOP"){
            printout = output.top();
            std::cout << printout;
        }else if (process == "POP"){
            output.pop();
        }
        input.pop();
    }

    return 0;
}
