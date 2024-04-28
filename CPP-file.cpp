// Raspberry Pi 3
// Compile: g++ CPP-file.cpp -lgpiodcxx 
// Run:     ./a.out

#include <iostream>
#include <gpiod.hpp>
#include <unistd.h>
 
int main(void)
{ 
    std::cout << "The C++ program is running:\n";
    ::gpiod::chip chip("gpiochip0");
    auto line = chip.get_line(4);  // GPIO4 - pin 7
    gpiod::line_request request;
    request.request_type = gpiod::line_request::DIRECTION_OUTPUT;
    request.flags = 0;
    line.request(request);
    
    while (1)
    {    
        line.set_value(1);
        std::cout << "CPP GPIO4 pin 7 - HIGH\n";
        sleep(5);
        line.set_value(0);
        std::cout << "CPP GPIO4 pin 7 - LOW\n";
        sleep(5);
    }

    line.release();
}

