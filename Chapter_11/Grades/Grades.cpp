#include <iostream>
#include <vector>
#include <algorithm> // std::sort
#include <string>

struct Student
{
	std::string name{};
	int grade{};
};

bool greater(const Student& a, const Student& b)
{
	return (a.grade > b.grade);
}

int main()
{
	std::cout << "How many students? ";
	int numberOfStudents{};
	std::cin >> numberOfStudents;

	std::vector<Student> students(numberOfStudents);

	for (auto& student: students)
	{
		std::cout << "Name? ";
		std::cin >> student.name;

		std::cout << "Grade? ";
		std::cin >> student.grade;
	}

	std::sort(students.begin(), students.end(), greater);

	for (const auto& student : students)
	{
		std::cout << student.name << " got a grade of " << student.grade << '\n';
	}

	return 0;
}