#include <iostream>
#include <locale.h>

const int N = 100;

typedef struct
{
	int beg, end;// end - индекс указывающий на последний элемент 
	int data[N];
} queue;

queue *init_q();
int push(queue *q, int n); // push elem n in queue and return 1, if error return 0.Make check memory overflow.
int pop(queue *q); // return beg-index elem.
void clear_q(queue *q); // clear all queue. beg = 0, end = -1
bool is_empty_q(queue *q);
void print_q(queue *q);

int main()
{
	setlocale(0, "");
	queue *q = init_q();
	std::cout << is_empty_q(q) << '\n';
	push(q, 11);
	pop(q);
	print_q(q);

	return 0;
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
		return 0;
	} else
	{
		q->end++;
		q->data[q->end] = n;
		return 1;
	}
}

int pop(queue *q)
{
	int n;
	if (is_empty_q(q))
	{
		std::cout << "EMPTY QUEUE\n";
		exit(-1);
	}

	n = q->data[q->beg];
	q->beg++;

	if (q->beg > q->end) clear_q(q);

	return n;
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