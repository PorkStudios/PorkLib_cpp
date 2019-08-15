#include <porklib.h>
#include <iostream>

/*class A {
    public:
        virtual void a() = 0;
        virtual void b() {
            std::cout << "Ab" << std::endl;
        }
        virtual void c(){
            std::cout << "Ac" << std::endl;
        }
};

class B: public A {
    public:
        void b() {
            std::cout << "Bb" << std::endl;
        }
        void c()    {
            std::cout << "Bc" << std::endl;
        }
};

class C: public B {
    public:
        void a() {
            std::cout << "Ca" << std::endl;
        }
};

int main()  {
    A* a = new C();

    a->a();
    a->b();
    a->c();
}*/

int main() {
    printf("Hello World!\n");
    printf("size_t: %d", (int) sizeof(size_t));

    vec3i a(1, 2, 3);
    vec3i b = a + vec3i(4, 5, 6);
    vec3i c = b * a;
}
