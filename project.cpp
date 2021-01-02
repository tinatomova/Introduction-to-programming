#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int precedence(char arr[], int i);
bool isOperator(char arr[], int i);
int main() {
	char arr[4];
	cin >> arr;
	stack<char>s;
	queue<char>q;
	for (int i = 0; i < 4; i++) {
		if (isdigit(arr[i])) {
			q.push(arr[i]);
		}
		else if (isOperator(arr,i)) {
			s.push(arr[i]);
		}
		else if (arr[i] == '(') {
			s.push(arr[i]);
		}
	}
}
int precedence(char arr[], int i) {
	if (arr[i] == '+' || arr[i] == '-') return 1;
	if (arr[i] == '*' || arr[i] == '/') return 2;
	if (arr[i] == '^') return 3;

	
}
bool isOperator(char arr[], int i) {
	if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '^') {
		return 1;
	}
		

	
}
