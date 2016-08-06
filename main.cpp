#include <iostream>

#include <memory.h>

using namespace std;


class A
{
public:
	A(char v1, char v2)
		: _var1(v1), _var2(v2), _ptr(new char('c'))
	{}

	~A()
	{
		cout << "Destructor A" << endl;
		delete _ptr;
	}

	void out() {
		cout << "Test " << _var1 << " " << _var2 << " " << *_ptr << endl;
	}

private:
	char _var1;
	char _var2;
	char* _ptr;
};

int main()
{
	// Let's make some scope
	{
		// Get memory from stack
		StackObject<A> a;
		// a has not initialized yet
		// So initialize it.
		a.construct('a', 'b');

		// Now we can use a as pointer on obj type A.
		a->out();
		A& aRef = *a;
		aRef.out();
	}
	// Here a is deleted from stack.
	// Stored object also deleted. ~A() was called.

	{
		StackObject<A> a1;
	}

	// Here a is deleted from stack.
	// Stored object also deleted. ~A() was called.
	return 0;
}
