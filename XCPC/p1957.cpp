#include<bits/stdc++.h>
using namespace std;
int main() {
    // 初始化变量
    int n;                // 操作总数
    cin >> n;             // 读取操作数
    string s1[123], s2[123], s3[123]; // 存储每个操作的元数据：
                            // s1-运算符类型(a/b/c/.), s2-左操作数, s3-右操作数
    // 读取并解析所有操作
    for(int i = 0; i < n; i++) {
        string tmp;       // 临时存储首字段
        cin >> tmp;
        // 处理显式运算符情况（a=加, b=减, c=乘）
        if(tmp == "a" || tmp == "b" || tmp == "c") {
            cin >> s2[i] >> s3[i];
            s1[i] = tmp;
        }
        // 处理继承运算符情况（使用最近的有效运算符）
        else {
            s2[i] = tmp;    // 首字段为左操作数
            s1[i] = ".";    // 标记为继承运算符
            cin >> s3[i];   // 读取右操作数
        }
    }
    int las = -1;
    for(int i = 0; i < n; i++) {
        string ans = "";
        int res;
        // cout << las << " " << s1[i] << "\n";
        // 处理显式加法运算
        if(s1[i] == "a") {
            las = 0;  // 更新最后有效运算符状态
            res = stoi(s2[i]) + stoi(s3[i]);  // 执行加法
            ans += s2[i] + "+" + s3[i] + "=" + to_string(res); // 构建结果字符串
        }
        // 处理显式减法运算
        else if(s1[i] == "b") {
            las = 1;  // 更新最后有效运算符状态
            res = stoi(s2[i]) - stoi(s3[i]);  // 执行减法
            ans += s2[i] + "-" + s3[i] + "=" + to_string(res); // 构建结果字符串
        } 
        // 处理显式乘法运算
        else if(s1[i] == "c") {
            las = 2;  // 更新最后有效运算符状态
            res = stoi(s2[i]) * stoi(s3[i]);  // 执行乘法
            ans += s2[i] + "*" + s3[i] + "=" + to_string(res); // 构建结果字符串
        }
        
        // 处理继承运算符情况
        else if(s1[i] == ".") {
            // 根据最后记录的运算符状态执行相应运算
            if(las == 0) {  // 继承加法
                res = stoi(s2[i]) + stoi(s3[i]);
                ans += s2[i] + "+" + s3[i] + "=" + to_string(res);
            }
            else if(las == 1) {  // 继承减法
                res = stoi(s2[i]) - stoi(s3[i]);
                ans += s2[i] + "-" + s3[i] + "=" + to_string(res);
            }
            else if(las == 2) {  // 继承乘法
                res = stoi(s2[i]) * stoi(s3[i]);
                ans += s2[i] + "*" + s3[i] + "=" + to_string(res);
            }
        }
        // 输出结果和字符串长度
        cout << ans << " " << "\n";  // 输出完整表达式
        cout << ans.size() << "\n";  // 输出字符串总长度（包含运算符和等号）
    }
}