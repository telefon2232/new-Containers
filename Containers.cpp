#include "Containers.h"
#include <iostream>
using namespace std;

int Container::getSize() const
{
	return 0;
}

int Container::getCapacity() const
{
	return 0;
}

void Container::show() const
{
}

void Container::addCapacity(int n)
{
}

Container::~Container()
{
}

MyArray::MyArray()
{
	ar = new int[0];
}

MyArray::MyArray(int n)
{
	ar = new int[size = n] {0};
}

MyArray::MyArray(const MyArray& ar)
{

	this->ar = new int[size = ar.size];
	for (int i = 0; i < size; i++)
		this->ar[i] = ar.ar[i];
}

int MyArray::getSize() const
{
	int result = 0;
	for (int i = 0; i < getCapacity(); i++)
		if (ar[i] != 0)
			result = i + 1;
	return result;
}

int MyArray::getCapacity() const
{
	return size;
}

void MyArray::show() const
{
	for (int i = 0; i < getCapacity(); i++)
		cout << ar[i]<<" ";
	cout << std::endl;
}

void MyArray::addCapacity(int n)
{
	int* tmp = new int[size + n];
	for (int i = 0; i < size; i++)
		tmp[i] = ar[i];
	for (int i = size; i < size + n; i++)
		tmp[i] = 0;
	delete[] ar;
	ar = tmp;
	size = size + n;
	tmp = nullptr;
}

int& MyArray::operator[](int index)
{
	return ar[index];
	

}

MyArray& MyArray::operator=(const MyArray& ar)
{
	if (ar.ar == this->ar)
		return *this;
	delete[]this->ar;
	size = ar.size;
	this->ar = new int[size];
	for (int i = 0; i < size; i++)
		this->ar[i] = ar.ar[i];
	return *this;
}

MyArray::~MyArray()
{
	delete[] ar;
	ar = nullptr;
}