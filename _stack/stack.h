#ifndef _STACK_H_
#define _STACK_H_

struct empty_struct {
	empty_struct(const char* str) {
		printf("%s\n", str);
	}
};

template<class T>
struct node {
	node* next;
	T data;
};

template<class T>
class stack {
private:
	node<T>* m_top;
	int m_size;

	node<T>* create_node(const T& val, node<T>* next) {
		node<T>* newNode = new node<T>();
		newNode->next = next;
		newNode->data = val;
		return newNode;
	}

public:
	stack() : m_size(0), m_top(nullptr) { }

	bool empty() const {
		return !m_top;
	}

	int size() const {
		return m_size;
	}

	T& top() { return m_top->data; }
	const T& top() const { return m_top->data; }

	void push(const T& val) {
		m_top = create_node(val, m_top);
		m_size++;
	}

	void pop() {
		if (empty()) {
			throw empty_struct("stack is empty");
		}

		node<T>* temp = new node<T>();
		temp = m_top;
		m_top = m_top->next;
		delete temp;
		m_size--;
	}

	friend std::ostream& operator<<(std::ostream& os, const stack<T>& s) {
		node<T>* temp = s.m_top;
		while (temp) {
			os << temp->data << ' ';
			temp = temp->next;
		}
		return os;
	}
};

#endif