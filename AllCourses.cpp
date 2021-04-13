//
// Created by tasya on 13.04.2021.
//
#include "AllCourses.hpp"

AllCourses::AllCourses() {
    courses_level_.resize(6);
}

//нормализация курсов по уровням и удаление дублирующихся
void AllCourses::Normalize() {
    for (auto & i : courses_level_) {
        std::set<int> unique_id;
        for (auto id : i) {
            unique_id.insert(id);
        }
        i.clear();
        for (auto id : unique_id) {
            i.push_back(id);
        }
    }
}

//добавляет курс в набор курсов
void AllCourses::AddCourse(int lvl, int id) {
    if (lvl < 0 || lvl > 5) {
        std::cout << "wrong level\n";
        return;
    } else {
        courses_level_[lvl].push_back(id);
    }
}

//считает количество курсов в данном варианте набора курсов
int AllCourses::MySize() {
    Normalize();
    int res = 0;
    for (int i = 0; i < courses_level_.size(); ++i) {
        res += courses_level_[i].size();
    }
    return res;
}

//считает количество приорететных курсов(а так же уровень их приоритета) в данном наборе
int AllCourses::Number_of_priorities(const std::vector<std::pair<int, int>> &priorities) const {
    int result = 0;
    for (auto prior : priorities) {
        int i = 0;
        //считаем только на втором уровне
        while (courses_level_[1][i] < prior.first) {
            //небольшая оптимизация, ведь всё отсортированное по индексу курса
            if (courses_level_[1][i] == prior.first) {
                result += prior.second;
                break;
            }
        }
    }
    return result;
}

