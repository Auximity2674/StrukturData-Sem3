#include <iostream>
#include <string>
#include <cstdlib>

std::string hashPassword(const std::string& password) {
    std::string hashedPassword = "";
    for (char c : password) {
        int asciiValue = static_cast<int>(c);
        hashedPassword += std::to_string(asciiValue);
    }
    return hashedPassword;
}

int main() {
    std::string realPassword = "password123";
    std::string hashedPassword = hashPassword(realPassword);

    // Proses login
    std::string inputPassword;
    std::cout << "Masukkan password: ";
    std::cin >> inputPassword;

    std::string hashedInputPassword = hashPassword(inputPassword);

    if (hashedInputPassword == hashedPassword) {
        std::cout << "Login berhasil!" << std::endl;
    } else {
        std::cout << "Login gagal. Password salah." << std::endl;
    }

    return 0;
}