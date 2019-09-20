#include <porklib.h>
#include <iostream>

int main() {
    printf("Hello World!\n");
    printf("size_t: %d\n", (int) sizeof(u_size));

    /*vec3i a(1, 2, 3);
    vec3i b = a + vec3i(4, 5, 6);
    printf("(%d,%d,%d)\n", b.x, b.y, b.z);
    vec3i c = b * a;
    printf("(%d,%d,%d)\n", c.x, c.y, c.z);
    c = c * 4;
    printf("(%d,%d,%d) %d %d\n", c.x, c.y, c.z, c == b, c == c);

    porklib::crypto::Digest* digest = new porklib::crypto::digest::SHA1();
    digest->init();
    delete digest;*/

    porklib::Collection<char*> list = porklib::ArrayList<char*>(2);
    list.add("Hello ");
    list.add("World");
    list.add("!");
    list.add("\n");
    list.forEach([](char* msg) { printf(msg); });
}
