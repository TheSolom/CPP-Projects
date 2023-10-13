#include <iostream>
#include <stack>
using namespace std;

void insert_bottom(stack<int>& st, int value) {
	if (st.empty())
		return st.push(value);

	int temp = st.top();
	st.pop();

	insert_bottom(st, value);

	st.push(temp);
}

void reverse(stack<int>& st) {
	if (st.empty())
		return;

	int temp = st.top();
	st.pop();

	reverse(st);

	insert_bottom(st, temp);
}

int main()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	reverse(st);
	
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}