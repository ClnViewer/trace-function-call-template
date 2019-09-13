#include <iostream>

#define _BUILD_TRACE 1
#include "extTraceFunction.h"

/// This example produce trace report:
/*
 // Name: example.cpp.tlog

 *-> (compiled)   :[Sep 14 2019 02:34:15]
 |- (enter)  :[main|58|example.cpp] -> int main(int32_t, char**)
 |- (info)   :[main|59] -> arguments: 1, exec = C:\__TEST__\TRACE_FUNCTION\bin\Debug\TRACE_FUNCTION.exe
 |- (args)   :[test1] -> 42,
 |- (enter)  :[test1|49|example.cpp] -> std::string test1(int32_t)
 | |- (args)   :[test2] -> 42,
 | |- (enter)  :[test2|41|example.cpp] -> int32_t test2(int32_t)
 | | |- (args)   :[test3] -> 42,
 | | |- (enter)  :[test3|24|example.cpp] -> int32_t test3(int32_t)
 | | | |- (args)   :[test4] -> 42,
 | | | |- (enter)  :[test4|8|example.cpp] -> int32_t test4(int32_t)
 | | | | |- (return) :[test4|10] -> custom return value - 37
 | | | | |- (exit)   :[test4]
 | | | |- (info)   :[test3|32] -> break from line: 32, reason: 32
 | | | |- (return) :[test3|36] -> 1037
 | | | |- (exit)   :[test3]
 | | |- (return) :[test2|44] -> 2074
 | | |- (exit)   :[test2]
 | |- (return) :[test1|53] -> 2074 value
 | |- (exit)   :[test1]
 |- (return) :[main|90] -> 0
 |- (exit)   :[main]

*/

int32_t test4(int32_t x)
    {
        tracer();
        x -= 5;
        trace_return_cb(
            x,              // return value
            int32_t,        // return type
            [](int32_t a)   // callback function, return std::string
            {
                std::string s("custom return value - ");
                s += std::to_string(a);
                return s;
            }
        );
    }

int32_t test3(int32_t x)
    {
        tracer();

        x = trace_call(test4, x);

        do
        {
            x += 100;
            if (x > 1000)
                trace_break(__LINE__);
        }
        while (true);

        trace_return(x);
    }

int32_t test2(int32_t x)
    {
        tracer();
        x = trace_call(test3, x);
        x = x * 2;
        trace_return(x);
    }

std::string test1(int32_t x)
    {
        tracer();
        x = trace_call(test2, x);
        std::string s = std::to_string(x);
        s.append(" value");
        trace_return(s);
    }

int main(int32_t argc, char *argv[])
    {
        trace_start();
        trace_info("arguments: %d, exec = %s", argc, argv[0]);
        std::string s = trace_call(test1, 42);
        std::cout << "Hello world! : " << s.c_str() << std::endl;
        trace_return(0);
    }
