//Employee Importance Leetcode 690

//Suming the importance value of an employee and all their subordinates in a company hierachy


class Solution {
public:
     int getImportance(vector<Employee*> employees, int id) {

        unordered_map<int, Employee*> map;
            for(auto e : employees){
          map[e->id] = e;
    }
     return  getImp(map, id);

    }
    private: 
    int getImp(unordered_map<int, Employee*> map, intid){
        Employee* e = map[id];
       int imp = e->importance;
        for(int subId : e->subordinates){
         imp += getImp(map, subId);
         }
     return imp;

    }
};