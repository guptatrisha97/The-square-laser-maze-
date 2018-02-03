#include <iostream>//Trisha Gupta 3035342419
using namespace std;

struct item
{
	string name,dir;
	int x,y;
	int dest;
};
item a[20];     string startdir="";

int stopx,stopy; 

int size, num,pos,posx,posy;
bool bound(int, int);
void empty(int&,int&);
void destination(int,int);
void direction(int&,int&);
bool mirror(int&, int&, string&, string&);//global variables


  
 int main()
    {
    	int count=1;
    	cin>>size;
    	cin>>num;
    	char dummy; 
    	int sourcenum=0;
      for(int i=0;i<num;i++)
      {
        a[i].name="";
        a[i].dir="";
        a[i].x=0;
        a[i].y=0;
        a[i].dest=0;
      }
    	for(int i=0;i<num;i++)
    	{
    		cin>>a[i].name;
    		if( (a[i].name == "block") || (a[i].name == "dest") )//inputs according to its name
    		{
    		  cin>>a[i].x>>dummy>>a[i].y;//block and dest have no direction
    		}
    		else
    		{
         	  cin>>a[i].dir>>a[i].x>>dummy>>a[i].y;
         	}
        if(a[i].name == "dest")
         {
         	a[i].dest = count;
         	count++;//counter to count the number of destination that the source reaches
         } 

        } 
    	  
           	  for(int i=0;i<num;i++)
    	   {
          posx=a[i].x;
          posy=a[i].y;
           if(a[i].name=="source")
           	  {
                pos=i;
           	  	sourcenum++;
           	  	cout<<sourcenum<<"-";//outputs the source we are referring to
           	  	if(a[i].dir=="south")
           	  	{
           	 	startdir="south";
              a[i].y--;
           	     empty(a[i].x,a[i].y);
           	 }
           	    else if(a[i].dir=="north")
           	    {
           	    startdir="north";
                a[i].y++;
           	      empty(a[i].x,a[i].y);
           	  }
           	    else if(a[i].dir=="east")
           	    {
           	    startdir="east";
                a[i].x++;
           	   empty(a[i].x,a[i].y);
           	}
           	    else
           	    {
           	   startdir="west";
               a[i].x--;
            	empty(a[i].x,a[i].y);
           	  }
             }
             a[i].x=posx;
             a[i].y=posy;
    	    }
    return 0;
    } 
	



void empty(int& startx,int& starty)//does most of the job
{
  bool done=false,ans=false;
  while(ans==false)
  {
    done=false;
for (int i=0;i<num && ans==false;i++)
{
		if(a[i].x==startx&&a[i].y==starty && i!=pos)
		{
      ans= mirror(startx,starty, a[i].dir, startdir);// calls mirror function if there is an object in middle of laser beam 
      done = true;
		}
  }

  if (done==false)
    {
      if(bound(startx,starty)==true)
     ans=true;
    
    else
   	direction(startx, starty);//calls direction if there is no object
 }
}
}




bool bound(int startx, int starty)
{
		if(startx>size-1||starty>size-1 || startx<0 || starty<0)//checks if the beam stays within the maze
	      {
          cout<<"X"<<endl;
          return true;
	      }
        return false;
}
void destination(int startx, int starty)
{
for(int i=0;i<num;i++)
	{
	if(startx==a[i].x&&starty==a[i].y && pos!=i)
	{
    cout<<a[i].dest<<endl;//outputs the destination number 
	}
    }
}

void direction(int& startx,int& starty)//helps the laser beam move and change its direction
		{
			
			if(startdir=="east")
			{
				startx++;startdir="east";
			}
			else if(startdir=="west")
			{
				startx--;startdir="west";
			}
			else if(startdir=="north")
			{
				starty++;startdir="north";
			}
			else
			{
				starty--;startdir="south";
			}
			}	    
bool mirror(int& startx, int& starty, string& dir, string& startdir)//checks what kind of object and performs function accordingly
			{
				for(int i=0;i<num;i++)
				{ 
          if(a[i].x == startx && a[i].y == starty && pos!=i)
				  {	
				  if(a[i].name=="single")
				  {
                    if(a[i].dir=="sw")
				    {
                     if(startdir=="east")
                     {
                     	starty--;startdir="south";
                      return false;
                     }
                     else if(startdir=="north")
                     {
                     	startx--;startdir="west";
                      return false;

                     }
				     else
				     {
				     	cout<<"X"<<endl;
              return true;

				     }
			        }
			      else if(a[i].dir=="nw")
			      {
			        	if(startdir=="east")
			        	{
			        		starty++;startdir="north";
                  return false;
			            }
			        else if(startdir=="south")
			        {
			        	startx--;startdir="west";
                return false;
			        }
			        else
			        {
              cout<<"X"<<endl;
              return true;
			        }
			      }
			      else if(a[i].dir=="ne")
			      {
			      	if(startdir=="west")
			      	{
			      		starty++;startdir="north";
                return false;
			      	}
			      	else if(startdir=="south")
			      	{
			      		startx++;startdir="east";
                return false;
			      	}
			      	else
			      	{
              cout<<"X"<<endl;
              return true;
			      	}
			      }
			      else
			      {
			      	if (startdir=="north")
			      	{
			      		startx++;startdir="east";
                return false;
			      	}
			      	else if(startdir=="west")
			      	{
			      		starty--;startdir="south";
               return false;

			      	}
			      	else
			      	{
              cout<<"X"<<endl;
              return true;
			      	}
			      }
			      	}
			      	else if(a[i].name=="double")
			         {
			         	if(a[i].dir=="nw"||a[i].dir=="se")
			             {
                          if(startdir=="north")
                          {
                          	startx++;startdir="east";return false;
                          }
                          else if(startdir=="west")
                          {
                          	starty--;startdir="south";return false;

                          }
                          else if(startdir=="east")
                          {
                          	starty++;startdir="north";return false;

                          }
                          else 
                          {
                          	startx--;startdir="west";return false;

                          }
                         }
                         else 
                         {
                         	if(startdir=="north")
                         	{
                         		startx--;startdir="west";return false;

                         	}
                         	else if(startdir=="east")
                         	{
                         		starty--;startdir="south";return false;

                         	}
                         	else if( startdir=="west")
                         	{
                         		starty++;startdir="north";return false;

                         	}
                         	else
                         	{
                         		startx++;startdir="east";return false;

                         	}
                         }
                     }
                     else if(a[i].name=="block" || a[i].name=="source")
                     {
                     	cout<<"X"<<endl;//if it is block, prints X
                      return true;
                     }
                     else if(a[i].name=="dest")
                     {
                     	destination(startx, starty);//calls destination function if name is destination
                      return true;
                     }
                   }  
                   }
                   return true;
                 }
                 
                        