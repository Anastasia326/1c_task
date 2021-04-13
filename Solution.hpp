//
// Created by tasya on 13.04.2021.
//
#include "AllCourses.hpp"

#ifndef INC_1C_TASK_Finder_HPP
#define INC_1C_TASK_Finder_HPP
struct Information {
    int level;
    int id;
    std::string name;
    std::vector<int> courses;

};

struct Finder {
    std::vector<Information> hierarchy_;
    explicit Finder(std::vector<Information> hierarchy);
    bool Dfs(const Information &cur_info, AllCourses &cur_all_courses,
             std::vector<AllCourses> &all_courses);

    std::vector<AllCourses>
    Round(int number_of_5_course, const std::vector<int> &number_of_3_course);

    static std::vector<AllCourses> ChooseMin(std::vector<AllCourses> &all_variants);

    static AllCourses
    Result(const std::vector<AllCourses> &good_variants,
           const std::vector<std::pair<int, int>> &priorities);
};

#endif //INC_1C_TASK_Finder_HPP
