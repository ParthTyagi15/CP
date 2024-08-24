#include <bits/stdc++.h>
#include <math.h>

using namespace std;


/*
FRIEND FUNCTION AND FRIEND CLASS IN C++ EXAMPLE.
class A{
private:
    int x, y;
public:
    A(int a, int b){
        x = a;
        y = b;
    }
    friend void display(A);
    friend class B;
};

class B{
public:
    void show(A a){
        cout << 10 * a.x << ": " << 10 * a.y << endl;
    }
};

void display(A a){
    cout << a.x << ": " << a.y << endl;
}
*/

/*
STRUCTS AND STATIC VARIABLES IN C++ EXAMPLE.

struct A{
    static int x;
    static int y;
    int z;
    A(int z){
        this->z = z;
    }
    void multiply(){
        x *= 10;
        y *= 10;
        z *= 10;
    }
    static void display(){
        cout << x << ": " << y << endl;
    }
};

int A::x = 10;
int A::y = 20;

*/

/*
LOCAL CLASS IN C++ EXAMPLE.
void func(){
    class A{
    public:
        void display(){
            cout << "Hello" << endl;
        }
    };
    A a;
    a.display();
}
*/

void func(){
    int x = 0;
    try{
        if(x > 5)
        cout << "This works!" << endl;
        else
        throw 10;
    }
    catch(...){
        cout << "Exception caught" << endl;
        cout << e << endl;
    }
    final{
        cout << "Finally block" << endl;
    }
}

int main(){
    func();
    return 0;
}


