/*
Author : Maria 
Date : 17 July 2025
Description : A program to find the sum of two polynomials.
*/

#include <stdio.h>
struct polynomial{
int coeff;
int expo;
};
int main(){
  struct polynomial poly1[3];
  struct polynomial poly2[3];
  struct polynomial result[6];
  int n1,n2,i=0,j=0,k=0;
  printf("enter no of terms in polynomial1: ");
  scanf("%d", &n1);
  printf("enter terms in descending order  of exponent. \n");
  for(int i=0;i<n1;i++){
    printf("enter coefficient and exponent of term %d :",i+1);
    scanf("%d%d",&poly1[i].coeff,&poly1[i].expo);
  }
  printf("enter no of terms in polynomial2: ");
  scanf("%d", &n2);
  printf("enter terms in descending order  of exponent: \n");
  for(int j=0;j<n2;j++){
    printf("enter coefficient and exponent of term %d ",j+1);
    scanf("%d%d",&poly2[j].coeff,&poly2[j].expo);
  }
  while (i<n1 && j<n2){
    if (poly1[i].expo==poly2[j].expo){
      result[k].coeff=poly1[i].coeff+poly2[j].coeff;
      result[k].expo=poly1[i].expo;
      i++,j++,k++;
    }
    else if (poly1[i].expo >poly2[j].expo){
       result[k].coeff=poly1[i].coeff;
       result[k].expo=poly1[i].expo;
       i++,k++;
   }
   else{
     result[k].coeff=poly2[j].coeff;
     result[k].expo=poly2[j].expo;
     j++,k++;
   }
 }
 while (i<n1){
  result[k]=poly1[i];
  i++,k++;
 }
 while (j<n2){
  result[k]=poly2[j];
  j++,k++;
 }
 for (int i=0;i<k;i++){
  printf("%d x^%d ",result[i].coeff, result[i].expo);
  if (i != k - 1) {
    printf("+ ");
  }  

 }
 return 0;
}
/*
/*
Author : Maria 
Date : 17 July 2025
Description : A program to find the sum of two polynomials.
*/

#include <stdio.h>
struct polynomial{
int coeff;
int expo;
};
int main(){
  struct polynomial poly1[3];
  struct polynomial poly2[3];
  struct polynomial result[6];
  int size1,size2,i=0,j=0,k=0;
  printf("Enter no of terms in Polynomial1: ");
  scanf("%d", &size1);
  printf("enter terms in descending order  of exponent. \n");
  for(int i=0;i<size1;i++){
    printf("enter coefficient and exponent of term %d :",i+1);
    scanf("%d%d",&poly1[i].coeff,&poly1[i].expo);
  }
  for (int i=0;i<size1;i++){
  printf("%d x^%d ",poly1[i].coeff, poly1[i].expo);
  if (i != size1 - 1) {
    printf("+ ");
  }  
}
  
  printf("enter no of terms in Polynomial2: ");
  scanf("%d", &size2);
  printf("Enter terms in descending order  of exponent: \n");
  for(int j=0;j<size2;j++){
    printf("Enter coefficient and exponent of term %d ",j+1);
    scanf("%d%d",&poly2[j].coeff,&poly2[j].expo);
  }
  for (int j=0;j<size2;j++){
  printf("%d x^%d ",poly2[j].coeff, poly2[j].expo);
  if (j != size2 - 1) {
    printf("+ ");
  }  
  
  while (i<size1 && j<size2){
    if (poly1[i].expo==poly2[j].expo){
      result[k].coeff=poly1[i].coeff+poly2[j].coeff;
      result[k].expo=poly1[i].expo;
      i++,j++,k++;
    }
    else if (poly1[i].expo >poly2[j].expo){
       result[k].coeff=poly1[i].coeff;
       result[k].expo=poly1[i].expo;
       i++,k++;
   }
   else{
     result[k].coeff=poly2[j].coeff;
     result[k].expo=poly2[j].expo;
     j++,k++;
   }
 }
 while (i<size1){
  result[k]=poly1[i];
  i++,k++;
 }
 while (j<size2){
  result[k]=poly2[j];
  j++,k++;
 }
 for (int i=0;i<k;i++){
  printf("%d x^%d ",result[i].coeff, result[i].expo);
  if (i != k - 1) {
    printf("+ ");
  }  
}
 return 0;
}
*/
