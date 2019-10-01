#include <porklib.h>
#include <iostream>

void destroyer(char* val) { printf("Deleting %s\n", val); }

int main() {
    {
        porklib::ArrayList<char*, destroyer> list(2);
        list.add("Hello ");
        list.add("World");
        list.add("!");
        list.add("\n");
        list.forEach([](char* msg) { printf(msg); });
    }

    printf("%f\n", porklib::math::sqrt(16.0f));
    printf("%d\n", porklib::math::sqrt<f32, i32>(16.0f));
}
