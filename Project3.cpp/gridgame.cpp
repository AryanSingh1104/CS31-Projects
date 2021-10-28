
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
int cardinal(char a);



int main() {
    setSize(4,4);
    setWall(1,4);
    setWall(2,2);
    setWall(3,2);
    draw(2,1,4,4);
    assert(hasCorrectForm(""));
    assert(hasCorrectForm("5rL00L0R09R7L"));
    assert(hasCorrectForm("LL2R2r2L1R"));
    assert(hasCorrectForm("42l"));
    assert(!hasCorrectForm("L2"));
    assert(!hasCorrectForm("1Rx2L"));
    assert(!hasCorrectForm("144R"));
    assert(!hasCorrectForm("1R+2L"));
    assert(!hasCorrectForm("N144"));
    assert(!hasCorrectForm("N14"));
    assert(!hasCorrectForm("w2+n3"));
    assert(hasCorrectForm("2R1r"));
    assert(!hasCorrectForm("1Lx"));
    assert(determineSafeDistance(3, 1, 'N', 3) == 2);
    assert(determineSafeDistance(2, 2, 'W', 3) == -1);
    assert(determineSafeDistance(3, 1, 'q', 3) == -1);
    assert(determineSafeDistance(4, 1, 'E', 0) == 0);
    assert(determineSafeDistance(2, 4, 's', 3) == 2);
    assert(determineSafeDistance(4, 4, 'W', 2) == 2);
    assert(determineSafeDistance(1, 1, 'E', 3) == 2);
    assert(determineSafeDistance(3, 1, 'S', 3) == 1);
    int len = -999;
    assert(obeyPlan(3,1, 3,4, 'N', "1Lx", len) == 2);
    assert(obeyPlan(5,5, 3,4, 'N', "2R1r", len) == 2);
    assert(obeyPlan(3,1, 7,4, 'N', "1RrR2L1L1r", len) == 2);
    assert(obeyPlan(3,1, 7,4, 'p', "2R1r", len) == 2);
    assert(obeyPlan(3,1, 2,2, 'l', "LL2R2r2L1R", len) == 2);
    assert(obeyPlan(2,4, 1,1, 'w', "3R1L", len) == 3 && len == 1);
    assert(obeyPlan(4,1, 1,1, 'n', "R5L", len) == 3 && len == 3);
 
    // Errors
 
    assert(obeyPlan(4,1, 1,1, 'e', "2l2llll2r", len) == 3 && len == 5);
    assert(obeyPlan(2,3, 1,1, 'N', "1RrR2L1L1r", len) == 3 && len == 4);
    assert(obeyPlan(1,1, 1,1, 'e', "1r3r", len) == 3 && len == 1);
    assert(obeyPlan(3,1, 3,4, 'S', "LL2R2r2L1R", len) == 0 && len == 7);
    assert(obeyPlan(1,1, 4,4, 'e', "2r3l1l", len) == 0 && len == 6);
    assert(obeyPlan(4,1, 4,4, 'N', "1rr1L3r", len) == 0 && len == 5);
    assert(obeyPlan(1,1, 4,4, 'e', "2r3l1l", len) == 0 && len == 6);
    assert(obeyPlan(1,1, 4,4, 'e', "2r3l1l", len) == 0 && len == 6);
    assert(obeyPlan(1,1, 1,1, 'e', "2rr2r", len) == 0 && len == 4);
    assert(obeyPlan(4,1, 4,4, 'N', "1rr1r", len) == 1 && len == 2);
    assert(obeyPlan(4,1, 1,1, 'n', "2r", len) == 1 && len == 2);
    assert(obeyPlan(2,1, 4,4, 'N', "rr2l2l", len) == 1 && len == 4);
    assert(obeyPlan(2,4, 1,1, 'n', "L1L2R1L", len) == 1 && len == 4);
    cerr << "All tests succeeded" << endl;
}


