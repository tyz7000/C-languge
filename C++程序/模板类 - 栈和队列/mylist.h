/* -------------------------------------------
// ջ�����ͷ�ļ�
//
// ��Ĺ�ϵͼ
//  list   list  node
//   |       \   /
//  stack    queue
//
// �ṩģ���� stack<type> �� queue<type>
// ģ����Ķ����ʵ��һ��Ҫ��ͬһ���ļ�����
// �������ඨ�������� #include <��ʵ��.cpp>
--------------------------------------------- */

#pragma once	// ֻ����һ��

#ifndef LIST_H	// ���û���� LIST_H
#define LIST_H	// ����һ��	LIST_H

// ������Ĵ���Ҳ����һ��

#endif			// ���� #IF


// �������, �ṩ��ͬ�Ľӿ�
template <typename type>
class list
{
protected:
	virtual bool empty() = 0;
	virtual void push(type data) = 0;
	virtual void pop() = 0;
	virtual int  size() = 0;
};


// ���к�ջ������ []
template <typename type>
class node
{
public:
	type data;			// ������
	node<type> *next;	// ָ����
};


// ��ʽջ��, �����̳к�, �ٹ��л�
template <typename type>
class stack: protected list<type>
{
public:
	stack();
	~stack();
	virtual bool empty();
	virtual void push(type data);
	virtual void pop();
	virtual int  size();
	type top();		// ȡջ��
private:
	int _size;
	node<type> *_top;	// type���͵Ľ��ṹ��ַ
};


// ��ʽ������,���ƶ���ͷ�ṹ
template <typename type>
class queue: protected list<type>
{
public:
	queue();
	~queue();
	virtual bool empty();
	virtual void push(type data);
	virtual void pop();
	virtual int  size();
	type front();		// ȡ����
private:
	int qsize;
	node<type> *q_front;	// ͷָ��
	node<type> *q_rear;		// βָ��
};


// -----------------����ʵ�ֲ���---------------------

template <typename type>	// ���캯��
queue<type>::queue()
{
	node<type> *n;			// type ���͵�node

	qsize = 0;
	n = new node<type>;		// �½�һ�����,����ͷβָ��
	if (!n) abort();
	n->next = NULL;
	q_front = q_rear = n;
}

template <typename type>	// ��������
queue<type>::~queue()
{
	node<type> *cur;
	if (q_front)
	{
		cur = q_front;
		while (cur)
		{
			q_front = cur->next;
			delete cur;
			cur = q_front;
		}
	}
}

template <typename type>	// �п�
bool queue<type>::empty()
{
	if (q_front && q_front == q_rear) 
		return true;
	else return false;
}

// ����ʱ: [front == rear(����)]

// [front] -> [] -> ... -> [] -> [rear(����)]
// [] node ����
template <typename type>	// ���
void queue<type>::push(type data)
{
	node<type> *n;

	q_rear->data = data;
	n = new node<type>;		// ������㲹��
	if (!n) abort();

	n->next = q_rear->next;	// ��������
	q_rear->next = n;
	q_rear = n;
	qsize++;
}

template <typename type>	// ����
void queue<type>::pop()
{
	node<type> *cur;

	if (q_front && q_front != q_rear)
	{
		 cur = q_front;
		 q_front = cur->next;
		 delete cur;
		 qsize--;
	}
}

template <typename type>
int queue<type>::size()
{  return qsize;  }

template <typename type>
type queue<type>::front()
{
	if (q_front && q_front != q_rear)
		return q_front->data;
	else abort();
}


// -----------------ջʵ�ֲ���---------------------
// ����ʱ [top(����)]
// ʹ�ú� [top(����)] -> [] -> [] -> NULL

template <typename type>	// ����
stack<type>::stack()
{
	_top = new node<type>;
	_top->next = NULL;
	_size = 0;
}

template <typename type>	// ����
stack<type>::~stack()
{
	node<type> *cur;
	cur = _top;
	while (cur)
	{
		_top = cur->next;
		delete cur;
		cur = _top;
	}
}

template <typename type>	// ��ջ
void stack<type>::push(type data)
{
	node<type> *n;

	_top->data = data;		// ������ջ
	n = new node<type>;		// �����¿ռ�
	if (!n) abort();
	n->next = _top;
	_top = n;
	_size++;
}

template <typename type>	// ��ջ
void stack<type>::pop()
{
	node<type> *del;

	if (_size)
	{
		del = _top;		// �ͷ�һ�����
		_top = _top->next;
		delete del;
		_size--;
	}
}

template <typename type>	// ȡջ��
type stack<type>::top()
{
	return _top->next->data;
}

template <typename type>	// �п�
bool stack<type>::empty()
{
	if (_size) return false;
	else return true;
}

template <typename type>	// ���С
int stack<type>::size()
{  return _size; }