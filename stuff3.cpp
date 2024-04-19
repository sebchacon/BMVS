#include "stuff3.h"

int Stuff3::compareCount = 0;

Stuff3::Stuff3(bool israndom, int x, int y, int z)
{
  if (israndom)
	{
	  a = rand() % 1000;
	  b = rand() % 1000;
	  c = rand() % 1000;
	}
  else
	{
	  a = x;
	  b = y; 
	  c = z;
	}
}

Stuff3::Stuff3(const Stuff3& s)
{
   a = s.a;
   b = s.b;
   c = s.c;
}


bool Stuff3::operator==(const Stuff3& s)
{
   Stuff3::compareCount++;
   return (a == s.a) && (b == s.b) && (c == s.c);
}

Stuff3& Stuff3::operator=(const Stuff3& s)
{
    a = s.a;
    b = s.b;
    c = s.c;
    return *this;
}

ostream& operator<<(ostream& os, const Stuff3& s)
{
   os << "(" << s.a << " " << s.b << " " << s.c << ")";
   return os;
}

istream& operator>>(istream& is, Stuff3& s)
{
   is >> s.a >> s.b >> s.c;
   return is;
}
