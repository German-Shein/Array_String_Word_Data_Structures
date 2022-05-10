#include "Word.h"

istream &operator >> (istream &input, Word &w)
{
	w.Empty ();
	int index;
	w.word = new Node;
	w.word -> previous = NULL;
	w.word -> next = NULL;
	while (true)
	{
		input.get (w.word -> letter);
		if (!isalpha (w.word -> letter) && w.word -> letter != '-')
		{
			break;
		}
		w.word -> next = new Node;
		w.word -> next -> previous = w.word;
		w.word = w.word -> next;
		w.word -> next = NULL;
		w.length = w.length + 1;
	}
	Node *temp = w.word;
	w.word = w.word -> previous;
	delete temp;
	w.word -> next = NULL;
	for (index = 0; index < w.length - 1; index = index + 1)
	{
		w.word -> letter = tolower (w.word -> letter);
		w.word = w.word -> previous;
	}
	w.word -> letter = toupper (w.word -> letter);
	Word temporary;
	for (index = 0; index < w.numberofwords; index = index + 1)
	{
		temporary.word = temporary.dictionary [index];
		temporary.length = temporary.lengths [index];
		if (temporary == w)
		{
			return input;
		}
	}
	w.Empty ();
	input.clear ();
	return input;
}

ostream &operator << (ostream &output, const Word &w)
{
	Node *temp = w.word;
	while (temp != NULL)
	{
		output << temp -> letter;
		temp = temp -> next;
	}
	return output;
}

Word::Word ()
{
	word = NULL;
	length = 0;
	char temporarycharacter;
	ifstream dictionarycreator;
	int index;
	dictionarycreator.open ("Words.txt");
	numberofwords = 0;
	while (!dictionarycreator.eof ())
	{
		dictionarycreator.get (temporarycharacter);
		if (temporarycharacter == '\n')
		{
			numberofwords = numberofwords + 1;
		}
	}
	numberofwords = numberofwords - 1;
	dictionary = new Node* [numberofwords];
	lengths = new int [numberofwords];
	for (index = 0; index < numberofwords; index = index + 1)
	{
		dictionary [index] = NULL;
	}
	dictionarycreator.close ();
	dictionarycreator.open ("Words.txt");
	for (index = 0; index < numberofwords; index = index + 1)
	{
		lengths [index] = 0;
		dictionarycreator.get (temporarycharacter);
		while (temporarycharacter != '\n')
		{
			if (dictionary [index] == NULL)
			{
				dictionary [index] = new Node;
				dictionary [index] -> previous = NULL;
				dictionary [index] -> letter = toupper (temporarycharacter);
				dictionary [index] -> next = NULL;
				lengths [index] = lengths [index] + 1;
			}
			else
			{
				dictionary [index] -> next = new Node;
				dictionary [index] -> next -> previous = dictionary [index];
				dictionary [index] = dictionary [index] -> next;
				dictionary [index] -> letter = temporarycharacter;
				dictionary [index] -> next = NULL;
				lengths [index] = lengths [index] + 1;
			}
			dictionarycreator.get (temporarycharacter);
		}
		while (dictionary [index] -> previous != NULL)
		{
			dictionary [index] = dictionary [index] -> previous;
		}
	}
	dictionarycreator.close ();
}

Word::Word (const Word &w)
{
	int index;
	Node *link, *copy;
	length = w.length;
	link = w.word;
	if (link == NULL)
	{
		word = NULL;
	}
	else
	{
		word = new Node;
		copy = new Node;
		word = copy;
		copy -> previous = NULL;
		copy -> letter = link -> letter;
		copy -> next = NULL;
		while (link -> next != NULL)
		{
			link = link -> next;
			copy -> next = new Node;
			copy -> next -> previous = link -> previous;
			copy = copy -> next;
			copy -> letter = link -> letter;
			copy -> next = NULL;
		}
	}
	dictionary = w.dictionary;
	numberofwords = w.numberofwords;
	lengths = new int [numberofwords];
	for (index = 0; index < numberofwords; index = index + 1)
	{
		lengths [index] = w.lengths [index];
	}
}

