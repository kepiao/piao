#include <stdio.h>//��̬���������С
#include <stdlib.h> //mallocͷ����
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