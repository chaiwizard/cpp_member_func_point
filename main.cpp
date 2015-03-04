#include <iostream>
using namespace std;
typedef void (*pfun)(void* arg);
class A{
public:
	A() {}
	int foo(){
		cout << "foo" << endl;
		return 0;
	}
private:
	int m;
};
typedef int (A::*pFun)();
void bar(A& a,pFun fun)
{
	int val = (a.*fun)();
	A* pa = &a;
	val = (pa->*fun)();
}
int main(int argc, char* argv[])
{
	A a;
	bar(a,&A::foo);
	return 0;
}