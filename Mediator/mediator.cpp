#include "mediator.h"
int main()
{
	ConcreteMediator * m = new ConcreteMediator();

	ConcreteColleague1 * c1 = new ConcreteColleague1(m);
	ConcreteColleague2 * c2 = new ConcreteColleague2(m);
	
	m->Colleague1(c1);
	m->Colleague2(c2);

	c1->Send("�Է�����?");
	c2->Send("û���أ��������ͣ�");
	return 0;
}