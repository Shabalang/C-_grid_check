#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

string getUserInput(string prompt)
   {
      string t="";
      cout<<prompt;
      getline(cin,t);
      return t;
   }

void errorMsg(string msg, bool term)
   {
      cout<<msg<<endl;
      if (term)
         exit(0);
   }

bool isDigitString(string s)
   {
      if (!isdigit(s[0]) && s[0]!='+' && s[0]!='-')
         return false;
      for (int i=1;i<s.length();i++)
         if (!isdigit(s[i]))
            return false;
      return true;
   }

int getUserInteger(string prompt)
   {
      string t="billybob";

      while (!isDigitString(t))
         {
            t = getUserInput(prompt);
         }
      return atoi(t.c_str());
   }

void dumpGrid(int rows, int cols, char **a, string msg)
   {
      if (msg.length()>0)
         cout<<msg<<endl;

      cout<<"     ";
      for(int j=0;j<cols;j++)
         cout<<j<<' ';
      cout<<endl;
      cout<<"    ";
      for(int j=0;j<cols;j++)
         cout<<"--";
      cout<<endl;

      for (int i=0;i<rows;i++)
         {
            cout<<"  "<<i<<" |";
            for (int j=0;j<cols;j++)
               {
                  cout<<a[i][j];
                  cout<<' ';
               }
            cout<<endl;
         }
   }


// overloaded function from above to display current position in the grid
// if you don't like overloaded functions (I don't), you can rename it dumpGrid2()
// and change the call in main()
void dumpGrid(int cr, int cc, int rows, int cols, char **a, string msg)
   {
      if (msg.length()>0)
         cout<<msg<<endl;

      cout<<"     ";
      for(int j=0;j<cols;j++)
         cout<<j<<' ';
      cout<<endl;
      cout<<"    ";
      for(int j=0;j<cols;j++)
         cout<<"--";
      cout<<endl;

      for (int i=0;i<rows;i++)
         {
            cout<<"  "<<i<<" |";
            for (int j=0;j<cols;j++)
               {
                  if (cr==i  && cc==j)
                     cout<<'*';
                  else
                     cout<<a[i][j];
                  cout<<' ';
               }
            cout<<endl;
         }
   }  // dumpGrid2()


char **makeGrid(int &rows, int &cols)
   {
      rows=5, cols=7;
      string s[5] = { "X XX  X",
                      "    X  ",
                      "       ",
                      "  XXX X",
                      "X   X  "  };

      char **a = new char*[rows];
      for (int i=0;i<rows;i++)
         {
            a[i] = new char[cols];
            for (int j=0;j<cols;j++)
               a[i][j] = s[i][j];
         }
      return a;
   }

bool isValidPosition(int r, int c, int rows, int cols, char **grid)
   {
	   if (r <= rows && c <=cols && r >=0 && c >= 0)
		{
			if(grid[r][c] != 'X')
			{
				return true;
			}
			else
				return false;	
				
		}
		
		else
			return false;
   }

bool canGoUp(int r,int c,int rows,int cols, char** grid)
   {   if (r <= rows && c <=cols && (r-1) > 0)
	   {
			if(grid[r-1][c] != 'X')
				return true;
		
			else 
				return false;
		}
		else 
			return false;
   }

bool canGoRight(int r, int c, int rows, int cols, char **grid)
   {   if (r <= rows && c <=cols && (c+1) < cols)
	   {
			if(grid[r][c+1] != 'X')
				return true;
		
			else 
				return false;
		}
		else
			return false;
			
   }

bool canGoDown(int r, int c, int rows,int cols, char **grid)
   {    if (r <= rows && c <=cols && (r+1) < rows)
	    {
			if(grid[r+1][c] != 'X')
				return true;
		
			else 
				return false;
		}
		else
			return false;
   }

bool canGoLeft(int r, int c, int rows, int cols, char **grid)
   {    if (r <= rows && c <=cols && (c-1) > 0)
	   {
			if(grid[r][c-1] != 'X')
					return true;
		
			else 
				return false;
		}
		else
			return false;
   }

int main(int argc, char *argv[])
   {
      int rows,cols;

      char **a = makeGrid(rows,cols);

      dumpGrid(rows,cols,a,"");

      string s;
      stringstream ss;

      int cr,cc;

      while (true)
         {
            s = getUserInput("Enter x y position (e.g. 3 5): ");
            ss.clear();
            ss<<s;
            ss>>cr>>cc;
            if (!isValidPosition(cr,cc,rows,cols,a))
               cout<<"Invalid position!!"<<endl;
            else
               {
                  dumpGrid(cr,cc,rows,cols,a,"");
                  cout<<"      '*' marks position"<<endl;
                  if (!canGoUp(cr,cc,rows,cols,a))
                     cout<<"       Can't go up"<<endl;
                  else
                     cout<<"       CAN go up"<<endl;
                  if (!canGoRight(cr,cc,rows,cols,a))
                     cout<<"       Can't go right"<<endl;
                  else
                     cout<<"       CAN go right"<<endl;
                  if (!canGoDown(cr,cc,rows,cols,a))
                     cout<<"       Can't go down"<<endl;
                  else
                     cout<<"       CAN go down"<<endl;
                  if (!canGoLeft(cr,cc,rows,cols,a))
                     cout<<"       Can't go left"<<endl;
                  else
                     cout<<"       CAN go left"<<endl;

                  cout<<endl;
               }
            cout<<endl;
         }
   }
