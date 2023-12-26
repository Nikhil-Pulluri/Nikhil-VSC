// Targets 
// TRIE Implementation
// Timer utility
// GUI

#include<iostream>
#include <fstream> // File handling
#include <cctype> // Some string operations
#include <vector> // Some basic vector operations
#include <string> // To inlcude strings
#include <cstring>
#include <algorithm> // Transform function 


#define ALPH 26

using namespace std;

struct Node   // Declaring the node for TRIE 
{
    char data;
    bool endOfWord;
    // vector<Node*> children;
    Node* children[ALPH];
    bool leaf;
};

Node* createNode(char c) 
{
    Node* newNode = new Node;

    if(newNode == NULL)
    {
        cout << "Cannot create a new node!" << endl;
        return NULL;
    }
    newNode->data = c;
    newNode->endOfWord = false;
    newNode->leaf = false;
    return newNode;
}

Node* findingChild(Node* current, char c) 
{
    // for (int i = 0; i < current->children.size(); i++) { 
    //     Node* temp1 = current->children[i];
    //     if (temp1->data == c) {
    //         return temp1;
    //     }
    // }

    int index = static_cast<int>(c) - 97;

    return current->children[index];
    // return NULL;
}

void addWord(Node* root, string s) 
{
    Node* current = root;
    if (s.size() == 0) 
    {
        current->endOfWord = true; // an empty word
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        Node* child = findingChild(current, s[i]);
        if (child != NULL) 
        {
            current = child;
        }
        else 
        {
            Node* tmp = createNode(s[i]);
            int index = static_cast<int> (s[i]) - 97;
            current->children[index] = tmp;
            current = tmp;
        }
        if (i == s.size() - 1)
            current->endOfWord = true;
    }
}


// Has no use in the code 
// bool searchWord(Node* root, string s) { 
//     Node* current = root;
//     while (current != NULL) {
//         for (int i = 0; i < s.size(); i++) {
//             Node* temp1 = findingChild(current, s[i]);
//             if (temp1 == NULL)
//                 return false;
//             current = temp1;
//         }
//         if (current->endOfWord)
//             return true;
//         else
//             return false;
//     }
//     return false;
// }


void parseTree(Node* current, char* s, vector<string>& res, bool& loop) {
    char k[100] = { 0 }; // empty string initialization 
    char aa[2] = { 0 }; // For concatinating purpose
    if (loop) {
        if (current != NULL) {
            if (current->endOfWord == true) 
            {
                res.push_back(s);
                if (res.size() > 300)
                    loop = false;
            }
            // vector<Node*> child = current->children;
            Node* child[26];
            for(int i=0; i<ALPH; i++) // copying the addresses of the children
            {
                child[i] = current->children[i];
            }
            for (int j = 0; j < ALPH && loop; j++) {
                strcpy(k, s);
                aa[0] = child[j]->data;
                aa[1] = '\0';
                strcat(k, aa);
                if (loop)
                    parseTree(child[j], k, res, loop);
            }
        }
    }
}

bool complete(Node* root, string s, vector<string>& res) 
{
    Node* current = root;
    for (int i = 0; i < s.size(); i++) {
        Node* tmp = findingChild(current, s[i]);
        if (tmp == NULL)
            return false;
        current = tmp;
    }
    char c[100];
    strcpy(c, s.c_str());
    bool loop = true;
    parseTree(current, c, res, loop);
    return true;
}

bool loadDictionary(Node* root, string fn) 
{
    ifstream dictionary;
    dictionary.open(fn.c_str());
    if (!dictionary.is_open()) 
    {
        cout << "Could not open Dictionary file" << endl;
        return false;
    }
    while (!dictionary.eof()) 
    {
        char s[100];
        dictionary >> s;
        addWord(root, s);
    }
    dictionary.close();
    return true;
}

int main() 
{
    Node* root = createNode(' ');
    char mode;
    cout << "Loading the dictionary file" << endl;
    loadDictionary(root, "dictionary.txt");
    while (1) 
    {
        cout << endl
            << endl;
        cout << "Interactive mode, press " << endl;
        cout << "1: Auto Complete Feature" << endl;
        // cout << "2: Enter new words into the dictionary\n";
        cout << "2: Quit" << endl
            << endl;
        cin >> mode;
        if (isalpha(mode)) {
            cout << "Invalid Input!\n";
            cout << "Enter either 1 or 2..";
            continue;
        }
        switch (mode) {
        case '1': 
        {
            string s;
            cout << "Enter the partial word : ";
            cin >> s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            vector<string> listOfWords;
            complete(root, s, listOfWords);
                cout << "Auto complete reply :" << endl;
                for (int i = 0; i < listOfWords.size(); i++) {
                    cout << " \t     " << listOfWords[i] << endl;
            }
            continue;
        }
        case '2':
            delete root;
            return 0;
        default:
            cout << "Invalid input!";
            cout << "\nEnter either 1 or 2..";
            continue;
        }
    }
}
