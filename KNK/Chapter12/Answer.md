## Chapter 12 ## 

### 1 ###

    a) 54
    b) 34
    c) 4
    d) true 
    e) false

### 2 ###

    It is not legal. middle = low + (high-low)/2

### 3 ###

    {10,9,8,7,6,5,4,3,2,1};

### 4 ###

    bool is_empty(void)
    {
	*top_ptr == 0;
    }
    
    bool make_empty(void)
    {
	*top_ptr = 0;
    }

    bool is_full(void)
    {
	*top_ptr == STACK_SIZE;
    }

### 5 ###

    b,c

### 6 ###

    int sum_array(const int *a, int n)
    {
	int sum=0;
	for(i=0;i<n;i++) sum += *(a+i);
	return sum;
    }

### 7 ###

    bool search(const int a[], int n,int key)
    {
	for(int i=0;i<n;i++)
	   if( *(a+i) == key) return true;
	return false;
    }
    
### 8 ###

	void store_zeros(int a[], int n)
	{
		int i;
		for(i=0;i<n;i++) *(a+i)=0;
	}

### 9 ###

	double inner_product(const double *a, const double *b, int n)
	{
		int sum;
		for(int i=0;i<n;i++) sum += (*(a+i))*(*(b+i));
		return sum;
	}

### 10 ###

	int *find_middle(int a[], int n) {
		return a+(n/2);
	}

### 11 ###

	int find_largest(int *a, int n)
	{
		int index;
		for(int i=0;i<n;i++) {
			if(*(a+i) > largest) index = i; 
		}
		return *(a+index);
	}

### 12 ###

	int find_two_largest(const int *a,int *largest, int *second_largest, int n)
	{
		*largest =0, *second_largest=0;
		for(int i=0;i<n;i++) {
			if(*(a+i) > largest) {
				second_largest = largest;
				largest = *(a+i); 
			}
			else if(*(a+i) < largest && *(a+i) > second_largest) ; 
		}
		return *(a+index);
	}

### 13 ##

	double ident[N][N];
	double *id;
	int index=0;
	  
	for(id = &ident[0][0];id<=&ident[N-1][N-1];id++){
		if(index == N+1 || id == &ident[0][0] ) {
			*id = 1;
			index=0;
		}
		else {
			*id = 0;
			index++;
		}
	}

### 14 ###

	int temperature[2][4] = { {24,26,27,28},
					{28,22,21,32}};
	int x,y;
	int *p,*px = &x, *py = &y;

	bool search(const int a[], int n,int key,int*x)
	{
		for(int i=0;i<n;i++)
		if( *(a+i) == key) {
		*x= i;
		return true;
		}
		return false;
	}

	for(p=temperature[0];p<temperature[2];p+=4){
		if(search(p,4,32,px) == true) printf("X : %d -> TRUE!\n",*px);
	}
	bool search(const int a[], int n,int key)
	{
		for(int i=0;i<n;i++)
			if( *(a+i) == key) return true;
		return false;
	}


