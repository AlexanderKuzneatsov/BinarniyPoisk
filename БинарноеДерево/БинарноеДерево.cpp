#include <iostream>

using namespace std;
//TODO: Класс с прототипами методов вынести в заголовочный файл(.h), реализацию -- в .cpp
//TODO: Не вижу рекурсии: элементы ищешь с помощью цикла while, его быть не должно.

//TODO: Нормально назвать класс. Нейминг не должен быть русским транслитом.
class Drevo
{
public:
	Drevo();
	~Drevo();

	void Add_Element(int data);

	void Get_Element(int Key);

	void Print_Value(int rek, int Error);




private:

	class Node
	{
		
	public:
		Node* pLeft, * pRight;

		int data;
		Node(int data , Node* pLeft = nullptr, Node* pRight = nullptr) //TODO: лучше вообще не передавать в конструктор pLeft и pRight, ведь в большинстве ситуации они тебе там не нужны. Назначай их в самом методе вставки.
		{
			this->data = data;
			this->pLeft = pLeft;
			this->pRight = pRight;
		}

	};

	//TODO: Переменные именуются в camelCase
	int Size;
	Node * Root, * Leafs; //TODO: зачем указатель на листья?

};

Drevo::Drevo()
{
	Size = 0;
	Root = nullptr; //указатели по дефолту nullptr
	Leafs = nullptr; //TODO: зачем?
}

//TODO: зачем деструктор, если он бездействует? Почисти в нем выделяемую память, есть риск утечки
Drevo::~Drevo()
{

}

//TODO: Убрать нижнее подчеркивание у названия метода. Методы именуются в PascalCase.
void Drevo::Add_Element(int data)
{
	int pNull = 1;
	if (Root == nullptr)
	{
		Root = new Node(data);
		return;
	}
	else
	{
		Node* ptr = this->Root;

	

//TODO: Повторяющиеся фрагемнты кода вынести в отдельный метод (в твоем случае строки 76 - 116 и 140 - 181 дублируются)
		while (pNull == 1)
		{

			if (data < ptr->data)
			{
				
				if (ptr->pLeft == nullptr)
				{
					ptr->pLeft = new Node(data);
					Size++;
					pNull = 0;
					return;
				}
				else
				{
					ptr = ptr->pLeft;
				}

			}

			if (data > ptr->data)
			{
				
				if (ptr->pRight == nullptr)
				{
					ptr->pRight = new Node(data);
					Size++;
					pNull = 0;
					return;
				}
				else
				{
					ptr = ptr->pRight;
				}
				

			}



		}

	}

}
//TODO: Убрать нижнее подчеркивание у названия метода. Методы именуются в PascalCase. Х2
void Drevo::Get_Element(int Key)
{
	//TODO: 1) переменные именуются в camelCase; 2) Объясни, зачем переменные error, pNull, rek? Без них запросто можно обойтись, хардкодишь решение.
	int Error = 0; //TODO: почему не bool? Тот же вопрос для двух строчек ниже. По-хорошему, эти переменные вообще убери и реализуй без них.
	int pNull = 1;
	int rek = 0;// Разделяем логические блоким одной пустой строкой
	if (Root == nullptr)// TODO заменить на if(!root) - это тоже самое, что if(root == nullptr)
	{
		Error = 1;
		Print_Value(rek, Error);
	}
	else
	{
		Node* ptr = this->Root;
// TODO: Не оставляем пустого пространства. Для разделения максимум одна строка


//TODO: Повторяющиеся фрагемнты кода вынести в отдельный метод (в твоем случае строки 75 - 115 и 140 - 181 дублируются) X2
		while (pNull == 1)
		{
			if (Key < ptr->data)
			{

				if (ptr->pLeft == nullptr)
				{
					pNull = 0;
					Error = 1;
					Print_Value(rek, Error);
				}
				else
				{
					ptr = ptr->pLeft;
				}

			}

			if (Key > ptr->data)
			{

				if (ptr->pRight == nullptr)
				{
					pNull = 0;
					Error = 1;
					Print_Value(rek, Error);
				}
				else
				{
					ptr = ptr->pRight;
				}

			}

			if (Key == ptr->data)
			{
				pNull = 0;
				int rek = ptr->data;
				Print_Value(rek, Error);
			}

		}

	}

}
//TODO: Убрать нижнее подчеркивание у названия метода. Методы именуются в PascalCase. Х3
void Drevo::Print_Value(int rek,int Error)
{
	if (Error == 1)
	{
		cout << "Ebal tvoy rot daun takogo elementa net v dreve" << endl;
	}
	else
	{
		cout << "Vot tvoi oldoviy element dobitiy blagodorya etoi jestkoi rekursii - " << rek << endl;
	}

}





int main()
{
	Drevo FirstTest;

	FirstTest.Add_Element(3);
	FirstTest.Add_Element(5);
	FirstTest.Add_Element(7);
	FirstTest.Add_Element(4);
	FirstTest.Add_Element(21);
	FirstTest.Add_Element(22);

	FirstTest.Get_Element(22);
	FirstTest.Get_Element(81);
	
}
