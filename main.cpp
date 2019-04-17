//
//  main.cpp
//  DataBase
//
//  Created by Grisha Okin on 04/03/2019.
//  Copyright © 2019 Grisha Okin. All rights reserved.
//

#include <iostream>
#include "functions.hpp"
#include <algorithm>
// ---------------------------------
// | Name | Phone | Room | IsPayed |
//----------------------------------
using namespace std;
int main(int argc, const char * argv[]) {
    
	string statuss = "0";
	cout << statuss.length();
    string name;
    string fam;
    long phone;
    bool status;
    int room;
    vector<Student> allStudents;
    Student newStudent;
    bool flag = true;
    
    cout << "Если вы хотите ввести новую базу нажмите 1."<<endl;
    cout << "Если вы хотите вывести базу данных нажмите 2."<<endl;
    cout << "Если вы хотите добавить студента в базу нажмите 3."<<endl;
    cout << "Если вы хотите выполнить поиск нажмите 4."<<endl;
    cout << "Если вы хотите удалить что то из базы нажмите 5."<<endl;
    cout << "Если вы хотите выполнить сортировку базы данных нажмите 6."<<endl;
    cout << "Если вы хотите выйти нажмите 7."<<endl;
    int userInput;
    int inputValue;
    while (flag) {
		cin >> userInput;
        switch (userInput) {
            case 1:
                
                cout << "Считать фаил из файла или из консоли? 1 - из файла, 2 - из консоли." << endl;
                cin >> inputValue;
                switch (inputValue) {
                    case 1:
                        allStudents = readFile("/Users/kokos/Documents/Prog/Semestr2/DataBase/DataBase/DataBase.txt");
                        break;
                    case 2:
                         allStudents = consoleInput();
                        break;
                    default:
                        cout << "Something was wrong. Try to input 1 or 2" << endl;
                        break;
                }
                break;
                
            case 2:
                
                cout << "Вывести в файл или в консоль? 1 - в файла, 2 - в консоли." << endl;
                cin >> inputValue;
                switch (inputValue) {
                    case 1:
                        writeFile(allStudents, "/Users/kokos/Documents/Prog/Semestr2/DataBase/DataBase/Output.txt");
                        break;
                    case 2:
                        consoleOutput(allStudents);
                        break;
                    default:
                        cout << "Something was wrong. Try to input 1 or 2" << endl;
                        break;
                }
                break;
                
            case 3:

                newStudent = addStudent();
                allStudents.push_back(newStudent);
                
                break;
            case 4:
                
                int userInput;
                cout << "По какому столбцу вы хотите искать?\n";
                cout << "По имени: 1\n";
                cout << "По фамилии: 2\n";
                cout << "По номеру телефона: 3\n";
                cout << "По комнате: 4\n";
				cout << "По статусу оплаты: 5\n";
                
                cin >> userInput;
                switch (userInput) {
                    case 1:
                        cout << "Введите имя: ";
                        cin >> name;
                        searchFirstName(allStudents, name);
                        break;
                    case 2:
                        cout << "Введите Фамилию: ";
                        cin >> fam;
                        searchSecondName(allStudents, fam);
                        break;
                    case 3:
                        cout << "Введите номер телефона: ";
                        cin >> phone;
                        searchPhone(allStudents, phone);
                        break;
                    case 4:
                        cout << "Введите комнату: ";
                        cin >> room;
                        searchRoom(allStudents, room);
                        break;
                    case 5:
                        cout << "Введите статус оплаты, оплачено(1) или не оплачено(0): ";
                        cin >> status;
                        searchStatus(allStudents, status);
                        break;
                    default: cout << "Something was wrong\n";
                        break;
                }
                
                break;
            case 5:
                
                delStudent(allStudents);
                
                break;
            case 6:
                
                cout << "По какому столбцу вы хотите отсортировать?\n";
                cout << "По имени: 1\n";
                cout << "По фамилии: 2\n";
                cout << "По номеру телефона: 3\n";
                cout << "По комнате: 4\n";
                cout << "По статусу оплаты: 5\n";
                cout << "Вернуть все как было: 6\n";
                
                cin >> userInput;
                
                switch (userInput) {
                    case 1:
                        sort(allStudents.begin(), allStudents.end(), Student::FirstName());
                        break;
                    case 2:
                        sort(allStudents.begin(),allStudents.end(), Student::SecondName());
                        break;
                    case 3:
                        sort(allStudents.begin(),allStudents.end(), Student::Phone());
                        break;
                    case 4:
                        sort(allStudents.begin(),allStudents.end(), Student::Room());
                        break;
                    case 5:
                        sort(allStudents.begin(),allStudents.end(), Student::Status());
                        break;
                    case 6:
                        sort(allStudents.begin(), allStudents.end(), Student::NormalView());
                        break;
                    default: sort(allStudents.begin(),allStudents.end(), Student::FirstName());
                        break;
                }
                
                break;
            case 7:
                flag = false;
                break;
        default: cout << "Something was wrong" << endl;
        break;
        }
    }
    
    return 0;
}




//sort(allStudents.begin(), allStudents.end(), Name())
