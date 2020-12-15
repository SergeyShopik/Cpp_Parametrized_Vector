#pragma once
#include<iostream>

template<class Type>

class Vector
{
public:
	Vector() : size(0), capacity(1), data(new Type[1]) {}
	Vector(size_t);
	Vector(const Vector<Type>&);
	~Vector() { delete[]data; };

	size_t getSize() { return size; }
	size_t getCapacity() { return capacity; }

	Vector<Type>& operator=(const Vector<Type>&);

	Type& operator[](size_t);
	const Type& operator[](size_t) const;

	typedef Type* Iterator;
	Iterator Begin() { return data; }
	Iterator End() { return data + size; }

	typedef Type* Riterator;
	Riterator Rbegin() { return data + size - 1; }
	Riterator Rend() { return data - 1; }

	void pushBack(const Type&);
	Type popBack();
	void insert(const Type&, size_t);
	Iterator find(Iterator, Type);

	void erase(size_t);
	void erase(Iterator, Iterator);

	void printVector();

private:
	size_t size;
	size_t capacity;
	Type* data;

	bool needMem();
};

template<class Type>
bool Vector<Type>::needMem()
{
	if (this->size + 1 <= capacity)
		return false;

	return true;
}

template<class Type>
void Vector<Type>::pushBack(const Type& element)
{
	if (needMem())
	{
		capacity *= 2;
		Type* temp = new Type[capacity];

		for (size_t i = 0; i < size; i++)
			temp[i] = data[i];
		delete[]data;

		data = temp;
	}
	data[size++] = element;
}

template<class Type>
void Vector<Type>::printVector()
{
	for (Iterator it = Begin; it < End; it++)
		std::cout << *it << " ";
}

template<class Type>
Type Vector<Type>::popBack()
{
	if (size == 0)
	{
		std::cout << "Vector is empty\n";
		return Type();
	}
	size--;
	return data[size];
}

template<class Type>
void Vector<Type>::insert(const Type& element, size_t position)
{
	if (position > size)
	{
		std::cout << "Wrong position.\n";
		return;
	}
	if (position == size)
		pushBack(element);

	if (needMem())
	{
		capacity *= 2;

		Type* temp = new Type[capacity];

		for (size_t i = 0; i < position; i++)
			temp[i] = data[i];
		temp[position] = element;
		for (size_t i = position; i < size; i++)
			temp[i + 1] = data[i];

		delete[]data;
		data = temp;
		size++;
		return;
	}
	memcpy(Begin() + position + 1, Begin() + position, sizeof(Type) * (size - position));
	data[position] = element;

	size++;
}

template<class Type>
void Vector<Type>::erase(Iterator start, Iterator end)
{
	if (start >= End())
	{
		std::cout << "Wrong iterator.\n";
		return;
	}
	if (end > End())
		end = End() - 1;

	memcpy(start, end + 1, sizeof(Type) * (end - start));
	size -= end - start + 1;
}