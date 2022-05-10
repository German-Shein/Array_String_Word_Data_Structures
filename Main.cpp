#include "Array/Array.cpp"

void main ()
{
	Array <Word> a;
	int index;
	for (index = 0; index < 5; index = index + 1)
	{
		a [index].GenerateARandomWord ();
	}
	cout << a << endl;
	a.Sort ();
	cout << a << endl;
	a.Rotate ();
	cout << a << endl;
	a.Reverse ();
	cout << a << endl;
}