valgrind ./bin/allocate -s | sed 's/std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >/std::string/g'
