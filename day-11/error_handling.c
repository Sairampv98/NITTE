#include<stdio.h>
#include<errno.h>

typedef enum{
    ERR_OK = 0, ERR_NULL = -1,
    ERR_BOUNDS = -2, ERR_ALLOC = -3,
    ERR_IO = -4, ERR_NOT_FOUND = -5
} errorCode;

typedef struct {
    int size;
}V;
V v;
errorCode vecInserts(V *v, int idx, int val){
    if(v==NULL)
        return ERR_NULL;
    if(idx< 0 || idx > v->size)
        return ERR_BOUNDS;
    return ERR_OK;
}
int main(){
v.size = 2;
errorCode err = vecInserts(&v, 1, 42);
if(err!=ERR_OK){
    fprintf(stderr, "vec_insert failed: %d\n", err);
    return 0;
}
return 0;
}
