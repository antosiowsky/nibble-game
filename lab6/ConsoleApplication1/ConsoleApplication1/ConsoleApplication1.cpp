#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>
#include <algorithm>

void FragmentSum(const std::vector<int>& array, int& result, size_t start, size_t end) {
    int sum = 0;
    for (size_t i = start; i < end; ++i) {
        sum += array[i];
    }
    result += sum;
}
void ArraySum(std::vector<int> array) {
    int sum = 0;
    for (auto& el : array) {
        sum += el;
    }
}
//Task 1
int ThreadArraySum(std::vector<int> array) {

    const size_t numThreads = std::thread::hardware_concurrency();
    const size_t rangeSize = array.size() / numThreads;
    int result = 0;
    std::vector<std::thread> threads;
    for (size_t i = 0; i < numThreads; ++i) {
        size_t start = i * rangeSize;
        size_t end = (i == numThreads - 1) ? array.size() : (i + 1) * rangeSize;
        threads.emplace_back(FragmentSum, std::ref(array), std::ref(result), start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return result;
}


//Task 2
struct Pixel {
    int red;
    int green;
    int blue;
};

void ChangeColor(Pixel& pixel) {
    if (pixel.red + 10 > 255) {
        pixel.red = 255;
    }
    else
        pixel.red += 10;

    if (pixel.green - 5 < 0) {
        pixel.green = 0;
    }
    else
        pixel.green -= 5;

    if (pixel.blue + 5 > 255) {
        pixel.blue = 255;
    }
    pixel.blue += 5;

}

void ChangeRgb(size_t start, size_t end, std::vector<Pixel>& pixels) {
    for (size_t i = start; i < end; i++) {
        ChangeColor(pixels[i]);
    }
}

std::vector<Pixel> ThreadChangeRgb(std::vector<Pixel>& pixels) {
    const size_t numThreads = std::thread::hardware_concurrency();
    const size_t rangeSize = pixels.size() / numThreads;
    std::vector<std::thread> threads;
    for (size_t i = 0; i < numThreads; ++i) {
        size_t start = i * rangeSize;
        size_t end = (i == numThreads - 1) ? pixels.size() : (i + 1) * rangeSize;
        threads.emplace_back(ChangeRgb, start, end, std::ref(pixels));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return pixels;
}

std::vector<Pixel> NoThreadChangeRgb(std::vector<Pixel>& pixels) {
    for (int i = 0; i < pixels.size(); i++) {
        ChangeColor(pixels[i]);
    }
    return pixels;
}




//Task 3 
bool isPrime(int value) {
    if (value <= 1) {
        return false;
    }

    for (int i = 2; i <= std::sqrt(value); ++i) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

void PrimesInRange(int start, int end, std::vector<int>& result) {
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            result.push_back(i);
        }
    }
}

std::vector<int> ThreadSearchForPrimes(int first, int last) {
    const size_t numThreads = std::thread::hardware_concurrency();
    const size_t rangeSize = (last - first + numThreads) / numThreads;
    std::vector<std::thread> threads;
    std::vector<std::vector<int>> threadResults(numThreads);

    for (size_t i = 0; i < numThreads; ++i) {
        size_t start = first + i * rangeSize;
        size_t end = std::min(start + rangeSize - 1, static_cast<size_t>(last));
        threads.emplace_back(PrimesInRange, static_cast<int>(start), static_cast<int>(end), std::ref(threadResults[i]));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::vector<int> result;
    for (const auto& threadResult : threadResults) {
        result.insert(result.end(), threadResult.begin(), threadResult.end());
    }

    return result;
}

std::vector<int> SearchForPrimes(int first, int last) {
    std::vector<int> result;
    PrimesInRange(first, last, result);
    return result;
}




//Task 4
void TestSpeed(std::vector<int> TestArray, std::vector<Pixel> TestPixels, int PrimeStart, int PrimeEnd) {

    //array sum
    auto start = std::chrono::high_resolution_clock::now();
    ArraySum(TestArray);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = end - start;
    std::cout << "Time taken for array summation without multithreading: " << elapsedTime.count() << "\n";

    start = std::chrono::high_resolution_clock::now();
    ThreadArraySum(TestArray);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken for array summation with multithreading: " << elapsedTime.count() << "\n";

    //color change
    std::vector<Pixel> Test2 = TestPixels;
    start = std::chrono::high_resolution_clock::now();
    NoThreadChangeRgb(Test2);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken for pixel color change without multithreading: " << elapsedTime.count() << "\n";

    Test2 = TestPixels;
    start = std::chrono::high_resolution_clock::now();
    ThreadChangeRgb(Test2);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken for pixel color change with multithreading: " << elapsedTime.count() << "\n";

    //num range
    start = std::chrono::high_resolution_clock::now();
    SearchForPrimes(PrimeStart, PrimeEnd);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken for prime number search in a given range without multithreading: " << elapsedTime.count() << "\n";

    start = std::chrono::high_resolution_clock::now();
    ThreadSearchForPrimes(PrimeStart, PrimeEnd);
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken for prime number search in a given range with multithreading: " << elapsedTime.count() << "\n";
}


int main() {


    const size_t arraySize = 50000000;


    std::mt19937 integerGenerator(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> distribution(0, 20);
    std::uniform_int_distribution<int> pixelDistribution(0, 255);


    std::vector<int> array(arraySize);
    std::vector<int> testArray(arraySize);

    std::vector<Pixel> pixels(arraySize);
    for (size_t i = 0; i < arraySize; ++i) {
        array[i] = distribution(integerGenerator);
        testArray[i] = distribution(integerGenerator);
        pixels[i].red = pixelDistribution(integerGenerator);
        pixels[i].green = pixelDistribution(integerGenerator);
        pixels[i].blue = pixelDistribution(integerGenerator);
    }





    //Task 1
    std::cout << ThreadArraySum(array);

    //Task 2
    pixels = ThreadChangeRgb(pixels);

    //Task 3
    std::vector<int> primesResult = ThreadSearchForPrimes(1, 100000);

    //Task 4
    TestSpeed(testArray, pixels, 1, 100000);

    return 0;
}
