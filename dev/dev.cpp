#include <porklib.h>
#include <iostream>

void destroyer(char* val) { printf("Deleting %s\n", val); }

int main() {
    porklib::ArrayList<char*, destroyer> list(2);
    list.add("Hello ");
    list.add("World");
    list.add("!");
    list.add("\n");
    list.forEach([](char* msg) { printf(msg); });
}
