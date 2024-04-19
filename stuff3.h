#include <iostream>

using namespace std;


class Stuff3 {

	friend ostream& operator<<(ostream& os, const Stuff3& s);
	friend istream& operator>>(istream& os, Stuff3& s);

public:

	Stuff3(bool = true, int = 0, int = 0, int = 0);
	Stuff3(const Stuff3&);

	bool operator==(const Stuff3& s);
	Stuff3& operator=(const Stuff3& s);

	static int compareCount;


private:

	int a, b, c;

};
