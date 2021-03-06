#include "Core/Time/Time.h"

namespace Zn
{
    String Time::ToString(std::chrono::time_point<SystemClock> time_point)
    {
        // Get c time from chrono::system_clock.
        const auto CTime = SystemClock::to_time_t(time_point);

        // Convert to tm struct.
        std::tm TMTime;
        localtime_s(&TMTime, &CTime);

        char Buffer[50];   // 50 is an arbitrary number. It's more than enough, considering the format type. If the type changes, change this size.
        auto WrittenSize = std::strftime(&Buffer[0], sizeof(Buffer), "%F:%T", &TMTime);

        _ASSERT(WrittenSize > 0);   //std::strftime returns 0 in case of error.

        return { &Buffer[0], WrittenSize }; // Implicit String constructor.
    }
}