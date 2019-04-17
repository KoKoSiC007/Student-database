//
//  functions.cpp
//  DataBase
//
//  Created by Grisha Okin on 07/03/2019.
//  Copyright © 2019 Grisha Okin. All rights reserved.
//

#include "functions.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Student.hpp"

bool isItRight(std::string chek) {
	for (int i = 0; i < chek.length(); i++){
		if (!isdigit(chek[i])) {
			return false;
		}
	}
	return true;
}

bool isItStatus(std::string chek){
	if (chek.length()==1 && (chek[0] == '1' || chek[0] == '0'))
		return true;
	return false;
}

Student addStudent(){
	std::string userConsoleInputSecondName;
	std::string userConsoleInputFirstName;
	std::string userConsoleInputPhone;
	std::string userConsoleInputRoom;
	std::string userConsoleInputStatus;
	long chekedPhone;
	int chekedRoom;
	bool chekedStatus;
	
	std::cout << "Введите имя: ";
	std::cin >> userConsoleInputFirstName;
	std::cout << "Введите фамилию: ";
	std::cin >> userConsoleInputSecondName;
	std::cout << "Введите телефон: ";
	std::cin >> userConsoleInputPhone;
	while (!isItRight(userConsoleInputPhone)) {
		std::cout << "Введено не корректное значение повторите попытку!";
		std::cout << "Введите телефон: ";
		std::cin >> userConsoleInputPhone;
	}
	chekedPhone = stol(userConsoleInputPhone);
	
	std::cout << "Введите комнату: ";
	std::cin >> userConsoleInputRoom;
	while (!isItRight(userConsoleInputRoom)) {
		std::cout << "Введено не корректное значение повторите попытку!";
		std::cout << "Введите комнату: ";
		std::cin >> userConsoleInputRoom;
		
	}
	chekedRoom = stoi(userConsoleInputRoom);
	std::cout << "Введите Статус оплаты (0 или 1)";
	std::cin >> userConsoleInputStatus;
	while (!isItStatus(userConsoleInputStatus)) {
		std::cout << "Введено не корректное значение повторите попытку!";
		std::cout << "Введите Статус оплаты (0 или 1)";
		std::cin >> userConsoleInputStatus;
	}
	chekedStatus = stoi(userConsoleInputStatus);
	return Student(userConsoleInputFirstName, userConsoleInputSecondName, chekedPhone, chekedRoom, chekedStatus);
}

std::vector<Student> consoleInput(){
	
	int studentCount;
	std::cout << "Введите количество студентов: ";
	std::cin >> studentCount;
	std::vector<Student> students;
	
	for (int i = 0; i < studentCount; i++) {
		students.push_back(addStudent());
	}
	
	//    for (int i = 0; i < students.size(); i++) {
	//        std::cout << students[i].FirstName << std::endl;
	//    }
	
	return students;
}

const std::vector<Student> readFile(const std::string fileName){
	std::ifstream inputFile = std::ifstream(fileName);
	std::vector<Student> students;
	std::vector<char> inputChars;
	
	if (!inputFile.is_open()) std::cout << "Файл не открыт.";
	
	char currentChar;
	while (inputFile.get(currentChar)) {
		if (currentChar == '\n') inputChars.push_back(' ');
		inputChars.push_back(currentChar);
		if (currentChar == '\n'){
			int index = 0;
			int spaceCounter = 0;
			std::string buffer;
			std::string firstName;
			std::string secondName;
			long phone;
			int room;
			bool isPayed;
			while (inputChars[index] != '\n') {
				auto flag = inputChars[index] == ' ';
				if (flag && spaceCounter == 0 ){
					firstName = buffer;
					spaceCounter++;
					buffer.clear();
				}
				else if (flag && spaceCounter == 1 ){
					secondName = buffer;
					spaceCounter++;
					buffer.clear();
				}
				else if (flag && spaceCounter == 2){
					phone = std::stol(buffer);
					spaceCounter++;
					buffer.clear();
				}
				else if (flag && spaceCounter == 3){
					room = std::stoi(buffer);
					spaceCounter++;
					buffer.clear();
				}
				else if (flag && spaceCounter == 4) {
					isPayed = std::stoi(buffer);
					spaceCounter++;
					buffer.clear();
				}
				buffer.push_back(inputChars[index]);
				index++;
			}
			inputChars.clear();
			students.push_back(Student(firstName, secondName, phone, room, isPayed));
		}
	}
	inputFile.close();
	//    for (int i = 0; i < students.size(); i++){
	//        std::cout << students[i].FirstName << ' ' << students[i].SecondName << ' ' << students[i].Phone << ' ' << students[i].Room << ' ' << students[i].IsPayed << std::endl;
	//    }
	std::cout << "Файл успешно считан!" << std::endl;
	return students;
}

