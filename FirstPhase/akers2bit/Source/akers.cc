#include "../Headers/problem_object.h"
#include "../Headers/claim.h"
#include "../Headers/akers.h"

#include <iostream> 
#include <list> 
#include <stdlib.h>
#include <deque> 
#include <algorithm> 
using namespace std; 


     list<int> listx; 
     list<int> listy; 
     list<int> listvals;
     int sizex, sizey; 
     //int board[10][10]; 
     int input; 
     int a; 
     int b; 
     int i=0; 
     int j=0; 
     int value; 
     int startval; 
     int startval_; 
     int value2; 
     int value3; 
     int value4; 
     int value5; 
     int x; 
     int y; 
     int cv = 1; 
     bool found = false; 
     bool startfound =false; 
     int ** board = NULL; 

/*
The creatematrix() function will will create a matrix of size height X width.
It is in this matrix is where the searching from source to sink happens and traceback from sink to source happens.
*/
int akers::creatematrix(int height, int width)
{
	cout<<"BOARD SIZE IS"<<height<<width<<endl;
	sizex = height;
	sizey = width;
  	board = (int**)malloc(4 * height);
	if (board)
	{
  		for (i = 0; i < height; i++)
  		{
    			board[i] = (int*)malloc(4 * width);
  		}
	
	return 1;
	}
	return 0;
}

/*
The readdata() funtion asks the user for the co-ordinates of the source and the sink in the martrix.
*/
void akers::readdata()
{

	cout << "please give start position in row and start position in coloumn to found path from"; 
	cin >> value2;//starting x 
	cin >> value3;//starting y 
	cout << "please give finish position in row and finish posiiton in coloumn to found path to"; 
	cin >> value4; 
	cin >> value5; 
	value3 = value3-1, value2 = value2-1, value5 = value5-1, value4 = value4-1; 
	board[value4][value5] = -1; // Sink represented by -1 in the matrix
	board[value2][value3] = -1; // Source represented by -1 in the matrix
}

/*
The akers_blockages() funtion adds a blockage in the matrix so as to prevent the searching from source to sink
and also the traceback from sink to source along the points where there are blockages.
A blockage is represented by value -10 in the matrix.
*/
void akers::akers_blockages(int blockage_x,int blockage_y,int blockage_width,int blockage_height)
{

	for (int i =blockage_x+1; i<= (blockage_x+blockage_height); i++)
	{
		for(int j =blockage_y; j< (blockage_y+blockage_width); j++)
		{
				board[i][j] = -10;
		}
	}

}

