#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
#define size 100
class stack
{
	double items[size];
	char items2[size];
	int top;
	int top1;
public:
	stack(){top = -1; top1 = -1;}
	bool isEmpty();
	bool isEmpty2();
	bool isFull();
	bool isFull2();
	void push(double item);
	void push_ch(char item);
	double pop();
	char pop_ch();
	void print();
	void print_ch();
	string infixToPostfix(string expression);
	double post_eval(string exprssion);
	
};
bool stack::isEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}
bool stack::isEmpty2()
{
	if (top1 == -1)
	{
		return 1;
	}
	return 0;
}
bool stack::isFull()
{
	if (top == size-1)
	{
		return 1;
	}
	return 0;
}
bool stack::isFull2()
{
	if (top1 == size - 1)
	{
		return 1;
	}
	return 0;
}
void stack::push(double item)
{
	if (isFull())
	{
		cout << "Stack Overflow.\n";
		return;
	}
	items[++top] = item;
}
void stack::push_ch(char item)
{
	if(isFull2())
	{
		cout << "Stack Overflow.\n";
		return;
	}
	items2[++top1] = item;
}
double stack::pop()
{
	double item;
	if (isEmpty())
	{
		cout << "Stack Underflow.\n";
		return-1;
	}
	item = items[top--];
	return item;
}
char stack::pop_ch()
{
	char item;
	if (isEmpty2())
	{
		cout << "Stack Underflow.\n";
		return -1;
	}
	item= items2[top1--];
	return item;
}
void stack::print()
{
	cout << "The Stack is :-\n";
	for (int i = top;i >=0;i--)
	{
		cout << items[i] << "\n";
	}
}
void stack::print_ch ()
{
	cout << "The Stack is :-\n";
	for (int i = top1;i >= 0;i--)
	{
		cout << items2[i] << "\n";
	}
}
double stack::post_eval(string expression)
{
	stack stack1;double result;int i = 0;
	double obj1, obj2;
	while (i < expression.length())
	{
		if (isdigit(expression[i]))
		{
			 stack1.push( expression[i] - '0');
	    }
		else
		{
			obj2=stack1.pop();
			obj1=stack1.pop();
			switch (expression[i])
			{
			case '*':
			{
				result = (double)obj1*obj2;
				break;
			}
			case '/':
			{
				result = (double)obj1/obj2;
				break;
			}
			case '+':
			{
				result = obj1+obj2;
				break;
			}
			case '-':
			{
				result = obj1-obj2;
				break;
			}
			case '^':
			{
				result = pow(obj1,obj2);
				break;
			}
			case '%':
			{
				result = (int)obj1%(int)obj2;
				break;
			}
			}

			stack1.push(result);

		}
		i++;
    }
	return stack1.pop();
}
int poriorty(char ch)
{
	switch (ch)
	{
	case '(':
		return 1;
	case ')':
		return 2;
	case '+':
	case '-':
		return 3;
	case '*':
	case '/':
	case '%':
		return 4;
	case '^':
		return 5;
	default:
		return -1;
	}
}

string post;
string stack::infixToPostfix(string expression)
{
	stack stack1;
	char postfix[size];

	int len = expression.length();
	//expression[len++] = ')';
	expression += ")";len++;
	stack1.push_ch('(');
	
	int i = 0,x=0;
	while (i < len)
	{
		if (isdigit(expression[i]))
		{
			postfix[x++] = expression[i];
		}
		else
		{
			switch (poriorty(expression[i]))
			{
			case 1:
			{
				stack1.push_ch(expression[i]);
				break;
			}
			case 2:
			{
				char ch = stack1.pop_ch();
				while (ch != '(')
				{
					postfix[x++] = ch; 
					ch = stack1.pop_ch();
				}
				break;
			}
			case 3:
			{
				char ch = stack1.pop_ch();
				while (poriorty(ch) >= 3)
				{
					postfix[x++] = ch;
					ch = stack1.pop_ch();
				}
				stack1.push_ch(ch);
				stack1.push_ch(expression[i]);
				break;
			}
			case 4:
			{
				char ch = stack1.pop_ch();
				while (poriorty(ch) >= 4)
				{
					postfix[x++] = ch;
					ch = stack1.pop_ch();
				}
				stack1.push_ch(ch);
				stack1.push_ch(expression[i]);
				break;
			}
			case 5:
			{
				char ch = stack1.pop_ch();
				while (poriorty(ch) == 5)
				{
					postfix[x++] = ch;
					ch = stack1.pop_ch();
				}
				stack1.push_ch(ch);
				stack1.push_ch(expression[i]);
			}
			default:
			{
				cout << "Error .. Invalid Expression.";
			}
			}
		}

		i++;
	}

	
	for (int i = 0;i < x;i++)
	{
		post+= postfix[i];
	}
	return post;
}


void calculator()
{
	stack stack1;
	string expression;
	cout << "Enter Mathematical Expression : ";
	cin>>expression;
	cout<<"Expression result is : "<<stack1.post_eval(stack1.infixToPostfix(expression))<<"\n";
}
void ConvertDecimalToBinary()
{

	stack s;
	int n ;
	cout << "Enter Decimal Number : ";
	cin >> n;
	while (n > 0) {
		s.push(n % 2);
		n /= 2;
	}
	while (!s.isEmpty()) {
		cout << s.pop() ;
	}
	cout << "\n";
}
void main()
{
	while (1) {
		cout << "Entet\n1 - Calculator.\n2 - Decimal to Binary.\n3 - Exit.\n";
		char ch = _getche();
		switch (ch)
		{
		case '2':
		{
			system("cls");
			ConvertDecimalToBinary();
			break;
		}
		case '1':
		{
			system("cls");
			calculator();
		}
		case '3':
		{
			string s;
			stack ss;
			cin >> s;
			cout << ss.infixToPostfix(s) << endl;_getche();
			exit(0);
		}
		default:
			cout << "\nInvlaid Choice.Press any Key to back to Main Menu.\n";
			_getche();
			system("cls");
		}
	}
}
