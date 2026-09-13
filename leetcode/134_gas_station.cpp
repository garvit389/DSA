#include<bits/stdc++.h>
using namespace std;

//Note: to decrease runtime, remove netGas function and netG array and directly put sum as gas[i] - cost[i]

class Solution {
public:
    vector<int> netGas(vector<int>& gas, vector<int>& cost){
        vector<int> net;
        for(int i=0; i< gas.size(); i++){
            net.push_back(gas[i]-cost[i]);
        }
        return net;
    }

   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> netG = netGas(gas,cost);

        int sum = 0;
        int failSum = 0;
        int flag = -1;
        int s=0;        

        for(int i=0; i<netG.size(); i++){
            sum+=netG[i];
            if(sum<0){
                failSum+=sum; 
                sum = 0;
                s = i+1;
            }
        }

        sum +=failSum;

        if(sum>=0) return s;

        return -1;
    }
};