#include<iostream>
#include<conio.h>
using namespace std;

char ask_ins()
{
	char ch;
	cout << "Do you want to perform another insertion: (Press Y for yes) " << endl;
	ch = getch();
	return ch;
}

char ask_del()
{
	char ch;
	cout << "Do you want to perform another deletion: (Press Y for yes) " << endl;
	ch = getch();
	return ch;
}

void assign(int arr[], int value, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = value;	
	}	
}

void display(int &x, int &y)
{
	cout << endl;
	cout << "Front = " << y << endl;
	cout << "Rear = " << x << endl;
}

void show(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " | " ;
	}
}

bool checkVal(int arr[], int size)
{
	bool val = 1; 
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0 )
		{
			val = 0;
			break;
		}
	}
	
	return val;
}

void insert(int arr[], int &x, int &y, int size)
{
	if (x == 0 && y == 0)
	{
		int value;
		cout << "Enter value to be inserted: ";
		cin >> value;
		arr[x] = value;
		show(arr, size);
		x = x + 1;
		y = y + 1;
		display(x,y);
	}
	
	else if ( checkVal(arr, size) == 1)
	{
		cout << "The array is full. Insertion is not possible... " << endl;
	}
	
	else
	{
		int value;
		cout << "Enter the value to be inserted: ";
		cin >> value;
		if (x >= size)
		{
			arr[x%size] = value;
			show(arr, size);
			x = (x + 1) % size;
		}
		
		else
		{
			arr[x] = value;
			show(arr, size);
			x = x + 1;		
		} 
			
		display(x,y);
	}
	
	int opt;
	cout << "Do you want to perform another insertion: (Press Y for yes) " ;
	opt = getch();
	cout << endl;
	if (opt == 'Y' || opt == 'y')
		insert( arr, x, y, size);		
	
}

void remove(int arr[], int &x, int &y, int size)
{
	int n = 0;
	if (x == 0 && y == 0)
	{
		cout << "The array is empty. Deletion is not possible... " << endl;
	}
	
	else if ( x == y)
	{
		assign(arr, 0, size);
		show(arr, size);
		x = y = 0;
		display(x,y);
	}
	
	else
	{
		arr[y-1] = 0;
		if (y >= size)
		{
			show(arr, size);
			y = (y + 1) % size;
		}
		
		else
		{
			show(arr, size);
			y = y + 1;		
		} 
			
		display(x,y);
	}
	
	int opt;
	cout << "Do you want to perform another deletion: (Press Y for yes) " ;
	opt = getch();
	cout << endl;
	if (opt == 'Y' || opt == 'y')
		{
			remove( arr, x, y, size);		
			n++;
		}
}

void operate(int arr[], int &x, int &y, int size)
{
	int choice;
	while (1)
	{
		cout << "Choose any one of the following: " << endl;
		cout << "1. Insertion " << endl;
		cout << "2. Deletion " << endl;
		cin >> choice;
	
		switch(choice)
		{
			case 1:
				{
					insert(arr,x,y,size);
					break;
				}
			
			case 2:
				{
					remove(arr,x,y,size);
					break;
				}
		
			cout << endl;
		}
		
		
		char term;
		cout << "Do you want to perform another operation? (Press Y for yes): ";
		term = getch();
		cout << endl;
		if (term == 'Y' || term == 'y')
			continue;
		else
			break;
	}
}

int main()
{
	int size;
	cout << "Enter the size of the given circular queue: ";
	cin >> size;
	int queue[size] = {0};
	
	int front = 0;
	int rear = 0;
	operate(queue, rear, front, size);
	return 0;
}
