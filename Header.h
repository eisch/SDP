#ifndef STACK_H_
#define STACK_H_

int const MAX = 100;

class Stack {
private:
	int a[MAX];	// ���������� �� �����
	int topIndex;	// ������ �� ��������� �������

					// �������� ���� ���� � �����
	bool full() const;

public:

	// ��������� �� ������ ����
	Stack();

	// ���������

	// �������� ���� ���� � ������
	bool empty() const;

	// �������� �� �������� �� ����� �� �����
	int top() const;

	// ��������

	// ��������� �� �������
	void push(int const&);

	// ���������� �� �������
	int pop();
};

#endif /* STACK_H_ */