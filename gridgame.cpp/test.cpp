//#include <iostream>
//#include "grid.h"
//#include <cassert>
//#include <string>
//#include <cctype>
//using namespace std;
//
//
//
//bool hasCorrectForm(string plan);
//bool validLoco(int r, int c);
//int determineSafeDistance(int r, int c, char dir, int maxSteps);
//int obeyPlan(int sr, int sc, int er, int ec, char dir, string plan, int& nsteps);
//
//
//
////int main()
//{
//    setSize(4,4);
//    setWall(1,4);
//    setWall(2,2);
//    setWall(3,2);
//    draw(2,1,4,4);
//    assert(hasCorrectForm(""));
//    assert(hasCorrectForm("5rL00L0R09R7L"));
//    assert(hasCorrectForm("LL2R2r2L1R"));
//    assert(hasCorrectForm("42l"));
//    assert(!hasCorrectForm("L2"));
//    assert(!hasCorrectForm("1Rx2L"));
//    assert(!hasCorrectForm("144R"));
//    assert(!hasCorrectForm("1R+2L"));
//    assert(!hasCorrectForm("N144"));
//    assert(!hasCorrectForm("N14"));
//    assert(!hasCorrectForm("w2+n3"));
//    assert(hasCorrectForm("2R1r"));
//    assert(!hasCorrectForm("1Lx"));
//    assert(determineSafeDistance(3, 1, 'N', 3) == 2);
//    assert(determineSafeDistance(2, 2, 'W', 3) == -1);
//    assert(determineSafeDistance(3, 1, 'q', 3) == -1);
//    assert(determineSafeDistance(4, 1, 'E', 0) == 0);
//    assert(determineSafeDistance(2, 4, 's', 3) == 2);
//    assert(determineSafeDistance(4, 4, 'W', 2) == 2);
//    assert(determineSafeDistance(1, 1, 'E', 3) == 2);
//    assert(determineSafeDistance(3, 1, 'S', 3) == 1);
//    int len = -999;
//    assert(obeyPlan(3,1, 3,4, 'N', "1Lx", len) == 2);
//    assert(obeyPlan(5,5, 3,4, 'N', "2R1r", len) == 2);
//    assert(obeyPlan(3,1, 7,4, 'N', "1RrR2L1L1r", len) == 2);
//    assert(obeyPlan(3,1, 7,4, 'p', "2R1r", len) == 2);
//    assert(obeyPlan(3,1, 2,2, 'l', "LL2R2r2L1R", len) == 2);
//    assert(obeyPlan(2,4, 1,1, 'w', "3R1L", len) == 3 && len == 1);
//    assert(obeyPlan(4,1, 1,1, 'n', "R5L", len) == 3 && len == 3);
//    assert(obeyPlan(4,1, 1,1, 'e', "2l2llll2r", len) == 3 && len == 5);
//    assert(obeyPlan(2,3, 1,1, 'N', "1RrR2L1L1r", len) == 3 && len == 4);
//    assert(obeyPlan(1,1, 1,1, 'e', "1r3r", len) == 3 && len == 1);
//    assert(obeyPlan(3,1, 3,4, 'S', "LL2R2r2L1R", len) == 0 && len == 7);
//    assert(obeyPlan(1,1, 4,4, 'e', "2r3l1l", len) == 0 && len == 6);
//    assert(obeyPlan(4,1, 4,4, 'N', "1rr1L3r", len) == 0 && len == 5);
//    assert(obeyPlan(1,1, 4,4, 'e', "2r3l1l", len) == 0 && len == 6);
//    assert(obeyPlan(1,1, 4,4, 'e', "2r3l1l", len) == 0 && len == 6);
//    assert(obeyPlan(1,1, 1,1, 'e', "2rr2r", len) == 0 && len == 4);
//    assert(obeyPlan(4,1, 4,4, 'N', "1rr1r", len) == 1 && len == 2);
//    assert(obeyPlan(4,1, 1,1, 'n', "2r", len) == 1 && len == 2);
//    assert(obeyPlan(2,1, 4,4, 'N', "rr2l2l", len) == 1 && len == 4);
//    assert(obeyPlan(2,4, 1,1, 'n', "L1L2R1L", len) == 1 && len == 4);
//}
//
//
//int obeyPlan(int sr, int sc, int er, int ec, char dir, string plan, int& nsteps)
//{
//    if (validLoco(sr,sc) && validLoco(er, ec) && hasCorrectForm(plan))
//        ;
//    else
//        return 2;
//    
//    // intialize way to change cardinal directions to mod 4
//    
//    int way = 0;
//    
//    if (dir == 'N' || dir == 'n')
//        way = 0;
//    else if (dir == 'E' || dir == 'e')
//        way = 1;
//    else if (dir == 'S' || dir == 's')
//        way = 2;
//    else if (dir == 'W' || dir == 'w')
//        way = 3;
//    else
//        return 2;
//
//    // for loop to iterate through string
//    
//    nsteps = 0;
//
//    for (int i = 0 ; i != plan.size() ; i++)
//    {
//        // if letter, change way
//        
//        if ( isalpha(plan[i]) )
//        {
//            if (plan[i] == 'R' || plan[i] == 'r')
//                way++;
//            else
//                way--;
//            way %= 4;
//            continue;
//        }
//        
//        // store 1-2 digit number to move
//        
//        int move = 0;
//        bool double_digit = false;
//        
//        if ( isdigit(plan[i]) )
//        {
//            if ( isdigit(plan[i+1]) )
//            {
//                move = 10 * (plan[i] - '0') + (plan[i+1] - '0');
//                double_digit = true;
//            }
//            else
//                move = plan[i] - '0';
//        }
//        
//        // move stepwise. stop when invalid.
//        
//        for (int i = move ; i > 0 ; i--)
//        {
//            if (way == 0)
//                sr--;
//            if (way == 1)
//                sc++;
//            if (way == 2)
//                sr++;
//            if (way == 3)
//                sc--;
//            if (!(validLoco(sr,sc)))
//                return 3;
//            nsteps++;
//        }
//        
//        // skip next digit if double digit
//        
//        if (double_digit)
//            i++;
//    }
//    
//    if (sr == er && sc == ec) // successful journey
//        return 0;
//    
//    return 1;
//    
//}
//
//bool hasCorrectForm(string route) // check if valid route
//{
//    if (route == "") // allow empty string
//        return true;
//    
//    int digCount = 0; // digit count
//    
//    for (int i = 0; i != route.size(); i++)
//    {
//        if (isdigit(route[i])) // check valid digit
//            digCount++;
//        else if (route[i] == 'l' || route[i] == 'L' ||
//                 route[i] == 'r' || route[i] == 'R') // check valid direction
//            digCount = 0;
//        else // invalid digit or letter
//            return false;
//        if (digCount == 3) // string has 3+ consecutive digits
//            return false;
//    }
//    
//    if (digCount != 0) // last character is direction
//        return false;
//    
//    return true;
//}
//
//
//
//bool validLoco(int r, int c)
//{
//    int nRow = getRows();
//    int nCol = getCols();
//    
//    if (nRow == 0 || r < 1  ||  r > nRow  ||
//        c < 1  ||  c > nCol || isWall(r, c))
//        return false;
//    
//    return true;
//}
//
//
//
//int determineSafeDistance(int r, int c, char dir, int maxSteps)
//{
//    dir = tolower(dir);
//    
//    if (validLoco(r, c) && ( dir == 'n' || dir == 'e' ||
//        dir == 'w' || dir == 's' ) && maxSteps >= 0)
//        ;
//    else
//        return -1;
//    
//    int count = 0;
//    
//    if (dir == 'n')
//    {
//        for (int i = r; i >= 1; i--)
//        {
//            if (validLoco(i, c))
//                count++;
//            else
//                break;
//        }
//        count--;
//    }
//    
//    if (dir == 's')
//    {
//        for (int i = r; i <= getRows(); i++)
//        {
//            if (validLoco(i, c))
//                count++;
//            else
//                break;
//        }
//        count--;
//    }
//
//    if (dir == 'e')
//    {
//        for (int j = c; j <= getRows(); j++)
//        {
//            if (validLoco(r, j))
//                count++;
//            else
//                break;
//        }
//        count--;
//    }
//    
//    if (dir == 'w')
//    {
//        for (int j = c; j >= 1; j--)
//        {
//            if (validLoco(r, j))
//                count++;
//            else
//                break;
//        }
//        count--;
//    }
//    
//    if (count < maxSteps)
//        return count;
//    else
//        return maxSteps;
//
//}
//
