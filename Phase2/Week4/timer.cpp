#include <chrono>

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start(std::chrono::high_resolution_clock::now()) {}
    double elapsed() const {
        return std::chrono::duration<double, std::milli>(
            std::chrono::high_resolution_clock::now() - start
        ).count();
    }
};
