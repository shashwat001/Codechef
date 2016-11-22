#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring> 
#include <cstdlib>
//include <conio.h> 
using namespace std;
 
 
string get_lcs(char * s1, int len1, char * s2, int len2)
{
  vector<vector<int> > m(len1+1, vector<int>(len2+1, 0));
 
  int i, j;
  for (i = 0; i < len1+1; i++) m[i][0] = 0;
  for (j = 0; j < len2+1; j++) m[0][j] = 0;
   
  int max = 0,pos=0;
  int max_i = -1;
  int max_j = -1;
 
  for (i = 0; i < len1; i++){
    for (j = 0; j < len2; j++){
      if (s1[i] == s2[j]){
        m[i+1][j+1] = m[i][j] + 1;
      }
      else{
        m[i+1][j+1] = 0; 
      }
 
      if (max <= m[i+1][j+1]){
         max = m[i+1][j+1];
         max_i = i;
         max_j = j;
      }
    }
  }
  return string(s1).substr(max_i - max + 1, max); 
}
 
 
int main()
{
  char s1[250005];
  char s2[250005];
  scanf("%s %s",s1,s2);
  string s3=  get_lcs(s1, strlen(s1), s2, strlen(s2));
 // printf("%s",s3);
  if(s3.size()==0)
    printf("0\n");
  else
  cout << s3 << endl << s3.size() <<endl;
  //getch();
  return 0;
}
