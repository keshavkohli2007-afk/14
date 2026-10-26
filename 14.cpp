
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code) {
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

void huffmanCoding(char chars[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    cout << "Huffman Codes:\n";
    generateCodes(pq.top(), "");
}

int main() {
    char chars[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int n = sizeof(chars) / sizeof(chars[0]);

    huffmanCoding(chars, freq, n);

    return 0;
}
