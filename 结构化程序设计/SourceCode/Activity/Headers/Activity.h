#pragma once
class Activity // �κν����������˳����򣩶���һ���
{
public:
	virtual void run() = 0; // һ�����еĽӿڣ� ����ʵ��������ɾ��彻��
	virtual void show_name() const = 0; // һ����ӡ�Լ����ֵĽӿ�
	virtual ~Activity() {}
};