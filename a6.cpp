#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class table {
public:
	table(int rows, int cols) {
		if (rows <= 0 || cols <= 0) {
			throw std::invalid_argument("Некорректные размеры таблицы");
		}
		m_rows = rows;
		m_cols = cols;
		m_data.resize(rows, std::vector<T>(cols));
	}

	std::vector<T>& operator[](int row) {
		if (row < 0 || row >= m_rows) {
			throw std::out_of_range("Индекс строки вне диапазона");
		}
		return m_data[row];
	}

	const std::vector<T>& operator[](int row) const {
		if (row < 0 || row >= m_rows) {
			throw std::out_of_range("Индекс строки вне диапазона");
		}
		return m_data[row];
	}

	std::pair<int, int> Size() const {
		return { m_rows, m_cols };
	}

private:
	std::vector<std::vector<T>> m_data;
	int m_rows;
	int m_cols;
};

int main() {
	auto test = table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0] << std::endl;

	test[1][2] = 42;
	std::cout << test[1][2] << std::endl;

	auto size = test.Size();
	std::cout << size.first << "x" << size.second << std::endl;

	const auto& const_test = test;
	std::cout << const_test[0][0] << std::endl;

	return 0;
}

