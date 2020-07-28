// MIT License
//
// Copyright (c) 2020 David Gannerud
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <iomanip>
#include <random>
#include <sstream>

namespace simpleUUID
{
    // UUID version 4
    std::string random()
    {
        // Save cout formatting
        std::ios coutFormat(nullptr);
        coutFormat.copyfmt(std::cout);

        std::stringstream stream;
        std::random_device rd;
        std::uniform_int_distribution<int> dist(0, INT32_MAX);

        for (int i = 0; i < 4; i++)
        {
            int randomNumber = dist(rd);
            stream << std::setfill('0') << std::setw(sizeof(int) * 2) << std::hex << randomNumber;
        }
        // Reset cout formatting
        std::cout.copyfmt(coutFormat);

        std::string uuid = stream.str();
        uuid.insert(8, "-");
        uuid.insert(13, "-");
        uuid.insert(17, "-");
        uuid.insert(23, "-");
        return uuid;
    }

    std::string nil()
    {
        return "00000000-0000-0000-0000-000000000000";
    }
}
