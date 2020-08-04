## Chapter16 Exercises

### 1

   해당 선언에는 아무런 문제가 없으며 각 변수 모두 x,y멤버에 접근이 가능하다.

### 2

   a,b)
	struct {
	    double real;
	    double imaginary;
	} c1 = {0.0}, c2 = { 1.0, 0.0}, c3;

   c)  c1 = c2;
   d)  c3.real = c1.real + c2.real; // c4.imaginary = c1.imaginary + c2.imaginary


### 3

    a)
	struct complex {
	    double real;
	    double imaginary;
	};

    b)
	struct complex c1,c2,c3

    c) 

       struct complex make_complex(double real, double imaginary){
       	      return (struct complex) {real, imaginary};
       }
       
    d) 
       
       struct complex make_complex(struct complex a, struct complex b){
       	      struct complex result;
	      result.real = a.real + b.real;
	      result.imaginary = a.imaginary +b.imaginary;
	      return result;
       }

### 4

    a)
	typedef struct {
	    double real;
	    double imaginary;
	}complex;

    b)
	complex c1,c2,c3

    c) 

       complex make_complex(double real, double imaginary){
       	      return (complex) {real, imaginary};
       }
       
    d) 
       
       complex make_complex(complex a, complex b){
       	      complex result;
	      result.real = a.real + b.real;
	      result.imaginary = a.imaginary +b.imaginary;
	      return result;
       }

### 5

    int day_of_year(struct date d) {
	int res = 0, i;
	const int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (d.month > 1 && ((d.year % 4 == 0 && d.year % 100 != 0) 
	    || d.year % 400 == 0))
	    res++;
	for (i = 0; i < d.month; i++)
	    res += days_month[i];
	return res + d.day;
    } 

    int compare_dates(struct date d1, struct date d2) {
    int d1day = day_of_year(d1);
    int d2day = day_of_year(d2);
    if (d1day > d2day)
        return -1;
    else if (d1day < d2day)
        return 1;
    else
        return 0;
    }

### 6

    struct time split_time(long total_seconds) {
    	   struct time result;
	   result.hours = total_seconds/ 3600;
	   result.minutes = (total_seconds%3600)/60;
	   result.seconds = total_seconds%60;
	   return result;
    }

### 8

    struct color {
       int red;
       int green;
       int blue;
    };

    a) const struct color MAGENTA = {255,0,255};
    b) const struct color MAGENTA = { .red = 255, .blue = 255};


### 9 

    a)
	struct color make_color(int red, int green, int blue){

	       struct color result;

	       if( red < 0 ) red = 0;
	       else if (red > 255) red = 255;

	       if( green < 0 ) green = 0;
	       else if ( green > 255) green = 255;

	       if( blue < 0 ) blue = 0;
	       else if ( blue > 255) blue = 255;

	       result.red = red;
	       result.blue = blue;
	       result.green = green;
	       return result;
	}

    b)
	int getRed(struct color c) {
	    return c.red;
	}

    c)
	bool equal_color( struct color color1, struct color color2){
	     if( color1.red == color2.red && color1.blue == color2.blue && color1.green == color2.green)
	     	 return 1;
	     else
		 return 0;
	}
	
### 10