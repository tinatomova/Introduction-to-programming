/**
*  
* Solution to course project # 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Tina Tomova
* @idnumber 62594
* @compiler VC
*
* <main>
*
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

int precedence(string str);
bool isOperator(string str);

int main() 
{
	char arr[100];
	cin >> arr;

	stack<string>s;
	queue<string>q;

	string str;
	for (int i = 0; i < strlen(arr); i++) {
		for (int j = i; j < strlen(arr); j++) {
			if (isdigit(arr[j])) {
				str.push_back(arr[j]);
			}
			else {
				if (str.length() == 0) {
					str.push_back(arr[j]);
					break;
				}
				if (str.length() > 0) {
					break;
				}
			}
		}
		//sy
		if (isdigit(str[0])) {
			q.push(str);
		}
		else if (isOperator(str)) {
			if (s.empty()) s.push(str);
			else {
				string tops = s.top();				
				if (precedence(str) > precedence(tops)) {
					s.push(str);
				}
				if (precedence(str) == precedence(tops) && precedence(tops) == 3) {
					s.push(str);
				}
				if (((precedence(tops) > precedence(str))
					|| ((precedence(tops) == precedence(str)) && ((precedence(str) == 1 || precedence(str) == 2))))
					&& (s.top() != "(")) {
					q.push(tops);
					s.pop();
					s.push(str);
				}

			}

		}
		else if (str == "(") {
			s.push(str);
		}
		else if (str == ")") {
			while (s.top() != "(") {
				string tops = s.top();
				q.push(tops);
				s.pop();

			}
			if (s.top() == "(") {
				s.pop();
			}
		}

		//sy close
		i = i + str.length() - 1;
		str.clear();
	}
	while (s.empty() == 0) {
		string temp1 = s.top();
		q.push(temp1);
		s.pop();

	}
	/*while (q.empty() == 0) {
		cout << q.front()<<endl;
		q.pop();
	}
	*/
	stack<double>calc;
	while (!q.empty()) {
		string frontq = q.front();
		if (isdigit(frontq[0])) {
			int number = 0;
			for (int i = 0; i <= frontq.length; i++) {
				number += (frontq[i] - 48) * pow(10, frontq.length() - 1 - i);				
			}
			cout << number;
			calc.push(number);

		}
		else if (isOperator(frontq)) {
			if (frontq == "+") {
				double a = calc.top();
				//cout << a << endl;
				calc.pop();
				double b = calc.top();
				//cout << b << endl;
				calc.pop();
				calc.push(b + a);
				//cout << calc.top()<<endl;
			}
			/*if (frontq == '-') {
				double a = calc.top() - 48;
				//cout << a << endl;
				calc.pop();
				double b = calc.top() - 48;
				//cout << b << endl;
				calc.pop();
				calc.push(b - a + 48);

			}
			if (frontq == '*') {
				double a = calc.top() - 48;
				//cout << a << endl;
				calc.pop();
				double b = calc.top() - 48;
				//cout << b << endl;
				calc.pop();
				calc.push(b * a + 48);
				//cout << calc.top()<<endl;
			}
			if (frontq == '/') {
				double a = calc.top() - 48;
				if (a == 0) {
					cout << "Can't devide by 0!";
					return 0;
				}
				calc.pop();
				double b = calc.top() - 48;
				calc.pop();
				calc.push(b / a + 48);
			}
			if (frontq == '^') {
				double a = calc.top() - 48;
				calc.pop();
				double b = calc.top() - 48;
				calc.pop();
				double temp = pow(b, a);
				calc.push(temp + 48);
			}*/
		}
		q.pop();
	}
	cout<<calc.top();
	


}


bool isOperator(string str) {
	if (str == "+" || str == "-" || str == "*" || str == "/" || str == "^") {
		return 1;
	}
	else return 0;

}
int precedence(string str) {
	if (str == "+" || str == "-")
		return 1;
	if (str == "*" || str == "/")
		return 2;
	if (str == "^")
		return 3;
	else return 0;

}