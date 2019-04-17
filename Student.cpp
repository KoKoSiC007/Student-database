//
//  Student.cpp
//  DataBase
//
//  Created by Grisha Okin on 04/03/2019.
//  Copyright © 2019 Grisha Okin. All rights reserved.
//

#include "Student.hpp"
#include <iostream>

Student::Student(){}
int Student::studentCount = 0;

Student::Student(std::string firstName, std::string secondName, long Phone=NULL, int Room=NULL, bool IsPayed=NULL){
    this->identifire = ++studentCount;
    this->indexIdentifire = this->identifire;
    this->firstName = firstName;
    this->secondName = secondName;
    this->phone = Phone;
    this->room = Room;
    this->isPayed = IsPayed;
}

bool Student::FirstName::operator()(Student a1, Student a2){
    return a1.firstName < a2.firstName;
}

bool Student::SecondName::operator()(Student a1, Student a2){
    return a1.secondName < a2.secondName;
}

bool Student::Phone::operator()(Student a1, Student a2){
    return a1.phone < a2.phone;
}

bool Student::Room::operator()(Student a1, Student a2){
    return a1.room < a2.room;
}

bool Student::Status::operator()(Student a1, Student a2){
    return a1.isPayed < a2.isPayed;
}
bool Student::NormalView::operator()(Student a1, Student a2){
    return a1.identifire < a2.identifire;
}
