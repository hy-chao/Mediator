#pragma once
#include<iostream>
#include<string>
using namespace std;
class Colleague;
class ConcreteColleague1;
class ConcreteColleague2;

//抽象中介者类
class Mediator
{
public:
	virtual void Send(string message, Colleague * colleague) = 0;
};
//抽象同事类
class Colleague
{
protected:
	Mediator * mediator;
public:
	Colleague(Mediator * mediator)
	{
		this->mediator = mediator;
	}
};

//具体同事对象
class ConcreteColleague1 : public Colleague
{
public:
	ConcreteColleague1(Mediator * mediator) : Colleague(mediator)
	{}
	void Send(string message)
	{
		mediator->Send(message, this);
	}
	void Notify(string message)
	{
		cout << "同事1得到消息: " << message << endl;
	}
};
class ConcreteColleague2 : public Colleague
{
public:
	ConcreteColleague2(Mediator * mediator) : Colleague(mediator)
	{}
	void Send(string message)
	{
		mediator->Send(message, this);
	}
	void Notify(string message)
	{
		cout << "同事2得到消息: " << message << endl;
	}
};
//具体中介者类
class ConcreteMediator : public Mediator
{
private:
	ConcreteColleague1 * colleague1;
	ConcreteColleague2 * colleague2;
public:
	void Colleague1(ConcreteColleague1 * colleague1)
	{
		this->colleague1 = colleague1;
	}
	void Colleague2(ConcreteColleague2 * colleague2)
	{
		this->colleague2 = colleague2;
	}
	void Send(string message, Colleague * colleague)
	{
		if (colleague == colleague1)
		{
			colleague2->Notify(message);
		}
		else
		{
			colleague1->Notify(message);
		}
	}
};