/*
The akers_search() funtion is responsible for searching for a route from the source to the sink. 
Here cv is the current value that is being pushed into the matrix.
*/
void akers::akers_search()
{
    	cout<<"value 2:"<<value2<<endl;
		cout<<"value 3:"<<value3<<endl;
		cout<<"value 4:"<<value4<<endl;
		cout<<"value 5:"<<value5<<endl;
		int cx = value2;
		int cy = value3;
		int gx = value4;
		int gy = value5;
		board[value2][value3] = cv-1;
		listx.push_front(value2);
		listy.push_front(value3);
		listvals.push_front(cv-1);
		do{
		cv = listvals.back();
		cx = listx.back();
		cy = listy.back();
		x = cx;
		y = cy + 1; // Check if search can continue in the cell that is below the current cell
		if((x > -1)&&(x < sizex)&&(y > -1)&&(y < sizey)) // Check if the neighbouring cell is out of bounds of the matrix
		{
		if(check(x,y) == false)
		{
		if(cv == 1)
		{
		if( board[x][y+1] == 0 && board[x+1][y] == 0 && board[x][y-1] == 0 && board[x-1][y] == 0 && board[x][y+2] == 0 && board[x+2][y] == 0 && board[x][y-2] == 0 && board[x-2][y] == 0)	
			{
				board[x][y] = 1;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front((1));
			}
		else if( ((board[x][y+1] == 1 && board[x][y+2] == 1) || (board[x][y-1] == 1 && board[x][y-2] == 1) || (board[x-1][y] == 1 && board[x-2][y] == 1) || (board[x+1][y] == 1 && board[x+2][y] == 1))&&board[x][y]==0)
		{
		        board[x][y] = 2;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front((2));	
		}
		else {
			    board[x][y] = 1;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front(1);
			}
		}
		else if (cv == 2)
		{
		if(( (board[x][y+1] == 2 && board[x][y+2] == 2) || (board[x][y-1] == 2 && board[x][y-2] == 2) || (board[x-1][y] == 2 && board[x-2][y] == 2) || (board[x+1][y] == 2 && board[x+2][y] == 2))&&board[x][y]==0)	
		{
		board[x][y] = 1;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front(1);
		}
		else 
		{
		board[x][y] = 2;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front(2);
		}
	}
		else
		{
		cv=1;
		board[x][y] = 1;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front((1));
		}
		}
		}
		else
		{
		  x = listx.back();
          y = listy.back();  
		}
		if((x == gx)&&(y == gy)){found = true;
		    if(listvals.back()==2){
		    		board[gx][gy]=2;
		    }
		    else{
		    		board[gx][gy]=1;
		    }
		
			break;}
		x = cx + 1; // Check if search can continue in the cell that is to the right of the current cell
		y = cy;
		if((x > -1)&&(x < sizex)&&(y > -1)&&(y < sizey)) // Check if the neighbouring cell is out of bounds of the matrix
		{
		if(check(x,y) == false)
		{
		if(cv == 1)
		{
		if( board[x][y+1] == 0 && board[x+1][y] == 0 && board[x][y-1] == 0 && board[x-1][y] == 0 && board[x][y+2] == 0 && board[x+2][y] == 0 && board[x][y-2] == 0 && board[x-2][y] == 0)	
			{
				board[x][y] = 1;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front((1));
			}
		else if( ((board[x][y+1] == 1 && board[x][y+2] == 1) || (board[x][y-1] == 1 && board[x][y-2] == 1) || (board[x-1][y] == 1 && board[x-2][y] == 1) || (board[x+1][y] == 1 && board[x+2][y] == 1))&&board[x][y]==0)
		{
		        board[x][y] = 2;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front((2));	
		}
		else {
			    board[x][y] = 1;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front(1);
			}
		}
		else if (cv == 2)
		{
		if(( (board[x][y+1] == 2 && board[x][y+2] == 2) || (board[x][y-1] == 2 && board[x][y-2] == 2) || (board[x-1][y] == 2 && board[x-2][y] == 2) || (board[x+1][y] == 2 && board[x+2][y] == 2))	&&board[x][y]==0)
		{
		board[x][y] = 1;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front(1);
		}
		else 
		{
		board[x][y] = 2;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front(2);
		}
	}
		else
		{
		cv=1;
		board[x][y] = 1;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front((1));
		}
		}
		}
		else
		{
		  x = listx.back();
          y = listy.back(); 
		}
		
			if((x == gx)&&(y == gy)){found = true;
		    if(listvals.back()==2){
		    		board[gx][gy]=2;
		    }
		    else{
		    		board[gx][gy]=1;
		    }
		
			break;}
		x = cx;
		y = cy - 1; // Check if search can continue in the cell that is above the current cell
		if((x > -1)&&(x < sizex)&&(y > -1)&&(y < sizey)) // Check if the neighbouring cell is out of bounds of the matrix
		{
		if(check(x,y) == false)
		{
		if(cv == 1)
		{
		if( board[x][y+1] == 0 && board[x+1][y] == 0 && board[x][y-1] == 0 && board[x-1][y] == 0 && board[x][y+2] == 0 && board[x+2][y] == 0 && board[x][y-2] == 0 && board[x-2][y] == 0)	
			{
				board[x][y] = 1;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front((1));
			}
		else if( ((board[x][y+1] == 1 && board[x][y+2] == 1) || (board[x][y-1] == 1 && board[x][y-2] == 1) || (board[x-1][y] == 1 && board[x-2][y] == 1) || (board[x+1][y] == 1 && board[x+2][y] == 1))&&board[x][y]==0)
		{
		        board[x][y] = 2;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front((2));	
		}
		else {
			    board[x][y] = 1;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front(1);
			}
		}
		else if (cv == 2)
		{
		if(( (board[x][y+1] == 2 && board[x][y+2] == 2) || (board[x][y-1] == 2 && board[x][y-2] == 2) || (board[x-1][y] == 2 && board[x-2][y] == 2) || (board[x+1][y] == 2 && board[x+2][y] == 2))&&board[x][y]==0)	
		{
		board[x][y] = 1;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front(1);
		}
		else 
		{
		board[x][y] = 2;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front(2);
		}
	}
		else
		{
		cv=1;
		board[x][y] = 1;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front((1));
		}
		}
		}
		else
		{
		  x = listx.back();
          y = listy.back(); 
		}
		
		if((x == gx)&&(y == gy)){found = true;
		    if(listvals.back()==2){
		    		board[gx][gy]=2;
		    }
		    else{
		    		board[gx][gy]=1;
		    }
		
			break;}
			
		x = cx-1; // Check if search can continue in the cell that is to the left of the current cell
		y = cy;
		if((x > -1)&&(x < sizex)&&(y > -1)&&(y < sizey)) // Check if the neighbouring cell is out of bounds of the matrix
		{
		if(check(x,y) == false)
		{
		if(cv == 1)
		{
		if( board[x][y+1] == 0 && board[x+1][y] == 0 && board[x][y-1] == 0 && board[x-1][y] == 0 && board[x][y+2] == 0 && board[x+2][y] == 0 && board[x][y-2] == 0 && board[x-2][y] == 0)	
			{
				board[x][y] = 1;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front((1));
			}
		else if(( (board[x][y+1] == 1 && board[x][y+2] == 1) || (board[x][y-1] == 1 && board[x][y-2] == 1) || (board[x-1][y] == 1 && board[x-2][y] == 1) || (board[x+1][y] == 1 && board[x+2][y] == 1))&&board[x][y]==0)
		{
		        board[x][y] = 2;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front((2));	
		}
		else {
			    board[x][y] = 1;
				listx.push_front(x);
				listy.push_front(y);
				listvals.push_front(1);
			}
		}
		else if (cv == 2)
		{
		if( ((board[x][y+1] == 2 && board[x][y+2] == 2) || (board[x][y-1] == 2 && board[x][y-2] == 2) || (board[x-1][y] == 2 && board[x-2][y] == 2) || (board[x+1][y] == 2 && board[x+2][y] == 2))	&&board[x][y]==0)
		{
		board[x][y] = 1;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front(1);
		}
		else 
		{
		board[x][y] = 2;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front(2);
		}
	  }
		else
		{
		cv=1;
		board[x][y] = 1;
		listx.push_front(x);
		listy.push_front(y);
		listvals.push_front((1));
		}
		}
		}
		else
		{
		  x = listx.back();
          y = listy.back();  
		}
		if((x == gx)&&(y == gy)){found = true;
		    if(listvals.back()==2){
		    		board[gx][gy]=2;
		    }
		    else{
		    		board[gx][gy]=1;
		    }
		
			break;}
			
		listx.pop_back();
		listy.pop_back();
		listvals.pop_back();
		cv = cv+1;
		if(cv > 2)
		{
		cv = 1;
		
		}
		
		}while (found ==false);
}

