#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 440;

string CMD[N], USR[N], SUSR[N], ANS[N];
int VAL[N], AMN[N], n, IND[N], ind, SKN[110], values[10], cntvalues[10];
long long TIM[N];
map<string, int> USER;

void SWAP(int a, int b){
    swap(CMD[a], CMD[b]);
    swap(USR[a], USR[b]);
    swap(IND[a], IND[b]);
    swap(AMN[a], AMN[b]);
    swap(VAL[a], VAL[b]);
    swap(SUSR[a], SUSR[b]);
    swap(TIM[a], TIM[b]);
    return;
}

int to_int(char c){
    return ((int)c - (int)'0');
}

long long to_second(string T){
    long long y = to_int(T[0]) * 1000 + to_int(T[1]) * 100 + to_int(T[2]) * 10 + to_int(T[3]);
    long long mo = to_int(T[5]) * 10 + to_int(T[6]);
    long long d = to_int(T[8]) * 10 + to_int(T[9]);
    long long h = to_int(T[11]) * 10 + to_int(T[12]);
    long long m = to_int(T[14]) * 10 + to_int(T[15]);
    long long s = to_int(T[17]) * 10 + to_int(T[18]);
    mo += 12ll * y;
    d += 31ll * mo;
    h += 24ll * d;
    m += 60ll * h;
    s += 60ll * m;
    return s;
}

string to_String(int a){
    if(a == 0) return "0";
    int pw = 1;
    while(pw * 10 <= a) pw *= 10;

    string ans = "";
    while(pw > 0){
        ans += (char)((a / pw) + (int)'0');
        a = a % pw;
        pw /= 10;
    }

    return ans;
}

void inp_reg(){
    cin >> USR[ind];
    string T;
    cin >> T;
    TIM[ind] = to_second(T);
    IND[ind] = ind;
    return;
}

void cal_reg(int id){
    if(USER.find(USR[id]) != USER.end()){
        ANS[IND[id]] = "Duplicate User!";
    }
    else {
	USER[USR[id]] = 100;
    ANS[IND[id]] = "Registered Successfully";
    return;
    }
    
   
}

void inp_dep(){
    cin >> USR[ind];
    cin >> AMN[ind];
    IND[ind] = ind;
    string T;
    cin >> T;
    TIM[ind] = to_second(T);
    return;
}

void cal_dep(int id){
    if(USER.find(USR[id]) == USER.end()){
        ANS[IND[id]] = "No Such User Found!";
        return;
    }
    USER[USR[id]] += AMN[id];
    ANS[IND[id]] = to_String(USER[USR[id]]);
    return;
}

void inp_wd(){
    cin >> USR[ind];
    cin >> AMN[ind];
    IND[ind] = ind;
    string T;
    cin >> T;
    TIM[ind] = to_second(T);
    return;
}

void cal_wd(int id){
    if(USER.find(USR[id]) == USER.end()){
        ANS[IND[id]] = "No Such User Found!";
        return;
    }
    if(AMN[id] > 200){
        ANS[IND[id]] = "Maximum Amount Exceeded!";
        return;
    }
    if(USER[USR[id]] < AMN[id]){
        ANS[IND[id]] = "Not Enough Fund!";
        return;
    }

    int tmpamn = AMN[id];
    for(int i = 4; i >= 0; i--){
        cntvalues[i] = min(tmpamn / values[i], SKN[values[i]]);
        tmpamn -= cntvalues[i] * values[i];
    }

    if(tmpamn > 0){
        ANS[IND[id]] = "Not Enough Banknotes!";
        return;
    }
    for(int i = 0; i < 5; i++){
        SKN[values[i]] -= cntvalues[i];
    }
    USER[USR[id]] -= AMN[id];
    ANS[IND[id]] = to_String(USER[USR[id]]);
    return;
}

