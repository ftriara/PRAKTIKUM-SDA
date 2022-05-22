#include <iostream>
using namespace std;

//Deklarasi struct untuk menyimpan value node
struct Node {
	int item;
	struct Node *kiri, *kanan;
};

//Fungsi untuk membentuk Binary Search Tree
struct Node* nodeBST(int num)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->item = num;
	temp->kiri = temp->kanan = NULL;
	return temp;
}

//Fungsi untuk memasukkan value ke dalam node
struct Node* insertNode(struct Node* node, int val)
{
	//Jika node kosong maka diisi val
	if (node == NULL)
		return nodeBST(val);

	//Mengecek apakah val lebih kecil dari node yang ditunjuk, jika iya maka val dimasukkan ke dalam child kiri dari node.
    //Jika tidak maka val dimasukkan ke dalam child kanan dari node.
	if (val < node->item){
		node->kiri = insertNode(node->kiri, val);
	} else{
		node->kanan = insertNode(node->kanan, val);
	}
	return node;
}

//Fungsi untuk mencari nilai minimum di BST
struct Node* minNode(struct Node* node)
{
	struct Node* temp = node;

	//Loop untuk menemukan value node paling kiri
	while (temp && temp->kiri != NULL)
		temp = temp->kiri;

	return temp;
}

//Fungsi untuk menghapus node dalam BST
struct Node* deleteNode(struct Node* node, int val)
{
	//Base case
	if (node == NULL)
		return node;

	if (val < node->item){
		node->kiri = deleteNode(node->kiri, val);
	} else if (val > node->item){
		node->kanan = deleteNode(node->kanan, val);
	} else{
		//Jika node tidak memiliki child
		if (node->kiri==NULL && node->kanan==NULL){
			return NULL;

		//Jika node memiliki satu child
		} else if (node->kiri == NULL){
			struct Node* temp = node->kanan;
			free(node);
			return temp;
		} else if (node->kanan == NULL){
			struct Node* temp = node->kiri;
			free(node);
			return temp;

		//Jika node memiliki dua child
		} else{
			struct Node* temp = minNode(node->kanan);
			node->item = temp->item;
			node->kanan = deleteNode(node->kanan, temp->item);
		}
	}
	return node;
}

//Fungsi untuk menyusun node secara inorder traversal
void inOrder(struct Node* node)
{
	if (node != NULL){
		inOrder(node->kiri);
		cout << "--> " << node->item << "\n";
		inOrder(node->kanan);
	}
}

int main()
{
	struct Node* rootNode = NULL;
	rootNode = insertNode(rootNode, 50);
	rootNode = insertNode(rootNode, 30);
	rootNode = insertNode(rootNode, 20);
	rootNode = insertNode(rootNode, 40);
	rootNode = insertNode(rootNode, 70);
	rootNode = insertNode(rootNode, 60);
	rootNode = insertNode(rootNode, 80);

	cout << "\nBST sebelum modifikasi:\n";
	inOrder(rootNode);

	cout << "\n\nBST setelah modifikasi (Hapus 20):\n";
	rootNode = deleteNode(rootNode, 20);
	inOrder(rootNode);

	cout << "\n\nBST setelah modifikasi (Hapus 30):\n";
	rootNode = deleteNode(rootNode, 30);
	inOrder(rootNode);

	cout << "\n\nBST setelah modifikasi (Hapus 50):\n";
	rootNode = deleteNode(rootNode, 50);
	inOrder(rootNode);

	return 0;
}
