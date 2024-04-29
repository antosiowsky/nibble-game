#include <iostream>
#include <future>
#include <chrono> 

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b == 0) {
        std::cerr << "Can't divide" << std::endl;
        return 0.0f;
    }
    return static_cast<float>(a) / static_cast<float>(b);
}

std::future<void> performCalculationsAsync(int a, int b, const std::string& operation) {
    return std::async(std::launch::async, [=] {

        std::cout << "Starting process: " << operation << std::endl;

        int result;
        if (operation == "Add") {
            result = add(a, b);
        }
        else if (operation == "Substract") {
            result = subtract(a, b);
        }
        else if (operation == "Multiply") {
            result = multiply(a, b);
        }
        else if (operation == "Divide") {
            result = divide(a, b);
        }

        std::cout << "Result: " << operation << ": " << result << std::endl << std::endl;
        });
}

std::future<void> displayGreetingAsync() {
    return std::async(std::launch::async, [] {
        std::this_thread::sleep_for(std::chrono::seconds(5));

        std::cout << "Hello!" << std::endl;
        });
}

void serverResponse(std::promise<std::string>& responsePromise, int delaySeconds) {
    std::this_thread::sleep_for(std::chrono::seconds(delaySeconds));
    if (rand() % 2 == 0) {
        responsePromise.set_value("Server response: Success!");
    }
    else {
        responsePromise.set_value("Server response: Failure!");
    }
}

int main() {
    //Zadanie 1

    /*
    int number1, number2;
    std::cout << "Type two intigers: ";
    std::cin >> number1 >> number2;

    std::future<void> additionFuture = performCalculationsAsync(number1, number2, "Add");
    std::future<void> subtractionFuture = performCalculationsAsync(number1, number2, "Substract");
    std::future<void> multiplicationFuture = performCalculationsAsync(number1, number2, "Multiply");
    std::future<void> divisionFuture = performCalculationsAsync(number1, number2, "Divide");

    additionFuture.wait();
    subtractionFuture.wait();
    multiplicationFuture.wait();
    divisionFuture.wait();
    */

    //Zadanie 2

    /*
    std::cout << "Starting program with delay.." << std::endl;

    std::future<void> greetingFuture = displayGreetingAsync();

    std::cout << "Program can continue " << std::endl;
    int liczba;
    std::cout << "Type a number to continue" << std::endl;
    std::cin >> liczba;
    std::cout << "Your number is: " << liczba << std::endl;

    greetingFuture.wait();
    */

    //Zadanie 3

    /*
    srand(time(nullptr));

    std::promise<std::string> responsePromise;

    std::future<std::string> responseFuture = responsePromise.get_future();

    std::cout << "Sending request to server..." << std::endl;
    serverResponse(responsePromise, 3); 

    std::cout << "Oczekiwanie na odpowiedz z serwera..." << std::endl;
    std::future_status status = responseFuture.wait_for(std::chrono::seconds(5));


    if (status == std::future_status::ready) {

        std::string serverResponse = responseFuture.get();
        std::cout << serverResponse << std::endl;
    }
    else if (status == std::future_status::timeout) {
        std::cout << "Server response timed out" << std::endl;
    }
    */


    return 0;
}
