#include <iostream>
#include <string>

struct MyPerson {
	std::string name;
	int age;
	std::string job;
};

void print_person(const MyPerson& MP) {
	std::cout << "Name: " << MP.name << std::endl;
	std::cout << "Age: " << MP.age << std::endl;
	std::cout << "Position: " << MP.job << std::endl;
	


}


MyPerson input_person() {
	MyPerson result;
	std::cout << "Enter name -> ";
	std::getline(std::cin, result.name);
	
	std::cout << "Enter age -> ";
	std::cin >> result.age;
	std::cin.ignore();
	
	std::cout << "Enter position ->";
	std::getline(std::cin, result.job);
	return result;
}

struct Date {
	int day = 1;
	int month = 1;
	int year = 1970;
};

struct CoinsKeeper {
	std::string name;
	Date birthday;
	int coins_number = 0;
	int* coins = nullptr;
};
void print_keeper(const CoinsKeeper& CK) {
	std::cout << "Name: "<< CK.name << std::endl;
	std::cout << "Birthday: " <<
		CK.birthday.day << '.' <<
		CK.birthday.month << '.' <<
		CK.birthday.year << std::endl;
	std::cout << "Монеты: ";
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ' ';
	std::cout << std::endl;
}

inline int age(const CoinsKeeper& CK, int year) {
	return (year - CK.birthday.year);
}
int cash(const CoinsKeeper& CK) {
	int result = 0;
	for (int i = 0;i < CK.coins_number; i++)
		result += CK.coins[i];
	return result;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	
	// Поля по умолчанию, вложенные структуры и указатели на объекты структуру
	
	struct Date {
		int day = 1;
		int month = 1;
		int year = 1970;
	};
	
	Date d1;
	std::cout << d1.day << "." << d1.month << "." << d1.year << std::endl;
	Date d2{ 20, 5, 2024 };
	std::cout << d2.day << "." << d2.month << "." << d2.year << std::endl;
	
	struct Human {
		std::string name;
		Date birthday;
		std::string job;
	};
	
	Human h1{ " Elisa Rumm,", {10, 10, 2000}, "UFC Light-Weight Champion"};
	std::cout << "Name:" << h1.name << std::endl;
	std::cout << "Birthday:" << h1.birthday.day << '.'<< h1.birthday.month<< '.'<<h1.birthday.year<< std::endl;
	std::cout << "Position:" << h1.job << std::endl;

	Human* ph = &h1;
	std::cout << ph->name << std::endl;
	std::cout << ph->birthday.day << std::endl;
	
	// Объявление структуры.
	
	struct Person {
		std::string name;
		int age;
		std::string job;
		int salary;
	}p4, p5, p6;
	
	Person p1;
	p1.name = "Tom smith";
	p1.age = 20;
	p1.job = "Wanker";
	p1.salary = 100;
	std::cout << "Name: " << p1.name << std::endl;
	std::cout << "Age: " << p1.age << std::endl;
	std::cout << "Job: " << p1.job << std::endl;
	std::cout << "Salary: " << p1.salary << std::endl;
	
	std::cout << "-------------------------------------\n";
	Person p2{"Tom the Gipsy", 40, "Boxer", 25};
	std::cout << "Name: " << p2.name << std::endl;
	std::cout << "Age: " << p2.age << std::endl;
	std::cout << "Job: " << p2.job << std::endl;
	std::cout << "Salary: " << p2.salary << std::endl;

	std::cout << "-------------------------------------\n";
	// ctrl+y;ctrl+x удалить строчку.
	Person p3 = p1;
	p3.age = 30;
	std::cout << "Name: " << p3.name << std::endl;
	std::cout << "Age: " << p3.age << std::endl;
	std::cout << "Job: " << p3.job << std::endl;
	std::cout << "Salary: " << p3.salary << std::endl;
	
	// Структуры и функции
	
	MyPerson mp1{ "Rodion Raskolnikov ", 30, "Axe enjoyer"};
	print_person(mp1);
	std::cout << "-----------------------\n";
	MyPerson mp2 = input_person();
	print_person(mp2);


	// Задача 1. Хранитель монет
	std::cout << "Задача 1.\nИнформация о хранителе:\n";
	CoinsKeeper ck{
		"Gendalf", 
		{17, 8, 1000},
		5,
		new int[5] {1, 10, 2, 2, 10}
	};
	print_keeper(ck);
	std::cout << "Keepers age " << age(ck, 2024) << std::endl;
	std::cout << "Coins summary: " << cash(ck) << std::endl;
	return 0;
}