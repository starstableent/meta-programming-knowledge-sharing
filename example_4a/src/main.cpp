#include <iostream>
#include <string>

void Foo(const std::string& a)
{
    std::cout << "void Foo(const std::string& a)\n";
}

void Foo(float a)
{
    std::cout << "void Foo(float a)\n";
}

void Foo(int a)
{
    std::cout << "void Foo(int a)\n";
}

void main()
{
    Foo(1.0f);
    Foo(1);
}