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

int main()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	insert_bottom(st, 0);

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}