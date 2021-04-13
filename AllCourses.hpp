//
// Created by tasya on 13.04.2021.
//
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <set>

#ifndef INC_1C_TASK_ALLCOURSES_HPP
#define INC_1C_TASK_ALLCOURSES_HPP

//данный класс представляет собой набор курсов, разделенных по уровню
//это учебная траектория по факту

class AllCourses {
    std::vector<std::vector<int>> courses_level_;
public:
    AllCourses();

    void AddCourse(int lvl, int id);

    void Normalize();

    int MySize();

    int Number_of_priorities(const std::vector<std::pair<int, int>> &priorities) const;
};

#endif //INC_1C_TASK_ALLCOURSES_HPP
