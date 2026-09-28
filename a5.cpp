#include <iostream>
#include <vector>

template <typename T>
T square(T value) {
	return value * value;
}

template <typename T>
std::vector<T> square(const std::vector<T>& vec) {
	std::vector<T> result;
	result.reserve(vec.size());
	for (const auto& item : vec) {
		result.push_back(item * item);
	}
	return result;
}

int main() {
	int number;
	std::cout << "[IN]: ";
	std::cin >> number;
	std::cout << "[OUT]: " << square(number) << std::endl;

	std::vector<int> vec;
	int value;
	std::cout << "[IN]: ";
	while (std::cin >> value) {
		vec.push_back(value);
		if (std::cin.peek() == '\n') break;
	}

	std::cout << "[OUT]: ";
	auto result = square(vec);
	for (size_t i = 0; i < result.size(); i++) {
		if (i > 0) std::cout << ", ";
		std::cout << result[i];
	}
	std::cout << std::endl;

	return 0;
}
