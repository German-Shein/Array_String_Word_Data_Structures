#include "String.h"

istream &operator >> (istream &input, String &s)
{
	s.Empty ();
	int index;
	s.line = new Node;
	s.line -> previous = NULL;
	s.line -> next = NULL;
	while (true)
	{
		input.get (s.line -> letter);
		if (s.line -> letter == '\n')
		{
			break;
		}
		s.line -> next = new Node;
		s.line -> next -> previous = s.line;
		s.line = s.line -> next;
		s.line -> next = NULL;
		s.length = s.length + 1;
	}
	Node *temp = s.line;
	s.line = s.line -> previous;
	delete temp;
	s.line -> next = NULL;
	for (index = 0; index < s.length - 1; index = index + 1)
	{
		s.line = s.line -> previous;
	}
	return input;
}

ostream &operator << (ostream &output, const String &s)
{
	Node *temp = s.line;
	while (temp != NULL)
	{
		output << temp -> letter;
		temp = temp -> next;
	}
	return output;
}

const String operator + (const String &s1, const String &s2)
{
	Node *result, *temp1, *temp2, *link, *copy;
	temp1 = s1.line;
	temp2 = s2.line;
	result = new Node;
	result -> previous = NULL;
	result -> next = NULL;
	while (temp1 != NULL)
	{
		result -> next = new Node;
		result -> next -> previous = result;
		result -> letter = temp1 -> letter;
		result = result -> next;
		result -> next = NULL;
		temp1 = temp1 -> next;
	}
	while (temp2 != NULL)
	{
		result -> next = new Node;
		result -> next -> previous = result;
		result -> letter = temp2 -> letter;
		result = result -> next;
		result -> next = NULL;
		temp2 = temp2 -> next;
	}
	Node *temp = result;
	result = result->previous;
	delete temp;
	result -> next = NULL;
	while (result -> previous != NULL)
	{
		result = result -> previous;
	}
	String newstring;
	link = result;
	if (link == NULL)
	{
		newstring.line = NULL;
	}
	else
	{
		newstring.line = new Node;
		copy = new Node;
		newstring.line = copy;
		copy -> previous = NULL;
		copy -> letter = link->letter;
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
	newstring.length = s1.length + s2.length;
	return newstring;
}

const String operator + (const String &s, const Word &w)
{
	Node *result, *temp1, *temp2, *link, *copy;
	String newstring, tempstring = s;
	Word word = w;
	temp1 = s.line;
	temp2 = word.GetWord ();
	result = new Node;
	result -> previous = NULL;
	result -> next = NULL;
	while (temp1 != NULL)
	{
		result -> next = new Node;
		result -> next -> previous = result;
		result -> letter = temp1 -> letter;
		result = result -> next;
		result -> next = NULL;
		temp1 = temp1 -> next;
	}
	while (temp2 != NULL)
	{
		result -> next = new Node;
		result -> next -> previous = result;
		result -> letter = temp2 -> letter;
		result = result -> next;
		result -> next = NULL;
		temp2 = temp2 -> next;
	}
	Node *temp = result;
	result = result -> previous;
	delete temp;
	result -> next = NULL;
	while (result -> previous != NULL)
	{
		result = result -> previous;
	}
	link = result;
	if (link == NULL)
	{
		newstring.line = NULL;
	}
	else
	{
		newstring.line = new Node;
		copy = new Node;
		newstring.line = copy;
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
	newstring.length = tempstring.GetLength () + word.GetLength ();
	return newstring;
}

const String operator + (const String &s1, const char *s2)
{
	int index;
	Node *result, *temp, *link, *copy;
	temp = s1.line;
	result = new Node;
	result -> previous = NULL;
	result -> next = NULL;
	while (temp != NULL)
	{
		result -> next = new Node;
		result -> next -> previous = result;
		result -> letter = temp -> letter;
		result = result -> next;
		result -> next = NULL;
		temp = temp -> next;
	}
	for (index = 0; index < strlen (s2); index = index + 1)
	{
		result -> next = new Node;
		result -> next -> previous = result;
		result -> letter = s2 [index];
		result = result -> next;
		result -> next = NULL;
	}
	Node *garbage = result;
	result = result -> previous;
	delete garbage;
	result -> next = NULL;
	while (result -> previous != NULL)
	{
		result = result -> previous;
	}
	String newstring;
	link = result;
	if (link == NULL)
	{
		newstring.line = NULL;
	}
	else
	{
		newstring.line = new Node;
		copy = new Node;
		newstring.line = copy;
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
	newstring.length = s1.length + strlen (s2);
	return newstring;
}

const String operator + (const Word &w1, const Word &w2)
{
	Node *result, *temp1, *temp2, *link, *copy;
	Word word1 = w1, word2 = w2;
	temp1 = word1.GetWord ();
	temp2 = word2.GetWord ();
	result = new Node;
	result -> previous = NULL;
	result -> next = NULL;
	while (temp1 != NULL)
	{
		result -> next = new Node;
		result -> next -> previous = result;
		result -> letter = temp1 -> letter;
		result = result -> next;
		result -> next = NULL;
		temp1 = temp1 -> next;
	}
	while (temp2 != NULL)
	{
		result -> next = new Node;
		result -> next -> previous = result;
		result -> letter = temp2 -> letter;
		result = result -> next;
		result -> next = NULL;
		temp2 = temp2 -> next;
	}
	Node *temp = result;
	result = result -> previous;
	delete temp;
	result -> next = NULL;
	while (result -> previous != NULL)
	{
		result = result -> previous;
	}
	String newstring;
	link = result;
	if (link == NULL)
	{
		newstring.line = NULL;
	}
	else
	{
		newstring.line = new Node;
		copy = new Node;
		newstring.line = copy;
		copy -> previous = NULL;
		copy -> letter = link->letter;
		copy -> next = NULL;
		while (link -> next != NULL)
		{
			link = link->next;
			copy -> next = new Node;
			copy -> next -> previous = link->previous;
			copy = copy -> next;
			copy -> letter = link -> letter;
			copy -> next = NULL;
		}
	}
	newstring.length = word1.GetLength () + word2.GetLength ();
	return newstring;
}

const String operator + (const Word &w, const char *s)
{
	int index;
	Node *result, *temp, *link, *copy;
	Word word = w;
	temp = word.GetWord ();
	result = new Node;
	result -> previous = NULL;
	result -> next = NULL;
	while (temp != NULL)
	{
		result -> next = new Node;
		result->next->previous = result;
		result -> letter = temp -> letter;
		result = result -> next;
		result -> next = NULL;
		temp = temp -> next;
	}
	for (index = 0; index < strlen (s); index = index + 1)
	{
		result -> next = new Node;
		result -> next -> previous = result;
		result -> letter = s [index];
		result = result -> next;
		result -> next = NULL;
	}
	Node *garbage = result;
	result = result -> previous;
	delete garbage;
	result -> next = NULL;
	while (result -> previous != NULL)
	{
		result = result->previous;
	}
	String newstring;
	link = result;
	if (link == NULL)
	{
		newstring.line = NULL;
	}
	else
	{
		newstring.line = new Node;
		copy = new Node;
		newstring.line = copy;
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
	newstring.length = word.GetLength () + strlen (s);
	return newstring;
}

String::String ()
{
	line = NULL;
	length = 0;
}

String::String (const String &s)
{
	Node *link, *copy;
	length = s.length;
	link = s.line;
	if (link == NULL)
	{
		line = NULL;
	}
	else
	{
		line = new Node;
		copy = new Node;
		line = copy;
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
}

String::String (const Word &w)
{
	Node *link, *copy;
	Word temp = w;
	length = temp.GetLength ();
	link = temp.GetWord ();
	if (link == NULL)
	{
		line = NULL;
	}
	else
	{
		line = new Node;
		copy = new Node;
		line = copy;
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
}

String::String (const char *s)
{
	int index;
	line = new Node;
	line -> previous = NULL;
	line -> next = NULL;
	line -> letter = s [0];
	length = strlen (s);
	for (index = 1; index < length; index = index + 1)
	{
		line -> next = new Node;
		line -> next -> previous = line;
		line = line -> next;
		line -> letter = s [index];
		line -> next = NULL;
	}
	for (index = 0; index < length - 1; index = index + 1)
	{
		line = line -> previous;
	}
}

String &String::operator = (const String &s)
{
	Node *link, *copy;
	length = s.length;
	link = s.line;
	Empty ();
	if (link == NULL)
	{
		line = NULL;
	}
	else
	{
		line = new Node;
		copy = new Node;
		line = copy;
		copy -> previous = NULL;
		copy -> letter = link -> letter;
		copy -> next = NULL;
		while (link -> next != NULL)
		{
			link = link->next;
			copy -> next = new Node;
			copy -> next -> previous = link -> previous;
			copy = copy -> next;
			copy -> letter = link -> letter;
			copy -> next = NULL;
		}
	}
	return *this;
}

String &String::operator = (const Word &w)
{
	Node *link, *copy;
	Word temp = w;
	length = temp.GetLength ();
	link = temp.GetWord ();
	Empty ();
	if (link == NULL)
	{
		line = NULL;
	}
	else
	{
		line = new Node;
		copy = new Node;
		line = copy;
		copy -> previous = NULL;
		copy -> letter = link->letter;
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
	return *this;
}

String &String::operator = (const char *s)
{
	Empty ();
	int index;
	line = new Node;
	line -> previous = NULL;
	line -> next = NULL;
	line -> letter = s [0];
	length = strlen (s);
	for (index = 1; index < length; index = index + 1)
	{
		line -> next = new Node;
		line -> next -> previous = line;
		line = line -> next;
		line -> letter = s [index];
		line -> next = NULL;
	}
	for (index = 0; index < length - 1; index = index + 1)
	{
		line = line -> previous;
	}
	return *this;
}

bool String::operator == (const String &s)
{
	if (length != s.length)
	{
		return false;
	}
	else
	{
		Node *temp1, *temp2;
		temp1 = line;
		temp2 = s.line;
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

bool String::operator == (const Word &w)
{
	Word temp = w;
	if (length != temp.GetLength ())
	{
		return false;
	}
	else
	{
		Node *temp1, *temp2;
		temp1 = line;
		temp2 = temp.GetWord ();
		while (temp1 != NULL)
		{
			if (temp1->letter != temp2->letter)
			{
				return true;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return false;
	}
}

bool String::operator == (const char *s)
{
	if (strlen (s) != length)
	{
		return false;
	}
	int index;
	Node *temp = line;
	for (index = 0; index < length; index = index + 1)
	{
		if (temp -> letter != s [index])
		{
			return false;
		}
		temp = temp -> next;
	}
	return true;
}

bool String::operator != (const String &s)
{
	return !(operator == (s));
}

bool String::operator != (const Word &w)
{
	return !(operator == (w));
}

bool String::operator != (const char *s)
{
	return !(operator == (s));
}

bool String::operator < (const String &s)
{
	int index, minimallength;
	if (length < s.length)
	{
		minimallength = length;
	}
	else
	{
		minimallength = s.length;
	}
	Node *temp1, *temp2;
	temp1 = line;
	temp2 = s.line;
	for (index = 0; index < minimallength; index = index + 1)
	{
		if (temp1 -> letter > temp2 -> letter)
		{
			return false;
		}
		if (temp1 -> letter < temp2 -> letter)
		{
			return true;
		}
		temp1 = temp1 -> next;
		temp2 = temp2 -> next;
	}
}

bool String::operator < (const Word &w)
{
	Word temp = w;
	int index, minimallength;
	if (length < temp.GetLength ())
	{
		minimallength = length;
	}
	else
	{
		minimallength = temp.GetLength ();
	}
	Node *temp1, *temp2;
	temp1 = line;
	temp2 = temp.GetWord ();
	for (index = 0; index < minimallength; index = index + 1)
	{
		if (temp1 -> letter > temp2 -> letter)
		{
			return false;
		}
		if (temp1 -> letter < temp2 -> letter)
		{
			return true;
		}
		temp1 = temp1 -> next;
		temp2 = temp2 -> next;
	}
	return true;
}

bool String::operator < (const char *s)
{
	int index, minimallength;
	if (length < strlen (s))
	{
		minimallength = length;
	}
	else
	{
		minimallength = strlen (s);
	}
	Node *temp = line;
	for (index = 0; index < length; index = index + 1)
	{
		if (temp -> letter > s [index])
		{
			return false;
		}
		if (temp -> letter < s [index])
		{
			return true;
		}
		temp = temp -> next;
	}
}

bool String::operator > (const String &s)
{
	int index, minimallength;
	if (length < s.length)
	{
		minimallength = length;
	}
	else
	{
		minimallength = s.length;
	}
	Node *temp1, *temp2;
	temp1 = line;
	temp2 = s.line;
	for (index = 0; index < minimallength; index = index + 1)
	{
		if (temp1 -> letter < temp2 -> letter)
		{
			return false;
		}
		if (temp1 -> letter > temp2 -> letter)
		{
			return true;
		}
		temp1 = temp1 -> next;
		temp2 = temp2 -> next;
	}
}

bool String::operator > (const Word &w)
{
	Word temp = w;
	int index, minimallength;
	if (length < temp.GetLength ())
	{
		minimallength = length;
	}
	else
	{
		minimallength = temp.GetLength ();
	}
	Node *temp1, *temp2;
	temp1 = line;
	temp2 = temp.GetWord ();
	for (index = 0; index < minimallength; index = index + 1)
	{
		if (temp1 -> letter < temp2 -> letter)
		{
			return false;
		}
		if (temp1 -> letter > temp2 -> letter)
		{
			return true;
		}
		temp1 = temp1 -> next;
		temp2 = temp2 -> next;
	}
}

bool String::operator > (const char *s)
{
	int index, minimallength;
	if (length < strlen (s))
	{
		minimallength = length;
	}
	else
	{
		minimallength = strlen (s);
	}
	Node *temp = line;
	for (index = 0; index < length; index = index + 1)
	{
		if (temp -> letter < s [index])
		{
			return false;
		}
		if (temp -> letter > s [index])
		{
			return true;
		}
		temp = temp -> next;
	}
}

bool String::operator <= (const String &s)
{
	return (operator == (s) || operator < (s));
}

bool String::operator <= (const Word &w)
{
	return (operator == (w) || operator < (w));
}

bool String::operator <= (const char *s)
{
	return (operator == (s) || operator < (s));
}

bool String::operator >= (const String &s)
{
	return (operator == (s) || operator > (s));
}

bool String::operator >= (const Word &w)
{
	return (operator == (w) || operator > (w));
}

bool String::operator >= (const char *s)
{
	return (operator == (s) || operator > (s));
}

char &String::operator [] (int index)
{
	int counter = 0;
	Node *temp = line;
	while (counter != index)
	{
		counter = counter + 1;
		temp = temp -> next;
	}
	return temp -> letter;
}

String *String::Tokenize (char target)
{
	int index, size = 0;
	Node *temp1 = line, *temp2 = line;
	while (temp1 != NULL)
	{
		if (temp1 -> letter == target)
		{
			if (temp1 -> next != NULL)
			{
				size = size + 1;
			}
		}
		if (size > 1 && temp1 -> next == NULL)
		{
			size = size + 1;
		}
		temp1 = temp1 -> next;
	}
	if (size == 0)
	{
		return NULL;
	}
	else
	{
		String *tokens = new String [size];
		for (index = 0; index < size; index = index + 1)
		{
			tokens [index].line = new Node;
			tokens [index].line -> previous = NULL;
			tokens [index].line -> next = NULL;
			while (temp2 -> letter != target)
			{
				tokens [index].line -> next = new Node;
				tokens [index].line -> next -> previous = tokens [index].line;
				tokens [index].line -> letter = temp2 -> letter;
				tokens [index].line = tokens [index].line -> next;
				tokens [index].line -> next = NULL;
				temp2 = temp2 -> next;
				tokens [index].length = tokens [index].length + 1;
				if (temp2 == NULL)
				{
					break;
				}
			}
			Node *garbage = tokens [index].line;
			tokens [index].line = tokens [index].line -> previous;
			delete garbage;
			tokens [index].line -> next = NULL;
			while (tokens [index].line -> previous != NULL)
			{
				tokens [index].line = tokens [index].line -> previous;
			}
			if (temp2 != NULL)
			{
				temp2 = temp2 -> next;
			}
			if (tokens [index].line -> letter == ' ')
			{
				garbage = tokens [index].line;
				tokens [index].line = tokens [index].line -> next;
				delete garbage;
				tokens [index].line -> previous = NULL;
			}
		}
		return tokens;
	}
}

double String::ConvertToDouble ()
{
	double result = 0;
	int index, pointcounter = 0, pointposition;
	Node *temp = line;
	for (index = 0; index < length - 1; index = index + 1)
	{
		if (!isdigit (line -> letter) && line -> letter != '.')
		{
			return result;
		}
		if (line -> letter == '.')
		{
			pointcounter = pointcounter + 1;
			pointposition = index + 1;
		}
		line = line -> next;
	}
	if (pointcounter > 1)
	{
		return result;
	}
	if (pointcounter == 0)
	{
		for (index = 0; index < length; index = index + 1)
		{
			result = result + (line -> letter - '0') * pow (10.0, (double) index);
			line = line -> previous;
		}
	}
	else
	{
		for (index = 0; index < pointposition; index = index + 1)
		{
			result = result + (line -> letter - '0') * pow (10.0, (double) (index - pointposition));
			line = line -> previous;
		}
		line = line -> previous;
		for (index = pointposition + 1; index < length; index = index + 1)
		{
			result = result + (line -> letter - '0') * pow (10.0, (double) index - pointposition - 1);
			line = line -> previous;
		}
	}
	line = temp;
	return result;
}

float String::ConvertToFloat ()
{
	float result = 0;
	int index, pointcounter = 0, pointposition;
	Node *temp = line;
	for (index = 0; index < length - 1; index = index + 1)
	{
		if (!isdigit (line -> letter) && line -> letter != '.')
		{
			return result;
		}
		if (line -> letter == '.')
		{
			pointcounter = pointcounter + 1;
			pointposition = index + 1;
		}
		line = line -> next;
	}
	if (pointcounter > 1)
	{
		return result;
	}
	if (pointcounter == 0)
	{
		for (index = 0; index < length; index = index + 1)
		{
			result = result + (line -> letter - '0') * pow (10.0, (double) index);
			line = line -> previous;
		}
	}
	else
	{
		for (index = 0; index < pointposition; index = index + 1)
		{
			result = result + (line -> letter - '0') * pow (10.0, (double) (index - pointposition));
			line = line -> previous;
		}
		line = line->previous;
		for (index = pointposition + 1; index < length; index = index + 1)
		{
			result = result + (line -> letter - '0') * pow (10.0, (double) index - pointposition - 1);
			line = line -> previous;
		}
	}
	line = temp;
	return result;
}

int String::ConvertToInteger ()
{
	int result = 0;
	int index;
	Node *temp = line;
	for (index = 0; index < length - 1; index = index + 1)
	{
		if (!isdigit (line -> letter))
		{
			return result;
		}
		line = line -> next;
	}
	for (index = 0; index < length; index = index + 1)
	{
		result = result + (line -> letter - '0') * pow (10.0, (double) index);
		line = line -> previous;
	}
	line = temp;
	return result;
}

long String::ConvertToLong ()
{
	long result = 0;
	int index;
	Node *temp = line;
	for (index = 0; index < length - 1; index = index + 1)
	{
		if (!isdigit (line -> letter))
		{
			return result;
		}
		line = line->next;
	}
	for (index = 0; index < length; index = index + 1)
	{
		result = result + (line -> letter - '0') * pow (10.0, (double) index);
		line = line -> previous;
	}
	line = temp;
	return result;
}

short String::ConvertToShort ()
{
	short result = 0;
	int index;
	Node *temp = line;
	for (index = 0; index < length - 1; index = index + 1)
	{
		if (!isdigit (line -> letter))
		{
			return result;
		}
		line = line->next;
	}
	for (index = 0; index < length; index = index + 1)
	{
		result = result + (line -> letter - '0') * pow (10.0, (double) index);
		line = line -> previous;
	}
	line = temp;
	return result;
}

void String::Capitalize ()
{
	while (line -> next != NULL)
	{
		if (isalpha (line -> letter))
		{
			line -> letter = toupper (line -> letter);
		}
		line = line -> next;
	}
	if (isalpha (line -> letter))
	{
		toupper (line -> letter);
	}
	while (line -> previous != NULL)
	{
		line = line -> previous;
	}
}

void String::Decapitalize ()
{
	while (line -> next != NULL)
	{
		if (isalpha (line -> letter))
		{
			line -> letter = tolower (line -> letter);
		}
		line = line -> next;
	}
	if (isalpha (line -> letter))
	{
		toupper (line -> letter);
	}
	while (line -> previous != NULL)
	{
		line = line -> previous;
	}
}

void String::Reverse ()
{
	Node *reverse;
	while (line -> next != NULL)
	{
		line = line -> next;
	}
	reverse = new Node;
	reverse -> previous = NULL;
	reverse -> next = NULL;
	while (line != NULL)
	{
		reverse -> letter = line -> letter;
		reverse -> next = new Node;
		reverse -> next -> previous = reverse;
		reverse = reverse -> next;
		reverse -> next = NULL;
		line = line -> previous;
	}
	Node *garbage = reverse;
	reverse = reverse -> previous;
	delete garbage;
	reverse -> next = NULL;
	while (reverse -> previous != NULL)
	{
		reverse = reverse -> previous;
	}
	line = reverse;
}

char *String::GetACharacterString ()
{
	char *cstring = new char [length + 1];
	int index;
	Node *temp = line;
	for (index = 0; index < length; index = index + 1)
	{
		cstring [index] = temp -> letter;
		temp = temp -> next;
	}
	cstring [length] = '\0';
	return cstring;
}

int String::GetLength ()
{
	return length;
}

void String::Empty ()
{
	Node *temp;
	while (line != NULL)
	{
		temp = line;
		line = line -> next;
		delete temp;
	}
	line = NULL;
	length = 0;
}

String::~String ()
{
	Empty ();
}