#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    spdlog::set_level(spdlog::level::debug);
    spdlog::error("this is a error");
    spdlog::info("this is a info");
    spdlog::debug("this is debug");
    spdlog::warn("this is a warn");
    spdlog::critical("this is a critical");
    spdlog::info("{} a info {}", 3.14159, false);
    auto mylogger = spdlog::basic_logger_mt("basic_logger", "logger.txt");
    mylogger->debug("file debug");
    mylogger->error("file error");
    return 0;
}