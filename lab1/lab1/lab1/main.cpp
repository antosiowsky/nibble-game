import Zespolona;
import <iostream>;



int main()
{
	std::cout << "Podaj pierwsza liczbe zespolona (jako a+b) ";
	double re_1{}, im_1{};
	char c_1{};
	std::cin >> re_1 >> c_1 >> im_1;
	//std::cout << re_1<<im_1;

	Zespolona l1(re_1, im_1);

	std::cout << l1;
	std::cout << "Podaj druga liczbe zespolona (jako a+b) ";
	double re_2{}, im_2{};
	char c_2{};
	std::cin >> re_2 >> c_2 >> im_2;
	Zespolona l2(re_2, im_2);
	std::cout << "Wybierz operacje:" << std::endl;
	std::cout << "1. Dodawanie" << std::endl;
	std::cout << "2. Odejmowanie" << std::endl;
	std::cout << "3. Mnozenie" << std::endl;
	std::cout << "4. Dzielenie" << std::endl;
	int wybor{};
	std::cin >> wybor;
	Zespolona wynik(0.0, 0.0);
	switch (wybor)
	{
	case 1:
	{
		wynik = l1 + l2;
		break;
	}
	case 2:
	{
		wynik = l1 - l2;
		break;
	}
	case 3:
	{
		wynik = l1 * l2;
		break;
	}
	case 4:
	{
		wynik = l1 / l2;
		break;
	}
	default:
	{
		std::cout << "Brak dostepnej opcji." << std::endl;
		return 1;
	}
	}
	std::cout << "Wynik dzialania: " << wynik << std::endl;
	return 0;
}
