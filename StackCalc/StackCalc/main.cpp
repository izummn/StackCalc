#include <stdio.h>
#include <String.h>
#include <conio.h>


const int SIZE = 10;
const int OPERATION_SIZE = 5;
const char *ADD = "add";
const char *SUB = "sub";
const char *PUSH = "push";
const char *MUL = "mul";
const char *DIV = "div";
const char *POP = "pop";


struct Stack{
	int data[SIZE];
	int count;

	Stack()
	{
		count = 0;
		for (int i = 0; i < SIZE; i++)
			data[i] = NULL;
	};
	~Stack(){};
};


void StackPush(Stack* st, int value)
{
	st->data[st->count++] = value;	
}

int StackPop(Stack* st)
{	
	if (st->count < 1) printf(" Error! ");
	else
	{
		st->count--;
		int result = st->data[st->count];
		st->data[st->count] = NULL;
		return result;
	}
	return 0;
}

void Add(Stack* st, int value)
{
	StackPush(st, value);
	st->data[st->count-2] += st->data[st->count - 1];
	st->count--;
}

void Mul(Stack* st, int value)
{
	StackPush(st, value);
	st->data[st->count - 2] *= st->data[st->count - 1];
	st->count--;
}

void Div(Stack* st, int value)
{
	StackPush(st, value);
	st->data[st->count - 2] = st->data[st->count - 2] / st->data[st->count - 1];
	st->count--;
}

void Sub(Stack* st, int value)
{
	StackPush(st, value);
	st->data[st->count - 2] = st->data[st->count - 2] - st->data[st->count - 1];
	st->count--;
}

void Input(char* operation, int* value)
{
	printf(" Welcome to Stack Calculater! \n");
	printf(" Please, enter operation and value: \n");
	scanf_s("%s%d", operation, OPERATION_SIZE, value);
	
}

void Output(Stack* st)
{
	printf(" Result: \n");
	for (int i = 0; i < st->count; i++)
		printf("[%d] = %d;\n", i + 1, st->data[i]);
	printf("\n");
}

void StackCalculation(Stack* st, char* operation, int value)
{
	if (_stricmp(operation, ADD) == 0) Add(st, value);
	if (_stricmp(operation, SUB) == 0) Sub(st, value);
	if (_stricmp(operation, MUL) == 0) Mul(st, value);
	if (_stricmp(operation, DIV) == 0) Div(st, value);
	if (_stricmp(operation, PUSH) == 0) StackPush(st, value);
	if (_stricmp(operation, POP) == 0) StackPop(st);
}

void Start()
{
	Stack StackToCalc;
	char operation[OPERATION_SIZE];
	int value = 0;
	int t = 0;
	while (t == 0)
	{ 
		Input(operation, &value);
		StackCalculation(&StackToCalc, operation, value);
		Output(&StackToCalc);
	}
}

void TestStackCalculation()
{
	Stack StackToCalc;
	char operation[OPERATION_SIZE];
	int value = 0;
	StackCalculation(&StackToCalc, "push", 3);
	Output(&StackToCalc);
	StackCalculation(&StackToCalc, "push", 8);
	Output(&StackToCalc);
	StackCalculation(&StackToCalc, "push", 12);
	Output(&StackToCalc);
	StackCalculation(&StackToCalc, "add", 9);
	Output(&StackToCalc);
	StackCalculation(&StackToCalc, "sub", 8);
	Output(&StackToCalc);
	StackCalculation(&StackToCalc, "mul", 3);
	Output(&StackToCalc);
	StackCalculation(&StackToCalc, "push", 87);
	Output(&StackToCalc);
	StackCalculation(&StackToCalc, "add", 34);
	Output(&StackToCalc);
	StackCalculation(&StackToCalc, "pop", 0);
	Output(&StackToCalc);
}

int main()
{
	TestStackCalculation();
	//Start();
	return 0;
}


