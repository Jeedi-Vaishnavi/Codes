#include<stdio.h>
void selection(int list[], int i, int j, int size, int flag){
int temp;
if (i < size - 1){
if (flag)
 j = i + 1;

if (j < size){
if (list[i] > list[j]){
temp = list[i];
list[i] = list[j];
list[j] = temp;
}
selection(list, i, j + 1, size, 0);
}

selection(list, i + 1, 0, size, 1);
}}

int main(){
int a[50], size, temp, i, j;
printf("Enter the size of the list: ");
scanf("%d", &size);
printf("Enter the elements in list:\n");
for (i = 0; i < size; i++)
{
   scanf("%d", &a[i]);
}
selection(a, 0, 0, size, 1);
printf("The sorted list in ascending order is\n");
for (i = 0; i < size; i++)
{
   printf("%d  ", a[i]);
}
}