Word::Word (const char *w)
{
	bool match = false;
	char *temp = new char [strlen (w) + 1];
	int index1, index2 = 0;
	for (index1 = 0; index1 < strlen (w); index1 = index1 + 1)
	{
		if (isalpha (w [index1]) || w [index1] == '-')
		{
			temp [index2] = w [index1];
			temp [index2] = tolower (temp [index2]);
			index2 = index2 + 1;
		}
	}
	temp [0] = toupper (temp [0]);
	temp [index2] = '\0';
	word = new Node;
	word -> previous = NULL;
	word -> next = NULL;
	word -> letter = temp [0];
	length = strlen (temp);
	for (index1 = 1; index1 < length; index1 = index1 + 1)
	{
		word -> next = new Node;
		word -> next -> previous = word;
		word = word -> next;
		word -> letter = temp [index1];
		word -> next = NULL;
	}
	for (index1 = 0; index1 < length - 1; index1 = index1 + 1)
	{
		word = word -> previous;
	}
	delete temp;
	Word temporary;
	for (index1 = 0; index1 < temporary.numberofwords; index1 = index1 + 1)
	{
		temporary.word = temporary.dictionary [index1];
		temporary.length = temporary.lengths [index1];
		if (temporary == w)
		{
			match = true;
			dictionary = temporary.dictionary;
			numberofwords = temporary.numberofwords;
			for (index1 = 0; index1 < temporary.numberofwords; index1 = index1 + 1)
			{
				lengths [index1] = temporary.lengths [index1];
			}
		}
	}
	if (match == false)
	{
		Empty ();
	}
}

Word &Word::operator = (const Word &w)
{
	if (*this == w)
	{
		return *this;
	}
	int index;
	Node *link, *copy;
	link = w.word;
	Empty ();
	if (link == NULL)
	{
		word = NULL;
	}
	else
	{
		word = new Node;
		copy = new Node;
		word = copy;
		copy -> previous = NULL;
		copy -> letter = link -> letter;
		copy -> next = NULL;
		while (link -> next != NULL)
		{
			link = link -> next;
			copy -> next = new Node;
			copy -> next -> previous = link -> previous;
			copy = copy -> next;
			copy -> letter = link -> letter;
			copy -> next = NULL;
		}
	}
	length = w.length;
	dictionary = w.dictionary;
	numberofwords = w.numberofwords;
	lengths = new int [numberofwords];
	for (index = 0; index < numberofwords; index = index + 1)
	{
		lengths [index] = w.lengths [index];
	}
	return *this;
}

Word &Word::operator = (const char *w)
{
	Empty ();
	char *temp = new char [strlen (w) + 1];
	int index1, index2 = 0;
	for (index1 = 0; index1 < strlen (w); index1 = index1 + 1)
	{
		if (isalpha (w [index1]) || w [index1] == '-')
		{
			temp [index2] = w [index1];
			temp [index2] = tolower (temp [index2]);
			index2 = index2 + 1;
		}
	}
	temp [0] = toupper (temp [0]);
	temp [index2] = '\0';
	word = new Node;
	word -> previous = NULL;
	word -> next = NULL;
	word -> letter = temp [0];
	length = strlen (temp);
	for (index1 = 1; index1 < length; index1 = index1 + 1)
	{
		word -> next = new Node;
		word -> next -> previous = word;
		word = word -> next;
		word -> letter = temp [index1];
		word -> next = NULL;
	}
	for (index1 = 0; index1 < length - 1; index1 = index1 + 1)
	{
		word = word -> previous;
	}
	delete temp;
	Word temporary;
	for (index1 = 0; index1 < numberofwords; index1 = index1 + 1)
	{
		temporary.word = temporary.dictionary [index1];
		temporary.length = temporary.lengths [index1];
		if (temporary == w)
		{
			dictionary = temporary.dictionary;
			numberofwords = temporary.numberofwords;
			for (index1 = 0; index1 < temporary.numberofwords; index1 = index1 + 1)
			{
				lengths [index1] = temporary.lengths [index1];
			}
			return *this;
		}
	}
	Empty ();
	return *this;
}

bool Word::operator == (const Word &w)
{
	if (length != w.length)
	{
		return false;
	}
	else
	{
		Node *temp1, *temp2;
		temp1 = word;
		temp2 = w.word;
		while (temp1 != NULL)
		{
			if (temp1 -> letter != temp2 -> letter)
			{
				return false;
			}
			temp1 = temp1 -> next;
			temp2 = temp2 -> next;
		}
		return true;
	}
}

