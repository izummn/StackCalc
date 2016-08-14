#include <stdio.h>
#include <String.h>
#include <conio.h>
#include <iostream>
#include <assert.h>

const int SIZE = 3;
const int OPERATION_SIZE = 5;
const char *ADD = "add";
const char *SUB = "sub";
const char *PUSH = "push";
const char *MUL = "mul";
const char *DIV = "div";
const char *POP = "pop";


void Input(char*, int*);
void Start();
void TestStackCalculation();

template <typename T> 
class Stack{
public:
	Stack();
	Stack(const T data[], int);
	bool OK();
	FILE* Dump(FILE* out = stdout) const;
	bool StackPush(T);
	bool StackPop();
	void Output();
	bool StackCalculation(char*, T);
	bool Add(T);
	bool Mul(T);
	bool Sub(T);
	bool Div(T);
	~Stack(){};

private:
	void InternalResize() { std::cout << " TODO "; };
	int count_;
	T data_[SIZE];
};

template <typename T>
Stack<T>::Stack() :
count_(0)
{
	for (int i(0); i < SIZE; i++) data_[i] = 0;
};

template <typename T>
Stack<T>::Stack(const T data[], int count) :
count_(count)
{
	for (int i(0); i < SIZE; i++) data_[i] = data[i];
};

template <typename T>
bool Stack<T>::OK()
{
	if (0 <= count_ && count_ < SIZE) return true;
	else
		if (count_ == SIZE) InternalResize();
		else std::cout << " Stack is empty!" << std::endl;
		return false;
};

template <typename T>
bool Stack<T>::StackPush(T value)
{
	if (OK())
	{
		data_[count_++] = value;
		return true;
	}
	else return false;

}

template <typename T>
bool Stack<T>::StackPop()
{
	count_--;
	if (OK())
	{
		data_[count_] = 0;
		return true;
	}
	else
	{
		count_++;
		std::cout << " Error in operation POP! " << std::endl;
		return false;
	}
}

template <typename T>
bool Stack<T>::Add(T value)
{
	if (((count_ - 1) >= 0) && StackPush(value))
	{
		data_[count_ - 2] += data_[count_ - 1];
		count_--;
		return true;
	}
	else
	{
		std::cout << " Error in operation Add! " << std::endl;
		return false;
	}
}

template <typename T>
bool Stack<T>::Mul(T value)
{
	if (((count_ - 1) >= 0) && StackPush(value))
	{
		data_[count_ - 2] *= data_[count_ - 1];
		count_--;
		return true;
	}
	else 
	{
		std::cout << " Error in operation Mul! " << std::endl;
		return false;
	}
}


template <typename T>
bool Stack<T>::Div(T value)
{
	if (((count_ - 1) >= 0) && StackPush(value) && (data_[count_ - 1] != 0))
	{
		data_[count_ - 2] = data_[count_ - 2] / data_[count_ - 1];
		count_--;
		return true;
	}
	else
	{
		std::cout << " Error in operation Div! " << std::endl;
		return false;
	};
}


template <typename T>
bool Stack<T>::Sub(T value)
{
	if (((count_ - 1) >= 0) && StackPush(value))
	{
		data_[count_ - 2] = data_[count_ - 2] - data_[count_ - 1];
		count_--;
		return true;
	}
	else 
	{
		std::cout << " Error in operation Sub! " << std::endl;
		return false;
	}
}

template <typename T>
void Stack<T>::Output()
{
	printf(" Result: \n");
	for (int i = 0; i < count_; i++)
		std::cout << "[" << i + 1 << "] = " << data_[i] << std::endl;
	printf("\n");
}

template <typename T>
bool Stack<T>::StackCalculation(char* operation, T value)
{
	if (_stricmp(operation, ADD) == 0) { return Add(value); };
	if (_stricmp(operation, MUL) == 0) { return Mul(value); };
	if (_stricmp(operation, SUB) == 0) { return Sub(value); };
	if (_stricmp(operation, DIV) == 0) { return Div(value); };
	if (_stricmp(operation, PUSH) == 0) { return StackPush(value); };
	if (_stricmp(operation, POP) == 0) { return StackPop(); };
	printf("Incorrect operation! ");
	return true;
}

template <typename T>
void Input(char* operation, T* value)
{
	printf(" Welcome to Stack Calculater! \n");
	printf(" Please, enter operation and value: \n");
	std::cin >> operation >> *value;
}

template <typename T>
void Start()
{
	Stack<double> st;
	char operation[OPERATION_SIZE];
	T value = 0;
	int t = 0;
	while (t == 0)
	{
		Input<T>(operation, &value);
		st.StackCalculation(operation, value);
		st.Output();
	}
}

void TestStackCalculation()
{
	Stack<double> st;
	st.StackCalculation("push", 3.6);
	st.Output();
	st.StackCalculation("div", 4.4);
	st.Output();
	st.StackCalculation("sub", 6.2);
	st.Output();
	st.StackCalculation("push", 3.8);
	st.Output();
	st.StackCalculation("div", 0.0);
	st.Output();
	st.StackCalculation("push", 4.5);
	st.Output();
	st.StackCalculation("pop", 0);
	st.Output();
	st.StackCalculation("mul", 3.4);
	st.Output();
}

int main()
{
	TestStackCalculation();
	//Start<double>();

	return 0;
}


