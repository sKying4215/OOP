# 面向对象
* 封装  

   希望暴露public

   希望隐藏private

   对象实例化有两种方式，从栈实例化，从堆（new出来的）实例化。

   以谁做什么作为核心。

   public 放前面，private放后面（属性可以定义为private格式）。

   只读属性，只有get方法，没有set方法。
   ```C
    #include <iostream>
    #include <string>
    using namespace std;

    /**
       * 定义类：Student
       * 数据成员：m_strName
       * 数据成员的封装函数：setName()、getName()
       */  
    class Student  
    {  
          public:  
          // 定义数据成员封装函数setName()  
          void setName(string name) {   
              m_strName = name;  
          }  
      
       
          // 定义数据成员封装函数getName()  
          string getName() {  
              return m_strName;  
          }  
      
      
       //定义Student类私有数据成员m_strName  
      private:  
         string m_strName;   
      };   
  
      int main()   
      {   
           // 使用new关键字，实例化对象  
           Student *str = new Student;  
           // 设置对象的数据成员  
           str->setName("cpp");  
           // 使用cout打印对象str的数据成员  
           cout << str->getName() << endl;  
           // 将对象str的内存释放，并将其置空  
           delete str;  
           str = NULL;  
           return 0;  
      }  
   ```
   栈区，存储变量。  

   new分配的内存，是堆区。  

   全局区，存储全局变量和静态变量。  
 
   常量区，存储常量。  

   代码区，存储代码。  

   对象需要初始化，有的只有一次，有的需要初始化多次。  

   构造函数，会在对象实例化时被调用。   

   都有默认值的构造函数，称为默认构造函数。  

   一个类可以没有默认构造函数，有别的构造函数也可以实例化对象。   

   C++中，构造函数与类名相同，析构函数前面加一个波浪线。析构函数，可以进行资源释放。  
  
* 继承  
    ```C
        #include<iostream>
        using namespace std;
        //////////////////////////////////////////////////////////////////////////
        class A       //父类
        {
        private:
            int privatedateA;
        protected:
            int protecteddateA;
        public:
            int publicdateA;
        };
        //////////////////////////////////////////////////////////////////////////
        class B :public A      //基类A的派生类B（共有继承）
        {
        public:
            void funct()
            {
                int b;
                b=privatedateA;   //error：基类中私有成员在派生类中是不可见的
                b=protecteddateA; //ok：基类的保护成员在派生类中为保护成员
                b=publicdateA;    //ok：基类的公共成员在派生类中为公共成员
            }
        };
        //////////////////////////////////////////////////////////////////////////
        class C :private A  //基类A的派生类C（私有继承）
        {
                public:
                    void funct()
                    {
                int c;
                c=privatedateA;    //error：基类中私有成员在派生类中是不可见的
                c=protecteddateA;  //ok：基类的保护成员在派生类中为私有成员
                c=publicdateA;     //ok：基类的公共成员在派生类中为私有成员
            }
        };
        //////////////////////////////////////////////////////////////////////////
        class D :protected A   //基类A的派生类D（保护继承）
        {
        public:
            void funct()
            {
                int d;
                d=privatedateA;   //error：基类中私有成员在派生类中是不可见的
                d=protecteddateA; //ok：基类的保护成员在派生类中为保护成员
                d=publicdateA;    //ok：基类的公共成员在派生类中为保护成员
            }
        };
        //////////////////////////////////////////////////////////////////////////
        int main()
        {
            int a; 

            B objB;
            a=objB.privatedateA;   //error：基类中私有成员在派生类中是不可见的,对对象不可见
            a=objB.protecteddateA; //error：基类的保护成员在派生类中为保护成员，对对象不可见
            a=objB.publicdateA;    //ok：基类的公共成员在派生类中为公共成员，对对象可见

            C objC;
            a=objC.privatedateA;   //error：基类中私有成员在派生类中是不可见的,对对象不可见
            a=objC.protecteddateA; //error：基类的保护成员在派生类中为私有成员，对对象不可见
            a=objC.publicdateA;    //error：基类的公共成员在派生类中为私有成员，对对象不可见

            D objD;
            a=objD.privatedateA;   //error：基类中私有成员在派生类中是不可见的,对对象不可见
            a=objD.protecteddateA; //error：基类的保护成员在派生类中为保护成员，对对象不可见
            a=objD.publicdateA;    //error：基类的公共成员在派生类中为保护成员，对对象不可见

            return 0;  }                                                                                                                                       ```                         
 
* 多态    
