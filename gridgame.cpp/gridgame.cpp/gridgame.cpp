
#include "grid.h"
#include <cassert>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

bool hasCorrectForm(string plan);
int determineSafeDistance(int r, int c, char dir, int maxSteps);
int obeyPlan(int sr, int sc, int er, int ec, char dir, string plan, int& nsteps);
bool valid(int r,int c);


    int main()
    {
        setSize(3,4);      // make a 3 by 4 grid
        setWall(1,4);      // put a wall at (1,4)
        setWall(2,2);      // put a wall at (2,2)
        if (!isWall(3,2))  // if there's no wall at (3,2)  [there isn't]
            setWall(3,2);  //    put a wall at (3,2)
        draw(3,1, 3,4);    // draw the grid, showing an S at (3,1) start
                           //    position, and an E at (3,4) end position
        
        
        for(;;)
        {
                    cout << "Enter plan: ";
                    string p;
                getline(cin, p);
                if (p == "quit")
                    break;
                cout << "hasCorrectForm returns ";
                if (hasCorrectForm(p))
                    cout << "true";
                else
                    cout << "false";
                cout << endl;
                }
    }

bool hasCorrectForm(string plan){          //Defining correct form prototype
    
    if (plan=="")
        return true;
    int digitCnt = 0;
    for (int k=0;k!=plan.size();k++){
        if (isdigit(plan.at(k)))
            digitCnt++;
        else if (plan.at(k)=='l' || plan.at(k)=='L' || plan.at(k)=='r' || plan.at(k)=='R')
            digitCnt=0;
        else
            return false;
        if (digitCnt==3)
            return false;
        
        
        
    }
    if (isdigit(plan.at(plan.size()-1)))
        return false;
    else
        return true;
    
        
}

int determineSafeDistance(int r, int c, char dir, int maxSteps){
    
    dir = toupper(dir);
    
    if (valid(r, c) && (dir == 'N' || dir == 'S' || dir == 'E' || dir == 'W') && (maxSteps >= 0))
        ;
    else
        return -1;
    
    int steps = 0;
    
    
    if(dir == 'N')
    {
        for (int k = r; k >= 1; k--)
        {
            if(valid(k, c))
                steps++;
            else
                break;
            
        }
        steps--;
    }
    
    if(dir=='S')
        
    {
        for(int k = r; k<=getRows();k++)
        {
            if(valid(k, c))
                steps++;
            else
                break;
            
            
        }
        steps--;
    }
    if(dir=='E')
    {
        for(int k =c;k<=getRows();k++)
        {
            if(valid(r, k))
                steps++;
            else
                break;
            
        }
        steps--;
    }
    if (dir =='W')
    {
        for(int k =c; k>=1; k--)
        {
            if(valid(r, k))
                steps++;
            else
                break;
        }
        steps--;
    }
    if(steps<maxSteps)
        return steps;
    else
        return maxSteps;
    
    
}

int obeyPlan(int sr, int sc, int er, int ec, char dir, string plan, int& nsteps)
{ //Checking If (sr,sc) or (er,ec) are not valid empty grid positions or if dir is not a direction letter or if the plan string is not a plan, the function returns 2 and leaves nsteps unchanged
    
    if(valid(sr, sc) && valid(er, ec) && (dir == 'N' || dir == 'S' || dir == 'E' || dir == 'W') && hasCorrectForm(plan))
        ;
    else
        return 2;
    //Compassing the direction to digits
    int dirNo = 0;
    
    if (dir == 'N' || dir == 'n')
        dirNo = 0;
    else if (dir == 'E' || dir == 'e')
        dirNo = 1;
    else if (dir == 'S' || dir == 's')
        dirNo = 2;
    else if (dir == 'W' || dir == 'w')
        dirNo = 3;
    //Maintaning the face direction of the person
    nsteps = 0;
    for(int k =0; k!=plan.size();k++)
        
    {
        if(isalpha(plan.at(k)))
        {
            if (plan.at(k)=='r' || plan.at(k)=='R' )
                dirNo++;
            else
                dir--;
            dir=dir%4;
            
        }
        // Traversing through 2 digits
        bool doub = false;
        int val = 0;
        if (isdigit(plan.at(k)))
        {
            if(isdigit(plan.at(k+1)))
            {
                val= 10 * (plan.at(k)-'0') + (plan.at(k+1)-'0');
                doub=true;
            }
            else
                val = plan.at(k)-'0';
        }
        //moving along the path made and counting steps
        
        
        for(int k=val; k>=1 ;k--)
        {
            if (dirNo == 0)
                sr--;
            
            if (dirNo == 1)
                sc++;
            
            if (dirNo == 2)
                sr++;
            
            if (dirNo == 3)
                sc--;
            
            if(!valid(sr, sc))
                nsteps++;
        }
        
        if (doub)
            k++;
        
            
    }
    if (sr == er && sc == ec)
        return 0;
    else
        return 1;
}


bool valid(int r,int c){
    int rowNo =getRows();
    int colNo = getCols();
    if (r>rowNo || r < 1 || rowNo== 0 || c>colNo || c < 1 || colNo== 0 || isWall(r, c))
        return false;
    return true;
    
    
    
}
