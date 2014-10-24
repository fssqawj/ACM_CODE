#include <cstdio>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
#define PI 3.1415926535
#define N 1010
 
struct POINT {
	int x, y;
	POINT ( void ) {};
	POINT ( int _x, int _y ) : x( _x), y( _y ) {}
	POINT ( const POINT& a ) {
		x = a.x; y = a.y;
	}
	POINT& operator = ( const POINT a ) {
		x = a.x; y = a.y;
		return *this;
	}
	friend bool operator < ( const POINT& a, const POINT& b ) {
		if ( a.y != b.y ) return a.y < b.y;
		else return a.x < b.x;
	}
	friend int operator ^ ( const POINT& a, const POINT& b ) {
		return a.x * b.y - a.y * b.x;
	}
	friend POINT operator - ( const POINT& a, const POINT& b ) {
		return POINT ( a.x - b.x, a.y - b.y );
	}
	double mod ( void ) {
		return sqrt ( x * x + y * y + 0.0 );
	}
} pt[ N ];
 
int st[ N ];
 
double gao ( int n ) {
	int top;
	st[ top = 0 ] = 0;
	for ( int i = 1 ; i < n ; ++i ) {
		while ( top > 0 && ( ( pt[ st[ top ] ] - pt[ st[ top - 1 ] ] ) ^ ( pt[ i ] - pt[ st[ top ] ] ) ) < 0 ) {
			--top;
		}
		st[ ++top ] = i;
	}
	int tmp = top;
	for ( int i = n - 2 ; i >= 0 ; --i ) {
		while ( top != tmp && ( ( pt[ st[ top ] ] - pt[ st[ top - 1 ] ] ) ^ ( pt[ i ] - pt[ st[ top ] ] ) ) < 0 ) {
			--top;
		}
		st[ ++top ] = i;
	}
	double ret = 0;
	for ( int i = 0 ; i < top ; ++i ) {
		POINT m = pt[ st[ i ] ] - pt[ st[ i + 1 ] ];
		ret += m.mod ();
	}
	POINT m = pt[ st[ 0 ] ] - pt[ st[ top ] ];
	ret += m.mod ();
	return ret;
}
 
int main ( int argc, char* argv[] ) {
	int n, l;
	while ( scanf ( "%d%d", &n, &l ) != EOF ) {
		for ( int i = 0 ; i < n ; ++i ) {
			scanf ( "%d%d", &pt[ i ].x, &pt[ i ].y );
		}
		sort ( pt, pt + n );
		printf ( "%.0lf\n", gao ( n ) + 2 * PI * l );
	}
	return 0;
}
