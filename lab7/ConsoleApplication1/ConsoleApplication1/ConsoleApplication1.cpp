#include <iostream>
#include <concepts>
#include <vector>
#include <algorithm>

template<typename T>
concept Integral = std::integral<T>;

template<typename Kontener>
    requires Integral<typename Kontener::value_type>
auto suma(const Kontener& kontener) {
    typename Kontener::value_type wynik = 0;
    for (const auto& elem : kontener) {
        wynik += elem;
    }
    return wynik;
}

template<typename T>
concept Numeryczny = std::is_arithmetic_v<T>;

template<Numeryczny T1, Numeryczny T2>
class Para {
private:
    T1 pierwszy;
    T2 drugi;
public:
    Para(T1 p, T2 d) : pierwszy(p), drugi(d) {}
    void wyswietl() {
        std::cout << "Pierwszy: " << pierwszy << ", Drugi: " << drugi << std::endl;
    }
};

template<typename T>
concept Porownywalny = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
    { a == b } -> std::convertible_to<bool>;
};

template<typename Kontener>
    requires Porownywalny<typename Kontener::value_type>
void moje_sortowanie(Kontener& kontener) {
    std::sort(kontener.begin(), kontener.end());
}

int main() {
    //ZADANIE 1
    std::cout << "ZADANIE 1" << std::endl;
    std::vector<int> wektor = { 1, 2, 3, 4, 5 };
    std::cout << "Suma elementów wektora: " << suma(wektor) << std::endl;


    //ZADANIE 2
    std::cout << std::endl << "ZADANIE 2" << std::endl;
    Para<int, double> para1(5, 3.14);
    para1.wyswietl();


    //ZADANIE 3 
    std::cout << std::endl << "ZADANIE 3" << std::endl;
    wektor = { 5, 2, 8, 1, 3 };
    moje_sortowanie(wektor);
    for (const auto& elem : wektor) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}
