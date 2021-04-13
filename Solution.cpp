//
// Created by tasya on 13.04.2021.
//
#include "Solution.hpp"

#include <utility>

//функция возвращает набор или наборы курсов, необходимых для закрытия одного конкретного курса
bool Solution::Dfs(const Information &cur_info, AllCourses &cur_all_courses,
                   std::vector<AllCourses> &all_courses) {
    //рекурсивный спуск для добавления необходимых курсов
    if (!cur_info.courses.empty()) {
        for (auto req_id : cur_info.courses) {
            if (hierarchy_[req_id].courses.size() > 1) {
                for (int number_of_variants = 0;
                     number_of_variants < cur_info.courses.size(); ++number_of_variants) {
                    AllCourses copy = cur_all_courses;
                    Dfs(hierarchy_[req_id], copy, all_courses);
                }
            } else {
                int req_lvl = hierarchy_[req_id].level;
                cur_all_courses.AddCourse(req_lvl, req_id);
                Dfs(hierarchy_[req_id], cur_all_courses, all_courses);
            }
        }
    }
    all_courses.push_back(cur_all_courses);
    return true;
}

//функция возвращает все варианты набора курсов, необходимых для закрытия данных третьих и пятого
std::vector<AllCourses>
Solution::Round(int number_of_5_course, const std::vector<int> &number_of_3_course) {
    std::vector<AllCourses> result;
    AllCourses first_all_course;
    first_all_course.AddCourse(5, number_of_5_course);
    Dfs(hierarchy_[number_of_5_course], first_all_course, result);
    //заполнены все курсы для прохождения курса 5 уровня
    for (auto id_3_lvl : number_of_3_course) {
        first_all_course.AddCourse(3, id_3_lvl);
        Dfs(hierarchy_[id_3_lvl], first_all_course, result);
    }
    return result;
}

//функция выбирает наборы курсов для закрытия всех нужных курсов с минимальным числом курсов в нем
std::vector<AllCourses> Solution::ChooseMin(std::vector<AllCourses> &all_variants) {
    std::vector<int> sums(all_variants.size());
    std::vector<AllCourses> answer;
    for (int i = 0; i < sums.size(); ++i) {
        sums[i] = all_variants[i].MySize();
    }
    int min_size = 100000;
    std::vector<int> index_of_min;
    for (int sum : sums) {
        if (sum < min_size) {
            min_size = sum;
        }
    }
    for (int i = 0; i < sums.size(); ++i) {
        if (sums[i] == min_size) {
            index_of_min.push_back(i);
        }
    }

    answer.reserve(index_of_min.size());
for (auto id : index_of_min) {
        answer.push_back(all_variants[id]);
    }
    return answer;
}

//функция возвращает результат - набор курсов с максимальным количеством приорететных курсов
AllCourses
Solution::Result(const std::vector<AllCourses> &good_variants,
                 const std::vector<std::pair<int, int>> &priorities) {
    std::sort(priorities.begin(), priorities.end(), [](auto &one, auto &another) {
        return one.first < another.first;
    });

    std::vector<int> number_of_prior(good_variants.size());
    std::vector<AllCourses> answer;
    for (int i = 0; i < good_variants.size(); ++i) {
        number_of_prior[i] = good_variants[i].Number_of_priorities(priorities);
    }
    int max_number = 0;
    int index_of_best;
    for (int i = 0; i < number_of_prior.size(); ++i) {
        if (number_of_prior[i] > max_number) {
            max_number = number_of_prior[i];
            index_of_best = i;
        }
    }
    return good_variants[index_of_best];
}

Solution::Solution(std::vector<Information> hierarchy) : hierarchy_(std::move(hierarchy)){
}