bool Word::operator == (const char *w)
{
	if (strlen (w) != length)
	{
		return false;
	}
	int index;
	Node *temp = word;
	for (index = 0; index < length; index = index + 1)
	{
		if (temp -> letter != w [index])
		{
			return false;
		}
		temp = temp -> next;
	}
	return true;
}

bool Word::operator != (const Word &w)
{
	if (length != w.length)
	{
		return true;
	}
	else
	{
		Node *temp1, *temp2;
		temp1 = word;
		temp2 = w.word;
		while (temp1 != NULL)
		{
			if (temp1 -> letter != temp2 -> letter)
			{
				return true;
			}
			temp1 = temp1 -> next;
			temp2 = temp2 -> next;
		}
		return false;
	}
}

bool Word::operator != (const char *w)
{
	if (strlen (w) != length)
	{
		return true;
	}
	int index;
	Node *temp = word;
	for (index = 0; index < length; index = index + 1)
	{
		if (temp -> letter != w [index])
		{
			return true;
		}
		temp = temp -> next;
	}
	return false;
}

bool Word::operator < (const Word &w)
{
	Word temp = w;
	return (strcmp (GetACharacterString (), temp.GetACharacterString ()) < 0);
}

bool Word::operator < (const char *w)
{
	return (strcmp (GetACharacterString (), w) < 0);
}

bool Word::operator > (const Word &w)
{
	Word temp = w;
	return (strcmp (GetACharacterString (), temp.GetACharacterString ()) > 0);
}

bool Word::operator > (const char *w)
{
	return (strcmp (GetACharacterString (), w) > 0);
}

bool Word::operator <= (const Word &w)
{
	return operator == (w) || operator < (w);
}

bool Word::operator <= (const char *w)
{
	return operator == (w) || operator < (w);
}

bool Word::operator >= (const Word &w)
{
	return operator == (w) || operator > (w);
}

bool Word::operator >= (const char *w)
{
	return operator == (w) || operator > (w);
}

const char &Word::operator [] (int index)
{
	if (length == 0)
	{
		return '\0';
	}
	if (index < 0)
	{
		index = 0;
	}
	if (index >= length)
	{
		index = length - 1;
	}
	int counter = 0;
	Node *temp = word;
	while (counter != index)
	{
		counter = counter + 1;
		temp = temp -> next;
	}
	return temp -> letter;
}

char *Word::GetACharacterString ()
{
	char *cstring = new char [length + 1];
	int index;
	Node *temp = word;
	for (index = 0; index < length; index = index + 1)
	{
		cstring [index] = temp -> letter;
		temp = temp -> next;
	}
	cstring [length] = '\0';
	return cstring;
}

int Word::GetLength ()
{
	return length;
}

Node *Word::GetWord ()
{
	return word;
}

void Word::GenerateARandomWord ()
{
	Empty ();
	Node *link, *copy;
	random_device randomnumbergenerator;
	link = dictionary [randomnumbergenerator () % numberofwords];
	word = new Node;
	copy = new Node;
	word = copy;
	copy -> previous = NULL;
	copy -> letter = link -> letter;
	copy -> next = NULL;
	length = 1;
	while (link -> next != NULL)
	{
		link = link -> next;
		copy -> next = new Node;
		copy -> next -> previous = link -> previous;
		copy = copy -> next;
		copy -> letter = link -> letter;
		copy -> next = NULL;
		length = length + 1;
	}
}

void Word::Empty ()
{
	Node *temp;
	while (word != NULL)
	{
		temp = word;
		word = word -> next;
		delete temp;
	}
	word = NULL;
	length = 0;
}

Word::~Word ()
{
	Empty ();
	/*int index;
	Node *temp;
	for (index = 0; index < numberofwords; index = index + 1)
	{
		while (dictionary [index] != NULL)
		{
			temp = dictionary [index];
			dictionary [index] = dictionary [index] -> next;
			delete temp;
		}
		cout << index << endl;
	}
	delete [] dictionary;*/
	delete [] lengths;
	numberofwords = 0;
}