#include "dorm.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender) {
    struct dorm_t dorm;
    // Memindahkan nilai
    strcpy(dorm.name, _name);
    dorm.capacity = _capacity;
    dorm.gender = _gender;
    dorm.residents_num = 0;

    return dorm;
}

void print_dorm(struct dorm_t *_dorm, int _index) {
    // Untuk nilai string gender
    char *_gender;
    // Untuk Output
    for (int i = 0; i < _index; i++) {
        // Perbandingan untuk nilai string gender
        if (_dorm[i].gender == GENDER_MALE) {
            _gender = "male";
        } else {
            _gender = "female";
        }
        printf("%s|%d|%s\n", _dorm[i].name, _dorm[i].capacity, _gender);
    }
}

void print_dorm_detail(struct dorm_t *_dorm, int _index) {
    // Untuk nilai string gender
    char *_gender;
    // Untuk Output
    for (int i = 0; i < _index; i++) {
        // Perbandingan untuk nilai string gender
        if (_dorm[i].gender == GENDER_MALE) {
            _gender = "male";
        } else {
            _gender = "female";
        }
        printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity, _gender, _dorm[i].residents_num);
    }
}