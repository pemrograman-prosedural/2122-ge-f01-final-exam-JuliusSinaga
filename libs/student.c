#include "student.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender) {
    struct student_t student;
    // Memindahkan nilai parameter
    strcpy(student.id, _id);
    strcpy(student.name, _name);
    strcpy(student.year, _year);
    student.gender = _gender;
    student.dorm = NULL;

    return student;
}


struct student_t assign_student(struct student_t _student, struct dorm_t *_dorm) {
    struct student_t student;
    student = _student;
    // Perbandingan penghuni dan kapasitas
    if (_dorm->residents_num < _dorm->capacity) {
        student.dorm = &_dorm;
    }

    return student;
}


struct student_t move_student(struct student_t _student, struct dorm_t *_dorm) {
    struct student_t student;
    student = _student;
    // Perbandingan penghuni dan kapasitas
    if (student.dorm == NULL) {
        student.dorm = &_dorm;
    } else if (_dorm->residents_num < _dorm->capacity) {
        student.dorm->residents_num--;
        student.dorm = &_dorm;
    }

    return student;
}


struct student_t leave_student(struct student_t _student, struct dorm_t _dorm) {
    struct student_t student;
    student = _student;
    if (student.dorm == NULL) {
        strcpy(student.dorm->name, "left");
    } else {
        student.dorm->residents_num--;
        strcpy(student.dorm->name, "left");
    }

    return student;
}

void print_student(struct student_t *_student, int _index) {
    // Untuk nilai string gender
    char *_gender;
    // Untuk Output
    for (int i = 0; i < _index; i++) {
        // Perbandingan untuk nilai string gender
        if (_student[i].gender == GENDER_MALE) {
            _gender = "male";
        } else {
            _gender = "female";
        }
        printf("%s|%s|%s|%s", _student[i].id, _student[i].name, _student[i].year, _gender);
    }
}

void print_student(struct student_t *_student, int _index) {
        // Untuk nilai string gender
    char *_gender;
    // Untuk Output
    for (int i = 0; i < _index; i++) {
        // Perbandingan untuk nilai string gender
        if (_student[i].gender == GENDER_MALE) {
            _gender = "male";
        } else {
            _gender = "female";
        }
        // Memeriksa nilai asrama
        if (_student[i].dorm == NULL) {
            printf("%s|%s|%s|%s|unassigned", _student[i].id, _student[i].name, _student[i].year, _gender);
        } else {
            printf("%s|%s|%s|%s|%s", _student[i].id, _student[i].name, _student[i].year, _gender,  _student[i].dorm->name);
        }
    }
}