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
        _dorm->residents_num++;
        student.dorm = _dorm;
    }

    return student;
}


struct student_t move_student(struct student_t _student, struct dorm_t *_dorm) {
    struct student_t student;
    student = _student;
    // Perbandingan penghuni dan kapasitas
    if (student.dorm == NULL) {
        student.dorm = _dorm;
    } else if (_dorm->residents_num < _dorm->capacity) {
        student.dorm->residents_num--;
        student.dorm = _dorm;
    }

    return student;
}


struct student_t leave_student(struct student_t *_student, struct dorm_t *_dorm, int _index, int _indexstu) {
    for (int i = 0 ; i < _indexstu; i++) {
        if (i == _index) {
            strcpy(_student[i].dormName, "left");
        }
    }
    return _student[_index];
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
        printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, _gender);
        fflush(stdout);
    }
}

void print_student_detail(struct student_t *_student, int _index) {
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
            printf("%s|%s|%s|%s|unassigned\n", _student[i].id, _student[i].name, _student[i].year, _gender);
        } else if (strcmp(_student[i].dormName, "left") == 0) {
            printf("%s|%s|%s|%s|left\n", _student[i].id, _student[i].name, _student[i].year, _gender);
        } else {
            printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, _gender,  _student[i].dorm->name);
        }
        fflush(stdout);
    }
}