#include <vector>
#include <string>
#ifndef CAESAR_CIPHER_FUNCTIONS_H 1
#define CAESAR_CIPHER_FUNCTIONS_H
// Utility Function
void introduction();
void process_request(std::vector<int>& text_numerized, int key_value);

// Text input functions
void get_text_input(std::string& user_input);
int get_key_input();

// Conversion functions
std::vector<int> convert_to_num(std::string input_text, char alphabet_array[]);
std::string convert_to_string(std::vector<int> text_values, char alphabet_array[]);

// Encryption functions
void encrypt(std::vector<int>& plaintext_values, int key_value);
void decrypt(std::vector<int>& ciphertext_values, int key_value);
#endif // !1


