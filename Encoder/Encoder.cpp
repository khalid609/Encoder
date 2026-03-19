#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Example shellcode (replace with your actual shellcode)
unsigned char shellcode[] = {
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    // Add your shellcode bytes here
};

void XOR(const std::string& key, unsigned char* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        data[i] ^= key[i % key.length()];
    }
}

int main() {
    std::string key = "mysecretkey"; // Replace with your XOR key

    // Encode the shellcode
    XOR(key, shellcode, sizeof(shellcode));

    // Write the encoded shellcode to a file
    std::ofstream output("encoded_shellcode.h");
    if (!output.is_open()) {
        std::cerr << "[-] Failed to open output file." << std::endl;
        return 1;
    }

    output << "unsigned char shellcode[] = { ";
    for (size_t i = 0; i < sizeof(shellcode); i++) {
        output << "0x" << std::hex << (int)shellcode[i];
        if (i < sizeof(shellcode) - 1) {
            output << ", ";
        }
    }
    output << " };" << std::endl;

    output.close();
    std::cout << "[+] Encoded shellcode written to encoded_shellcode.h" << std::endl;

    return 0;
}
