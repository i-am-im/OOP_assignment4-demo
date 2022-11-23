//ISHITA MUKHERJEE 2105967 CSE18 ASSIGNMENT 4
#include <iostream>
using namespace std;
// Constructor class created to demonstrate constructors and destructors
class Constructor
{
public:
    int x;
    Constructor()
    {
        x = 28;
        cout << "\nDefault Constructor called with value: " << x;
    }
    Constructor(int a)
    {
        x = a;
        cout << "\nParameterised Constructor called with value: " << x;
    }
    Constructor (Constructor &const1, Constructor &const2)
    {
        x = const1.x + const2.x;
        cout << "\nCopy Constructor called with value: " << x;
    }
    ~Constructor()
    {
        cout << "\nDestructor invoked ";
    }
};
// Operator overloading to show --operator overloading
class Count {
   private:
    int value;

   public:  // Constructor to initialize count to 18
    Count() : value(18) {
    }

    // Overload -- when used as prefix
    void operator -- ()
    {
        --value;
    }

    void display() 
    {
        cout << "Count: " << value << endl;
    }
};
// Function overloading to carry out arithmatic operation
float arith(int r)
{
    float a;
    a =  r/2 ;
    return a;
}
int arith(int a, int b)
{
    float a1;
    a1 = a%b;
    return a1;
}
float arith(int x, int y, int z)
{
    int a2;
    a2 = x * y * z;
    return a2;
}
// friend function concept used to add two values
class base {
    int val1, val2;
public:

    void get() {
        cout << "Enter two values:";
        cin >> val1>>val2;
    }
    friend float mean(base ob);
};

float mean(base ob) {
    return float(ob.val1 + ob.val2) / 2;
}
// Demonstration of Inheritance
class A
{
protected:
    int a;

public:
    A()
    {
        a = 18;
    }
    virtual void Show_Value() = 0;
};
//use of virtual class
class B : virtual public A
{
protected:
    int b;

public:
    B()
    {
        b = 16;
    }
};
class C : virtual public A
{
protected:
    int c;

public:
    C()
    {
        c = 28;
    }
};
class D : public B, public C
{
protected:
    int d;

public:
    D()
    {
        d = 13;
    }
    void Show_Value()
    {
        cout << "\nA: " << a;
        cout << "\nB: " << b;
        cout << "\nC: " << c;
        cout << "\nD: " << d;
    }
};
// Template class to show the smaller number
template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

// Exception handling to carry out division by zero error
void Div_by_zero()
{
    int a, b;
    cout << "\nEnter two numbers :";
    cin >> a >> b;
    try
    {
        if (b == 0)
            throw -1;
        else
            cout << "\nQuotient : " << (a / b);
    }
    catch (int)
    {
        cout << "\nDivision not possible !";
    }
}
//program to show function overloading

int main()
{
    int c;
    while (1)
    {
        cout << "\n\nENTER YOUR CHOICE\n\n";
        cout << "\n1.Demonstrating use of Constructor and Destructor";
        cout << "\n2.Using Operator Overloading";
        cout << "\n3.Using Function Overloading";
        cout << "\n4.Utilizing Friend Function";
        cout << "\n5.Demonstrating Inheritance";
        cout << "\n6.Using Template";
        cout << "\n7.Using Exception Handling";
        cout << "\n9.Quit";
        cout << endl;
        cout << "Enter choice: ";
        cin >> c;
        if (c == 1)
        {
            Constructor s1 ;//default constructor called
            Constructor  s2(20);//parametarised constructor called
            Constructor  s3(s1, s2);//copy constructor called
        }
        else if (c == 2)
        {
            Count count1;
           // Call the "void operator ++" function
         --count1;
          count1.display();
        }
        else if (c == 3)
        {
            int r,a,b,x,y,z;
            float arith1;
            cout << "\nEnter the number to be halved: \n";
            cin >> r;
            arith1 = arith(r);
            cout << "\nHalf of " <<r<<" is : " << arith1 << endl;
            cout << "Enter the numbers to be multiplied:\n";
            cin >> x;
            cin >> y;
            cin >> z;
            arith1 = arith(x,y,z);
            cout << "\nProduct of the numbers : " << arith1 << endl;
            cout << "\nEnter the Dividend and Divisor : \n";
            cin >> a >> b;
            arith1 = arith(a, b);
            cout << "\nRemainder : " << arith1 << endl;
            break;
        }
        //to demonstrate friend function
        else if (c == 4)
        {
           base obj;
          obj.get();
          cout << "\n Average value is : " << mean(obj);
        }
        //demonnstrating inheritence
        else if (c == 5)
        {
            D d;
            cout << "\nInherited values: ";
            d.Show_Value();
            break;
        }
        else if (c == 6)
        {
           cout << myMax<int>(28, 13) << endl;
            cout << myMax<double>(13.5, 30.15) << endl;
            cout << myMax<char>('I', 'M') << endl;
            break;
        }
        else if (c == 7)
        {
            cout << "\nDivision by Zero using Exception Handling: ";
            Div_by_zero();
            break;
        }
        else if (c == 8)
        {
            exit(0);
        }
        else
        {
            cout << "\n Invalid  Choice ! ";
        }
    }
    return 0;
}