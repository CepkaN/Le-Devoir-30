#include<iostream>
#include<fstream>
#include<string>

bool overwrite(std::string put, std::string stroka);
int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Задача 1.\n";
	std::ofstream out;
	out.open("text.txt", std::ios::app);
	if (out.is_open()) {
		std::string input;
		do {
			std::cout << "Введите строку :";
			std::getline(std::cin, input);
			out << input << "\n";
		} while (input != "end");
		out.close();
	}
	else
		std::cout << "Ошибка открытия файла.\n";
	std::ifstream in;
	in.open("text.txt");
	if (in.is_open()) {
		std::string str;
		while (std::getline(in, str))
			std::cout << str << "\n";
	}
	else
		std::cout << "Ошибка открытия файла.\n";
	in.close();
	remove("text.txt");
	std::cout << "\nЗадача 2.\n";
	std::string file;
	std::string str;
	std::cout << "Введите путь к файлу : \n";
	std::getline(std::cin, file);
	std::cout << "Введите строку : \n";
	std::getline(std::cin, str);
	if (overwrite(file, str)) 
		std::cout << "Всё выполнено!\n";
	else
		std::cout<<"Ошибка!\n";



	return 0;
}
bool overwrite(std::string put, std::string stroka) {
	std::ofstream f;
	f.open(put);
	if (f.is_open()) {
		f << stroka << "\n";
		f.close();
	}
	else
		return false;
	std::ifstream fi(put); 
	std::string line;
	if (fi.is_open())
		while (getline(fi, line))
			std::cout <<"Ваша строка : "<< line << std::endl;
	else
		return false;
	fi.close();
	return true;
}
