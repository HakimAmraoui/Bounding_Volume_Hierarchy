#ifndef RAYTRACING_
#define RAYTRACING_

#include <chrono>

namespace Raytracing{
    class Chrono{
        public:
            using Clock = std::chrono::high_resolution_clock;
            using Duration = std::chrono::duration<double>;
            void start();
            void stop();
            double elapsedTime() const;
        private:
        Clock::time_point begin_time;
        Clock::time_point end_time;
    
    };
}

#endif