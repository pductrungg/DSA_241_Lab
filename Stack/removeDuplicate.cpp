string removeDuplicates(string S){
    /*TODO*/
    stack<char> stac;
    stac.push(S[0]);
    for(unsigned int i=1;i<S.size();i++){
        if(stac.top()==S[i]){
            while(stac.top()==S[i]){
                S.erase(i-1,2);
                i--;
                //cout<<S[i]<<endl;
                //cout<<stac.top()<<endl;
                stac.pop();
                if(stac.size()==0){
                    break;
                }
            }
            stac.push(S[i]);
        }
        else {
            stac.push(S[i]);
        }
    }
    return S;
}