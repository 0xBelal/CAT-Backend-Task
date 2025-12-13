#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> read_input(){
    int n; cin>>n;
    vector<string> vs(n);
    
    for(string& s : vs){
        cin>>s;
    }

    return vs;
}

void solve(){

    vector<string> vs = read_input();

/* sol using sorting O(nlog(n))

    sort(vs.begin(),vs.end());
    cout<< vs[0];

*/

/* brute force solution O(n) */

    string min_el = vs[0];
    for(int i=0;i<vs.size();i++){
        min_el = min(min_el,vs[i]);
    }
    cout<< min_el;

}
int main(){

    solve();
}