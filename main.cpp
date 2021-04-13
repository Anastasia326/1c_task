#include "Solution.hpp"
#include <fstream>

int main() {
    std::string line;
    std::ifstream in("NameOfFile.txt");
    std::vector<Information> information;
    int number_of_5_course;
    std::cin >> number_of_5_course;
    std::vector<int> number_of_3_course;
    for(int i = 0; i < 3; ++i) {
        int number;
        std::cin >> number;
        number_of_3_course.push_back(number);
    }
    int number_of_prior;
    std::cin >> number_of_prior;
    std::vector<std::pair<int, int>> priorities;
    for(int i = 0; i < number_of_prior; ++i) {
        int prior, weight;
        std::cin >> prior >> weight;
        priorities.emplace_back(prior, weight);
    }
    if(in.is_open()){
        while(getline(in, line)){
            //считываем нужную информацию, обрабатываем файл
        }
    }
    Finder solution = Finder(information);
    std::vector<AllCourses> all_variants = solution.Round(number_of_5_course, number_of_3_course);
    std::vector<AllCourses> min_var = solution.ChooseMin(all_variants);
    AllCourses result = solution.Result(min_var, priorities);
    //в AllCourses лежит, по сути, ответ
    //дальше надо будет только по id определить названия курса и посмотреть какой курс когда закрывать
    //так же надо сделать метод в AllCourses, который будет проверять размер на то, что он больше 9
    //и если он меньше, то запускать рандомайзер по добавлению курсов 1го уровня :)
    in.close();
}
