#include <iostream>
#include <cassert>

using namespace std;

class Stack
{
private:
	int m_array[10];
	int m_length;
public:
	void reset()
	{
		m_length = 0;
		for (int i = 0; i < 10; i++)
			m_array[i] = 0;
	}

	bool push(int x)
	{
		// If stack full, return false
		if (m_length == 10)
			return false;

		m_array[m_length++] = x;		// set the next free element to the value, then increase m_next
		return true;
	}

	int pop()
	{
		// If there are no elements on the stack, assert out
		assert(m_length > 0);

		// m_next points to the next free element, so the last valid element is m_next -1.
		// what we want to do is something like this:
		// int val = m_array[m_next-1]; // get the last valid element
		// --m_next; // m_next is now one less since we just removed the top element
		// return val; // return the element
		// that can be condensed down into this:
		return m_array[--m_length];
	}

	void print()
	{
		cout << "( ";

		for (int i = 0; i < m_length; i++)
		{
			cout << m_array[i] << " ";
		}
		
		cout << " )" << endl;
	}
};