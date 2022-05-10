#include <fstream>
#include <iostream>
#include <random>

using namespace std;

#ifndef Node_h 
#define Node_h

struct Node
{
	char letter;
	Node *previous, *next;
};

#endif

#ifndef Word_h 
#define Word_h

class Word
{
	friend istream &operator >> (istream &input, Word &w);
	friend ostream &operator << (ostream &output, const Word &w);
	public:
		Word ();
		Word (const Word &w);
		Word (const char *w);
		Word &operator = (const Word &w);
		Word &operator = (const char *w);
		bool operator == (const Word &w);
		bool operator == (const char *w);
		bool operator != (const Word &w);
		bool operator != (const char *w);
		bool operator < (const Word &w);
		bool operator < (const char *w);
		bool operator > (const Word &w);
		bool operator > (const char *w);
		bool operator <= (const Word &w);
		bool operator <= (const char *w);
		bool operator >= (const Word &w);
		bool operator >= (const char *w);
		const char &operator [] (int index);
		char *GetACharacterString ();
		int GetLength ();
		Node *GetWord ();
		void GenerateARandomWord ();
		void Empty ();
		~Word ();
	private:
		int length, *lengths, numberofwords;
		Node *word, **dictionary;
};

#endif