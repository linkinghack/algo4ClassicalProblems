#include <iostream>

using namespace std;

class A
{
private:
public:
    void func1(){};
    void func2(){};
};

class B
{
private:
    int param1;
    int param2;
public:
    B(){
        param1 = 123;
        param2 = 234;
    }
    /**
     * 当类中存在虚函数时，将自动加入一个虚函数表指针, 
     *此指针占用对象内存空间
     * 
     * 虚函数表 virtual table
    */
    // void *vptr;  // Linux g++ 占8字节， Win-VS 占4字节
    virtual void vfunc(){};
    virtual void vfunc2(){};
};

int main(int argc, char const *argv[])
{
    A a; // sizeof(a) = 1
    B b; // sizeof(b) = 8 || 4(windows)
    cout << "sizeof A: " << sizeof(a) << " sizeof B: " << sizeof(b) << endl;
    cout << "size of int: " << sizeof(int)<<endl; // 4bytes

    B *p = &b;
    b.vfunc();
    p->vfunc();
    return 0;
}
