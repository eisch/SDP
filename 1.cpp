#include <iostream>
using namespace std;

#include "stack.h"

int const EMPTY_STACK = -1; // ����������� ������ ����

Stack::Stack() {
	topIndex = EMPTY_STACK;
}

bool Stack::empty() const {
	return topIndex == EMPTY_STACK;
}

int Stack::top() const {
	if (empty()) {
		cout << "������: ���� �� ���������� � ������ ����!\n";
		return 0;
	}

	return a[topIndex];
}

void Stack::push(int const& x) {
	if (full()) {
		cout << "������: ���� �� ��������� � ����� ����!\n";
	}
	else
		a[++topIndex] = x;
}

bool Stack::full() const {
	return topIndex == MAX - 1;
}

int Stack::pop() {
	if (empty()) {
		cout << "������: ���� �� ���������� �� ������ ����!\n";
		return 0;
	}
	return a[topIndex--];
}