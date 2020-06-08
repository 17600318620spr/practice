#include<iostream>
using namespace std;

class A
{
        private:
        int a;
        public:
        A(int i)
        {
                a=i;
        }

        void disp()
        {
                cout<<a<<",";
        }
};
 
class B
{
        private:
        int b;
        public:
        B(int j)
        {
                b=j;
        }

        void disp()
        {
                cout<<b<<",";
        }
};

class C:public B,public A
{
        private:
        int c;
        public:
        C(int k):
        A(k-2),B(k+2)
        {  
                c=k;
        }
 
        void disp()
        {
                A::disp();
                B::disp();
                cout<<c<<endl;
        }
};
 
int main()
{
        C obj(10);
        obj.disp();
        return 0;
}
