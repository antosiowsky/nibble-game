#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <string>

struct Person {
        std::string firstName;
        std::string lastName;
        int age;
    };
    
    void sortPeople(std::vector<Person>& people) {
        std::ranges::sort(people, [](const Person& a, const Person& b) {
            if (a.lastName != b.lastName)
                return a.lastName < b.lastName;
            if (a.firstName != b.firstName)
                return a.firstName < b.firstName;
            return a.age < b.age;
            });
    }

auto getEvenNumbers(const std::ranges::range auto& numbers) {
    return numbers | std::views::filter([](int x) { return x % 2 == 0; });
}

int maxDifference(const std::vector<int>& numbers) {
        auto minmax = std::ranges::minmax_element(numbers);
        return *std::ranges::max_element(numbers) - *std::ranges::min_element(numbers);
}

auto na_duze(const std::vector<std::string>& slowa)
{
    std::vector <std::string> wynik;
    for (auto& s : slowa)
    {
        std::string sl;
        for (char c : s | std::views::transform([](char c) { return std::toupper(c); }))
            sl += c;
        wynik.push_back(sl);
    }
    return wynik;
}

int main()
{
        std::cout << "+++++ ZADANIE 1 +++++"<< std::endl;
        std::vector<int> data = { -5, 10, -3, 20, 0, 15, -10, 25, -2, 30, 3, 4, 5, 6, 7, 8, 9 };
        auto even_numbers = getEvenNumbers(data);
        for (int num : even_numbers) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "+++++ ZADANIE 2 +++++" << std::endl;

        std::vector<Person> people = {
        {"Adam", "Kowalski", 35},
        {"Piotr", "Nowak", 28},
        {"Anna", "Kowalska", 31},
        {"Maria", "Nowak", 67},
        {"Katarzyna", "Winiewska", 22},
        {"Marek", "Kowalczyk", 45},
        {"Tomasz", "Winiewski", 39}
        };  
        sortPeople(people);
            
        for (const auto& person : people) {
        std::cout << person.firstName << " " << person.lastName << ", wiek: " << person.age << std::endl;
        }


        std::cout << std::endl;
        std::cout << "+++++ ZADANIE 3 +++++" << std::endl;

        std::vector<int> numbers = { 10, 20, 30, 40, 50, 60, 70, 80, 90, -10, -20, -30, -40, -50 };
        std::cout << "Max difference: " << maxDifference(numbers) << std::endl;


        std::cout << std::endl;
        std::cout << "+++++ ZADANIE 4 +++++" << std::endl;

        std::vector<std::string> zdanie{ "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
        std::vector<std::string> zdanie_duze = na_duze(zdanie);
        for (auto s : zdanie_duze)
        {
            std::cout << s << ' ';
        }
        std::cout << std::endl;
        return 0;
}