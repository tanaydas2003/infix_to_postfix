#include<stdio.h>
void quicksort(int a[15],int fi,int li){
    int i,j,pivot,temp;
    if(fi<li){
        pivot=fi;
        i=fi;
        j=li;
        while(i<j){
            while(a[i]<=a[pivot] && i<li){
                i++;
            }
            while(a[j]>a[pivot]){
                j--;
            }
            if(i<j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quicksort(a,fi,j-1);
        quicksort(a,j+1,li);
    }
}
int main(){
    int i,size,a[100];
    printf("Enter the size of an array");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("Enter the element at %d index: ",i);
        scanf("%d ",&a[i]);
    }
    quicksort(a,0,size-1);
    for(i=0;i<size;i++){
        printf("%d\n",a[i]);
    }
return 0;
}