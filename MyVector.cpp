#include "MyVector.h"

MyVector::MyVector() :MyArray(), capacity(0)
{
	size = 0;
}

MyVector::MyVector(int n) :MyArray(n), capacity(n)
{
	size = 0;
}

MyVector::MyVector(int n, int value):capacity(n)
{
	ar = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		ar[i] = value;
	}
	size = capacity;
}

MyVector::MyVector(const MyVector& vec):MyArray(vec.capacity)
{
	capacity = vec.capacity;
	size = vec.getSize();
	for (int i = 0; i < size; i++)
	{
		ar[i] = vec.ar[i];
	}
}

int MyVector::getCapacity() const
{
	return capacity;
}

void MyVector::addCapacity(int n)
{
	size = getSize();
	int* vect = new int[capacity + n];
	for (int i = 0; i < size; i++)
		vect[i] = ar[i];
	for (int i = size; i < capacity + n; i++)
		vect[i] = 0;
	delete[] ar;
	ar = vect;
	capacity = n+capacity;
	vect = nullptr;
}

void MyVector::pushBack(int val)
{
	size = getSize();
	int n = 1;
	if (size < capacity)
		ar[size++] = val;
	else
	{
		int* vect = new int[capacity + n]{ 0 };
		for (int i = 0; i < size; i++)
			vect[i] = ar[i];
		delete [] ar;
		vect[capacity + n - 1] = val;
		ar = vect;
		capacity = n+capacity;
		vect = nullptr;
	}
}

int MyVector::popBack()
{
	size = getSize();
	int vect = ar[size-1];
	ar[size-1] = 0;
	size--;
	return vect;
}

void MyVector::insert(int index, int val)
{
	size = getSize();
	if (size >= capacity)
	{
		int* vect = new int[capacity + 1]{ 0 };
		for (int i = 0; i < size; i++)
			vect[i] = ar[i];
		delete[] ar;
		ar = vect;
		capacity += 1;
		vect = nullptr;
	}		
		for (int i = size; i > index; i--)
		{
			ar[i] = ar[i - 1];
		}
		size++;
	ar[index] = val;
}

int MyVector::remove(int index)
{
	size = getSize();
	int vect = ar[index];
	for (int i = index; i < size; i++) {
		ar[i] = ar[i+1];
	}
	ar[size-1] = 0;
	return vect ;
}

MyVector& MyVector::operator=(const MyVector& vec)
{
	if (this == &vec)
		return *this;
	delete[]this->ar;
	size = vec.size;
	capacity = vec.capacity;
	ar = new int[capacity];
	for (int i = 0; i < vec.size; i++)
		ar[i] = vec.ar[i];
	return *this;
}