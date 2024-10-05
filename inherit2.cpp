#include <iostream>
#include <string>

class Computer {
    protected:
        std::string cpu_model;
        std::string gpu_model;
        int ram_memory;
    public:
        Computer(const std::string& cpu_model, const std::string& gpu_model, const int ram_memory) : cpu_model(cpu_model), gpu_model(gpu_model), ram_memory(ram_memory) {} 
        virtual void getInfo() {
            std::cout << "CPU: " << cpu_model << std::endl;
            std::cout << "GPU: " << gpu_model << std::endl;
            std::cout << "RAM: " << ram_memory << "GB" << std::endl;
        }
};

class Laptop: public Computer {
    private:
        std::string operation_system;
        std::string block_device;
        int block_memory;
        int block_energy;
    public:
        Laptop(const std::string& cpu_model, const std::string& gpu_model, const int ram_memory,
               std::string operation_system, std::string block_device, int block_memory, int block_energy) : Computer(cpu_model, gpu_model, ram_memory), operation_system(operation_system),
                                                                                                             block_device(block_device), block_memory(block_memory), block_energy(block_energy) {}
        void getInfo() override {
            Computer::getInfo();
            
            std::cout << "OS: " << operation_system << std::endl;
            std::cout << "Block: " << block_device << " " << block_memory << "GB" << std::endl;
            std::cout << "Power: " << block_energy << "W" << std::endl;
        }
};

class PersonalPC: public Computer {
    private:
        std::string operation_system;
        std::string block_device;
        int block_memory;
        int block_energy;
    public:
        PersonalPC(const std::string& cpu_model, const std::string& gpu_model, const int ram_memory,
               std::string operation_system, std::string block_device, int block_memory, int block_energy) : Computer(cpu_model, gpu_model, ram_memory), operation_system(operation_system),
                                                                                                             block_device(block_device), block_memory(block_memory), block_energy(block_energy) {}
        void getInfo() override {
            Computer::getInfo();
            
            std::cout << "OS: " << operation_system << std::endl;
            std::cout << "Block: " << block_device << " " << block_memory << "GB" << std::endl;
            std::cout << "Power: " << block_energy << "W" << std::endl;
        }
};

int main() {
    PersonalPC pc("i7 14700", "Nvidia RTX 4070", 32, "Windows", "SSD", 800, 650);
    Laptop Laptop("i7 14700", "Nvidia RTX 3070", 16, "Linux", "HDD", 800, 550);

    pc.getInfo();
    std::cout << std::endl;
    Laptop.getInfo();

    return 0;
}
