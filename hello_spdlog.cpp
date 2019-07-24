#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/syslog_sink.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    auto file_log = spdlog::basic_logger_mt("filelog1", "./file1.txt");
    file_log->info("this is file info");
    file_log->warn("this is {} file warn {}", "VisualGMQ", false);
    spdlog::drop_all();
    return 0;
}