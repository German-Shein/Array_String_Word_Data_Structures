#include "Word.h"

#ifndef String_h
#define String_h

class String
{
	friend istream &operator >> (istream &input, String &w);
	friend ostream &operator << (ostream &output, const String &w);
	friend const String operator + (const String &s1, const String &s2);
	friend const String operator + (const String &s, const Word &w);
	friend const String operator + (const String &s1, const char *s2);
	friend const String operator + (const Word &w1, const Word &w2);
	friend const String operator + (const Word &w, const char *s);
	friend const String operator - (const String &s1, const String &s2);
	friend const String operator - (const String &s, const Word &w);
	friend const String operator - (const String &s1, const char *s2);
	friend const String operator - (const Word &w1, const Word &w2);
	friend const String operator - (const Word &w, const char *s);
	public:
		String ();
		String (const String &s);
		String (const Word &w);
		String (const char *s);
		String &operator = (const String &s);
		String &operator = (const Word &w);
		String &operator = (const char *s);
		String &operator += (const String &s);
		String &operator += (const Word &w);
		String &operator += (const char *s);
		String &operator -= (const String &s);
		String &operator -= (const Word &w);
		String &operator -= (const char *s);
		bool operator == (const String &s);
		bool operator == (const Word &w);
		bool operator == (const char *s);
		bool operator != (const String &s);
		bool operator != (const Word &w);
		bool operator != (const char *s);
		bool operator < (const String &s);
		bool operator < (const Word &w);
		bool operator < (const char *s);
		bool operator > (const String &s);
		bool operator > (const Word &w);
		bool operator > (const char *s);
		bool operator <= (const String &s);
		bool operator <= (const Word &w);
		bool operator <= (const char *s);
		bool operator >= (const String &s);
		bool operator >= (const Word &w);
		bool operator >= (const char *s);
		char &operator [] (int index);
		String *Tokenize (char target);
		double ConvertToDouble ();
		float ConvertToFloat ();
		int ConvertToInteger ();
		long ConvertToLong ();
		short ConvertToShort ();
		void Capitalize ();
		void Decapitalize ();
		void Reverse ();
		char *GetACharacterString ();
		int GetLength ();
		void Empty ();
		~String ();
	private:
		int length;
		Node *line;
};

#endif