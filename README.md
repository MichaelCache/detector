# detector
C++ template meta-programming debug tool.

This tool will help print real type info while template meta function running.



#### Lisence

GNU General Public License V3.0



#### How to use

This is a header only library, just include to use.



#### Example

If you want to know what types user put in yout template meta function, and it's hard to deduce by yourself, you can use this tool as below

```C++
// yout template function
template<typename... T>
struct my_meta_func
{
    // what the type is
    using type = typename another_meta_func<T...>::type;
}

int main(int argc, char* argv){
    // what is t
    using t = typename my_meta_func<int, double, void>::type;
    // use detector show what t is, when t is not void
    using out = typename detecor<!std::is_same<t, void>::value, t>::type;
}
```

 While compiling, you will see info like below to show what type `t` is

```shell
detector.h: In instantiation of ‘struct detector<true, std::tuple<int&, double&, void&>’:
...
```

so `t` in `main` is `std::tuple<int&, double&, void&>`



#### Notice

No guarantee for other compilers except for g++ 4.8 or later.