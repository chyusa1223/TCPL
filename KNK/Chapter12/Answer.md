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

### 9 ###

### 10 ###

### 11 ###
