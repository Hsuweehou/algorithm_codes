#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>	//想要使用sort函数对数组排序少不了这个头文件


/*
bool findIn2DArray(int target, std::vector<std::vector<int> > array)
{
    if(array.empty() || array[0].empty()) return false;
    int row = array.size();int col = array[0].size();
    int w = row - 1;int h = 0;
    while (w >= 0 && h < col)
    {
        if(array[w][h] > target) w--;
        else if(array[w][h] < target) h++;
        else return true;
    }
    return false;
}
*/

class JumpSolution {
public:
    bool canJump(std::vector<int> &nums) {
        int maxNums = nums.size();
        int jumpIndex = nums[0];
        bool step_ = false;
        while (maxNums > 0) {
            std::cout << "maxNums:" << maxNums << std::endl;
            std::cout << "jumpIndex:"  << jumpIndex << std::endl;
            maxNums = maxNums - jumpIndex;
            if (maxNums == nums[jumpIndex - 1]) {
                step_ = true;
                break;
            } else {
                jumpIndex = nums[maxNums];
            }
        }
        return step_;
    }
};

/*****************
    gcd
    最大公约数
    Lcm
    最小公倍数
******************/
class GcdLcmSolution{
public:
    static bool cmp(int a, int b){//cmp函数，确定sort函数排序的规则
        return a > b;
    }


    /*
    思路：1）对这一组数从大到小进行排序、
         2）对每两个相邻的两个数进行如下操作：
         设相邻的两个数为A和B（A在前，因为已经排序，所以A>B），如果A=n*B（n为整数）,
         也就是A能够被B整除，那么就令A=B；如果A不能被B整除则令A=A%B。
         3）重复（1）、（2）直到数组中每个数都相等，则最大公约数就为这个数。
    */
    int gcd(int num[], int n){//求多个数的最大公约数的算法
        std::sort(num, num + n, cmp);
        /*for(int i = 0; i < n; i++){
            std::cout << num[i] << std::endl;
        }*/
        while(num[0] != num[n - 1])
        {
            for(int i = 0; i < n - 1; i++)
            {
                if(num[i + 1] == 0)
                    throw "Attempted to divide by zero!";
                if(num[i] % num[i + 1] == 0)
                    num[i] = num[i + 1];
                else
                    num[i] = num[i] % num[i + 1];
            }
            std::sort(num, num + n, cmp);
        }
        return num[0];
    }
    /*
        对于两个数，它们的最小公倍数等于两数之积除以最大公约数
        公式：最小公倍数=两数乘积/最大公约数
    */

    int gcd_forLcm(int a, int b)
    {
        if (a % b == 0) return b;
        else return gcd_forLcm(b, a % b);
    }

    int lcm(int a, int b)
    {
        int temp = a * b;
        temp = temp / gcd_forLcm(a, b);
        return temp;
    }

};

/*
exec: g++ -o cameratest camera_device.cpp -ludev
so:   g++ camera_device.cpp -fPIC -shared -o libgetCamId.so
*/


int main(){
    /*std::vector<std::vector<int> > targetArray = {{1,2,8,9},
                                                {2,4,9,12},
                                                {4,7,10,13},
                                                {6,8,11,15}};
    JumpSolution test;
    std::vector<int> targetArray = {3,2,1,0,4};
    
    int target = 3;
    bool ret = test.canJump(targetArray);
    //bool ret = findIn2DArray(target, targetArray);

    std::cout << "find the target? : " << ret << "/n";*/

    GcdLcmSolution GcdLcm;
    //gcd lcm
    /*
    int a[2] = {32,16};
    int L = sizeof(a) / sizeof(int);
    try{
        int ret = GcdLcm.gcd(a, L);
        std::cout << ret << std::endl;
    }catch(const char* e){
        std::cerr << e << std::endl;
    }
    */
   //lcm
   	int a[2] = { 40,20};			//最小公倍数：120
	int L = sizeof(a) / sizeof(int);	//L为元素个数
	int m = a[0];	//初始化最小公倍数：a[0]
	for (int i = 1; i < L; i++)	//从 a[1]开始
	{		
		m = m * a[i] / GcdLcm.gcd_forLcm(m, a[i]);
	}
	std::cout << m << std::endl;      				//输出最小公倍数：120


    return 0;
}
