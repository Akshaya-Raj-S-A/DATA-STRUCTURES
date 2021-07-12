#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int precedence(char c)
{
	if(c == '^')
	return 3;
	else if(c == '*' || c == '/')
	return 2;
	else if(c == '+' || c == '-')
	return 1;
	else
	return -1;
}

void InfixToPostfix(string exp)
{
	stack<char> st;
	st.push('N');
	int l = exp.length();
	string ns;
	for(int i = 0; i < l; i++)
	{

		if((exp[i] >= 'a' && exp[i] <= 'z')||(exp[i] >= 'A' && exp[i] <= 'Z'))
		ns+=exp[i];


		else if(exp[i] == '(')

		st.push('(');

		else if(exp[i] == ')')
		{
			while(st.top() != '(')
			{
				char c = st.top();
				st.pop();
			ns += c;
			}
			if(st.top() == '(')
			{

				st.pop();
			}
		}


		else
		{
			while(precedence(exp[i]) <= precedence(st.top()))
			{
				char c = st.top();
				st.pop();
				ns += c;
			}
			st.push(exp[i]);
		}

	}

	while(st.top() != 'N')
	{
		char c = st.top();
		st.pop();
		ns += c;
	}


	cout << ns << endl;

}

int main()
{
    cout<< "Programmed by AKSHAYA RAJ S A\n";
	string exp;
	cout<<"Enter the Expression to be Postfixed :    ";
	cin>>exp;
	cout<<"\nThe postfixed Expression is :  ";
	InfixToPostfix(exp);
	cout<<"\n\n";
	return 0;
}
