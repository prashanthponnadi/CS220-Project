	#include <iostream> 
	#include <list> 
	#include <deque> 
	#include <algorithm> 
	using namespace std; 
	
	
	list<int> listx; 
	list<int> listy; 
	list<int> listvals; 
	     int board[10][10]; 
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
	     bool check
	
	(int x, int y); 
	     void display(); 
	int main(){ 
	
	     deque<int> ideque; 
	      
	while(1) 
	          { 
	cout << endl; 
	// shows the input options.
	cout << "1. display" <<endl; 
	cout << "2. add" <<endl; 
	cout << "3. search" <<endl; 
	cout << "4. traceback" <<endl; 
	cout << "5. exit" << endl; 
	cout << "cv"; 
	cout<< cv;cout <<endl; 
	cin >> input; 
	if (input == 1) 
	     { 
	display(); 
	     } 
	else if (input == 2) 
	     { 
	     	 	//get the value for starting point and ending point
	cout << endl; 
	cout << "please give start position in row and start position in coloumn to found path from"; 
	cin >> value2;//starting x 
	cin >> value3;//starting y 
	cout << "please give finish position in row and finish posiiton in coloumn to found path to"; 
	cin >> value4; 
	cin >> value5; 
	value3 = value3-1, value2 = value2-1, value5 = value5-1, value4 = value4-1; 
	board[value4][value5] = 1; 
	board[value2][value3] = 1; 
	     } 
	else if (input ==3) 
	     { 
	    int blx1=2;
     int bly1=2; 
	 cout<<"value 2:"<<value2<<endl;
	 cout<<"value 3:"<<value3<<endl;
	 cout<<"value 4:"<<value4<<endl;
	 cout<<"value 5:"<<value5<<endl;
	     int cx = value2; 
	     int cy = value3; 
	     int gx = value4; 
	     int gy = value5; 
	     board[value2][value3] = cv; 
	     listx.push_front(value2); 
	     listy.push_front(value3); 
	     listvals.push_front(cv); 
	     do{ 
	cv = listvals.back(); //kajal
	cx = listx.back(); 
	cy = listy.back(); 
	     x = cx; 
	     y = cy + 1; 
	     if((x > -1)&&(x < 10)&&(y > -1)&&(y < 10)) 
	     { 
	          if(check(x,y) == false) 
	          { 
				  if (x==blx1 && y==bly1){ 
                 //x = -2; 
                 //y = -2; 
                 board[x][y] = -10; 
               } 
               else{ 
				  if(cv == 1)
				  {
					
					board[x][y] = cv+1;
					listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
					
				  }
				else if (cv == 2)
				{
					board[x][y] = cv+1;
					listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
				}
				else if (cv == 3)
				{
					board[x][y] = 1;
					listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front(1); 
				}
				else
				{
						cv=1;
						board[x][y] = 1;
						listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
				}
			  
	              //cv=cv + 1;
				}
		     }
	               
	     } 
	      
	     else 
	     { 
	          x = 0; 
	          y = 0; 
	     } 
	if((x == gx)&&(y == gy)){found = true;} 
	
	     x = cx + 1; 
	     y = cy; 
	     if((x > -1)&&(x < 10)&&(y > -1)&&(y < 10)) 
	     { 
	          if(check(x,y) == false) 
	          { 
	              if (x==blx1 && y==bly1){ 
                 //x = -2; 
                 //y = -2; 
                 board[x][y] = -10; 
               } 
               else{ 
	               if(cv == 1)
				  {
					
					board[x][y] = cv+1;
					listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
					
	}
	else if (cv == 2)
	{
		board[x][y] = cv+1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
		}
		else if (cv == 3)
	{
		board[x][y] = 1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
		}
	else{
	        cv=1;
	              board[x][y] = 1; 
	              listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
			  }
			  
	              //cv=cv + 1;
		   
	               }
	          }
	     } 
	     else 
	     { 
	          x = 0; 
	          y = 0; 
	     } 
	if((x == gx)&&(y == gy)){found = true;} 
	     x = cx; 
	     y = cy - 1; 
	     if((x > -1)&&(x < 10)&&(y > -1)&&(y < 10)) 
	     { 
	          if(check(x,y) == false) 
	          { 
	          	if (x==blx1 && y==bly1){ 
                 //x = -2; 
                 //y = -2; 
                 board[x][y] = -10; 
               } 
               else{ 
	                if(cv == 1)
				  {
					
					board[x][y] = cv+1;
					listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
					
	}
	else if (cv == 2)
	{
		board[x][y] = cv+1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
		}
		else if (cv == 3)
	{
		board[x][y] = 1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
		}
	else{
	        cv=1;
	              board[x][y] = 1; 
	              listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
			  }
			  
	              }
	          }
	     } 
	     else 
	     { 
	          x = 0; 
	          y = 0; 
	     } 
	if((x == gx)&&(y == gy)){found = true;} 
	     x = cx - 1; 
	     y = cy; 
	     if((x > -1)&&(x < 10)&&(y > -1)&&(y < 10)) 
	     { 
	          if(check(x,y) == false) 
	          { 
	          	if (x==blx1 && y==bly1){ 
                 //x = -2; 
                 //y = -2; 
                 board[x][y] = -10; 
               } 
               else{ 
	           if(cv == 1)
				  {
					
					board[x][y] = cv+1;
					listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
					
	}
	else if (cv == 2)
	{
		board[x][y] = cv+1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
		}
		else if (cv == 3)
	{
		board[x][y] = 1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
		}
	else{
	        cv=1;
	              board[x][y] = 1; 
	              listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
			  }
	}

	        }   
	     } 
	     else 
	     { 
	          x = 0; 
	          y = 0; 
	     } 
	/*if((x == gx)&&(y == gy)){found = true;} 
	     x = cx + 1; 
	     y = cy + 1; 
	     if((x > -1)&&(x < 10)&&(y > -1)&&(y < 10)) 
	     { 
	          if(check(x,y) == false) 
	          { 
	               board[x][y] = (cv + 1); 
	               listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
	          } 
	     } 
	     else 
	     { 
	          x = 0; 
	          y = 0; 
	     }
	*/ 
	if((x == gx)&&(y == gy)){found = true;} 
	
	if((x == gx)&&(y == gy)){found = true;} 
	     x = cx + 1; 
	     y = cy -1; 
	     if((x > -1)&&(x < 10)&&(y > -1)&&(y < 10)) 
	     { 
	          if(check(x,y) == false) 
	          { 
	          	if (x==blx1 && y==bly1){ 
                 //x = -2; 
                 //y = -2; 
                 board[x][y] = -10; 
               } 
               else{ 
               	if(cv == 1)
				  {
					
					board[x][y] = cv+1;
					listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
					
	}
	else if (cv == 2)
	{
		board[x][y] = cv+1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
		}
		else if (cv == 3)
	{
		board[x][y] = 1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
		}
	else{
	        cv=1;
	              board[x][y] = 1;
	              listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1));  
			  }
			  }
	         }  
	     } 
	     else 
	     { 
	          x = 0; 
	          y = 0; 
	     } 
	
	if((x == gx)&&(y == gy)){found = true;} 
	
	     x = cx - 1; 
	     y = cy - 1; 
	     if((x > -1)&&(x < 10)&&(y > -1)&&(y < 10)) 
	     { 
	          if(check(x,y) == false) 
	          { 
	          	if (x==blx1 && y==bly1){ 
                 //x = -2; 
                 //y = -2; 
                 board[x][y] = -10; 
               } 
               else{ 
	              if(cv == 1)
				  {
					
					board[x][y] = cv+1;
					listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
					
	}
	else if (cv == 2)
	{
		board[x][y] = cv+1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
		}
		else if (cv == 3)
	{
		board[x][y] = 1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
		}
	else{
	         cv=1;
	              board[x][y] = 1; 
	              listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
			  }
	       }    
	     } 
	 }
	     else 
	     { 
	          x = 0; 
	          y = 0; 
	     } 
	
	if((x == gx)&&(y == gy)){found = true;} 
	
	     x = cx - 1; 
	     y = cy + 1; 
	     if((x > -1)&&(x < 10)&&(y > -1)&&(y < 10)) 
	     { 
	          if(check(x,y) == false) 
	          { 
	          	if (x==blx1 && y==bly1){ 
                 //x = -2; 
                 //y = -2; 
                 board[x][y] = -10; 
               } 
               else{ 
	          	if(cv == 1)
				  {
					
					board[x][y] = cv+1;
					listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
					
	}
	else if (cv == 2)
	{
		board[x][y] = cv+1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((cv + 1)); 
		}
		else if (cv == 3)
	{
		board[x][y] = 1;
		listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
		}
	else{
	        cv=1;
	              board[x][y] = 1; 
	              listx.push_front(x); 
	               listy.push_front(y); 
	               listvals.push_front((1)); 
			  }

	          }
	     } 
	 }
	     else 
	     { 
	          x = 0; 
	          y = 0; 
	     } 
	if((x == gx)&&(y == gy)){found = true;} 
	 // board[gx+1][gy+1]=1; 
	// board[gx][gy]=cv+1; 
	board[gx][gy]=cv+1; //added by kajal
	
	
	
	          listx.pop_back(); 
	          listy.pop_back(); 
	          listvals.pop_back(); 
	
	cv = cv+1;
	if(cv >= 4)
	{ 
		cv = 1;
		cout<<"@@@@@@"<<cv<<endl;     
	} 
	        
	          

	     cout<<"!!!!cv "<<cv<<endl;     
	     }while (found ==false); 
	} 
	else if (input ==4) 
{ 
     int sx=value4;
     int sy=value5;
     int cx=value2;
     int cy=value3;
     int op;
    int cal = ((sx==cx) && (sy==cy));
    int val=board[sx][sy];
     do{
       if((val==3)||(val==2)){
         op=sx+1;
         
          if(val-1==board[op][sy]){
             val=board[op][sy]; 
             board[op][sy]=-1;
             sx=sx+1;
             
         }
         }
         else {
         op=sx+1;
         
          if(board[op][sy]==3){
             val=board[op][sy]; 
             board[op][sy]=-1;
             sx=sx+1;
             
         }	
         }
         if((val==3)||(val==2)){
         op=sx-1;
         
      if(val-1==board[op][sy]){
              val=board[op][sy]; 
             board[sx][sy]=-1;
             sx= sx-1;
             
         }
         }
         else {
         	if(board[op][sy]==3){
              val=board[op][sy]; 
             board[sx][sy]=-1;
             sx= sx-1;
             
         }
         }
       if((val==3)||(val==2)){
         op=sy-1;
       if(val-1==board[sx][op]){
              val=board[sx][op]; 
             board[sx][sy]=-1;
             sy=sy-1;
            
         }
        }
        else {
        	 op=sy-1;
       if(board[sx][op]==3){
              val=board[sx][op]; 
             board[sx][sy]=-1;
             sy=sy-1;
            
         }
        }
        if((val==3)||(val==2)){
          op=sy+1;
        
    if(val-1==board[sx][op]){
               val=board[sx][op]; 
             board[sx][sy]=-1;
             sy=sy+1;
            
         }
         }
         else {
         	 op=sy+1;
        
    if(board[sx][op]==3){
               val=board[sx][op]; 
             board[sx][sy]=-1;
             sy=sy+1;
            
         }
         }
        
         
         
         
         
         
    
         
     }while( !((sx==value2) && (sy==value3)) );
     board[cx][cy]=-1;
 }
	else if (input ==5) 
	{ 
	exit(1); 
	} 
	     } 
	} 
	
	void display() 
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
	
	bool check(int x, int y) 
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
	
