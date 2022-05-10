#include <iostream>
#include "String.h"
#include "Word.h"

using namespace std;

#ifndef UniversalNode_h
#define UniversalNode_h

template <class Type>
struct UniversalNode
{
	Type item;
	UniversalNode <Type> *previous, *next;
};

#endif

#ifndef Array_h
#define Array_h

template <class Type>
class Array
{
	template <class Temp>
	friend ostream &operator << (ostream &output, const Array <Temp> &a);
	/*template <class Temp>
	friend const Array <Temp> operator + (const Array <Temp> &a1, const Array <Temp> &a2);
	template <class Temp>
	friend const Array <Temp> operator + (const Array <Temp> &a1, const Temp *a2);
	template <class Temp>
	friend const Array <Temp> operator + (const Array <Temp> &a, const UniversalNode <Temp> *l);
	template <class Temp>
	friend const Array <Temp> operator + (const Temp *a1, const Temp *a2);
	template <class Temp>
	friend const Array <Temp> operator + (const Temp *a, const UniversalNode <Temp> *l);
	template <class Temp>
	friend const Array <Temp> operator + (const UniversalNode <Temp> *l1, const UniversalNode <Temp> *l2);*/
	private:
		long size;
		UniversalNode <Type> *list;
	public:
		Array ();
		Array (const Array <Type> &a);
		//Array (const Type *a);
		//Array (const UniversalNode <Type> *l);
		Array <Type> &operator = (const Array <Type> &a);
		//Array <Type> &operator = (const Type *a);
		//Array <Type> &operator = (const UniversalNode <Type> *l);
		//Array <Type> &operator += (const Array <Type> &a);
		//Array <Type> &operator += (const Type *a);
		//Array <Type> &operator += (const UniversalNode <Type> *l);
		//bool operator == (const Array <Type> &a) const;
		//bool operator == (const Type *a) const;
		//bool operator == (const UniversalNode <Type> *l) const;
		//bool operator != (const Array <Type> &a) const;
		//bool operator != (const Type *a) const;
		//bool operator != (const UniversalNode <Type> *l) const;
		Type &operator [] (long index);
		long GetSize ();
		Type GetTheSumOfAllTheElements ();
		Type GetMinimalElement ();
		Type GetMaximalElement ();
		double GetTheMeanOfTheElements ();
		Type GetTheMedianOfTheElements ();
		double GetTheStandardDeviation ();
		Type GetTheMostFrequentElement ();
		Type *GetArray ();
		UniversalNode <Type> *GetLinkedArray ();
		void Sort ();
		void Rotate ();
		void Reverse ();
		void Empty ();
		~Array ();
};

#endif