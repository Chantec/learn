//
// Created by root on 25-1-9.
//

#include "Log.h"
void TestLog() {
    Log::Instance()->init(0, "./log", ".log", 1024);
    LOG_DEBUG("hello %d",1);
    LOG_DEBUG("hello %d",1);

}
int main()
{
    TestLog();
}

