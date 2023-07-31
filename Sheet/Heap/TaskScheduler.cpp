/*
621. Task Scheduler
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> um;
        for(int i=0;i<tasks.size();i++){
            um[tasks[i]]++;
        }
        priority_queue<int>pq;

        for(auto i:um){
            pq.push(i.second);
        }

        int timer=0;
        while(pq.size()){
            vector<int>temp;
            for(int i=0;i<=n;i++){      // block of (n+1) choose most frequent first
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }

            for(int i=0;i<temp.size();i++){
                if(--temp[i]>0){      // decease the freq by one and push again in order of selection.
                    pq.push(temp[i]);
                }

            }
            timer+= (pq.empty() ? temp.size(): n+1);
        }
        return timer;
    }
};