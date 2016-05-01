#include<iostream>
using namespace std;

class Pos {
public:
	int row;
	int column;
	int key;
	Pos* next;
};

class Stack
{
	public:
	
	Pos* bottom;
	Pos* top;
	int size=0;
	
	
	public:
	
	Stack(){init();}
	void init();
	void push(Pos inPos);
	Pos pop();
	void isEmpty();
	void destroy();
	~Stack(){destroy();}
};

void Stack::init()
{
	bottom = new Pos;
	top = bottom;
	size = 0;
}

void Stack::push(Pos inPos)
{
	if(size == 0)
	{
		*bottom = inPos;
		size++;
	}
	else
	{
		Pos* temp = new Pos;
	    *temp = inPos;
	    temp->next = top;
	    top = temp;
	    size++;
	}

}

Pos Stack::pop()
{
	if(size!=0)
	{
	Pos* temp;
	temp = top;
	top = top->next;
	size--;
	return *temp;
	}
	else
	{
		Stack::isEmpty();
	}
}

void Stack::isEmpty()
{
	cout<<"The stack is empty!"<<endl;
}

void Stack::destroy()
{
	Pos* temp;
	while(size > 0)
	{
		temp = top;		
		top = top->next;
		delete temp;
		size--;
	}
}