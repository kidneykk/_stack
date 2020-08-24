#include <iostream>

#include "stack.h"

using std::cout;

int main() {
	stack<int> s;
	for (int i = 0; i < 5; ++i) s.push(i + 1);
	cout << s << '\n';
	
	return 0;
}