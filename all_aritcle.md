> @duzixi
> # Task01 C++对OOP的实现
> 
> 从本质上说，OOP是用机器（编程）语言描述和构建问题模型的一种方式。
> 是否应该用OOP范式，取决于所解决的问题是否是一个复杂系统，构成多样，
> 且构成要素之间有着繁杂的联系。
> 而机器"语言知识一个帮助你实现最终目标的载体。"
> 
> 能够实现OOP范式的编程语言有很多，C++只是其中之一。
> 一般而言，可以简单直接的实现OOP范式的语言被称之为"面向对象语言"。如: Java, C#等....
> 而事实上，通过一些技术手段，也可以让某些传统意义上的面向过程语言支持OOP范式。如：C
> 只是这样成本太大，一般不会这样做而已。
> 
> 数据是现代计算机对客观实在的唯一描述形式。
> 一组不同维度的数据（如：姓名、年龄、身高、体重、三维....），抽象成一个实例（如：人）。
> 一组有同样数据结构的实例抽象成一个类别。
> 对数据进行的各种计算等操作也包含在抽象的类别当中。
> 这本质上是对数据的改变，当然，这里所说的数据不限于本类中的数据。
> 数据维度、实例、类别、操作，在不同的语言设计逻辑中，这些概念所用的属于略有不同。
>  
>            C++
> 数据维度  数据成员
> 实例      数据对象
> 类别      类
> 操作      成员函数

# 面向对象

> @ifdog
> - 不完全面向对象
>        ```C
>>            #include <Iostream>
>>            using namespace std;
>>            
>>            class TestClass
>>            {
>>               public:
>>                   TestClass();
>>                   friend void setnum(TestClass &t,int n);
>>                   ~TestClass();
>>               private:
>>                   int num;
>>           };
>>
>>           TestClass::TestClass()
>>           {
>>               cout<<"TestClass constructor"<<endl;
>>            }
>>            
>>            TestClass::~TestClass()      //析构函数在RAII等技巧中广泛使用
>>            {                            //而在Java中没有这个概念，C#中虽有但通常并不建议使用
>>                cout<<"TestClass destructor"<<endl;
>>            }
>>            
>>            void setnum(TestClass &t,int n)
>>            {
>>                t.num=n;                 //“友元”特性使一个外部方法给私有成员数据赋值
>>            }
>>            
>>            TestClass Ts;                //存在class之外的global数据
>>            int main()                   //main函数不在任何class内
>>            {
>>                setnum(Ts,100);          //“友元”的概念打破了传统的封装
>>                std::setnum(Ts,250);     //::标识符用于访问class之外的方法
>>                return 0;
>>            }
>>        ```



# 封装  
> @yang
>
>   希望暴露public
>
>   希望隐藏private
>
>   对象实例化有两种方式，从栈实例化，从堆（new出来的）实例化。
>
>   以谁做什么作为核心。
>
>   public 放前面，private放后面（属性可以定义为private格式）。
>
>   只读属性，只有get方法，没有set方法。
>>   ```C
>>    #include <iostream>
>>    #include <string>
>>    using namespace std;
>>
>>    /**
>>       * 定义类：Student
>>       * 数据成员：m_strName
>>       * 数据成员的封装函数：setName()、getName()
>>       */  
>>    class Student  
>>    {  
>>          public:  
>>          // 定义数据成员封装函数setName()  
>>          void setName(string name) {   
>>              m_strName = name;  
>>          }  
>>      
>>        
>>           // 定义数据成员封装函数getName()  
>>           string getName() {  
>>               return m_strName;  
>>           }  
>>       
>>       
>>        //定义Student类私有数据成员m_strName  
>>          private:  
>>             string m_strName;   
>>          };   
>> 
>>          int main()   
>>          {   
>>               // 使用new关键字，实例化对象  
>>               Student *str = new Student;  
>>               // 设置对象的数据成员  
>>               str->setName("cpp");  
>>               // 使用cout打印对象str的数据成员  
>>               cout << str->getName() << endl;  
>>               // 将对象str的内存释放，并将其置空  
>>               delete str;  
>>               str = NULL;  
>>               return 0;  
>>         }  
>>      }
>>  ```
>   栈区，存储变量。  
>
>   new分配的内存，是堆区。  
>
>   全局区，存储全局变量和静态变量。  
> 
>   常量区，存储常量。  
>
>   代码区，存储代码。  
>
>   对象需要初始化，有的只有一次，有的需要初始化多次。  
>
>   构造函数，会在对象实例化时被调用。   
>
>   都有默认值的构造函数，称为默认构造函数。  
>
>   一个类可以没有默认构造函数，有别的构造函数也可以实例化对象。   
>
>   C++中，构造函数与类名相同，析构函数前面加一个波浪线。析构函数，可以进行资源释放。  

