// Main Function for the Caesars Cipher;
// User will be able to encode or decode any string as long as they have the key;
#include "functions.h"
#include <iostream>
#include <map>
#include <string>

int main() {
	//Initialize the alphabet
	char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	//Variables for input string and key
	std::string input_string;
	int key;
	//Variable for output_strings & vectors
	std::vector<int> text_values;
	//Get string and key input
	introduction();
	get_text_input(input_string);
	key = get_key_input();

	//Converts input to its numerical value
	text_values = convert_to_num(input_string, alphabet);

	//User decides to encrypt of decrypt text
	process_request(text_values, key);

	//Modified string is returned and printed
	std::cout << convert_to_string(text_values, alphabet) << "\n";


	std::cout << "Thank you for using this implementation of the Caesar Cipher.\n";
}





