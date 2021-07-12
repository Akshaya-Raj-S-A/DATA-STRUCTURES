#include <iostream>
using namespace std;


struct stack
{
	int data;
	struct stack *next;
};


void create(struct stack **s)
{
	*s = NULL;
}


int isEmpty(struct stack *s)
{
	if (s == NULL)
	{
	return 1;
    }
    else
    {
	return 0;
    }
}


void push(struct stack **s, int element)
{

	stack *temp = new stack;
	if (temp == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		return;
	}

	temp->data = element;
	temp->next = *s;
	*s = temp;
}

int pop(struct stack **s)
{
	int element;
	struct stack *temp;

	element = (*s)->data;
	temp = *s;
	(*s) = (*s)->next;


	return element;
}

int top(struct stack *s)
{
	return (s->data);
}

void sort_and_insert(struct stack **s, int element)
{
	if (isEmpty(*s) || element > top(*s))
	{
		push(s, element);
		return;
	}

	int temp = pop(s);
	sort_and_insert(s, element);

	push(s, temp);
}

void sorted_stack(struct stack **s)
{
	if (!isEmpty(*s))
	{
		int element = pop(s);

		sorted_stack(s);
		sort_and_insert(s, element);
	}
}

void print_stack(struct stack *s)
{
	while (s)
	{
		cout << s->data << "    ";
		s = s->next;
	}
	cout << "\n";
}

int main(void)
{
	struct stack *top;
	int x;
	int i;
	int value;
	create(&top);
	cout<< "Programmed by AKSHAYA RAJ S A\n";
	cout<<"Enter the number of values to be inserted :"<<endl;
	cin>>x;
	cout<<"Enter "<<x<<" values of the stack to be sorted :"<<endl;
	for(i=0;i<x;i++)
	{
	cin>>value;
	push(&top,value);
	}


	cout << "Stack elements before sorting:\n";
	print_stack(top);

	sorted_stack(&top);
	cout << "\n";

	cout << "Stack elements after sorting:\n";
	print_stack(top);

	return 0;
}
