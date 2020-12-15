#include"Vector.h"

int main()
{
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	v.pushBack(4);
	v.pushBack(5);
	v.pushBack(6);

	v.erase(v.Begin() + 2, v.Begin() + 10);

	for (Vector<int>::Riterator i = v.Rbegin(); i > v.Rend(); i--)
	{
		std::cout << *i << " ";
	}

	return 0;
}