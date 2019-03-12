#include "matrice.h"

t_mat * alouer_matrice(int nbl,int nbc){//nbl:nombreligne, nbc:nombrecolonne
      t_mat * new=malloc(sizeof(t_mat));
      new->mat = malloc(sizeof(case_t)*nbl);
      for (int i = 0; i < nbl; i++) {
            new->mat[i]=malloc(sizeof(case_t)*nbc);
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
