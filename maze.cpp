#include"stack.h"
#include<iostream>
using namespace std;
const int MAZE_SIZE = 8;

class Maze
{
public:
	int maze[MAZE_SIZE][MAZE_SIZE] =
	{
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,1,1,1,1,0,1,0 },
		{ 0,1,0,1,0,0,0,0 },
		{ 0,1,1,1,0,0,1,0 },
		{ 0,0,0,1,0,0,1,0 },
		{ 0,1,1,1,1,1,1,0 },
		{ 0,0,0,0,0,0,0,0 }
	};
	Stack path = Stack();

public:
	void find_path(Pos* start, Pos* end);
	void find_next(Pos* temp);
	void display_path();
};


void Maze::find_path(Pos* start, Pos* end)
{

	Pos* temp = start;
	while (temp->row != end->row || temp->column != end->column)
	{
		find_next(temp);
		if (path.size == 0)
		{
			cout << "There is no way to the exit!" << endl;
			system("pause");
			break;
		}
	}
	if (temp->row == end->row && temp->column == end->column)
	{
		maze[temp->row][temp->column] = 2;
		display_path();
	}
}

void Maze::find_next(Pos* temp)
{

	if (maze[temp->row - 1][temp->column] == 1)//up
	{
		path.push(*temp);
		maze[temp->row][temp->column] = 2;
		Pos* next = new Pos;
		next->row = temp->row - 1;
		next->column = temp->column;
		next->key = 1;
		*temp = *next;
		return;
	}

	if (maze[temp->row][temp->column + 1] == 1)//right
	{
		path.push(*temp);
		maze[temp->row][temp->column] = 2;
		Pos* next = new Pos;
		next->row = temp->row;
		next->column = temp->column + 1;
		next->key = 1;
		*temp = *next;
		return;
	}

	if (maze[temp->row + 1][temp->column] == 1)//down
	{
		path.push(*temp);
		maze[temp->row][temp->column] = 2;
		Pos* next = new Pos;
		next->row = temp->row + 1;
		next->column = temp->column;
		next->key = 1;
		*temp = *next;
		return;
	}

	if (maze[temp->row][temp->column - 1] == 1)//left
	{
		path.push(*temp);
		maze[temp->row][temp->column] = 2;
		Pos* next = new Pos;
		next->row = temp->row;
		next->column = temp->column - 1;
		next->key = 1;
		*temp = *next;
		return;
	}

	maze[temp->row][temp->column] = 0;
	*temp = path.pop();
}

void Maze::display_path()
{
	for (int cnt = 0; cnt < 8; cnt++)
	{
		for (int _cnt = 0; _cnt < 8; _cnt++)
		{
			if (maze[cnt][_cnt] == 1){
				maze[cnt][_cnt] = 0;
			}
			cout << maze[cnt][_cnt];
		}
		cout << endl;
	}
	system("pause");
}

void main()
{
	Maze maze;
	Pos* start = new Pos;
	start->row = 1;
	start->column = 2;
	start->key = 1;

	Pos* end = new Pos;
	end->row = 5;
	end->column = 6;
	end->key = 1;
	maze.find_path(start, end);

}
