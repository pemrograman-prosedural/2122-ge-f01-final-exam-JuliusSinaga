// 12S23035 - Julius Kaisar Bona Theo Sinaga
// 12S23044 - Gracia Pardede

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/gender.h"
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    // Alokasi memory
    struct student_t *student = malloc(12 * sizeof(struct student_t));
    struct dorm_t *dorm = malloc(12 * sizeof(struct dorm_t));

    // Deklarasi Variabel
    char line[100], name[40], id[12], year[5];
    unsigned short capacity;
    int indexStudent = 0, indexDorm = 0;
    enum gender_t gender;

    // Deklarasi temp
    char *temp;

    while (1) {     
        fgets(line, 100, stdin);
        line[strcspn(line, "\n")] = 0;  // Remove line
        if (strcmp(line, "---") == 0) {
            break;
        } else if (strcmp(line, "dorm-print-all-detail") == 0) {
            print_dorm_detail(dorm, indexDorm);
        } else if (strcmp(line, "dorm-print-all") == 0) {
            print_dorm(dorm, indexDorm);
        } else if (strcmp(line, "student-print-all-detail") == 0) {
            print_student_detail(student, indexStudent);
        } else if (strcmp(line, "student-print-all") == 0) {
            print_student(student, indexStudent);
        } else {
            temp = strtok(line, "#");
            if (strcmp(temp, "dorm-add") == 0) {
                temp = strtok(NULL, "#");
                strcpy(name, temp);
                temp = strtok(NULL, "#");
                capacity = atoi(temp);
                temp = strtok(NULL, "#");
                // melakukan perbandingan untuk nilai enum
                if (strcmp(temp, "male") == 0) {
                    gender = GENDER_MALE;
                } else {
                    gender = GENDER_FEMALE;
                }
                // Memanggil fungsi
                dorm[indexDorm] = create_dorm(name, capacity, gender);
                // Index bertambah
                indexDorm++;
            } else if (strcmp(temp, "student-add") == 0) {
                temp = strtok(NULL, "#");
                strcpy(id, temp);
                temp = strtok(NULL, "#");
                strcpy(name, temp);
                temp = strtok(NULL, "#");
                strcpy(year, temp);
                temp = strtok(NULL, "#");
                // melakukan perbandingan untuk nilai enum
                if (strcmp(temp, "male") == 0) {
                    gender = GENDER_MALE;
                } else {
                    gender = GENDER_FEMALE;
                }
                // Memanggil fungsi
                student[indexStudent] = create_student(id, name, year, gender);
                // Index bertambah
                indexStudent++;
            } else if (strcmp(temp, "assign-student") == 0) {
                temp = strtok(NULL, "#");
                strcpy(id, temp);
                temp = strtok(NULL, "#");
                strcpy(name, temp);
                for(int i = 0; i < indexDorm; i++) {
                    for (int j =0; j < indexStudent; j++) {
                        if ((strcmp(student[j].id, id) == 0) && (strcmp(dorm[i].name, name) == 0) && (dorm[i].gender == student[j].gender)) {
                            student[j] = assign_student(student[j], &dorm[i]);
                        }
                    }
                }
                continue;
            } else if (strcmp(temp, "move-student") == 0) {
                temp = strtok(NULL, "#");
                strcpy(id, temp);
                temp = strtok(NULL, "#");
                strcpy(name, temp);
                for(int i = 0; i < indexDorm; i++) {
                    for (int j =0; j < indexStudent; j++) {
                        if ((strcmp(student[j].id, id) == 0) && (strcmp(dorm[i].name, name) == 0) && (dorm[i].gender == student[j].gender)) {
                            student[j] = move_student(student[j], &dorm[i]);
                        }
                    }
                }
                continue;
            } else if (strcmp(temp, "student-leave") == 0) {
                temp = strtok(NULL, "#");
                for(int i = 0; i < indexStudent; i++) {
                    // Mendeteksi perbandingan id
                    if (strcmp(student[i].id, temp) == 0){
                        student[i] = leave_student(&student[i]);
                    } 
                
                }
            continue;
            }
        }
        
    } 

    return 0;
}
