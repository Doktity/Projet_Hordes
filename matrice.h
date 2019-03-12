#include <stdlib.h>
#include <stdio.h>
#include "case.h"

typedef struct{
      int nbl;
      int nbc;
      case_t ** mat;
}t_mat;

t_mat * alouer_matrice(int nbl,int nbc);

void liberer_matrice(t_mat * old);
