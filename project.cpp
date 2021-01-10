<<<<<<< HEAD
=======
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
* 
*
*/

>>>>>>> finished
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

int precedence(string str);
bool isOperator(string str);
bool isOperatorArr(char arr[], int i);
bool isAllowed(char arr[], int i);

int main() {
	char* filepath = new char[256];
	char* line = new char[1025];
	cin.getline(filepath, 256);
	fstream textFile(filepath, fstream::in);
	if (!textFile.is_open()) {
		cout << "Eror" << endl;
	}
	else {
		textFile.seekp(0);

		while (textFile.get(line, 1024, '\n')) {

			textFile.clear();

			int parentL = 0, parentR = 0;
			string str;

			stack<string>s;
			queue<string>q;

			for (unsigned int i = 0; i < strlen(line); i++) {
				if (isOperatorArr(line, i) == 1 && isOperatorArr(line, i + 1) == 1) {
					cout << "Eror";
					return 0;
				}
				if (line[i] == '(') parentL++;
				if (line[i] == ')') parentR++;
				if (!isAllowed(line, i)) {
					cout << "Eror";
					return 0;
				}

			}
			if (parentL != parentR) {
				cout << "Eror";
				return 0;
			}


			for (unsigned int i = 0; i < strlen(line); i++) {
				for (unsigned int j = i; j < strlen(line); j++) {
					if (isdigit(line[j])) {
						str.push_back(line[j]);
					}
					else {
						if (str.length() == 0) {
							str.push_back(line[j]);
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

			stack<double>calc;
			while (!q.empty()) {
				string frontq = q.front();
				if (isdigit(frontq[0])) {
					double number = 0;
					for (unsigned int i = 0; i < frontq.length(); i++) {
						number += (frontq[i] - 48.0) * pow(10, frontq.length() - 1 - i);
					}
					calc.push(number);

				}
				else if (isOperator(frontq)) {
					if (frontq == "+") {
						double a = calc.top();
						calc.pop();
						double b = calc.top();
						calc.pop();
						calc.push(b + a);
					}
					if (frontq == "-") {
						double a = calc.top();
						calc.pop();
						double b = calc.top();
						calc.pop();
						calc.push(b - a);

					}
					if (frontq == "*") {
						double a = calc.top();
						calc.pop();
						double b = calc.top();
						calc.pop();
						calc.push(b * a);
					}
					if (frontq == "/") {
						double a = calc.top();
						if (a == 0) {
							cout << "Can't devide by 0!";
							return 0;
						}
						calc.pop();
						double b = calc.top();
						calc.pop();
						calc.push(b / a);
					}
					if (frontq == "^") {
						double a = calc.top();
						calc.pop();
						double b = calc.top();
						calc.pop();
						double temp = pow(b, a);
						calc.push(temp);
					}
				}
				q.pop();
			}
			cout << calc.top();
		}

		textFile.close();
	}

	delete[] filepath;

	return 0;
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
bool isOperatorArr(char arr[], int i) {
	if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '^') {
		return 1;
	}
	else return 0;
}
bool isAllowed(char arr[], int i) {
	if (arr[i] > 47 && arr[i] < 58) return 1;
	else if (isOperatorArr(arr, i)) return 1;
	else if (arr[i] == '(') return 1;
	else if (arr[i] == ')') return 1;
	else if (arr[i] == ' ') return 1;
	else return 0;

}