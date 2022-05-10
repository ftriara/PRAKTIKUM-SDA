#include <iostream>
#include <vector>
using namespace std;

//Deklarasi struct Node untuk menyimpan data dan vector children
struct Node {
    //Deklarasi variabel
    int Data;
    vector<Node> Children;

    //Constructor
    Node(int data) {
        Data = data;
    }

    //Fungsi setData untuk mengatur nilai Data
    void setData(int data) {
        Data = data;
    }

    //Fungsi insert untuk memasukkan nilai node
    void insert(Node node) {
        Children.push_back(node);
    }

    //Fungsi deleteNodeIndex untuk menghapus nilai node
    bool deleteNodeIndex(unsigned int index) {
        if (Children.empty()) {
            return false;
        } else {
            if (Children.size() <= index) {
                return false;
            } else {
                Children.erase(Children.begin() + index);
                return true;
            }
        }
    }

    //Fungsi _preOrder untuk penelusuran node secara preorder
    void _preOrder(unsigned int temp = 0) {
        for (unsigned int i = 0; i < temp; i++) {
            cout << "--";
        }
        cout << "> " << Data << '\n';
        for (unsigned int i = 0; i < Children.size(); i++) {
            Children[i]._preOrder(temp + 1);
        }
    }

    void preOrder() {
        cout << "Preorder Traversal: \n";
        _preOrder();
    }

    //Fungsi _postOrder untuk penelusuran node secara postorder
    void _postOrder(unsigned int temp = 0) {
        for (unsigned int i = 0; i < Children.size(); i++) {
            Children[i]._postOrder(temp + 1);
        }
        for (unsigned int i = 0; i < temp; i++) {
            cout << "--";
        }
        cout << "> " << Data << '\n';
    }

    void postOrder() {
        cout << "Postorder Traversal: \n";
        _postOrder();
    }
};

int main() {
    //Memasukkan nilai untuk masing-masing node
    Node root(6);

    Node child_0(2);
    Node child_1(3);
    Node child_2(7);
    Node child_3(11);    

    Node child_0_0(2);
    Node child_0_1(3);

    Node child_1_0(4);
    Node child_1_1(1);
    Node child_1_2(9);
    
    Node child_3_0(6);

    Node child_0_0_0(12);
    Node child_0_0_1(5);
    Node child_0_0_2(5);
    Node child_0_0_3(10);

    Node child_3_0_0(1);
    Node child_3_0_1(7);
    Node child_3_0_2(8);

    Node child_0_0_2_0(8);

    //Membentuk tree
    child_0_0_2.insert(child_0_0_2_0);

    child_0_0.insert(child_0_0_0);
    child_0_0.insert(child_0_0_1);
    child_0_0.insert(child_0_0_2);
    child_0_0.insert(child_0_0_3);

    child_0.insert(child_0_0);

    child_1.insert(child_1_0);
    child_1.insert(child_1_1);
    child_1.insert(child_1_2);

    child_3.insert(child_3_0);

    root.insert(child_0);
    root.insert(child_1);
    root.insert(child_2);
    root.insert(child_3);

    //Menampilkan tree traversal secara preorder dan postorder
    root.preOrder();
    root.postOrder();

    //Menghapus nilai node
    root.Children[0].deleteNodeIndex(0);
    //Memasukkan nilai node
    root.Children[0].insert(child_0_1);

    root.Children[3].Children[0].insert(child_3_0_0);
    root.Children[3].Children[0].insert(child_3_0_1);
    root.Children[3].Children[0].insert(child_3_0_2);

    //Menampilkan tree traversal secara preorder dan postorder setelah perubahan
    root.preOrder();
    root.postOrder();

    return 0;
}

/*Jawaban Pertanyaan Tantangan:
1. Jenis struktur data tree
    a. Binary Tree
       adalah Tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal 2 subtree dan kedua subtree tersebut harus terpisah.
        -Full Binary Tree
            Binary Tree yang tiap nodenya (kecuali leaf) memiliki dua child dan tiap subtree harus mempunyai panjang path yang sama.
        -Complete Binary Tree
            Binary Tree yang tiap subtree boleh memiliki panjang path yang berbeda. Node kecuali leaf memiliki 0 atau 2 child.
        -Skewed Binary Tree
            Binary Tree yang semua nodenya (kecuali leaf) hanya memiliki satu child.
    b. Tree Traversal
       adalah pola urutan kunjungan terhadap node.
        -PreOrder
            Penelusuran node berawal dari root, kemudian berlanjut ke subtree sebelah kiri, jika subtree kiri sudah tidak ada anak lagi,
            diteruskan ke subtree sebelah kanan, terus berlanjut sampai akhir node.
        -InOrder
            Melakukan traversal InOrder secara recursive pada subtree sebelah kiri, menuju ke node ROOT, dan terakhir melakukan traversal
            inorder secara recursive pada subtree sebelah kanan.
        -PostOrder
            Melakukan traversal postorder secara recursive pada subtree bagian kiri dan kanan diikuti dengan berkunjung ke node root.

2.  Kita melakukan insert dari bawah atau cabang terkecil agar nilai node pada cabang-cabang dapat terbaca karena tiap cabang akan dimasukkan
    ke dalam parent masing-masing. Jika melakukan insert mulai dari root maka nilai node yang terbaca hanya node yang parent-nya root dan nilai
    node di cabang-cabang di bawahnya tidak terbaca. Hal tersebut dapat terjadi karena dalam fungsi insert menggunakan perintah .push_back()
    yang artinya nilai node akan ditambahkan pada bagian bawah dari nilai parent pada node cabang. 
*/
