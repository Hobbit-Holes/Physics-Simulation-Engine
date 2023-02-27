#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

#include "Logger.hh"

std::vector<LogEntry> Logger::messages;

std::string CurrentDateTimeToString() {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string output(30, '\0');
    std::strftime(&output[0], output.size(), "%d-%b-%Y %H-%M-%S", std::localtime(&now));
    return output;
}

void Logger::Info(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_INFO;
    logEntry.message = "INFO [" + CurrentDateTimeToString() + "]: " + message;
    std::cout << "\x18[32m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}

void Logger::Error(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_ERROR;
    logEntry.message = "ERROR [" + CurrentDateTimeToString() + "]: " + message;
    std::cerr << "\x18[91m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}

void Logger::Warning(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_WARNING;
    logEntry.message = "WARNING [" + CurrentDateTimeToString() + "]: " + message;
    std::cerr << "\x18[93m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}