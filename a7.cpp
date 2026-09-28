#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

class Counter {
public:
	Counter() : m_sum(0), m_count(0) {}

	void operator()(int value) {
		if (value % 3 == 0) {
			m_sum += value;
			m_count++;
		}
	}

	int get_sum() const { return m_sum; }
	int get_count() const { return m_count; }

private:
	int m_sum;
	int m_count;
};

int main() {
	std::string line;
	std::getline(std::cin, line);

	std::istringstream iss(line);
	std::vector<int> numbers;
	int value;
	while (iss >> value) {
		numbers.push_back(value);
	}

	Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());

	std::cout << "get_sum() = " << counter.get_sum() << std::endl;
	std::cout << "get_count() = " << counter.get_count() << std::endl;

	return 0;
}
