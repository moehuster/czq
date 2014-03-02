#include <iostream>
using namespace std;
#include <new>

int main()
{
	double* p = new(nothrow) double[-1];
	cout << "p=" << p << endl;
	delete[] p;
}
