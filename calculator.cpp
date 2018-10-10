#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int t;

/* 입력 받는 수식		*
*----------------------*
* input: 수식			*
* length: 수식의 길이	*
*----------------------*/
char input[100];
int length;

/* 후위 표기법            	*
*--------------------------*
* postfix: 후위표기법 수식 *
*--------------------------*/
vector<string> postfix;

/* 스택            									*
*--------------------------------------------------*
* stack_operator: 중위 -> 후위로 변경할 때 사용	*
* stack_calculator: 후위표기로 된 수식 연산시 사용	*
*--------------------------------------------------*/
stack<char> stack_operator;
stack<int> stack_calculator;

/* 우선순위 출력하는 함수	*
*---------------------------*
* 연산자(c)를 입력받아		*
* 우선순위 리턴				*
* 곱셈, 나눗셈: 1			*
* 덧셈, 뺄셈: 0				*
* 괄호: -1					*
*---------------------------*/
int priority(char c) {
	switch (c) {
	case '*':
	case '/':
		return 1;
	case '+':
	case '-':
		return 0;
	case '(':
	case ')':
		return -1;
	}
}

/* 중위 표기법을 후위 표기법으로 바꾸는 함수																						*
* 사용 스택: stack_operator																										*
*----------------------------------------------------------------------------------------------------------------------------------*
* 입력 받은 수식으로 부터 문자 하나씩 읽음																							*
* 현재 문자가 숫자인 경우: postfix에 저장																							*
* 현재 문자가 여는 괄호인 경우: 스택에 삽입																						*
* 현재 문자가 닫는 괄호인 경우: 여는 괄호가 나올 때까지 스택에 있는것들을 postfix에 저장											*
* 연산자의 경우: 아래와 같이 두 가지로 나뉜다																						*
*					1. 스택이 빈 경우:			현재 연산자를 스택에 삽입															*
*					2. 스택이 비지 않은 경우:	스택에서 현재 연산자 보다 우선순위가 높거나 같은 연산자들을 빼고(postfix에 저장)	*
*												현재 연산자를 스택에 삽입															*
* 수식을 다 읽고 스택에 연산자가 남아있으면 순서대로 postfix에 저장한다															*
*----------------------------------------------------------------------------------------------------------------------------------*/
void infixToPostfix();

/* 후위 표기법을 계산하는 함수										*
* 사용 스택: stack_calculator										*
*------------------------------------------------------------------*
* 후위 표기법 수식으로 부터 하나씩 읽음							*
* 숫자인 경우: 스택에 삽입											*
* 연산자인 경우: 숫자 두개를 끄내 연산을 한후 다시 스택에 넣는다	*
*------------------------------------------------------------------*/
void calculate();

int main() {
	/* 테스트 케이스 갯수 입력 */
	cin >> t;

	/* 테스트 케이스 갯수 만큼 반복 */
	for (int i = 1; i <= 4; i++) {

		/* 수식 입력 받음*/
		cin >> input;
		length = strlen(input);

		/* 중위 표기법 -> 후위 표기법 */
		infixToPostfix();

		/* 연산 결과 */
		calculate();
	}

	return 0;
}

void infixToPostfix() {
	char c;
	string s;
	/* 입력 받은 수식을 조사 */
	for (int i = 0; i < length; i++) {
		/* 수식에서 하나씩 읽어옴 */
		c = input[i];
		/* 숫자의 경우 */
		if (c >= '0' && c <= '9') {
			/* 숫자를 postfix로 옮김 */
			postfix.push_back(to_string(atoi(input + i)));
			while (input[i] >= '0' && input[i] <= '9')
				i++;
			i--;
		}
		/* 연산자의 경우 */
		else {
			/* 여는 괄호의 경우 */
			if (c == '(')
				stack_operator.push('(');
			/* 닫는 괄호의 경우 */
			else if (c == ')') {
				/* 여는 괄호가 나올 때까지 */
				while (stack_operator.top() != '(') {

					/* 스택 상단에 있는 것들을 postfix로 옮김 */
					string str(1, stack_operator.top());
					postfix.push_back(str);
					stack_operator.pop();
				}
				/* 여는 괄호도 스택에서 제거 */
				stack_operator.pop();
			}
			/* 사칙 연산의 경우 */
			else {
				/* 스택에 아무 것도 없는 경우 단순히 삽입 */
				if (stack_operator.empty())
					stack_operator.push(c);

				/* 스택에 무언가 있는 경우 */
				else {

					/* 스택 top에 있는 연산자가 들어오는 연산자 보다 우선순위가 크거나 같은 경우 */
					while (priority(stack_operator.top()) >= priority(c)) {

						/* 스택 상단에 있는 것들을 postfix로 옮김 */
						string str(1, stack_operator.top());
						postfix.push_back(str);
						stack_operator.pop();

						/* 스택이 빈 경우 반복문 벗어남 */
						if (stack_operator.empty())
							break;
					}
					/* 우선순위 높은 것들 제거 했으면 새로 추가 될 것 스택에 삽입 */
					stack_operator.push(c);
				}
			}
		}
	}

	/* 남은 연산자들을 postfix로 옮기는 과정 */
	while (!stack_operator.empty()) {
		/* 스택 상단에 있는 것들을 postfix로 옮김 */
		string str(1, stack_operator.top());
		postfix.push_back(str);
		stack_operator.pop();
	}
}

void calculate() {
	for (string s : postfix) {
		/* postfix에서 하나하나씩 읽음 */
		char c = s.at(0);
		/* 읽은 것이 연산자일 경우 */
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			/* 숫자 두개를 스택으로부터 끄내 읽음 */
			int n1 = stack_calculator.top();
			stack_calculator.pop();
			int n2 = stack_calculator.top();
			stack_calculator.pop();

			switch (c) {
			case '+':
				stack_calculator.push(n2 + n1);
				break;
			case '-':
				stack_calculator.push(n2 - n1);
				break;
			case '*':
				stack_calculator.push(n2 * n1);
				break;
			case '/':
				stack_calculator.push(n2 / n1);
				break;
			}
		}

		/* 읽은 것이 숫자인 경우 */
		else
			stack_calculator.push(atoi(s.c_str()));
	}
	cout << stack_calculator.top() << endl;
}