#include "Array.h"

template <class Temp>
ostream &operator << (ostream &output, const Array <Temp> &a)
{
	UniversalNode <Temp> *temp = a.list;
	while (temp != NULL)
	{
		cout << temp -> item << " ";
		temp = temp -> next;
	}
	return output;
}

template <class Type>
Array <Type>::Array ()
{
	size = 0;
	list = NULL;
}

template <class Type>
Array <Type>::Array (const Array <Type> &a)
{
	UniversalNode <Type> *link, *copy;
	size = a.size;
	link = s.list;
	if (link == NULL)
	{
		list = NULL;
	}
	else
	{
		list = new UniversalNode <Type>;
		copy = new UniversalNode <Type>;
		list = copy;
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

template <class Type>
Array <Type> &Array <Type>::operator = (const Array <Type> &a)
{
	UniversalNode <Type> *link, *copy;
	size = a.size;
	link = s.list;
	Empty ();
	if (link == NULL)
	{
		list = NULL;
	}
	else
	{
		list = new UniversalNode <Type>;
		copy = new UniversalNode <Type>;
		list = copy;
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
	return *this;
}

template <class Type>
Type &Array <Type>::operator [] (long index)
{
	if (list == NULL)
	{
		list = new UniversalNode <Type>;
		list -> previous = NULL;
		list -> next = NULL;
		size = 1;
		return list -> item;
	}
	if (index < 0)
	{
		index = 0;
	}
	long counter;
	UniversalNode <Type> *temp = list;
	for (counter = 0; counter < size - 1; counter = counter + 1)
	{
		if (counter == index)
		{
			return temp -> item;
		}
		temp = temp -> next;
	}
	if (index >= size)
	{
		for (counter = size; counter <= index; counter = counter + 1)
		{
			temp -> next = new UniversalNode <Type>;
			temp -> next -> previous = temp;
			temp = temp -> next;
			temp -> next = NULL;
		}
		size = index + 1;
	}
	return temp -> item;
}

template <class Type>
long Array <Type>::GetSize ()
{
	return size;
}

template <class Type>
Type Array <Type>::GetTheSumOfAllTheElements ()
{
	if (strcmp (typeid (list -> item).name (), "double") == 0 || strcmp (typeid (list -> item).name (), "float") == 0 || strcmp (typeid (list -> item).name (), "int") == 0 || strcmp (typeid (list -> item).name (), "long") == 0 || strcmp (typeid (list -> item).name (), "short") == 0)
	{
		long index;
		Type sum = 0;
		UniversalNode <Type> *temp = list;
		for (index = 0; index < size; index = index + 1)
		{
			sum = sum + temp -> item;
			temp = temp -> next;
		}
		return sum;
	}
	else
	{
		return 0;
	}
}

template <class Type>
Type Array <Type>::GetMinimalElement ()
{
	if (strcmp (typeid (list -> item).name (), "char") == 0 || strcmp (typeid (list -> item).name (), "double") == 0 || strcmp (typeid (list -> item).name (), "float") == 0 || strcmp (typeid (list -> item).name (), "int") == 0 || strcmp (typeid (list -> item).name (), "long") == 0 || strcmp (typeid (list -> item).name (), "short") == 0 || strcmp (typeid (list -> item).name (), "class String") == 0 || strcmp (typeid (list -> item).name (), "class Word") == 0)
	{
		long index;
		Type minimalelement = list -> item;
		UniversalNode <Type> *temp = list;
		for (index = 0; index < size; index = index + 1)
		{
			if (temp -> item < minimalelement)
			{
				minimalelement = temp -> item;
			}
			temp = temp -> next;
		}
		return minimalelement;
	}
	else
	{
		return 0;
	}
}

template <class Type>
Type Array <Type>::GetMaximalElement ()
{
	if (strcmp (typeid (list -> item).name (), "char") == 0 || strcmp (typeid (list -> item).name (), "double") == 0 || strcmp (typeid (list -> item).name (), "float") == 0 || strcmp (typeid (list -> item).name (), "int") == 0 || strcmp (typeid (list -> item).name (), "long") == 0 || strcmp (typeid (list -> item).name (), "short") == 0 || strcmp (typeid (list -> item).name (), "class String") == 0 || strcmp (typeid (list -> item).name (), "class Word") == 0)
	{
		long index;
		Type maximalelement = list -> item;
		UniversalNode <Type> *temp = list;
		for (index = 0; index < size; index = index + 1)
		{
			if (temp -> item > maximalelement)
			{
				maximalelement = temp -> item;
			}
			temp = temp -> next;
		}
		return maximalelement;
	}
	else
	{
		return 0;
	}
}

template <class Type>
double Array <Type>::GetTheMeanOfTheElements ()
{
	if (strcmp (typeid (list -> item).name (), "double") == 0 || strcmp (typeid (list -> item).name (), "float") == 0 || strcmp (typeid (list -> item).name (), "int") == 0 || strcmp (typeid (list -> item).name (), "long") == 0 || strcmp (typeid (list -> item).name (), "short") == 0)
	{
		double average;
		long index;
		UniversalNode <Type> *temp = list;
		for (index = 0; index < size; index = index + 1)
		{
			average = average + temp -> item;
			temp = temp -> next;
		}
		average = average / (size * 1.0);
		return average;
	}
	else
	{
		return 0.0;
	}
}

template <class Type>
Type Array <Type>::GetTheMedianOfTheElements ()
{
	Array temp = *this;
	temp.Sort ();
	if (size == 0)
	{
		return 0;
	}
	if ((size % 2) == 0)
	{
		return ((temp [size / 2] + temp [(size / 2) - 1]) / 2.0)
	}
	if ((size % 2) == 1)
	{
		return temp [size / 2];
	}
}

template <class Type>
double Array <Type>::GetTheStandardDeviation ()
{
	if (strcmp (typeid (list -> item).name (), "double") == 0 || strcmp (typeid (list -> item).name (), "float") == 0 || strcmp (typeid (list -> item).name (), "int") == 0 || strcmp (typeid (list -> item).name (), "long") == 0 || strcmp (typeid (list -> item).name (), "short") == 0)
	{
		double average = GetTheMeanOfTheElements (), standarddeviation = 0;
		long index;
		UniversalNode <Type> *temp = list;
		for (index = 0; index < size; index = index + 1)
		{
			standarddeviation = standarddeviation + pow ((temp -> item - average), 2.0);
			temp = temp -> next;
		}
		standarddeviation = sqrt (standarddeviation / (size * 1.0));
		return standarddeviation;
	}
	else
	{
		return 0.0;
	}
}

template <class Type>
Type Array <Type>::GetTheMostFrequentElement ()
{
	long index;
}

template <class Type>
Type *Array <Type>::GetArray ()
{
	long index;
	Type *a = new Type [size];
	UniversalNode *temp = list;
	for (index = 0; index < size; index = index + 1)
	{
		a [index] = temp -> item;
		temp = temp -> index;
	}
}

template <class Type>
UniversalNode <Type> *Array <Type>::GetLinkedArray ()
{
	return list;
}

template <class Type>
void Array <Type>::Sort ()
{
	if (size == 0)
	{
		return;
	}
	if (size == 1)
	{
		return;
	}
	if (strcmp (typeid (list -> item).name (), "char") == 0 || strcmp (typeid (list -> item).name (), "double") == 0 || strcmp (typeid (list -> item).name (), "float") == 0 || strcmp (typeid (list -> item).name (), "int") == 0 || strcmp (typeid (list -> item).name (), "long") == 0 || strcmp (typeid (list -> item).name (), "short") == 0 || strcmp (typeid (list -> item).name (), "class String") == 0 || strcmp (typeid (list -> item).name (), "class Word") == 0)
	{
		long index1, index2;
		Type temp;
		for (index1 = 0; index1 < size - 1; index1 = index1 + 1)
		{
			list = list -> next;
		}
		for (index1 = 0; index1 < size - 1; index1 = index1 + 1)
		{
			for (index2 = index1; index2 < size - 1; index2 = index2 + 1)
			{
				if (list -> item < list -> previous -> item)
				{
					temp = list -> item;
					list -> item = list -> previous -> item;
					list -> previous -> item = temp;
				}
				list = list -> previous;
			}
			for (index2 = index1; index2 < size - 1; index2 = index2 + 1)
			{
				list = list -> next;
			}
		}
		while (list -> previous != NULL)
		{
			list = list -> previous;
		}
	}
}

template <class Type>
void Array <Type>::Rotate ()
{
	if (size == 0)
	{
		return;
	}
	if (size == 1)
	{
		return;
	}
	long index;
	UniversalNode <Type> *temp = new UniversalNode <Type>;
	temp -> previous = NULL;
	temp -> next = NULL;
	while (list -> next != NULL)
	{
		list = list -> next;
	}
	temp -> item = list -> item;
	for (index = 0; index < size - 1; index = index + 1)
	{
		list = list -> previous;
	}
	for (index = 0; index < size - 1; index = index + 1)
	{
		temp -> next = new UniversalNode <Type>;
		temp -> next -> previous = temp;
		temp = temp -> next;
		temp -> next = NULL;
		temp -> item = list -> item;
		list = list -> next;
	}
	while (temp -> previous != NULL)
	{
		temp = temp -> previous;
	}
	list = temp;
}

template <class Type>
void Array <Type>::Reverse ()
{
	if (size == 0)
	{
		return;
	}
	if (size == 1)
	{
		return;
	}
	long index;
	UniversalNode <Type> *temp = new UniversalNode <Type>;
	temp -> previous = NULL;
	temp -> next = NULL;
	for (index = 0; index < size - 1; index = index + 1)
	{
		list = list -> next;
	}
	for (index = 0; index < size; index = index + 1)
	{
		temp -> item = list -> item;
		temp -> next = new UniversalNode <Type>;
		temp -> next -> previous = temp;
		temp = temp -> next;
		temp -> next = NULL;
		list = list -> previous;
	}
	while (temp -> previous != NULL)
	{
		temp = temp -> previous;
	}
	list = temp;
}

template <class Type>
void Array <Type>::Empty ()
{
	long index;
	UniversalNode <Type> *temp;
	for (index = 0; index < size; index = index + 1)
	{
		temp = list;
		list = list -> next;
		delete temp;
	}
	list = NULL;
	size = 0;
}

template <class Type>
Array <Type>::~Array ()
{
	Empty ();
}