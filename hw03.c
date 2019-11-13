#include <stdio.h>
#include <stdlib.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  char *grad_year;

} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
    case MAJOR_AND_NAME:
      printf("%s %s %s\n", s.major, s.first_name, s.last_name);
      break;
    case YEAR_AND_NAME:
      printf("%s %s %s\n", s.grad_year, s.first_name, s.last_name);
      break;
 
  }
}


int main(int argc, char **argv) {

  Mode mode = (int)atof(argv[1]);

  int amountOfStudents = (argc-2)/4;

  Student students[amountOfStudents]; 

  int studentUpTo = -1; 

  int i = 2; 
  for(i;i<argc;i++){

    switch ((i-2)%4){
      case 0:
        studentUpTo++; 
        students[studentUpTo].first_name = argv[i];
      case 1:
        students[studentUpTo].last_name = argv[i]; 
      case 2:
        students[studentUpTo].major = argv[i]; 
      case 3:
        students[studentUpTo].grad_year = argv[i];
    }

  }


  int j = 0; 
  for(j;j<amountOfStudents;j++){
    print_student(mode,students[j]);
  }

  return 0;
}
