//
//  functions.hpp
//  DataBase
//
//  Created by Grisha Okin on 07/03/2019.
//  Copyright © 2019 Grisha Okin. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <vector>
#include "Student.hpp"

bool isItRight(std::string chek);
bool isItStatus(std::string chek);
std::vector<Student> consoleInput();
const std::vector<Student> readFile (const std::string);
void consoleOutput(std::vector<Student>);
void writeFile (std::vector<Student>,std::string);
Student addStudent();
void delStudent(std::vector<Student>&);
void studentShow(std::vector<Student>&);
void indexing(std::vector<Student>&);
void operator <(Student, Student);
void searchRoom(std::vector<Student>&, int);
void searchPhone(std::vector<Student>&, long);
void searchFirstName(std::vector<Student>&, std::string);
void searchSecondName(std::vector<Student>&, std::string);
void searchStatus(std::vector<Student>&, bool);
#endif /* functions_hpp */
