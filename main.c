#include <stdio.h>
#include "vector.h"
#include "tested_declarations.h"
#include "rdebug.h"




int main()
{
    int size,x,liczba,flag=0;
    struct vector_t*tab;
    printf("Podaj rozmiar tablicy:");
    if(scanf("%d",&size)!=1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(size<=0)
    {
        printf("Incorrect input data");
        return 2;
    }

    if(vector_create_struct(&tab,size)==2)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    for(;;)
    {
        while(getchar()!='\n');
        printf("Podaj co chcesz zrobic: ");
        if(scanf("%d",&x)!=1)
        {
            printf("Incorrect input");
            vector_destroy_struct(&tab);
            return 1;
        }

        if(x==0)
        {
            break;
        }

        if(x==1)
        {

            printf("Podaj kolejne liczby, ktore maja zostac dodane do tablicy:");
            for(;;)
            {
                if(scanf("%d",&liczba)!=1)
                {
                    printf("Incorrect input");
                    vector_destroy_struct(&tab);
                    return 1;
                }
                if(liczba==0)
                {
                    break;
                }
                if(vector_push_back(tab,liczba)==2)
                {
                    flag=1;
                    break;

                }

            }

                if(flag==1)
                {
                    printf("Failed to allocate memory\n");
                    vector_display(tab);
                    printf("\n");
                }
                else
                {
                    vector_display(tab);
                    printf("\n");
                }

        }

        if(x==2)
        {
            printf("Podaj kolejne liczby, które mają zostać usuniete z tablicy:");
            for(int i=0;;i++)
            {
                if(scanf("%d",&liczba)!=1)
                {
                    printf("Incorrect input");
                    vector_destroy_struct(&tab);
                    return 1;
                }
                if(liczba==0)
                {
                    break;
                }

                if(vector_erase(tab,liczba)==-1)
                {
                    printf("Failed to allocate memory\n");
                    while(getchar()!='\n');
                    break;
                }

            }
            if(tab->size==0)
            {
                printf(" Buffer is empty\n");
            }
            else
            {
                vector_display(tab);
                printf("\n");
            }

        }
        if(x!=0 && x!=1 && x!=2)
        {
            printf("Incorrect input data\n");
        }
    }
    vector_destroy_struct(&tab);
    return 0;

}

