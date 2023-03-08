#include "Logger.hh"

int main(int argc, char *args[]) {
    Logger::Info("Testing an info message.");
    Logger::Error("Testing an error message");
    Logger::Warning("Testing a warning message");

    return 0;
}

