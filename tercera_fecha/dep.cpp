int solution(vector<int> &A, vector<int> &B, int F){
	vector <pair<int,int>> nuevo;
	for(int i=0; i<A.size(); i++)
		nuevo.push_back({A[i]-B[i],i});
	sort(nuevo.begin(), nuevo.end());
	long long suma=0;
	for(int i=0; i<F; i++)
		suma+=A[nuevo[i].second];
	for(int i=F; i<nuevo.size(); i++)
		suma+=B[nuevo[i].second];
	return suma;
}