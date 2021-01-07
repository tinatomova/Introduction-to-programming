#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int precedence(char arr[], int i);
int precedence(char i);
bool isOperator(char arr[], int i);
bool isOperator(char i);
int main() {
	char arr[100];
	cin >> arr;
	stack<char>s;
	queue<char>q;
	for (int i = 0; i < strlen(arr); i++) {
		if (isdigit(arr[i])) {
			q.push(arr[i]);
		}
		else if (isOperator(arr,i)) {
			char temp = s.top();
			while ((isOperator(temp)==1) && ((precedence(temp)>precedence(arr,i))||((precedence(temp) == precedence(arr, i))&&(precedence(arr,i)==1 || precedence(arr, i) == 2))) && (s.top()!='(')) {
				q.push(temp);
				s.pop();
			}
		}
		else if (arr[i] == '(') {
			s.push(arr[i]);
		}
		else if (arr[i] == ')') {
			while (s.top() != '(') {
				char temp=s.top();
				q.push(temp);
				s.pop();

			}
			if (s.top() == '(') {
				s.pop();
			}
		}
	}
	while (s.empty() == 0) {
		char temp1 = s.top();
		q.push(temp1);
		s.pop();

	}
	
}
int precedence(char arr[], int i) {
	if (arr[i] == '+' || arr[i] == '-') 
		return 1;
	if (arr[i] == '*' || arr[i] == '/') 
		return 2;
	if (arr[i] == '^') 
		return 3;
	else return 0;

	
}
bool isOperator(char arr[], int i) {
	if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '^') {
		return 1;
	}
	else return 0;
		

	
}
bool isOperator(char i) {
	if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^') {
		return 1;
	}
	else return 0;
	
}
int precedence(char i) {
	if (i == '+' || i == '-')
		return 1;
	if (i == '*' || i == '/')
		return 2;
	if (i == '^')
		return 3;
	else return 0;

}
