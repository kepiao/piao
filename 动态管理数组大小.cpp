#include <stdio.h>//动态管理数组大小
#include <stdlib.h> //malloc头函数
int main ()//
{ 
	int n , i ; 
	int *p = NULL ;
	scanf ("% d ",& n );
	p =( int *) malloc ( n * sizeof ( int )); 
	for ( i =0; i < n ; i ++) 
		scanf("%d",&p[i]); 
	for ( i =0; i < n ; i ++) 
		printf ("%d ",p[ i ]); 
		return 0;
}