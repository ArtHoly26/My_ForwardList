#include <iostream>

using namespace std;

#define tab "\t"

class Element
{
	int Data;           //значение элемента
	Element* pNext;     //адрес следующего элемента
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		count++;
	}
	~Element()
	{
		count--;
	}

	friend class ForwardList;
	friend class Iterator;
};

int Element::count = 0;

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) : Temp(Temp)
	{

	}
	~Iterator()
	{

	}
	
	Iterator& operator ++()
	{
		Temp = Temp->pNext;
		return* this;
	}
	bool  operator ==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool  operator !=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	int& operator*()
	{
		return Temp->Data;
	}
};

class ForwardList
{
	Element* Head;    //Голова списка - содержит указатель на нулевой элемент списка 
	int size;
public:
	ForwardList()
	{
		Head = nullptr;   //Если список пуст, то его голова указывает на 0
		size = 0;
	}
	ForwardList(const std::initializer_list<int> &il) :ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other)
	{

	}
	~ForwardList()
	{
		while (Head)pop_front();
	}

	Iterator begin()
	{
		return Head;
	}

	Iterator end()
	{
		return nullptr;
	}

	void push_front(int Data) 
	{
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
	
		Temp->pNext = new Element(Data);
		size++;
	}
	void pop_front()
	{
		Element* Erased = Head;
		Head = Head->pNext;
		delete Erased;
		size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void insert(int index, int Data)
	{
		if (index == 0)return push_front(Data);
		if (index > size)return;

		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	}

	void print()const
	{
		Element* Temp = Head;  //Temp это итератор
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
		cout << "Колличество элементов списка: " << size << endl;
		cout << "Общее элементов списка: " << Element::count << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	ForwardList list2;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();

	int value;
	int index;
	cout << "Введите индекс добавления элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();

	list2.push_front(23);
	list2.push_front(11);
	list2.push_front(2);
	list2.print();*/

	ForwardList list3 = { 3,5,8,13,21 };
	for (int i : list3)
	{
		cout << i << tab;
	}
	cout << endl;
	

}