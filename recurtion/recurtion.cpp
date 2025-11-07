#include 
#include 
using namespace std;

void generate(int n, string s) {
    if (s.length() == n) {
        cout << s << endl;
        return;
    }
    generate(n, s + "0");
    generate(n, s + "1");
}

int main() {
    int n = 3;
    cout << "Все бинарные строки длины " << n << ":" << endl;
    generate(n, "");
    return 0;
}


Вывод:


Все бинарные строки длины 3:
000
001
010
011
100
101
110
111
