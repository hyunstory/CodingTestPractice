#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string &N){

    int M = N.size();

    vector<int> pi(M, 0);

    int begin = 1, matched = 0;


    while (begin + matched < M){

        if (N[begin + matched] == N[matched]){
            matched++;

            pi[begin + matched - 1] = matched;
        }

        else{

            if (matched == 0)begin++;

                else{
                    begin += matched - pi[matched - 1];

                    matched = pi[matched - 1];

                }

        }

    }

    return pi;

}




vector<int> kmpSearch2(const string &H, const string &N){

    int n = H.size(), m = N.size();

    vector<int> result;

    vector<int> pi = getPartialMatch(N);





    int matched = 0;


    for (int i = 0; i < n; i++){



        while (matched > 0 && H[i] != N[matched])matched = pi[matched - 1];

        if (H[i] == N[matched]){
                matched++;

                if (matched == m){
                        result.push_back(i - m + 1);

                        matched = pi[matched - 1];
                }
        }

    }

    return result;

}




int shifts(string &original, const string &target){


    string doubleOriginal = original + original.substr(0, original.size() - 1);

    return kmpSearch2(doubleOriginal, target).size();

}

 



int GCD(int a, int b){

    if (a < b) swap(a, b);

    while (b != 0){

        int temp = a % b;

        a = b;

        b = temp;

    }

    return a;

}

 

void solution(){
    int N;

    cin >> N;

 

    string target, original;

    for (int i = 0; i < N; i++){

        char temp;

        cin >> temp;

        target += temp;

    }

    for (int i = 0; i < N; i++){

        char temp;

        cin >> temp;

        original += temp;

    }

 

    int result = shifts(target, original); 

 

    int divider = GCD(N, result);

 

    cout << result / divider << "/" << N / divider << endl; 

}
int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;

}
