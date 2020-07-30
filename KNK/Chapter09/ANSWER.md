## Excercises ##

### E1 ###

    double triangle_area(double base, double height)
    double product
    {
	product = base * height;
	return product / 2;
    }
    
### E2 ###

    int check(int x,int y,int n){
    	if( x>0 && x<n-1 && y>0 && y<n-1) return 1;
	else return 2;
    }

### E6 ###

    int digit(int n, int k){
    	int ans, tmp=1;
    	for(i=0;i<k;i++) tmp*=10; 
	ans = (int)((double)n/tmp);
	if(ans == 0) return 0;
	else return ans;
    }

### E7 ###

    a)  i = f(83,12);
    b)  x = f(83,12);
    c)  i = f(3.15,9.28);
    d)  x = f(3.15,9.28);
    e)  f(83,12);
    
    All legal!

### E8 ###

    a) void f(double x);
    b) void f(double);
    c) void f(x);
    d) f(double x);
    
    a,b are valid prototypes!!

### E9 ###

    i=1, j=2
    
### E10 ###

    int func1(int a[], int n) {
    	return a[n-1];
    }
    
    double func1(int a[], int n) {
    	int i=0, sum=0; 
    	for(i=0;i<n;i++){
	   sum+= a[i];
	}
	return sum/(double)n;
    }

    int func1(int a[], int n) {
    	int i=0, sum=0; 
    	for(i=0;i<n;i++){
	   if(a[i]>0) sum+= 1;
	}
	return sum;
    }

### E12 ###

    double inner_product( double a[], double b[], int n){
    	   int i=0, sum=0;
    	   for(i=0;i<n;i++){
		sum += (a[i]*b[i]);
	   }
	   return sum;
    }

### E14 ###

    bool has_zero(int a[], int n)
    {
	int i;

	for(i=0;i<n;i++)
	   if(a[i] == 0)
	      return true;

	return false;
    }

### E15 ###

    double median( double x, double y, double z)
    {
	return x>y?(x<z?x:(z>y?z:y)):(y<z?y:(z>x?z:x));
    }
	
### E16 ###

    int fact( int n)
    {
	return n==1? 1: n*fact(n-1);
    }

### E17 ###

    int fact( int n)
    {
        int i=1;	
	for(i=2;i<=n;i++) n*=i;
	return i;
    }

### E19 ###

    void pb(int n){
    	 if(n!=0) {
	 pb(n/2);
	 putchar('0'+n%2);
	 }
	 }