// name: 7
//secondname: 15
//phone: 11
//room: 3
//status: 1
void consoleOutput(std::vector<Student> students){
	std::cout << "+";
	for (int i = 0; i < 51; i++) std::cout << "-";
	std::cout << "+";
	std::cout << std::endl;
	for (int i = 0; i < students.size(); i++) {
		std::cout << "| ";
		std::cout << students[i].firstName;
		for (int j = 0; j < 7-students[i].firstName.size(); j++)
			std::cout << ' ';
		
		std::cout << " | ";
		std::cout << students[i].secondName;
		for (int j = 0; j < 15 - students[i].secondName.size();j++)
			std::cout << ' ';
		std::cout << " | ";
		std::cout << students[i].phone;
		std::cout << " | ";
		std::cout << students[i].room;
		std::cout << " | ";
		std::cout << students[i].isPayed;
		std::cout << " | \n";
		std::cout << "+";
		for (int i = 0; i < 51; i++) std::cout << "-";
		std::cout << "+";
		std::cout << std::endl;
	}
	
	//    for (int i = 0; i < students.size(); i++){
	//    std::cout << students[i].firstName << ' ' << students[i].secondName << ' ' << students[i].phone << ' ' << students[i].room << ' ' << students[i].isPayed << std::endl;
	//    }
}

void writeFile(std::vector<Student> students,std::string fileName){
	std::ofstream outputFile = std::ofstream(fileName);
	for (int i = 0; i < students.size(); i++){
		outputFile << students[i].firstName << ' ' << students[i].secondName << ' ' << students[i].phone << ' ' << students[i].room << ' ' << students[i].isPayed << std::endl;
	}
	outputFile.close();
	
	std::cout << "Файл успешно записан!" << std::endl;
}

void studentShow(std::vector<Student>& students){
	for (int i = 0; i < students.size(); i++) {
		std::cout << students[i].indexIdentifire<< ' ' << students[i].firstName << ' ' << students[i].secondName << ' ' << students[i].phone << ' ' << students[i].room << ' ' << students[i].isPayed << std::endl;
	}
	
}


void delWithParam(int column,std::vector<Student> &students, std::string delstring){
	switch (column) {
		case 1:
			for (int i = 0; i < students.size(); i++) {
				if (students[i].firstName == delstring){
					students.erase(students.begin()+i);
					std::vector<Student>(students).swap(students);
					i--;
				}
			}
			break;
		case 2:
			for (int i = 0; i < students.size(); i++) {
				if (students[i].firstName == delstring){
					students.erase(students.begin()+i);
					std::vector<Student>(students).swap(students);
					i--;
				}
			}
			break;
		case 3:
			for (int i = 0; i < students.size(); i++) {
				if (students[i].phone == stol(delstring)){
					students.erase(students.begin()+i);
					std::vector<Student>(students).swap(students);
					i--;
				}
			}
			break;
		case 4:
		{
			int room = stoi(delstring);
			for (int i = 0; i < students.size(); i++) {
				if (students[i].room == room){
					students.erase(students.begin()+i);
					std::vector<Student>(students).swap(students);
					i--;
				};
			}
		}
			break;
		case 5:
			for (int i = 0; i < students.size(); i++) {
				if (students[i].isPayed == stoi(delstring)){
					students.erase(students.begin()+i);
					std::vector<Student>(students).swap(students);
					i--;
				}
			}
			break;
		default:
			break;
	}
}

