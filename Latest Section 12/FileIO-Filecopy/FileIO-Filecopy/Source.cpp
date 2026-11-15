/*
Created by Umar Lone
Note:Use this code at your own risk.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <experimental\filesystem>
void Copy(
	const std::experimental::filesystem::path & source,
	const std::experimental::filesystem::path &destination) {

	using namespace std::experimental::filesystem;

	std::ifstream input(source, std::ios::in | std::ios::binary);
	if (!input) {
		throw std::runtime_error("Could not open the source file");
	}
	std::ofstream output(destination, std::ios::out | std::ios::binary);
	if (!output) {
		throw std::runtime_error("Could not open the destination file");
	}
	auto fileSize = file_size(source);
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE]{};
	std::cout << "Copying " << source;
	if (fileSize < BUFFER_SIZE) {
		//Source file is small, so read completely and write into target
		if (!input.read(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during read operation");
		}
		if (!output.write(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during write operation");
		}
	}
	else {
		//Split the file into chunks
		auto chunks = fileSize / BUFFER_SIZE;
		int remaining = fileSize % BUFFER_SIZE;
		int progress{}, oldProgress{};
		for (int i = 0; i < chunks; i++) {
			if (!input.read(buffer, BUFFER_SIZE)) {
				throw std::runtime_error("Error occurred during read operation");
			}
			if (!output.write(buffer, BUFFER_SIZE)) {
				throw std::runtime_error("Error occurred during write operation");
			}
			/*
			 * Get progress from 0 to 10 and print .s
			 * 
			 * I'm calculating the percentage of the 
			 * chunks copied. However, I multiply it by 
			 * 10 to ensure its value is greater than 0 
			 * and I can compare it with its old value
			 * later. Conversion to integer is necessary 
			 * because we cannot compare two float 
			 * values precisely. If the old and new 
			 * values of percentage are different, 
			 * then we print the period on the screen.
			 */
			progress = static_cast<int>((10 * static_cast<float>(i) / chunks));
			if(progress != oldProgress)
				std::cout << ".";
			oldProgress = progress;
		}
		/*
		The next read operation will read less than BUFFER_SIZE & the buffer may
		contain leftover characters from the last read operation.
		Therefore, zero out the buffer.
		*/
		memset(buffer, '\0', BUFFER_SIZE);

		//Read and write the remaining bytes
		if (remaining > 0) {
			if (!input.read(buffer, remaining)) {
				throw std::runtime_error("Error occurred during read operation");
			}
			if (!output.write(buffer, remaining)) {
				throw std::runtime_error("Error occurred during write operation");
			}
			std::cout << ".";
		}
	}
	std::cout << " Done!" << std::endl;
	input.close();
	output.close();

}
void BinaryFileCopy() {
	using namespace std::experimental::filesystem;
	path source(R"(e:/Downloads/SummerFreebieProducts.zip)");
	path dest(current_path());
	dest /= "Products.zip";
	Copy(source, dest);
}


void TextFileCopy() {
	using namespace std::experimental::filesystem;
	path source(current_path());
	source /= "Source.cpp";
	path dest(current_path());
	dest /= "Copy.cpp";

	std::ifstream input{ source };
	if (!input) {
		std::cout << "Source file not found" << std::endl;
		return ;
	}
	std::ofstream output{ dest };

	std::string line;
	/*
	getline returns input (ifstream). The while condition checks for failbit
	through the overloaded bool operator of ifstream. When it fails to read 
	any more lines, it sets the fail bit & the bool operator return false for !failbit().
	*/
	while (std::getline(input, line)) {
		output << line << std::endl;
	}
	input.close();
	output.close();
}
int main() {
	TextFileCopy();
	/*BinaryFileCopy();*/
	return 0;
}
//Comment