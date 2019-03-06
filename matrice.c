#include <stdlib.h>
typedef struct{
      int nbl;
      int nbc;
      void ** mat;
}t_mat;

t_mat * alouer_matrice(int nbl,int nbc,void * type_case){//nbl:nombreligne, nbc:nombrecolonne
      t_mat * new=malloc(sizeof(t_mat));
      new->mat = malloc(sizeof(type_case)*nbl);
      for (int i = 0; i < nbl; i++) {
            new->mat[i]=malloc(sizeof(type_case)*nbc);
      }
      new->nbl = nbl;
      new->nbc = nbc;
      return (new);
}

void liberer_matrice(t_mat * old){
      free(old->mat);
      free(old);
      old = NULL;
}
