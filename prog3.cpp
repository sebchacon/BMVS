#include <vector>
#include "stuff3.h"

//made by Sebastian Chacon on 04-12-2024

pair<bool, Stuff3> DecisionRecur1(vector<Stuff3>& vec)
{

   Stuff3 s;

   if(vec.empty())
   {
       pair<bool, Stuff3> p = make_pair(false, s);
       return p;
   }
   if(vec.size() == 1)
   {
       s = vec[0];
       pair<bool, Stuff3> p = make_pair(true, vec[0]);
       return p;
   }
   if(vec.size() == 2)
   {
       if(vec[0] == vec[1])
       {
           pair<bool, Stuff3> p = make_pair(true, vec[0]);
           return p;
       }
       else
       {
           pair<bool, Stuff3> p = make_pair(false, s);
           return p;
       }
   }

   int half = vec.size() / 2;
    vector<Stuff3> a(vec.begin(), vec.begin() + half);
    vector<Stuff3> b(vec.begin() + half, vec.end());

    auto AnswersA = DecisionRecur1(a);
    auto AnswersB = DecisionRecur1(b);

    if(AnswersA.first)
    {
        int count = std::count(a.begin(), a.end(), AnswersA.second);
        if(count > a.size()/2)
            return AnswersA;
    }
    if(AnswersB.first)
    {
        int count = std::count(b.begin(), b.end(), AnswersB.second);
        if(count > b.size()/2)
            return AnswersB;
    }

   pair<bool, Stuff3> p = make_pair(false, s);
   return p;
}

pair<bool, Stuff3> Decision1(vector<Stuff3>& vec)
{
   return DecisionRecur1(vec);
}

pair<bool, Stuff3> DecisionRecur2(vector<Stuff3>& vec, int index, Stuff3 &vote, int& num)
{
    
    if(vec[index] == vec[index + 1])
    {
        if(num == 0)
        {
            vote = vec[index];
            ++num;
        }
        else if(vec[index] == vote)
            ++num;
        else
            --num;
    }
    else if(!(vec[index] == vote) && !(vec[index + 1] == vote));
        if(num != 0)
            --num;

   int vRemaining = vec.size() - index;

   if(vRemaining == 3)
   {
        if(num == 0)
            vote = vec[index + 2];
        num = 1;
        if(vec[index + 1] == vote)
            ++num;
        if(vec[index] == vote)
            ++num;

       return make_pair(num > (vec.size() / 2 + 1), vote);
   }
   else if(vRemaining == 2)
   {
       num = 0;
       if(vec[index + 1] == vote)
           ++num;
       if(vec[index] == vote)
           ++num;
       if(num > (vec.size() / 2 + 1))
           return make_pair(true, vote);
       else
           return make_pair(false, vote);
   }
   else
   {
       int ind = index + 2;
       DecisionRecur2(vec, ind, vote, num);
   }

   if(vec[index] == vote)
       ++num;
   if(vec[index+ 1] == vote)
       ++num;

   if(num > (vec.size() / 2))
       return make_pair(true, vote);
   else
       return make_pair(false, vote);
}

pair<bool, Stuff3> Decision2(vector<Stuff3>& vec)
{
    int index = 0, num = 0;
    Stuff3 vote(false, 0,0,0);
   return DecisionRecur2(vec, index, vote, num);
}
