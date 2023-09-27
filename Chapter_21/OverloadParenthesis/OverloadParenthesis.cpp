#include <iostream>
#include <string>
#include <cassert>

class MyString
{
private:
	std::string m_string{};

public:
	MyString(const std::string& string = {}) : m_string{ string } {}
	MyString operator()(int index, int length);
	friend std::ostream& operator<< (std::ostream& out, const MyString& string);
};

MyString MyString::operator()(int index, int length)
{
	assert(index >= 0);
	assert(index + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range");

	return m_string.substr(
		static_cast<std::string::size_type>(index),
		static_cast<std::string::size_type>(length)
	);
}

std::ostream& operator<< (std::ostream& out, const MyString& string)
{
	out << string.m_string;
	return out;
}

int main()
{
	MyString s{ "Hello, world!" };
	std::cout << s(7, 5) << '\n';

	return 0;
}