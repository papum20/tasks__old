#include <iostream>
using namespace std;



const int length = 1000;



struct set {
	int data[length];
	int top;
};

set empty_set(){
	set tmp ;
	tmp.top = -1 ;
	return(tmp) ;
}



bool is_in(set s, int e){
	 if (s.top == -1) return(false) ;
	 else {
		 int l = 0 ;
		 int r = s.top ;
		 int m ;
		 bool found = false ;
		 return(found) ;
	 }
}


set intersection(set s1, set s2){
	 if ((s1.top == -1)||(s2.top == -1)) return(empty_set()) ;
	 else {
		 set s ;
		 int i = 0 ;
		 int j = 0 ;
		 s = empty_set() ;
		 return(s) ;
	 }
}



set set_union(set s1, set s2)
{
	if (s1.top == -1) return(s2) ;
	else if (s2.top == -1) return(s1) ;
	else {
		set s = empty_set() ;
		 int i1 = 0 ;
		 int i2 = 0 ;
		 while ((i1 <= s1.top) && (i2 <= s2.top) && (s.top < length)){
			 if (s1.data[i1] < s2.data[i2]) {
				 s.top = s.top + 1 ; s.data[s.top] = s1.data[i1] ; i1 = i1+1 ;
			 }
			 else if (s1.data[i1] > s2.data[i2]){
				 s.top = s.top + 1 ; s.data[s.top] = s2.data[i2] ; i2 = i2+1 ;
			 }
			 else {
				 s.top = s.top + 1 ; s.data[s.top] = s1.data[i1] ;
				 i1 = i1+1 ; i2 = i2+1 ;
		 }
		 }
		 while ((i1 <= s1.top) && (s.top < length)){
			 s.top = s.top + 1 ; s.data[s.top] = s1.data[i1] ; i1 = i1+1 ;
		 }
		 while ((i2 <= s2.top) && (s.top < length)){
			 s.top = s.top + 1 ; s.data[s.top] = s2.data[i2] ; i2 = i2+1 ;
		 }
		 if ((i1 <= s1.top) || (i2 <= s2.top)) cout << "write error" << endl ;
		 return(s) ;
	 }
}



int main()
{

}
