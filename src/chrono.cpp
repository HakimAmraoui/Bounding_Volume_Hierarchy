#include "chrono.hpp"
namespace Raytracing{
    void Chrono::start()
    {
        begin_time = Clock::now();
    }

    void Chrono::stop()
    {
        end_time = Clock::now();
    }

    double Chrono::elapsedTime() const
    {
        return (std::chrono::duration_cast<Duration> (end_time - begin_time)).count();
    }

}