/*
The akers_traceback algorithm finds a path from the sink to the source and displays the co-ordinates of the path
taken from sink to source.
*/
void akers::akers_traceback()
{
	
     cout<<"Thee traceback path is :";
     int sx=value4;
     int sy=value5;
     int cx=value2;
     int cy=value3;
     int op;
     int valtemp[500]={};
   
    int i=1;
    valtemp[0]=board[sx][sy];
     cout<<"The traceback path is :";
     cout<<"("<<sx<<","<<sy<<")"<<", ";
     do{
     	 
       op=sx+1;
       if(board[op][sy]!=0){
       if(valtemp[i-1]==valtemp[i-2]){
             if(valtemp[i-1]==1){
             	if(board[op][sy]==2)
                {
                    board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx+1;
                    valtemp[i]=2;
                    ++i;
                }
            }
            else if(valtemp[i-1]==2){
            	if(board[op][sy]==1)
                {
                    board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx+1;
                     valtemp[i]=1;
                     ++i;
                }
            }
        }
        else if (valtemp[i-1]==1){
        	if(board[op][sy]==1){
        			board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx+1;
                    valtemp[i]=1;
                    ++i;
        	}

        }
          else if (valtemp[i-1]==2){
        	if(board[op][sy]==2){
        			board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx+1;
                    valtemp[i]=2;
                    ++i;
        	}

        }  
        else{
            valtemp[i]=board[op][sy];
           board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx+1;
                   
                    ++i;	
        }
    }
    if(((cx==sx)&&(cy==sy))||board[op][sy]==-2) {
        	cout<<"("<<op<<","<<sy<<")"<<endl;
        	
        	break;
        }
         
     
       op=sx-1;
       if(board[op][sy]!=0){
       if(valtemp[i-1]==valtemp[i-2]){
             if(valtemp[i-1]==1){
             	if(board[op][sy]==2)
                {
                    board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx-1;
                    valtemp[i]=2;
                    ++i;
                }
            }
            else if(valtemp[i-1]==2){
            	if(board[op][sy]==1)
                {
                    board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx-1;
                    valtemp[i]=1;
                    ++i;
                }
            }
        }
        else if (valtemp[i-1]==1){
        	if(board[op][sy]==1){
        			board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx-1;
                    valtemp[i]=1;
                    ++i;
        	}

        }
          else if (valtemp[i-1]==2){
        			if(board[op][sy]==2)
        			{
        			board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx-1;
                    valtemp[i]=2;
                    ++i;
        			}

        }  
        	else{
        			valtemp[i]=board[op][sy];
           			board[op][sy]=-1;
                    cout<<"("<<op<<","<<sy<<")"<<", ";
                    sx=sx-1;
                   
                    ++i;	
                }

    }
      if(((cx==sx)&&(cy==sy))||board[op][sy]==-2){
        	cout<<"("<<op<<","<<sy<<")"<<endl;
        	board[sx][sy]=-1;
        	break;
        }   
      if(board[sx][op]!=0){
      op=sy+1;
      
       if(valtemp[i-1]==valtemp[i-2]){
             if(valtemp[i-1]==1){
             	if(board[sx][op]==2)
                {
                    board[sx][op]=-1;
                    cout<<"("<<sx<<","<<op<<")"<<", ";
                    sy=sy+1;
                    valtemp[i]=2;
                    ++i;
                }
            }
            else if(valtemp[i-1]==2){
            	if(board[sx][op]==1)
                {
                    board[sx][op]=-1;
                    cout<<"("<<sx<<","<<op<<")"<<", ";
                    sy=sy+1;
                     valtemp[i]=1;
                     ++i;
                }
            }
        }
        else if (valtemp[i-1]==1){
        			if(board[sx][op]==1){
        			 board[sx][op]=-1;
                     cout<<"("<<sx<<","<<op<<")"<<", ";
                     sy=sy+1;
                     valtemp[i]=1;
                     ++i;
        	}

        }
          else if (valtemp[i-1]==2){
        			if(board[sx][op]==2){
        			board[sx][op]=-1;
                    cout<<"("<<sx<<","<<op<<")"<<", ";
                    sy=sy+1;
                    valtemp[i]=2;
                    ++i;
        	}

        }  
        else{
        			valtemp[i]=board[sx][op];
            		board[sx][op]=-1;
                    cout<<"("<<sx<<","<<op<<")"<<", ";
                    sy=sy+1;
                   
                    ++i;	
        }
    }
        if(((cx==sx)&&(cy==sy))||board[sx][op]==-2){
        	cout<<"("<<sx<<","<<sy<<")"<<endl;
        	board[sx][sy]=-1;
        	break;
        }
     if(board[sx][op]!=0){
      op=sy-1;
      
       if(valtemp[i-1]==valtemp[i-2]){
             if(valtemp[i-1]==1){
             	if(board[sx][op]==2)
                {
                    board[sx][op]=-1;
                    cout<<"("<<sx<<","<<op<<")"<<", ";
                    sy=sy-1;
                    valtemp[i]=2;
                    ++i;
                }
            }
            else if(valtemp[i-1]==2){
            	if(board[sx][op]==1)
                {
                    board[sx][op]=-1;
                    cout<<"("<<sx<<","<<op<<")"<<", ";
                    sy=sy-1;
                    valtemp[i]=1;
                    ++i;
                }
            }
        }
        else if (valtemp[i-1]==1){
        	if(board[sx][op]==1){
        		     board[sx][op]=-1;
                     cout<<"("<<sx<<","<<op<<")"<<", ";
                     sy=sy-1;
                     valtemp[i]=1;
                     ++i;
        	}

        }
          else if (valtemp[i-1]==2){
        	if(board[sx][op]==2){
        		    board[sx][op]=-1;
                    cout<<"("<<sx<<","<<op<<")"<<", ";
                    sy=sy-1;
                    valtemp[i]=2;
                    ++i;
        	}

        }  
        else{
        	        valtemp[i]=board[sx][op];
                    board[sx][op]=-1;
                    cout<<"("<<sx<<","<<op<<")"<<", ";
                    sy=sy-1;
                   
                    ++i;	
        }
    }
        if(((cx==sx)&&(cy==sy))||board[sx][op]==-2){
        	cout<<"("<<sx<<","<<op<<")"<<endl;
        	board[sx][sy]=-1;
        	break;
        }
         
     }while( board[sx][sy]!=-2 );
     board[cx][cy]=-1;   
}

/*
The display function shows the contents of the matrix 
*/
void akers::display() 
{ 
cout << endl; 
for (a=0; a<10; a++) 
{ 
     for (b=0; b<10; b++) 
     { 
     cout << board[a][b]; 
     cout << "  "; 
      
     } cout << "\n";
} 
cout << endl; cout<<endl; 
} 

/*
The check function is used to see if the current cell in the matrix has value 0. If true it return a false staement 
and if false it returns a true statement
*/
bool akers::check(int x, int y) 
{ 
     if(board[x][y] == 0) 
     { 
          return false; 
     } 
     else 
     { 
          return true; 
     } 
}




