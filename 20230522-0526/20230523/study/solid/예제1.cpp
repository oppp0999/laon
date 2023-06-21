#include <iostream>
#include <string>

class Logger {
public:
    void log(const std::string& message) {
        std::cout << "Logging: " << message << std::endl;
    }
};

class Calculator {
private:
    Logger logger;

public:
    int add(int a, int b) {
        int result = a + b;
        logger.log("Addition performed: " + std::to_string(result));
        return result;
    }
};

int main() {
    Calculator calculator;
    int result = calculator.add(3, 5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}