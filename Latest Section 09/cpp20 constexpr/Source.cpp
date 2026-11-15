#include <iostream>
#include <format>
#include <vector>
constexpr double Divide(double a, double b) {
	try {
		if (b == 0) {
			throw std::runtime_error{ "Divide by 0" };
		}
		return a / b;
	} catch (const std::runtime_error& ex) {
		std::cout << "Exception\n";
	}
	return 0;
}

constexpr int Sum(int size) {
	//int data[size] ;
	int *data = new int[size]{};
	for (int i = 0 ; i < size; ++i) {
		data[i] = i+1;
	}
	auto sum = data[0] + data[size/2] + data[size-1] ;
	delete []data;
	return sum ;
}
constexpr int Sum2(int size) {
	//int data[size] ;
	std::vector<int> data;
	for (int i = 0 ; i < size; ++i) {
		data.push_back(i+1);
	}
	auto sum = data[0] + data[size/2] + data[size-1] ;
	//delete []data;
	return sum ;
}

class Animal {
public:
	constexpr virtual const char* GetName() const {
		return "Animal";
	}
};

class Mammal : public Animal {
public:
	constexpr const char* GetName() const override {
		return "Mammal";
	}
};

class Dog : public Mammal {
public:
	constexpr const char* GetName() const override {
		return "Dog";
	}
};

constexpr const char* GetAnimalName(const Animal& animal) {
	return animal.GetName();
}

int main() {
	auto result = Divide(5, 3);
	std::cout << "Result:" << result << '\n';

	auto sumofthree = Sum2(10) ;
	std::cout << std::format("Sum of three:{}\n", sumofthree) ;

	Dog dog{} ;
	auto name = GetAnimalName(dog) ;
	std::cout << name << '\n' ;
}