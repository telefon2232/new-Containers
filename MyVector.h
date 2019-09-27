#pragma once
#include "Containers.h"
class MyVector : public MyArray
{
protected:
	int capacity;								//������ ���������� ������
public:
	MyVector();
	MyVector(int n);							//������� ������ �� n ������� ���������
	MyVector(int n, int value);					//������� ������ �� n ��������� � ��������� value
	MyVector(const MyVector &vec);				//�������� ������ � ����������� �������� ������ vec

	int getCapacity() const;					//���������� capacity

	void addCapacity(int n);					//����������� ����������� ��������� ����������� ���������� �� n (�������) ���������(��� ������ ������)
	void pushBack(int val);						//���� size < capacity, �� ar[size++] = val; ����� ������� �������� ������
	int popBack();								//���������� ��c������ �������, size ����������� �� 1
	void insert(int index, int val);			//��������� ������� val �� ������� index, ��� ������������� ���������� ����� ������
	int remove(int index);						//�������� � �������� index+1, ..., size ��������� �� 1 ������� ����� � ������ �������. ������� � ������� index � ����� ������ "���������", �������� ��� return

	MyVector& operator=(const MyVector &vec);	//������� ������ �������� �������, �������� ������ ������ � ����������� �������� ������ vec
};