//
// Created by marty on 25.05.2022.
//

#include "vector.h"
#include "tested_declarations.h"
#include "rdebug.h"


int vector_create(struct vector_t *a, int N)
{
    if(N<=0 || a==NULL)
    {
        return 1;
    }
    (a->ptr)=(int*)malloc(N*sizeof(int));
    if((a->ptr)==NULL)
    {
        return 2;
    }
    (a->capacity)=N;
    (a->size)=0;
    return 0;
}

void vector_display(const struct vector_t *a)
{
    if(a==NULL || (a->capacity)<=0 || (a->size)<0 || (a->ptr)==NULL ||(a->capacity)<(a->size))
        return;
    else
    {
        for(int i=0;i<a->size;i++)
        {
            printf("%d ",*(a->ptr+i));
        }
    }
}

void vector_destroy(struct vector_t *a)
{
    if(a!=NULL)
    {
        free(a->ptr);
    }
}

int vector_create_struct(struct vector_t **a, int N)
{
    if(N<=0 || a==NULL)
    {
        return 1;
    }
    *a=(struct vector_t*)malloc(sizeof(struct vector_t));
    if(*a==NULL)
    {
        return 2;
    }
    if( vector_create(*a,N)==2)
    {
        free(*a);
        return 2;
    }
    return 0;
}

void vector_destroy_struct(struct vector_t **a)
{
    if((a!=NULL && *a!=NULL))
    {
        vector_destroy(*a);
        free(*a);
    }
}

int vector_push_back(struct vector_t *a, int value)
{
    int *wektor;
    if(a==NULL || (a->capacity)<=0 || (a->size)<0 || (a->ptr)==NULL ||(a->capacity)<(a->size) )
    {
        return 1;
    }
    if((a->capacity)==(a->size))
    {
        wektor=(int*)realloc(a->ptr,a->capacity*2*sizeof(int));
        if(wektor==NULL)
        {
            return 2;
        }
        a->ptr=wektor;
        a->capacity=a->capacity*2;
    }
    int x=(a->size);
    *(a->ptr+x)=value;
    a->size=a->size+1;
    return 0;
}

int vector_erase(struct vector_t *a, int value)
{
    int s=0;
    int *wektor;
    if(a==NULL || (a->capacity)<=0 || (a->size)<0 || a->ptr==NULL ||(a->capacity)<(a->size) )
    {
        return -1;
    }



    for(int j=0;j<a->size;j++)
    {
        if(*(a->ptr+j)==value)
        {
            s=s+1;
            for(int i=j;i<a->size-1;i++)
            {
                *(a->ptr+i)=*(a->ptr+i+1);
            }
            a->size=a->size-1;
            j--;
        }
    }

    if(a->size<a->capacity*0.25 && a->capacity>1)
    {
        wektor=(int*)realloc(a->ptr,a->capacity/2*sizeof(int));
        if(wektor==NULL)
        {
            return -1;
        }
        a->ptr=wektor;
        a->capacity=a->capacity/2;
    }

    return s;
}




