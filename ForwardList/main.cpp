#include <iostream>

using namespace std;

#define tab "\t"

template<typename T> class ForwardList;
template<typename T> class Iterator;


template<typename T>
class Element
{
	T Data;           //значение элемента
	Element<T>* pNext;     //адрес следующего элемента
	static int count;
public:
	Element(T Data, Element<T>* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		count++;
	}
	~Element()
	{
		count--;
	}

	friend class ForwardList<T>;
	friend class Iterator<T>;
};

template <typename T>
int Element<T>::count = 0;


template <typename T>
class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr) : Temp(Temp)
	{

	}
	~Iterator()
	{

	}
	
	Iterator<T>& operator ++()
	{
		Temp = Temp->pNext;
		return* this;
	}
	bool  operator ==(const Iterator<T>& other)const
	{
		return this->Temp == other.Temp;
	}
	bool  operator !=(const Iterator<T>& other)const
	{
		return this->Temp != other.Temp;
	}
	T& operator*()
	{
		return Temp->Data;
	}
};

template <typename T>
class ForwardList
{
	Element<T>* Head;    //Голова списка - содержит указатель на нулевой элемент списка 
	int size;
public:
	ForwardList()
	{
		Head = nullptr;   //Если список пуст, то его голова указывает на 0
		size = 0;
	}
	ForwardList(const std::initializer_list<T> &il) :ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		for (T const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	~ForwardList()
	{
		while (Head)pop_front();
	}

	Iterator<T> begin()
	{
		return Head;
	}
	Iterator<T> end()
	{
		return nullptr;
	}

	void push_front(T Data) 
	{
		Head = new Element<T>(Data, Head);
		size++;
	}
	void push_back(T Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element<T>* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
	
		Temp->pNext = new Element<T>(Data);
		size++;
	}
	void pop_front()
	{
		Element<T>* Erased = Head;
		Head = Head->pNext;
		delete Erased;
		size--;
	}
	void pop_back()
	{
		Element<T>* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void insert(int index, T Data)
	{
		if (index == 0)return push_front(Data);
		if (index > size)return;

		Element<T>* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		Temp->pNext = new Element<T>(Data, Temp->pNext);
		size++;
	}

	void print()const
	{
		Element<T>* Temp = Head;  //Temp это итератор
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

	ForwardList<int> list3 = { 3,5,8,13,21 };
	for (int i : list3)
	{
		cout << i << tab;
	}
	cout << endl;
	

}