void delStudent(std::vector<Student>& students){
	
	int swch;
	std::cout << "Вы хотите хотите удалить кого то конкретно или выборка по столбцам?(0 конкретно, 1 по столбцам)";
	std::cin >> swch;
	switch (swch) {
		case 0:
			studentShow(students);
			std::cout << "Какого студента вы хотите удалить?"<< std::endl;
			int userInput;
			std::cin >> userInput;
			students.erase(students.begin()+userInput-1);
			Student::studentCount--;
			std::cout << "Студент удален." << std::endl;
			indexing(students);
			studentShow(students);
			break;
		case 1:
		{
			int chooseColumn;
			std::string delItem = "";
			std::cout << "По какому столбцу вы хотите удалить?";
			std::cin >> chooseColumn;
			std::cout << "Что вы хотите удалить??";
			std::cin >> delItem;
			delWithParam(chooseColumn, students, delItem);
			indexing(students);
			studentShow(students);
		}
			break;
		default:
			break;
	}
	
}

void indexing(std::vector<Student>& students){
	for (int i = 0; i < students.size(); i++) {
		students[i].indexIdentifire = i+1;
	}
}

void searchRoom (std::vector<Student>& students, int number){
	for (int i = 0; i < students.size(); i++){
		if (students[i].room == number){
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
			std::cout << "| ";
			std::cout << students[i].firstName;
			for (int j = 0; j < 7-students[i].firstName.size(); j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].secondName;
			for (int j = 0; j < 15 - students[i].secondName.size();j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].phone;
			std::cout << " | ";
			std::cout << students[i].room;
			std::cout << " | ";
			std::cout << students[i].isPayed;
			std::cout << " | \n";
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
		}
	}
}
void searchPhone (std::vector<Student>& students, long number){
	for (int i = 0; i < students.size(); i++){
		if (students[i].phone == number){
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
			std::cout << "| ";
			std::cout << students[i].firstName;
			for (int j = 0; j < 7-students[i].firstName.size(); j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].secondName;
			for (int j = 0; j < 15 - students[i].secondName.size();j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].phone;
			std::cout << " | ";
			std::cout << students[i].room;
			std::cout << " | ";
			std::cout << students[i].isPayed;
			std::cout << " | \n";
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
		}
	}
}
void searchFirstName(std::vector<Student>& students, std::string name){
	for (int i = 0; i < students.size(); i++){
		
		if (students[i].firstName == name){
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
			std::cout << "| ";
			std::cout << students[i].firstName;
			for (int j = 0; j < 7-students[i].firstName.size(); j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].secondName;
			for (int j = 0; j < 15 - students[i].secondName.size();j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].phone;
			std::cout << " | ";
			std::cout << students[i].room;
			std::cout << " | ";
			std::cout << students[i].isPayed;
			std::cout << " | \n";
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
		}
	}
}
void searchSecondName(std::vector<Student>& students, std::string fam){
	fam = ' ' + fam;
	for (int i = 0; i < students.size(); i++){
		
		if (students[i].secondName == fam){
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
			std::cout << "| ";
			std::cout << students[i].firstName;
			for (int j = 0; j < 7-students[i].firstName.size(); j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].secondName;
			for (int j = 0; j < 15 - students[i].secondName.size();j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].phone;
			std::cout << " | ";
			std::cout << students[i].room;
			std::cout << " | ";
			std::cout << students[i].isPayed;
			std::cout << " | \n";
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
		}
	}
}
void searchStatus(std::vector<Student>& students, bool status){
	for (int i = 0; i < students.size(); i++){
		if (students[i].isPayed == status){
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
			std::cout << "| ";
			std::cout << students[i].firstName;
			for (int j = 0; j < 7-students[i].firstName.size(); j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].secondName;
			for (int j = 0; j < 15 - students[i].secondName.size();j++)
				std::cout << ' ';
			std::cout << " | ";
			std::cout << students[i].phone;
			std::cout << " | ";
			std::cout << students[i].room;
			std::cout << " | ";
			std::cout << students[i].isPayed;
			std::cout << " | \n";
			std::cout << "+";
			for (int i = 0; i < 51; i++) std::cout << "-";
			std::cout << "+";
			std::cout << std::endl;
		}
	}
}
