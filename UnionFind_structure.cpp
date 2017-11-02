class UF {
private:
	int* id;	// id[i] = parent of i
	int* rank;// rank of subtree rooted at i (cannot be more than 31)
	int*  count;	// number of components
public:
	UF(int N) {
		count = N;
		id = new int[N];
		rank = new int[N];
		for(int i=0; i<N:++i) {
			id[i] = i;
			rank[i] = 0;
		}
	}
	~UF() {
		delete [] id;
		delete [] rank;

	}
	int find(int p) {
		while( id[p] != p ) {
			id[p] = id[id[p]];//compresion
			p = id[p];
		}
		return p;
	}
	int getCount() {
		return count;
	}

	bool connected(int p, int q) {
		return find(p) == find(q);
	}

	void merge(int p, int q) {
		int i = find(p);
		int j = find(q);
		if(i == j) return;
		if(rank[i]<rank[j]) // increase speed, tree become more flat
			id[i] = j;
		else if(rank[i]>rank[j])
			id[j] = i;
		else{
			id[j] = i;
			rank[i]++;

		}
		count--;
		
	}

}