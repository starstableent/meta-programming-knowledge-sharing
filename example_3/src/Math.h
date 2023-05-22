#pragma once

#include <cassert>
#include <type_traits>

template<typename T>
auto Add_1(T a, T b)
{
    return a + b;
}

template<typename T>
auto Add_2(T a, T b)
{
    static_assert(std::is_arithmetic<T>::value, "Add_2() only accepts numbers");
    return 0;
    //return a + b;
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
auto Add_3(T a, T b)
{
    return a + b;
}

// ============= C++ 20 =============

template<typename T> 
auto Add_4(T a, T b) requires std::is_arithmetic_v<T>
{
    return a + b;
}

template<typename T>
concept ArithmeticType = std::is_arithmetic_v<T>;

template<ArithmeticType T>
auto Add_5(T a, T b)
{
    return a + b;
}

auto Add_6(ArithmeticType auto a, ArithmeticType auto b)
{
    return a + b;
}