void inp_tr(){
    CMD[ind] = "WITHDRAW2";
    CMD[ind + 1] = "DEPOSIT2";
    IND[ind] = ind;
    IND[ind + 1] = ind + 1;

    cin >> USR[ind];
    cin >> USR[ind + 1];
    SUSR[ind] = USR[ind + 1];
    cin >> AMN[ind];
    AMN[ind + 1] = AMN[ind];
    string T;
    cin >> T;
    TIM[ind] = to_second(T);
    TIM[ind + 1] = TIM[ind] + 3600;
    ind ++;
    return;
}

void inp_gb(){
    cin >> USR[ind];
    IND[ind] = ind;
    string T;
    cin >> T;
    TIM[ind] = to_second(T);
    return;
}

void inp_ab(){
    cin >> VAL[ind];
    cin >> AMN[ind];
    IND[ind] = ind;
    string T;
    cin >> T;
    TIM[ind] = to_second(T);
    return;
}





void cal_wd2(int id){
    if(USER.find(USR[id]) == USER.end()){
        ANS[IND[id] + 1] = "No Such User Found!";
        return;
    }
    if(USER.find(SUSR[id]) == USER.end()){
        ANS[IND[id] + 1] = "No Such User Found!";
        return;
    }
    if(AMN[id] > 3000){
        ANS[IND[id] + 1] = "Maximum Amount Exceeded!";
        return;
    }
    if(USER[USR[id]] < AMN[id]){
        ANS[IND[id] + 1] = "Not Enough Fund!";
        return;
    }
    USER[USR[id]] -= AMN[id];
    ANS[IND[id] + 1] = to_String(USER[USR[id]]);
    return;
}

void cal_dep2(int id){
    if(ANS[IND[id]][0] > '9'){
        return;
    }
    USER[USR[id]] += AMN[id];
    return;
}

void cal_gb(int id){
    if(USER.find(USR[id]) == USER.end()){
        ANS[IND[id]] = "No Such User Found!";
        return;
    }
    if(USER[USR[id]] < 10){
        ANS[IND[id]] = "Not Enough Fund!";
        return;
    }
    USER[USR[id]] -= 10;
    ANS[IND[id]] = to_String(USER[USR[id]]);
    return;
}

void cal_ab(int id){
    SKN[VAL[id]] += AMN[id];
    int ans = 0;
    for(int i = 0; i < 5; i++) ans += SKN[values[i]] * values[i];
    ANS[IND[id]] = to_String(ans);
    return;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> CMD[ind];
        if(CMD[ind] == "REGISTER") inp_reg();
        else if(CMD[ind] == "DEPOSIT") inp_dep();
        else if(CMD[ind] == "WITHDRAW") inp_wd();
        else if(CMD[ind] == "TRANSFER") inp_tr();
        else if(CMD[ind] == "GET_BALANCE") inp_gb();
        else if(CMD[ind] == "ADD_BANKNOTE") inp_ab();
        ind ++;
    }
    n = ind;

    for(int i = 1; i < n; i++){
        int cur = i;
        while(cur > 0 && TIM[cur - 1] > TIM[cur]){
            SWAP(cur, cur - 1);
            cur --;
        }
    }

    values[0] = 1, values[1] = 5, values[2] = 10, values[3] = 50, values[4] = 100;
    for(int i = 0; i < 5; i++) SKN[values[i]] = 10;

    for(int i = 0; i < n; i++){
        if(CMD[i] == "REGISTER") cal_reg(i);
        else if(CMD[i] == "DEPOSIT") cal_dep(i);
        else if(CMD[i] == "WITHDRAW") cal_wd(i);
        else if(CMD[i] == "WITHDRAW2") cal_wd2(i);
        else if(CMD[i] == "DEPOSIT2") cal_dep2(i);
        else if(CMD[i] == "GET_BALANCE") cal_gb(i);
        else if(CMD[i] == "ADD_BANKNOTE") cal_ab(i);
    }

    for(int i = 0; i < n; i++){
        if(ANS[i] != "")cout << ANS[i] << '\n';
    }
    return 0;
}