> @ifdog
>  - 字段无默认初始化，初始值不定
>>    ```C
>>    char revBuf[100];
>>    printf("%s", revBuf);
>>    ```
>>    ↓↓↓↓↓↓↓↓↓↓↓↓
>>    ```
>>    烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫....
>>    ```
>    - 可为class声明友元，友元可访问class的私有数据
>    - ::标识符用于访问class之外的方法


# 继承  
> @yang
>   - 对于公有继承方式  
>   
>      (1) 基类成员对其对象的可见性：
>
>      公有成员可见，其他不可见。这里保护成员同于私有成员。
>
>      (2) 基类成员对派生类的可见性：
>
>      公有成员和保护成员可见，而私有成员不可见。这里保护成员同于公有成员。
>
>      (3) 基类成员对派生类对象的可见性：
>
>      公有成员可见，其他成员不可见。
>
>      所以，在公有继承时，派生类的对象可以访问基类中的公有成员；派生类的成员函数可以访问基类中的公有成员和保护成员。这里，一定要区分清楚派生类的对象和派生类中的成员函数对基类的访问是不同的。
>
>   - 对于私有继承方式   
>   
>      (1) 基类成员对其对象的可见性：
>
>      公有成员可见，其他成员不可见。
>
>      (2) 基类成员对派生类的可见性：
>
>      公有成员和保护成员是可见的，而私有成员是不可见的。
>
>      (3) 基类成员对派生类对象的可见性：
>
>      所有成员都是不可见的。
>
>      所以，在私有继承时，基类的成员只能由直接派生类访问，而无法再往下继承。
>
>   - 对于保护继承方式   
>   
>      这种继承方式与私有继承方式的情况相同。两者的区别仅在于对派生类的成员而言，对基类成员有不同的可见性。
>
>      上述所说的可见性也就是可访问性。
>
>      关于可访问性还有另的一种说法。这种规则中，称派生类的对象对基类访问为水平访问，称派生类的派生类对基类的访问为垂直访问。
>>    ```C
>>        #include<iostream>
>>        using namespace std;
>>        //////////////////////////////////////////////////////////////////////////
>>       class A       //父类
>>        {
>>           private:
>>               int privatedateA;
>>           protected:
>>               int protecteddateA;
>>           public:
>>               int publicdateA;
>>         };
>>        //////////////////////////////////////////////////////////////////////////
>>        class B :public A      //基类A的派生类B（共有继承）
>>        {
>>           public:
>>               void funct()
>>               {
>>                   int b;
>>                   b=privatedateA;   //error：基类中私有成员在派生类中是不可见的
>>                  b=protecteddateA; //ok：基类的保护成员在派生类中为保护成员
>>                   b=publicdateA;    //ok：基类的公共成员在派生类中为公共成员
>>               }
>>        };
>>        //////////////////////////////////////////////////////////////////////////
>>        class C :private A  //基类A的派生类C（私有继承）
>>        {
>>          public:
>>              void funct()
>>              {
>>                int c;
>>                c=privatedateA;    //error：基类中私有成员在派生类中是不可见的
>>                c=protecteddateA;  //ok：基类的保护成员在派生类中为私有成员
>>                c=publicdateA;     //ok：基类的公共成员在派生类中为私有成员
>>               }
>>        };
>>        //////////////////////////////////////////////////////////////////////////
>>        class D :protected A   //基类A的派生类D（保护继承）
>>        {
>>           public:
>>               void funct()
>>               {
>>                   int d;
>>                   d=privatedateA;   //error：基类中私有成员在派生类中是不可见的
>>                   d=protecteddateA; //ok：基类的保护成员在派生类中为保护成员
>>                   d=publicdateA;    //ok：基类的公共成员在派生类中为保护成员
>>               }
>>           };
>>        //////////////////////////////////////////////////////////////////////////
>>        int main()
>>        {
>>            int a; 
>>
>>            B objB;
>>            a=objB.privatedateA;   //error：基类中私有成员在派生类中是不可见的,对对象不可见
>>            a=objB.protecteddateA; //error：基类的保护成员在派生类中为保护成员，对对象不可见
>>            a=objB.publicdateA;    //ok：基类的公共成员在派生类中为公共成员，对对象可见
>>
>>            C objC;
>>            a=objC.privatedateA;   //error：基类中私有成员在派生类中是不可见的,对对象不可见
>>            a=objC.protecteddateA; //error：基类的保护成员在派生类中为私有成员，对对象不可见
>>            a=objC.publicdateA;    //error：基类的公共成员在派生类中为私有成员，对对象不可见
>>
>>            D objD;
>>            a=objD.privatedateA;   //error：基类中私有成员在派生类中是不可见的,对对象不可见
>>            a=objD.protecteddateA; //error：基类的保护成员在派生类中为保护成员，对对象不可见
>>            a=objD.publicdateA;    //error：基类的公共成员在派生类中为保护成员，对对象不可见
>>
>>            return 0;   
>>              
>>          }                  

> @shiying
> //  C++ 允许多继承  JS不允许多继承
> //https://www.cnblogs.com/longcnblogs/archive/2017/10/09/7642951.html
>
>> #include "pch.h"
>> #include <iostream>
>> 
>> using namespace std;
>> class Base
>> {
>> public:
>> 	void fun0() { cout << "base" << endl; }
>> 	int base = 1;
>> };
>> class Base1
>> {
>> public:
>> 	void fun2() { cout << "base" << endl; }
>> 	int base1 = 3;
>> };
>> class Derive :public Base
>> {
>> public:
>> 	void fun1() { cout << "base1" << endl; }
>> 	int derive = 2;
>> };
>> 
>> class Derive2 :public Base,public Base1
>> {
>> public:
>> 	void fun1() { cout << "base1" << endl; }
>> 	int derive = 2;
>> };
>> 
>> int main()
>> {
>> 	Derive d;
>> 	Derive2 d2;
>> 	int _result = d.base + d.derive;
>> 	int _result2 = d2.base + d2.derive+d2.base1;
>> 	cout << _result << endl;
>> 	cout << _result2 << endl;
>> }
>> 
>> //JS 使用call 函数可以模拟出“假”的多继承
>> function Person(name){
>> 	this.name = name;
>> } 
>> 
>> Person.prototype.say = function(){
>> 	console.log(this.name);
>> }
>> var p = new Person("KD");
>> p.say();
>> var obj = {}
>> Object.setPrototypeOf(obj,Person.prototype)//obj.__proto__=Person.prototype
>> Person.call(obj,"KD");
>> obj.say()
>> console.log(obj instanceof Person)//true

> @ifdog
>    - 三种继承:public,protect,private
>    - 无统一的继承树。对比C#等一切都基于Object.
>    - 支持多继承，可有多个父类
>>    ```C
>>    class Derived : public B1, public B2
>>    {
>>    private:
>>        int d_;
>>    public:
>>        //构造函数，先调用B1的，在调用B2的，最后调用Derived的
>>        Derived(int b1 = 0, int b2 = 0, int d = 0) : B1(b1), B2(b2)
>>        {
>>           d_ = d;
>>            cout << "调用Derived的构造函数" << endl;
>>        }
>>        //析构函数的调用顺序和构造函数的相反
>>        ~Derived(){}
>>        void print()
>>        {
>>            cout << "b1_ : " << b1_ << " b2_ : " << b2_ << " d_ : " << d_ << endl;
>>        }
>>    };
>>    ```

# 多态    

> @yang
>   多态按字面的意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。  
>
>   C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。  
>
>   下面的实例中，基类 Shape 被派生为两个类，如下所示：  
>
>   实例   
>   
>>      #include <iostream>   
>>      using namespace std;  
>>
>>      class Shape {  
>>         protected:  
>>            int width, height;  
>>         public:  
>>            Shape( int a=0, int b=0)  
>>            {  
>>               width = a;  
>>               height = b;  
>>            }  
>>            int area()  
>>            {  
>>               cout << "Parent class area :" <<endl;  
>>               return 0;  
>>            }  
>>      };  
>>      class Rectangle: public Shape{  
>>         public:  
>>            Rectangle( int a=0, int b=0):Shape(a, b) { }  
>>            int area ()  
>>            {   
>>               cout << "Rectangle class area :" <<endl;  
>>               return (width * height);   
>>            }  
>>      };  
>>      class Triangle: public Shape{  
>>         public:  
>>            Triangle( int a=0, int b=0):Shape(a, b) { }  
>>            int area ()  
>>            {   
>>               cout << "Triangle class area :" <<endl;  
>>               return (width * height / 2);   
>>            }  
>>      };  
>>      // 程序的主函数  
>>      int main( )  
>>      {  
>>         Shape *shape;  
>>         Rectangle rec(10,7);  
>>         Triangle  tri(10,5);  
>>
>>         // 存储矩形的地址
>>         shape = &rec;
>>         // 调用矩形的求面积函数 area
>>         shape->area();
>>
>>         // 存储三角形的地址
>>         shape = &tri;
>>         // 调用三角形的求面积函数 area
>>         shape->area();
>>
>>         return 0;
>>      }
>   当上面的代码被编译和执行时，它会产生下列结果：
>
>>   Parent class area  
>>   Parent class area  
>   
>   导致错误输出的原因是，调用函数 area() 被编译器设置为基类中的版本，这就是所谓的静态多态，或静态链接 - 函数调用在程序执行前就准备好了。有时候这也被称为早绑定，因为 area() 函数在程序编译期间就已经设置好了。
>
>   但现在，让我们对程序稍作修改，在 Shape 类中，area() 的声明前放置关键字 virtual，如下所示：
>
>>      class Shape {
>>         protected:
>>            int width, height;
>>         public:
>>            Shape( int a=0, int b=0)
>>            {
>>               width = a;
>>               height = b;
>>            }
>>            virtual int area()
>>            {
>>               cout << "Parent class area :" <<endl;
>>               return 0;
>>            }
>>      };  
>   修改后，当编译和执行前面的实例代码时，它会产生以下结果： 
>   
>>   Rectangle class area  
>>   Triangle class area     
>   
>   此时，编译器看的是指针的内容，而不是它的类型。因此，由于 tri 和 rec 类的对象的地址存储在 *shape 中，所以会调用各自的 area() 函数。
>   
>   正如您所看到的，每个子类都有一个函数 area() 的独立实现。这就是多态的一般使用方式。有了多态，您可以有多个不同的类，都带有同一个名称但具有不同实现的函数，函数的参数甚至可以是相同的。  
>
>   虚函数     
>   虚函数是在基类中使用关键字 virtual 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。  
>   我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。  
>
>   纯虚函数  
>   您可能想要在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，但是您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。   
>   我们可以把基类中的虚函数 area() 改写如下：  
>
>>      class Shape {
>>         protected:
>>            int width, height;
>>         public:
>>            Shape( int a=0, int b=0)
>>            {
>>               width = a;
>>               height = b;
>>            }
>>            // pure virtual function
>>            virtual int area() = 0;
>>      };
>   = 0 告诉编译器，函数没有主体，上面的虚函数是纯虚函数。  

> @shiying
> //C++的多态性用一句话概括就是：在基类的函数前加上virtual关键字，在派生类中重写该函数，运行时将会根据对象的实际类型来调用相应的函数。如果对象类型是派生类，就调用派生类的函数；如果对象类型是基类,就调用基类的函数
> //1：用virtual关键字申明的函数叫做虚函数，虚函数肯定是类的成员函数。
> //2：存在虚函数的类都有一个一维的虚函数表叫做虚表，类的对象有一个指向虚表开始的虚指针。虚表是和类对应的，虚表指针是和对象对应的。
> //3：多态性是一个接口多种实现，是面向对象的核心，分为类的多态性和函数的多态性。
> //4：多态用虚函数来实现，结合动态绑定.
> //5:纯虚函数是虚函数再加上 = 0；
> //6：抽象类是指包括至少一个纯虚函数的类。
> //纯虚函数 : virtual void fun() = 0; 即抽象类！必须在子类实现这个函数，即先有名称，没有内容，在派生类实现内容。
> 
> //js 语法中不需要声明virtual也可以实现继承
>> #include "pch.h"
>> #include <iostream>
>> using namespace std;
>> 
>> class Base
>> {
>> public:
>> 	virtual void Funtest1(int i)
>> 	{
>> 		cout << "Base::Funtest1()" << endl;
>> 	}
>> 	void Funtest2(int i)
>> 	{
>> 		cout << "Base::Funtest2()" << endl;
>> 	}
>> };
>> 
>> class Drived :public Base
>> {
>> 	virtual void Funtest1(int i)
>> 	{
>> 		cout << "Drived::Fubtest1()" << endl;
>> 	}
>> 	virtual void Funtest2(int i)
>> 	{
>> 		cout << "Drived::Fubtest2()" << endl;
>> 	}
>> 	//此方法无法通过编译，是已声明成员函数
>> 	//void Funtest2(int i)
>> 	//{
>> 	//	cout << "Drived::Fubtest2()" << endl;
>> 	//}
>> };
>> class BaseVirtual
>> {
>> 	virtual void Funtest3() = 0;
>> };
>> class DrivedVirtual :public BaseVirtual
>> {
>> 	virtual void Funtest3()
>> 	{
>> 		cout << "Drived::Funtest3()" << endl;
>> 	};
>> };
>> 
>> void TestVirtual(Base& b)
>> {
>> 	b.Funtest1(1);
>> 	b.Funtest2(2);
>> };
>> 
>> int main()
>> {
>> 	Base b;
>> 	Drived d;
>> 	//BaseVirtual bv;	//纯虚函数不能实例化
>> 	DrivedVirtual v;
>> 	TestVirtual(b);
>> 	TestVirtual(d);
>> 	return 0;
>> }
>> 
>> //输出结果：
>> 
>> //Base::Funtest1()
>> //Base::Funtest2()
>> //Drived::Fubtest1()  
>> //Base::Funtest2()		//因为基类此方法为声明为虚方法，所以派生类调用时候调用的是基类的方法

> @ifdog
> - 方法和大部分操作符都可重载
>>    ```C
>>     bool operator <(const int& d)
>>      {
>>         if(num < d.num)
>>         {
>>            return true;
>>         }
>>         if(num == d.num)
>>         {
>>            return true;
>>         }
>>         return false;
>>      }
>>    ```
>    - 使用virtual标记可被重载的方法(虚方法),java中无此概念,C#有
>>    ```C
>>    #include<iostream> 
>>    using namespace std;
>>    class A{
>>    public:
>>         virtual  void  display(){  cout<<"A"<<endl; }
>>         };
>>    class B :  public A{
>>    public:
>>         void  display(){ cout<<"B"<<endl;}
>>         };
>>    void doDisplay(A *p)
>>    {
>>        p->display();
>>        delete p;
>>    }
>>    int main(int argc,char* argv[])
>>    {
>>        doDisplay(new B());
>>        return 0;
>>    }
>>    ```
