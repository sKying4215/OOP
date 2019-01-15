
//C++的多态性用一句话概括就是：在基类的函数前加上virtual关键字，在派生类中重写该函数，运行时将会根据对象的实际类型来调用相应的函数。如果对象类型是派生类，就调用派生类的函数；如果对象类型是基类，就调用基类的函数
//1：用virtual关键字申明的函数叫做虚函数，虚函数肯定是类的成员函数。
//2：存在虚函数的类都有一个一维的虚函数表叫做虚表，类的对象有一个指向虚表开始的虚指针。虚表是和类对应的，虚表指针是和对象对应的。
//3：多态性是一个接口多种实现，是面向对象的核心，分为类的多态性和函数的多态性。
//4：多态用虚函数来实现，结合动态绑定.
//5:纯虚函数是虚函数再加上 = 0；
//6：抽象类是指包括至少一个纯虚函数的类。
//纯虚函数 : virtual void fun() = 0; 即抽象类！必须在子类实现这个函数，即先有名称，没有内容，在派生类实现内容。


//js 语法中不需要声明virtual也可以实现继承
#include "pch.h"
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void Funtest1(int i)
	{
		cout << "Base::Funtest1()" << endl;
	}
	void Funtest2(int i)
	{
		cout << "Base::Funtest2()" << endl;
	}

};
class Drived :public Base
{
	virtual void Funtest1(int i)
	{
		cout << "Drived::Fubtest1()" << endl;
	}
	virtual void Funtest2(int i)
	{
		cout << "Drived::Fubtest2()" << endl;
	}
	//此方法无法通过编译，是已声明成员函数
	//void Funtest2(int i)
	//{
	//	cout << "Drived::Fubtest2()" << endl;
	//}
};
class BaseVirtual
{
	virtual void Funtest3() = 0;
};

class DrivedVirtual :public BaseVirtual
{
	virtual void Funtest3()
	{
		cout << "Drived::Funtest3()" << endl;
	};
};

void TestVirtual(Base& b)
{
	b.Funtest1(1);
	b.Funtest2(2);
};

int main()
{
	Base b;
	Drived d;
	//BaseVirtual bv;	//纯虚函数不能实例化
	DrivedVirtual v;
	TestVirtual(b);
	TestVirtual(d);
	return 0;
}
//输出结果：

//Base::Funtest1()
//Base::Funtest2()
//Drived::Fubtest1()  
//Base::Funtest2()		//因为基类此方法为声明为虚方法，所以派生类调用时候调用的是基类的方法

//继承
//  C++ 允许多继承  JS不允许多继承
//https://www.cnblogs.com/longcnblogs/archive/2017/10/09/7642951.html

#include "pch.h"
#include <iostream>

using namespace std;
class Base
{
public:
	void fun0() { cout << "base" << endl; }
	int base = 1;
};
class Base1
{
public:
	void fun2() { cout << "base" << endl; }
	int base1 = 3;
};
class Derive :public Base
{
public:
	void fun1() { cout << "base1" << endl; }
	int derive = 2;
};

class Derive2 :public Base,public Base1
{
public:
	void fun1() { cout << "base1" << endl; }
	int derive = 2;
};

int main()
{
	Derive d;
	Derive2 d2;
	int _result = d.base + d.derive;
	int _result2 = d2.base + d2.derive+d2.base1;
	cout << _result << endl;
	cout << _result2 << endl;
}

//JS 使用call 函数可以模拟出“假”的多继承
function Person(name){
	this.name = name;
}
 
Person.prototype.say = function(){
	console.log(this.name);
}
 
var p = new Person("KD");
p.say();
 
var obj = {}
Object.setPrototypeOf(obj,Person.prototype)//obj.__proto__=Person.prototype
Person.call(obj,"KD");
obj.say()
console.log(obj instanceof Person)//true

