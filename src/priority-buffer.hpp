#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <regex>

class PriorityBuffer
{
public:
    PriorityBuffer() {};

    ~PriorityBuffer() {};

    struct Record_t {
        double value;
        double priority;
        double index;

        bool operator<(const Record_t& rhs) const
        {
            return priority == rhs.priority ? index > rhs.index : priority < rhs.priority;
        }
    };

    enum OPCODE {EXIT, NUM, PRINT, GET, UNKNOWN};

    enum RETCODE {SUCCES};

    RETCODE Insert(double value, double priority);

    RETCODE Print();

    RETCODE Get();

    OPCODE LoadInput(double &value, double &priority);

private:
    std::priority_queue<Record_t> queue;
};
