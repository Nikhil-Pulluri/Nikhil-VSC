#include<iostream> // Standard input and output functions
#include<algorithm> // For Transform function ( Caps to Lower )
#include<stdlib.h> // Dynamic Data Allocation - new and delete operators
#include<string> // Basic String operations
#include<cctype> 
#include<fstream> // File Handling - Dictionary Loading

#define ALPH 26
#define MAX 100

using namespace std;

// Implementation of TRIE

struct node // TRIE Node
{
	struct node* child[ALPH];
	// Array of structure pointers for the next letter in the word sequence

	bool end;
	// Indicates the end of the word - either yes or no
};



struct node* create()
{
	node* newn = new node;

	if (newn == nullptr)
	{
		cerr << "Data Allocation Failed!";
		return nullptr;
	}

	// Making every child in the node to point to nullptr
	for (int i = 0; i < ALPH; i++)
	{
		newn->child[i] = nullptr;
	}

	newn->end = false;

	return newn;
}


// Insertion of a word from dectinary - happens in a loop from the main function
void insert(struct node* root, string& word)
{
	if (root == nullptr) {
		cerr << "The TRIE is empty!" << endl;
		return;
	}

	struct node* current = root;
	int index;
	for (auto k : word) // Auto Iteration using elements in the string
	{
		index = (int)k - 97;

		// For new entry of a certain 
		if (current->child[index] == nullptr) // Check if the node exists
		{
			current->child[index] = create();
			// Traversing to the next node
			current = current->child[index];
		}

		// else contunue in the respective index ( intersection of two words)

		current = current->child[index];

	}

	current->end = true;
	// Indicates the end of a word from the dictinary

}

// Insertion of a word ends


// Auto complete Operation starts

// Prints all possible suitable words from the TRIE using prefix entered by the user
void auto_complete_words(struct node* terminal, string prefix, string possible_word)
{
	// termminating condition for recursive call
	if (terminal == nullptr)
	{
		return; // Indicates the end of a branch in the TRIE - one word finished
	}

	// Printing one possible word 
	if (terminal->end == true)
	{
		cout << possible_word << endl;
	}

	// we have to make the recursive initiation here and we have to update the possible word string
	for (int i = 0; i < ALPH; i++)
	{
		if (terminal->child[i] != nullptr)
		{
			possible_word[possible_word.size()] = i + 'a'; // it should be a string
			possible_word[possible_word.size() + 1] = '\0';
			auto_complete_words(terminal->child[i], prefix, possible_word); // Recursive call initiates
			possible_word[possible_word.size() - 1] = '\0';
		}

		/*

		currentWord[strlen(currentWord)] = i + 'a';
		currentWord[strlen(currentWord) + 1] = '\0';
		autocomplete(node->children[i], prefix, currentWord);
		currentWord[strlen(currentWord) - 1] = '\0'; // Backtrack
		*/

	}
}

// decides the starting node for recursive calling
void terminating_node(struct node* root, string& prefix)
{
	// Prefix is the word we give as input

	struct node* current = root;

	if (root == nullptr)
	{
		cerr << "The TRIE does not exist!" << endl;
		return;
	}

	// Traversing the string to the end and make a conclusion on the auto-complete root node
	int index;
	for (auto k : prefix)
	{
		index = (int)k - 97;
		if (current->child[index] == nullptr)
		{
			cout << "Sorry!" << endl;
			cout << "Unfortunately, there are no words available for the given prefix" << endl;
			return;
		}

		current = current->child[index];
	}

	char possible_word[MAX];
	possible_word[0] = '\0';

	auto_complete_words(current, prefix, possible_word);

}


FILE *file;
    char word[MAX_WORD_LENGTH];

    // Open the file for reading
    file = fopen("dictionary.txt", "r");  // Replace "dictionary.txt" with your actual file name

    if (file == NULL) {
        perror("Error opening dictionary file");
        return 1; // Return an error code
    }

    // Read words from the file until the end is reached
    while (fscanf(file, "%s", word) != EOF) {
        // Process each word as needed
        printf("Word: %s\n", word);
    }

    // Close the file
    fclose(file);



// Function to load the dictinary words in to the TRIE - Includes File Handling
// Make sure to convert all the words into lower case
void dictionary_loading(struct node* root)
{

	// File Handling starts
	ifstream File("dictionary.txt");

	if (!File.is_open()) {
		cerr << "Error opening dictionary file." << endl;
		return;
	}

	string word;

	while (getline(File, word))
	{
		// Converts the words of dictionary into lower cases
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		// Insertion of words in to TRIE
		insert(root, word);
	}

	File.close();
	// File Handling ends

	// objectives
	// convert the word recieved from dictionary to lower case
}




int main()
{
	// Creating the root node of TRIE
	struct node* root;

	// Loading the words from ditionary into TRIE
	// Loading not checked yet! remove this comment after testing
	dictionary_loading(root);

	// Word input
	string prefix;
	getline(cin, prefix);

	// Caps to Lower of string
	transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);

	// Calling the terminal node function to find the suitable node for start searching
	// The game starts here : )
	terminating_node(root, prefix);


	return 0;
}