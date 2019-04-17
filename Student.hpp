//
//  Student.hpp
//  DataBase
//
//  Created by Grisha Okin on 04/03/2019.
//  Copyright © 2019 Grisha Okin. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
struct Student {
    static int studentCount;
    int identifire;
    int indexIdentifire;
    std::string firstName;
    std::string secondName;
    long phone;
    int room;
    bool isPayed;
    bool operator()(Student, Student);
    
    struct FirstName{
        bool operator()(Student, Student);
    };
    struct SecondName{
        bool operator()(Student, Student);
    };
    struct Phone{
        bool operator()(Student, Student);
    };
    struct Room{
        bool operator()(Student, Student);
    };
    struct Status{
        bool operator()(Student, Student);
    };
    struct NormalView{
        bool operator()(Student, Student);
    };
    
    Student();
    Student(std::string, std::string, long, int, bool);
};
#endif /* Student_hpp */
