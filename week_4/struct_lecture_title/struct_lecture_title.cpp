#include <iostream>
#include <string>

struct Specialization {
  std::string value;
  explicit Specialization(std::string new_val) {
    value = new_val;
  }
};
struct Course {
  std::string value;
  explicit Course(std::string new_val) {
    value = new_val;
  }
};
struct Week {
  std::string value;
  explicit Week(std::string new_val) {
    value = new_val;
  }
};
struct LectureTitle {
  std::string specialization;
  std::string course;
  std::string week;
  LectureTitle(Specialization new_s, Course new_c, Week new_w) {
    specialization = new_s.value;
    course = new_c.value;
    week = new_w.value;
  }
};
void PrintStruct(const LectureTitle& title) {
  std::cout << title.specialization << " " << title.course << " " << title.week
            << std::endl;
}

int main() {
  LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th"));
  PrintStruct(title);
  return 0;
}
