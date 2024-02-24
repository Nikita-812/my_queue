#include <iostream>
#include <locale.h>
#include <conio.h>
const int N = 100;

typedef struct
{
	int beg, end;// end - индекс указывающий на последний элемент 
	int data[N];
} queue;

queue *init_q();
int push(queue *q, int n); // push elem n in queue and return 0, if error return 1.Make check memory overflow.
int pop(queue *q, int *n); // return status of operation and put on *n elem of q->data[q->beg].
void clear_q(queue *q); // clear all queue. beg = 0, end = -1
bool is_empty_q(queue *q);
void print_q(queue *q);

int main()
{
	setlocale(0, "");
	queue *q = init_q();
	int c = 0, in = 0;
	printf_s("Введите количество элементов: ");
	std::cin >> c;
	printf_s("Введите начальные элементы списка: ");
	while (c)
	{
		scanf_s("%d", &in);
		push(q, in);
		c--;
	}
	int *tmp2 = nullptr;
	int tmp = 0;
	print_q(q);
	printf_s("Что вы хотите сделать с вашим списком? + x добавить элемент x, - удалить последний элемент, 0 - завершить программу: \n");
	while ((c = getchar()) != '0')
	{
		switch (c)
		{
		case '+':
			std::cin >> tmp;
			getchar();
			push(q, tmp);
			break;
		case '-':
			pop(q, tmp2);
			break;
		case 'c':
			getchar();
			clear_q(q);
			break;
		case '0':
			print_q(q);
			break;
		default:
			break;
		}
	}
	printf_s("Ваш список: \n");
	print_q(q);

	return 0 * _getch();

}

queue *init_q()
{
	queue *z = new queue;
	z->beg = 0;
	z->end = -1;
	return z;
}

int push(queue *q, int n)
{
	if (q->end == N - 1)
	{
		return 1;
	} else
	{
		q->end++;
		q->data[q->end] = n;
		return 0;
	}
}

int pop(queue *q, int *n)
{
	
	if (is_empty_q(q))
	{
		std::cout << "EMPTY QUEUE ERROR\n";
		return 2;
	}

	n = (int*) q->data[q->beg];
	q->beg++;

	if (q->beg > q->end) clear_q(q);

	return 0;
}

bool is_empty_q(queue *q)
{
	return q->beg == 0 and q->end == -1 ? 1 : 0;
}

void clear_q(queue *q)
{
	q->beg = 0;
	q->end = -1;
}

void print_q(queue *q)
{
	if (!is_empty_q(q))
		for (int i = q->beg; i < q->end + 1; i++)
			std::cout << q->data[i] << '\n';
	else
		std::cout << "Queue is empty";

}