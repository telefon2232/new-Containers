#pragma once
class Container
{
protected:
	int size;
public:
	virtual int getSize() const = 0; 			//���������� ���������� ��������� � ����������
	virtual int getCapacity() const = 0;		//���������� ����������� ��������� ���������� ��������� � ����������
	virtual void show() const = 0;				//������� �������� ��������� ���������� � �������, ����� ������
	
	virtual void addCapacity(int n) = 0;		//����������� ����������� ��������� ����������� ���������� �� n ��������� (��� ������ ������)

	
	virtual ~Container();					    //����������� ���������� ������
};

class MyArray : public Container
{
protected:
	int *ar;
public:
	MyArray();
	MyArray(int n);								//������� ������ �� n ������� ���������
	MyArray(const MyArray &ar);					//�������� ������ � ����������� �������� ������ ar

	int getSize() const;						//���������� size
	int getCapacity() const;					//���������� size
	void show() const;

	void addCapacity(int n);					// ����������� ����������� ��������� ����������� ���������� �� n (�������) ���������(��� ������ ������)

	int& operator[](int index);					//������ � i-��� ��������
	MyArray& operator=(const MyArray &ar);		//������� ������ �������� �������, �������� ������ ������ � ����������� �������� ������ ar

	~MyArray();
};