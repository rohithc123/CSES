 // this snippet is calculating all possible sum of subsets in an array
 //calc is predefined vector of data type long long
  FOR(i,0,1<<n){
    ll calc=0;
    FOR(j,0,n){
        if(i&(1<<j))
            calc+=v[j];
    }
    check.push_back(calc);
  }
