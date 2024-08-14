#ifndef UTILS_H_
#define UTILS_H_

#include "Include.hpp"

namespace Utils
{
    inline float HireTimeInSeconds()
    {
        float t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }

    std::string& LoadFileAsString(std::string&);

    int ParseInt(std::string);
}

#endif
