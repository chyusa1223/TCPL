## Chapter 11 ##

### 1 ###

	- a, g

### 2 ###

	- e,f,i

### 3 ###

	void avg_sum(double a[], int n, double *avg, double *sum)
	{
		int i;
		*sum = 0.0;
		for(i=0;i<n;i++) *sum += a[i];
		*avg = *sum/n;
	}

### 4 ###

	void swap(int *p, int *q)
	{
		int tmp;
		tmp = *p;
		*p = *q;
		*q = tmp;
	}

### 6 ###
	
	void find_two_largest(int a[], int n, int *largest, int *second_largest)
	{
		for(int i=0;i<n;i++){
			if( a[i] > *largest ) {
				*second_largest = *largest;
				*largest = a[i];
			}
			if( a[i] < *largest && a[i] > *second_largest ) {
				*second_largest = a[i];
			}
		}
	}

### 8 ###

	int *find_largest(int a[], int n) {
		int index=-1;
		for(i=0; i<n; i++){
			if( a[i] > *largest ) index = i;
		}
		return &a[i];
	}
