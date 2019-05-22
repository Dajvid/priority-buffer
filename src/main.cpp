#include "priority-buffer.hpp"

int main() {
    PriorityBuffer pb;
    double a, b;
    PriorityBuffer::OPCODE operation;

    while((operation = pb.LoadInput(a, b)) != PriorityBuffer::EXIT) {
        switch (operation)
        {
        case PriorityBuffer::NUM:
            pb.Insert(a, b);
            break;
        case PriorityBuffer::PRINT:
            pb.Print();
            break;
        case PriorityBuffer::GET:
            pb.Get();
            break;
        case PriorityBuffer::UNKNOWN:
            std::cerr << "Unknown command, try again.\n" <<
                         "exit\t\tto exit the application\n" <<
                         "number:number\tinserts new value into buffer, first number is value and second number is priority\n" <<
                         "print\t\tprints and clears buffer\n" <<
                         "get\t\tprints first value stored in buffer\n";
            break;
        case PriorityBuffer::EXIT:
            return 0;
        }
    }

    return 0;
}
