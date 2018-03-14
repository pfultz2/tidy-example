
#include <iostream>
#include <vector>

void move_it() {
    std::string str = "Hello, world!\n";
    std::vector<std::string> messages;
    messages.emplace_back(std::move(str));
    std::cout << str << std::endl;
    for (int i = 0; i < messages.size(); ++i)
        std::cout << messages[i] << std::endl;
}

void print_it(const char* s, bool lets_do_it=false)
{
    if (s == NULL)
    {
        std::cout << "Lets try to print a null pointer" << std::endl;
    }
    std::cout << s << std::endl;
}

int calculate(int z) {
    if (z == 0) {
        int x = 1 / z;
        return x;
    }
    return 0;
}


int main() {
    print_it("Hello world");
    std::cout << calculate(1) << std::endl;
    std::cout << calculate(0) << std::endl;
}

