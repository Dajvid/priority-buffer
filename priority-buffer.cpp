#include "priority-buffer.hpp"

PriorityBuffer::RETCODE PriorityBuffer::Insert(double value, double priority)
{
    static double index;
    index++;

    PriorityBuffer::Record_t record = {value, priority, index};
    record.index = index;
    queue.push(record);

    return PriorityBuffer::SUCCES;
}

PriorityBuffer::RETCODE PriorityBuffer::Get()
{
    if (!queue.empty()) {
        std::cout << queue.top().value << "\n";
    } else {
        std::cout << "buffer is empty\n";
    }

    return SUCCES;
}

PriorityBuffer::RETCODE PriorityBuffer::Print()
{
    if (!queue.empty()) {
        while(!queue.empty()) {
            std::cout << queue.top().value << " ";
            queue.pop();
        }
        std::cout << "\n";
    } else {
        std::cout << "buffer is empty\n";
    }

    return SUCCES;
}

PriorityBuffer::OPCODE PriorityBuffer::LoadInput(double &value, double &priority)
{
    std::string input;
    std::cin >> input;
    value = 0;
    priority = 0;
    char *endptr;

    if (input == "exit") {
        return EXIT;
    } else if (input == "print") {
        return PRINT;
    } else if (input == "get") {
        return GET;
    } else {
        value = strtod(input.c_str(), &endptr);
        if (endptr[0] != ':' or endptr == input.c_str()) {
            return UNKNOWN;
        }
        endptr = &endptr[1];
        char *tmp = endptr;
        priority = strtod(endptr, &endptr);
        return (endptr[0] != '\0' or endptr == tmp) ? UNKNOWN : NUM;
    }
}
