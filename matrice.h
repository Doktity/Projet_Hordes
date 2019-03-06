#include <stdlib.h>
typedef struct{
      int nbl;
      int nbc;
      void ** mat;
}t_mat;
t_mat * alouer_matrice(int nbl,int nbc,void * type_case);
void liberer_matrice(t_mat * old);
