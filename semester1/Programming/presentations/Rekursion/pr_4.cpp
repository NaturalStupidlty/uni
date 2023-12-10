#include <iostream>
using namespace std;

void diskMove(int diskFrom, int diskTo)
{ cout << diskFrom << "->" << diskTo << ' '; 
  return; 
}

void tower(int height, int from,int to, int via)
//height - висота, from - з, to - на, via - через
{ if(height==1) diskMove(from,to);
  else 
  { tower(height-1,from,via,to);
    diskMove(from,to);
    tower(height-1,via,to,from);
  } 
}  

int main()
{ int n;
  cout << "Hanoi towers\n"; 
  cout << "Enter a number of disks>"; 
  cin >> n; 
  if (n<0) n=1;
  tower(n,1,3,2);
  cout<<endl; 
  system("pause");
  return 0;
}

