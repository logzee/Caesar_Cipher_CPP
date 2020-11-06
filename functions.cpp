#include "functions.h"
#include <iostream>
#include <string>

//Utility
void introduction() {
	// Introduces the programs functionality
	std::cout << "Caesar Cipher Encryption\n";
	std::cout << "This program will let you encrypt any text that you wish using the Caesar Cipher.\n" 
		"It will also allow you to decrypt information encrypted with the Caesar Cipher.\n\n";
}

void process_request(std::vector<int> &text_values, int key_value) {
	// Allows the user to choose to either encode or decode their input text
	std::cout << "Do you need to encode, or decode this message?\n";
	std::cout << "1) Encode\n";
	std::cout << "2) Decode\n";
	int choice;
	std::cin >> choice;
	while (choice != 0) {
		if (choice == 1) {
			std::cout << "Encoding...\n";
			encrypt(text_values, key_value);
			choice = 0;
		}
		else if (choice == 2) {
			std::cout << "Decoding...\n";
			choice = 0;
			decrypt(text_values, key_value);
		}
		else {
			std::cout << "please select either option 1 or 2:\n";
			std::cout << "1) Encode\n";
			std::cout << "2) Decode\n";
			std::cin >> choice;
		}
	}
}

// User Input
void get_text_input(std::string &user_string_ref) {
	std::cout << "Enter your text to be encrypted or decrypted: ";
	std::getline(std::cin, user_string_ref);
	std::cout << "\n";
}

int get_key_input() {
	int key;
	std::cout << "Enter your key: ";
	std::cin >> key;
	std::cout << "\n";
	// Validates the Key input
	if (key > -26 && key < 26) {
		return key;
	}
	else {
		std::cout << "Key is invalid, must be an integer between -25 & 25\n";
		get_key_input();
	}
	return 0;
}

// Conversions
std::vector<int> convert_to_num(std::string input_text, char alphabet_array[]) {
	//Converts the characters of a string into their numerical equivilents
	std::vector<int> text_values;
	bool letter_found = false;
	for (char c : input_text) {
		for (int i{ 0 }; i < 26; i++) {
			if (tolower(c) == alphabet_array[i]) {
				text_values.push_back(i);
				letter_found = true;
				break;
			}
			else {
				letter_found = false;
				continue;
			}
		}
		if (letter_found == false) {
			text_values.push_back(-1);
		}
	}
	return text_values;
}

std::string convert_to_string(std::vector<int> text_values, char alphabet_array[]) {
	// Converts integer representations of a string back into characters based on the alphabet array
	std::string reconstructed_text = "";
	for (int char_value : text_values) {
		for (int i{ 0 }; i < 26; i++) {
			if (char_value == -1) {
				reconstructed_text += " ";
				break;
			}
			else if (char_value == i) {
				reconstructed_text += alphabet_array[i];
				break;
			}
		}
	}

	return reconstructed_text;
}



// Cipher Functions
void encrypt(std::vector<int>& plaintext_values, int key_value) {
	for (int &char_val : plaintext_values) {
		if (char_val != -1) {
			char_val += key_value;

			if (char_val > 25) {
				char_val -= 26;
			}
			else if (char_val < 0) {
				char_val += 26;
			}
		}
	}
}

void decrypt(std::vector<int>& ciphertext_values, int key_value) {
	for (int& char_val : ciphertext_values) {
		if (char_val != -1) {
			char_val -= key_value;

			if (char_val > 25) {
				char_val -= 26;
			}
			else if (char_val < 0) {
				char_val += 26;
			}
		}
	}
}