# C++ trace function call template
C++17 trace function call template, one header source

### Example produce trace report:

Auto trace name: [example.cpp.tlog](example.cpp)

```cpp

 *-> (compiled)   :[Sep 10 2019 17:34:15]
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

```

## Macros available

- `trace_start()`  
- `trace_init("filename" | FILE*)`  
- `tracer()`  
- `trace_info("format", args...)`  
- `trace_enter()`  
- `trace_break(numeric value)`  
- `trace_return(auto type)`  
- `trace_return_cb(value, type, std::function<std::string(type&)>)`  
- `trace_call(function name, function args...)`  

## License

 _MIT_

