#include <iostream>

using namespace std;


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
		Node(int data , Node* pLeft = nullptr, Node* pRight = nullptr)
		{
			this->data = data;
			this->pLeft = pLeft;
			this->pRight = pRight;
		}

	};

	int Size;
	Node * Root, * Leafs;

};

Drevo::Drevo()
{
	Size = 0;
	Root = nullptr;
	Leafs = nullptr;
}


Drevo::~Drevo()
{

}

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

void Drevo::Get_Element(int Key)
{
	int Error = 0;
	int pNull = 1;
	int rek = 0;
	if (Root == nullptr)
	{
		Error = 1;
		Print_Value(rek, Error);
	}
	else
	{
		Node* ptr = this->Root;




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
