#include <cstring>
#include <string>
using namespace std;

extern "C" {
int add1(int a, int b) { return a + b; }

string add2(string a, string b) { return a + b; }

char* add3(char* a, char* b) {
  char* p = new char[strlen(a) + strlen(b) + 1];
  p[0] = 0;
  strcat(p, a);
  strcat(p, b);
  return p;
}
}