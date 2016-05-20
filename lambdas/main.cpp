#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<math.h>
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Point
{
  double x,y;
  
  Point()
  {
      x = (rand() % 100000) - 5000;
      y = (rand() % 100000) - 5000;
  }
  
  void Print()
  {
      cout << "[" << x << "," << y << "]" << endl;
  }
};

void PerformOperation(std::function<void()> f)
{
    f();
}
int main()
{
    srand(time(NULL));
    int i = 10;
    int g = i*2;
    //To use local variables in lambdas 
    //functions, they must be captured...
    //Capttured variables are RO(Read Only)
    //If you want to change them.. must put them as refrences
    auto sayHelloWorld = [i,&g](int a, int b) -> int
    {
        //Unit Circle Value : 5pi/4  ---> (sqrt(2))/2
        g = cos((5*PI) / 4);
        return ((a+b) * (1/pow(((cos(i))),(sin(g)))));    
    };
    
    int b=3;
    int z=7;
    //Equal to sign, automcaitcally checks
    //what variables you are using inside,
    //then checks if its a local variable.
    // = change by Value. so you cant change value,
    //just refrence...
    auto equalTwoSign = [=]() -> bool
    {
        return(b==z);
    };
    
    int what = 3;
    //Same as above but now you can change,
    //since its a reference
    auto referenceMetric = [&]() -> int
    {
        what = 5;
        return what;
    };
    
    int steuf = 90;
    auto referenceAndMore = [&,steuf]() -> int
    {
        //Steuf cant be changed since
        //it is not passed in as reference
        //steuf = 90
        return steuf;
    };
    
    std::vector<int> stuff= {
        3,2,1,2,4,5
    };
    
    double total = 0;
    
    std::for_each(begin(stuff), end(stuff),
        [&](int x)
        {
         total += x;   
        }
    );
    
    cout << "Sum is " << total << endl;
    
    
    vector<Point> points;
    for(int i=0;i<=100;i++)
        points.push_back(Point());
        
    //Unsorted    
    cout << "Unsorted : " << endl;
    for(int i=0 ;i<=10;i++)
        points[i].Print();
    
    //Sorted
    std::sort(begin(points), end(points),
    //Put Const for security, reference for speed.
        [](const Point& a, const Point& b) -> bool
        {
            return((a.x*a.x)+(a.y*a.y)<((b.x*b.x)+(b.y*b.y)));
        }
    );
    
    cout << "Sorted\n";
    for(int i=0 ;i<=10;i++)
        points[i].Print();
    
    int performanceRATING = 10;
    PerformOperation(
        [&]()
        {
            performanceRATING++;
        }
    );
    cout << "PERFORMANCE RATING : " << performanceRATING << endl;
    int result = sayHelloWorld(3,2);
    cout << result << endl;
    
    cout << "REFERENCE MERTRIC : " << referenceMetric() << endl;
    cout << "ReferencesAndMore" << referenceAndMore() << endl;
}
