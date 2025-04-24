#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/utsname.h>

class SystemInfo {
public:
    static void display() {
        std::cout << "System Information\n";
        std::cout << "-----------------\n";
        
        displayKernelInfo();
        displayCPUInfo();
        displayMemoryInfo();
    }

private:
    static void displayKernelInfo() {
        struct utsname info;
        if (uname(&info) == 0) {
            std::cout << "\nKernel Information:\n";
            std::cout << "System: " << info.sysname << "\n";
            std::cout << "Release: " << info.release << "\n";
            std::cout << "Version: " << info.version << "\n";
            std::cout << "Machine: " << info.machine << "\n";
        }
    }

    static void displayCPUInfo() {
        std::ifstream cpuinfo("/proc/cpuinfo");
        if (cpuinfo.is_open()) {
            std::cout << "\nCPU Information:\n";
            std::string line;
            while (std::getline(cpuinfo, line)) {
                if (line.find("model name") != std::string::npos) {
                    std::cout << line << "\n";
                    break;
                }
            }
            cpuinfo.close();
        }
    }

    static void displayMemoryInfo() {
        std::ifstream meminfo("/proc/meminfo");
        if (meminfo.is_open()) {
            std::cout << "\nMemory Information:\n";
            std::string line;
            int count = 0;
            while (std::getline(meminfo, line) && count < 3) {
                if (line.find("MemTotal") != std::string::npos ||
                    line.find("MemFree") != std::string::npos ||
                    line.find("MemAvailable") != std::string::npos) {
                    std::cout << line << "\n";
                    count++;
                }
            }
            meminfo.close();
        }
    }
};

int main() {
    SystemInfo::display();
    return 0;
} 