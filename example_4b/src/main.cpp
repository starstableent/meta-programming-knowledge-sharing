#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
void func(T* a, int T::*val)
{
    std::cout << a->*val << "\n";
}

template <typename T>
void func(T* a, std::string T::*val)
{
    std::cout << a->*val << "\n";
}

// template <typename T, typename MemberType, typename = std::enable_if_t<std::is_convertible<decltype(std::cout << std::declval<MemberType>()), std::ostream&>::value>>
// void func(T* a, MemberType T::*val)
// {
//     std::cout << a->*val << "\n";
// }

struct MyClass
{
    int value;
};

struct MyClass2
{
    std::string value;
};

void main()
{
    MyClass cls1 { 10 };
    func(&cls1, &MyClass::value);

    MyClass2 cls2 { "Hello" };
    func(&cls2, &MyClass2::value);
}