bool hasCorrectForm(string plan){          //Defining correct form prototype
    
    int digitCnt = 0;
    for (int k=0;k!=plan.size();k++){
        if (digitCnt==3)                   // For 3 digit number
            return false;
        if (isdigit(plan.at(k)))
            digitCnt++;                    // Keeping tabs of numbers
        else if (plan.at(k)=='l' || plan.at(k)=='L' || plan.at(k)=='r' || plan.at(k)=='R')
            digitCnt=0;                     // Resetting the counter
        else
            return false;
        
        
        
        
    }
    if (isdigit(plan[plan.size()-1]))          //Checking Last Char as digit
        return false;
    else
        return true;
    
        
}

bool valid(int r,int c){                    //Declaring valid to check if the coordinates are valid coordinates
    int rowNo =getRows();
    int colNo = getCols();
    if (r>rowNo || r < 1 || rowNo== 0 || c>colNo || c < 1 || colNo== 0 || isWall(r, c))
        return false;                       // Checking if all the coordinates are inside the grid
    return true;
    
    
    
}

int determineSafeDistance(int r, int c, char dir, int maxSteps){        //Creating determineSafeDistance function
    
    dir = toupper(dir);
    
    if (valid(r, c) && (dir == 'N' || dir == 'S' || dir == 'E' || dir == 'W') && (maxSteps >= 0))
        ;
    else
        return -1;              //  Checking for letters a=other than NEWS
    
    int steps = 0;
    
    
    if (dir =='W')              //Moving west
    {
        for(int k =c; k>=1; k--)
        {
            if(valid(r, k))     //Checking a valid position
                steps++;
            else
                break;
        }
        
        steps--;
    }
    
    if(dir=='S')            //Moving SOuth
        
    {
        for(int k = r; k<=getRows();k++)
        {
            if(valid(k, c))     //Checking a valid position
                steps++;
            else
                break;
            
            
        }
        steps--;
    }
    if(dir=='E')               //Moving East
    {
        for(int k =c;k<=getRows();k++)
        {
            if(valid(r, k))     //Checking a valid position
                steps++;
            else
                break;
            
        }
        steps--;
    }
   
    if(dir == 'N')              //Moving North
    {
        for (int k = r; k >= 1; k--)
        {
            if(valid(k, c))         //Checking a valid position
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
{
   

    // Adding a direction number compasssing the actual direction.

    int dirNo = cardinal(dir);
    
    if (valid(sr,sc) && valid(er, ec) && hasCorrectForm(plan))      // Checking if the string is of valid form
        ;
    else
        return 2;

    

    nsteps = 0;

    for (int i = 0 ; i != plan.size() ; i++)
    {
        // Deciding the orientation of the pointer

        if ( isalpha(plan[i]) )
        {
            if (plan[i] == 'R' || plan[i] == 'r')
                dirNo++;
            else
                dirNo--;
            dirNo %= 4;
            continue;
        }

        int value = 0;
        bool doubNo = false;

        if ( isdigit(plan[i]) )                     //Storing 2 digit numbers
        {
            if ( isdigit(plan[i+1]) )
            {
                value = 10 * (plan[i] - '0') + (plan[i+1] - '0');
                doubNo = true;
            }
            else
                value = plan[i] - '0';
        }


        for (int i = value ; i > 0 ; i--)
            //adding to the column and rows to make the cursor value in cardinal direction
        {
            if (dirNo == 0)
                sr--;
            if (dirNo == 1)
                sc++;
            if (dirNo == 2)
                sr++;
            if (dirNo == 3)
                sc--;
            if (!(valid(sr,sc)))
                return 3;
            nsteps++;
        }

        // Adding cursor two value and skip the digit

        if (doubNo)
            i++;
    }

    if (sr == er && sc == ec) // Cursor reaches from start to end
        return 0;

    return 1;

}
int cardinal(char dir)
{
    if (dir == 'N' || dir == 'n')
        return 0;
    else if (dir == 'E' || dir == 'e')
        return  1;
    else if (dir == 'S' || dir == 's')
        return  2;
    else if (dir == 'W' || dir == 'w')
        return  3;
    else
        return 2;
}
