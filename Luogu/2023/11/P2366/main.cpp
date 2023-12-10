#include <bits/stdc++.h>

using namespace std;

int n;
array<pair<string, int>, 10005> valueTable; //将value中的值存入数组，方便用sort排序（似乎不这样做也可以直接对map排序的说）
map<string, int> value;

int toValue(string v){ //转为整型
    int out = 0;
    if(isdigit(*v.begin())){ //如果本身就是数字，那么将数字字符串转为整型
        int j = 1;
        for(auto it = v.end() - 1; it >= v.begin(); --it){
            out += (*it - '0') * j;
            j *= 10;
        }
    }
    else{ //否则就为变量，查找映射中变量的值，默认为0
        out = value[v];
    }
    return out;
}

int main(int argc, char *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int rv = 0; //标记加号左右两个表达式
        string input, valName, rightValue[3];
        /*
         * input为输入字符串
         * valName为左值
         * rightValue为右值加号左右的值
         */
        cin >> input;
        bool eq = false; //标记等号是否出现
        bool plus = false; //标记加号是否出现
        for(auto it : input){ //遍历输入字符串
            if(it == ';'){
                break;
            }
            if(!eq && it == '='){ //遍历到等号，标记
                eq = true;
                continue;
            }
            if(!eq){ //如果等号未被标记，则读入的是左值
                valName += it;
                continue;
            }
            if(it == '+'){ //遍历到加号
                rv++; //输入第二个表达式
                plus = true; //标记
                continue;
            }
            rightValue[rv] += it;
        }
        if(!plus){ //加号未被标记
            int val = 0;
            val = toValue(rightValue[0]); //将右值字符串转换为整型值
            value[valName] = val; //赋值
            continue;
        }
        else{ //被标记
            int val0 = 0, val1 = 0;
            val0 = toValue(rightValue[0]); //分别求值
            val1 = toValue(rightValue[1]);
            value[valName] = val0 + val1; //相加得到最终右值
        }
    }
    int m = 0; //被赋值过的变量数
    for(auto it : value){ //遍历value
        valueTable[m++] = it; //将遍历到的值存入valueTable
    }
    sort(valueTable.begin(), valueTable.begin() + m, [](const pair<string, int> a, pair<string, int> b) -> bool { return a.first < b.first; }); // 这里用了lambda表达式
    //按字典序排序
    for(auto it = valueTable.begin(); !it -> first.empty(); ++it){ //输出
        cout << it -> first << ' ' << it -> second << endl;
    }
    return 0;
}